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
void generateFood(objPosArrayList* blockOff) 
{   
    //is the objPosArrayList the player -> do i make the collision logic in here? 
   int new_items = 0;
   int x_values[28] = {0}; 
   int y_values[13] = {0};
   int x_cord, y_cord;


    do {
        x_cord = rand() % 28; //gives a value [0,27]
        
        if(x_values[x_cord] == 0)
        {
            x_values[x_cord] = 1;
            new_items++;
        }
    }
    while(new_items < blockOff -> getSize()); //assuming blockOff -> getSize() gives the number of food items to be generated
    
    new_items = 0;
    do {
        y_cord = rand() % 13; //gives a value [0,13]
        
        if(y_values[y_cord] == 0)
        {
            y_values[y_cord] = 1;
            new_items++;
        }
    }
    while(new_items < blockOff -> getSize());

    for(int i = 0; i < blockOff -> getSize(); i++)
    {
       for(int j = 0; j < 28; j++)
       {
            if(x_values[j] == 1)
            {
                blockOff -> getElement(i).pos -> x = j; //BlockOff is a pointer -> to dereference and use getElement(index). is .pos part of an object? (why can you just do .pos)
                //part of the objPos class is also a pointer and must dereference to get the x value 
                x_values[j] = 0;
                break;
            }
       } 

        for(int j = 0; j < 13; j++)
        {
            if(y_values[j] == 1)
            {
                blockOff -> getElement(i).pos -> y = j; //BlockOff is a pointer -> to dereference and use getElement(index). is .pos part of an object? (why can you just do .pos)
                //part of the objPos class is also a pointer and must dereference to get the x value 
                y_values[j] = 0;
                break;
            }
        }
    }
}