#include "GameMechs.h"


//the logic behind the game running and the board 

GameMechs::GameMechs()
{
    input = '\0';
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
    srand(time(NULL));

    food = Food();
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = '\0';
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    srand(time(NULL));

    food = Food();
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // nothing to deallocate, no heap data members
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

void GameMechs::incrementScore(int s)
{
    score += s;
}


int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

// More methods should be added here
void GameMechs::generateFood(objPosArrayList* blockOff) 
{
    int diffPos = 0;
    int x_values[28] = {0};
    int y_values[13] = {0};
    int x_cord, y_cord;

    while(!diffPos)
    {
        x_cord = rand() % 28;
        y_cord = rand() % 13;
        for(int i = 0; i < blockOff -> getSize(); i++)
            if(blockOff -> getElement(i).pos -> x == x_cord && blockOff -> getElement(i).pos -> y == y_cord)
            {
                diffPos = 0;
                break;
            }
            else
            {
                diffPos = 1;
            }
    }
    
    food.setFoodPos(x_cord, y_cord);
    
    }

objPos GameMechs::getfoodPos()
{
    return food.getFoodPos();
}