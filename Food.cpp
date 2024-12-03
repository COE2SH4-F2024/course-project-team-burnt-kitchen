/**
 * @file Food.cpp
 * @author Caden Chan (chanc167), Tyler Fong (fongt5)
 * @date 2024-12-02
 * 
 */

#include "Food.h"
#include <iostream>


Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodCount = 5;
    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff) 
{
    int diffPos;
    int x_cord, y_cord;
    char symbol = '$';
    while (getFoodBucket() -> getSize() > 0) {
        getFoodBucket() -> removeTail();
    }
    for(int i = 0; i < foodCount; i++)
    {
        diffPos = 0;
        while(!diffPos)
        {
            x_cord = rand() % (mainGameMechsRef -> getBoardSizeX()-2);
            y_cord = rand() % (mainGameMechsRef -> getBoardSizeY()-2);
            for(int j = 0; j < blockOff -> getSize(); j++)
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
        if(i <= 2)
        {
            getFoodBucket() -> insertTail(objPos(x_cord, y_cord, '$'));
        }
        else
        {
            getFoodBucket() -> insertTail(objPos(x_cord, y_cord, '%'));
        }
    }
    
}

objPosArrayList* Food::getFoodBucket() const
{
    return foodBucket;
}

int Food::getFoodCount() const
{
    return foodCount;
}