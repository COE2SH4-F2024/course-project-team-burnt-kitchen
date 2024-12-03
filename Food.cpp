#include "Food.h"
#include <iostream>


Food::Food()
{
    foodCount = 5;
    foodBucket = new objPos[foodCount];
    foodBucket[0] = {2, 5, '$'};
    foodBucket[1] = {3, 5, '$'};
    foodBucket[2] = {4, 5, '$'};
    foodBucket[3] = {5, 5, '$'};
    foodBucket[4] = {6, 5, '$'};
}

Food::~Food()
{
    
}

void Food::generateFood(objPosArrayList* blockOff) 
{
    int diffPos;
    int x_cord, y_cord;
    char symbol = '$';

    for(int i = 0; i < foodCount; i++)
    {
        diffPos = 0;
        while(!diffPos)
        {
            x_cord = rand() % 28;
            y_cord = rand() % 13;
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
            getFoodBucket()[i].setObjPos(x_cord, y_cord, '$');
        }
        else
        {
            getFoodBucket()[i].setObjPos(x_cord, y_cord, '%');
        }
    }
    
}

objPos* Food::getFoodBucket() const
{
    return foodBucket;
}