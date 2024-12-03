/**
 * @file Project.cpp
 * @author Caden Chan (chanc167), Tyler Fong (fongt5)
 * @date 2024-12-02
 * 
 */

#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs * game;
Player * player;
Food * food;

int main(void)
{

    Initialize();

    while(!(game -> getExitFlagStatus()))  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    game = new GameMechs();
    food = new Food(game);
    player = new Player(game, food);
    food -> generateFood(player -> getPlayerPosList()); 
}

void GetInput(void)
{
    if(MacUILib_hasChar()) {
        game -> setInput(MacUILib_getChar());
    }
   
}

void RunLogic(void)
{
    player -> updatePlayerDir();
    player -> movePlayer();
    game -> clearInput();
    if(player -> checkFoodConsumption() == '$')
    {
        game -> incrementScore(100);
        player -> increasePlayerLength(1);
        food -> generateFood(player -> getPlayerPosList()); 
    }
    else if(player -> checkFoodConsumption() == '%')
    {
        game -> incrementScore(500);
        player -> increasePlayerLength(3);
        food -> generateFood(player -> getPlayerPosList()); 
    }

    if(player -> checkSelfCollision()) {
        game -> setLoseFlag();
        game -> setExitTrue();
    }
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int i, j, k;
    int spaceFlag = 1;
    objPosArrayList* playerPosList;

    // drawing routine
    for(i=0;i<game -> getBoardSizeY();i++) {
        for(j=0;j<game -> getBoardSizeX();j++) {
            if(i == 0 || i == game -> getBoardSizeY()-1 || j == 0 || j == game -> getBoardSizeX()-1) {
                MacUILib_printf("#");
            } 
            else {
                // not player, not border. check if any item positions match
                spaceFlag = 1;
                playerPosList = player -> getPlayerPosList();
                for(int k=0;k<playerPosList -> getSize();k++) {
                    if(playerPosList -> getElement(k).pos -> x == j-1 && playerPosList -> getElement(k).pos -> y == i-1) {
                        MacUILib_printf("%c", (playerPosList -> getElement(k).symbol));
                        spaceFlag = 0;
                        break;
                    }
                }

                for(int k=0;k < food -> getFoodCount();k++) {
                    if(food -> getFoodBucket() -> getElement(k).pos -> x == j-1 && food -> getFoodBucket() -> getElement(k).pos -> y == i-1) {
                        MacUILib_printf("%c", (food -> getFoodBucket() -> getElement(k).symbol));
                        spaceFlag = 0;
                        break;
                    }
                }


                if(spaceFlag) {
                    MacUILib_printf(" ");
                }
            }

        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d\n", game -> getScore());   
    MacUILib_printf("Snake Length: %d\n", player -> getPlayerPosList() -> getSize());
    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
