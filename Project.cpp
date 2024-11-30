#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs * game;
Player * player;

int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
    player = new Player(game);
    
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
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    int i, j;
    int spaceFlag = 1;
    objPosArrayList* playerPosList;

    // drawing routine
    int x, y;
    for(i=0;i<game -> getBoardSizeY();i++) {
        for(j=0;j<game -> getBoardSizeX();j++) {
            x = (player -> getPlayerHead()).pos -> x;
            y = (player -> getPlayerHead()).pos -> y;
            if(i == 0 || i == game -> getBoardSizeY()-1 || j == 0 || j == game -> getBoardSizeX()-1) {
                MacUILib_printf("#");
            // } else if(x+1 == j && y+1 == i) {
            //     MacUILib_printf("%c", (player -> getPlayerHead()).symbol);
            // } else {
            } else {
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
                if(spaceFlag) {
                    MacUILib_printf(" ");
                }
            }

        }
        MacUILib_printf("\n");
    }   
    MacUILib_printf("HELLO\n");
    playerPosList -> printList();
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
