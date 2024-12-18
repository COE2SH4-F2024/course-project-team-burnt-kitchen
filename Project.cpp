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

#define DELAY_CONST 100000 // 0.1s delay

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
    // Player movement 
    player -> updatePlayerDir();
    player -> movePlayer();
    game -> clearInput();

    // Collision Logic
    // Checking if the player hit a normal food, special food or itself
    char consumed = player -> checkFoodConsumption();
    if(consumed == '@')
    {
        game -> incrementScore(100);
        player -> increasePlayerLength(1);
        food -> generateFood(player -> getPlayerPosList()); 
    }
    else if(consumed == '$')
    {
        game -> incrementScore(500);
        player -> increasePlayerLength(3);
        food -> generateFood(player -> getPlayerPosList()); 
    }

    if(player -> checkSelfCollision()) {
        game -> setLoseFlag();
        game -> setExitTrue();
    }
    int emptySpacesLeft = game -> getBoardAreaNoBorder() - player -> getPlayerPosList() -> getSize();
    if(emptySpacesLeft < 5) {
        food -> setFoodCount(0);
    }
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int i, j, k;
    int spaceFlag = 1;
    objPosArrayList* playerPosList;
    objPos currentPos;
    char currentSymbol;

    // Drawing routine
    for(i=0;i<game -> getBoardSizeY();i++) {
        for(j=0;j<game -> getBoardSizeX();j++) {
            // Game border = top/bottom row + left/right-most column 
            if(i == 0 || i == game -> getBoardSizeY()-1 || j == 0 || j == game -> getBoardSizeX()-1) {
                MacUILib_printf("#");
            } 
            // non-border
            else {
                /**
                 * j-1 = x coordinate, shifted one to the right to account for border
                 * i-1 = y coordainte, shifted one down to account for border
                 * '\0' = placeholder
                 */
                currentPos = objPos(j-1, i-1, '\0'); 

                spaceFlag = 1;
                // draw player
                playerPosList = player -> getPlayerPosList();
                for(int k=0;k<playerPosList -> getSize();k++) {
                    currentSymbol = playerPosList -> getElement(k).getSymbolIfPosEqual(&currentPos);
                    if(currentSymbol) {
                        MacUILib_printf("%c", currentSymbol);
                        spaceFlag = 0;
                        break;
                    }
                }
                // draw food
                for(int k=0;k < food -> getFoodCount();k++) {
                    currentSymbol = food -> getFoodBucket() -> getElement(k).getSymbolIfPosEqual(&currentPos);
                    if(currentSymbol) {
                        MacUILib_printf("%c", currentSymbol);
                        spaceFlag = 0;
                        break;
                    }
                }


                if(spaceFlag) { // if still true, then position [i, j] in game grid is empty
                    MacUILib_printf(" ");
                }
            }

        }
        MacUILib_printf("\n");
    }

    //Additional Info for Player HUD
    if(!game -> getExitFlagStatus()) {
        MacUILib_printf("===================\n");
        MacUILib_printf("WASD to move\n");
        MacUILib_printf("@: +100 pts | + 1 snake length\n");
        MacUILib_printf("$: +500 pts | + 3 snake length\n");
        MacUILib_printf("===================\n");
        MacUILib_printf("Score: %d\n", game -> getScore());   
        MacUILib_printf("Snake Length: %d\n", player -> getPlayerPosList() -> getSize());
        MacUILib_printf("===================\n");
    }
    else {
        // exit/lose messages
        MacUILib_printf("=======================\n");
        if(game -> getLoseFlagStatus()) {
            MacUILib_printf("Your snake crashed into\nitself and perished...\nYou lose!\n");
        } else {
            MacUILib_printf("Game exited.\nThanks for playing!\n");
        }
        MacUILib_printf("=======================\n");

        // MacUILib_printf("================\n");
        MacUILib_printf("Score: %d\n", game -> getScore());   
        MacUILib_printf("Snake Length: %d\n", player -> getPlayerPosList() -> getSize());
        MacUILib_printf("=======================\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST);
}


void CleanUp(void)
{
    MacUILib_uninit();
}
