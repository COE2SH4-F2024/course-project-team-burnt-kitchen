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

/**
 * Function creates a new array list of food objects
 */
void Food::generateFood(objPosArrayList* blockOff) 
{
    bool validNewPos;
    //Removes all the existing objects in the food bucket
    while (getFoodBucket() -> getSize() > 0) 
    {
        getFoodBucket() -> removeTail();
    } 
    // Generate new food
    objPos newFood;
    for(int i = 0; i < foodCount; i++)
    {
        // 3 normal items, 2 special items
        if (i <= 2) {
            newFood = objPos(0, 0, '@');
        } else {
            newFood = objPos(0, 0, '$');
        }
        validNewPos = true;
        do {
            //Generates random x and y values within the game board
            newFood.pos -> x = rand() % (mainGameMechsRef -> getBoardSizeX()-2);
            newFood.pos -> y = rand() % (mainGameMechsRef -> getBoardSizeY()-2);


            for(int j = 0; j < blockOff -> getSize(); j++)
            {
                //Checks the all the existing player position and compares them to the randomly generated x and y values
                if(blockOff -> getElement(j).isPosEqual(&newFood))
                {
                    validNewPos = false;
                    break;
                }
            }
            if(validNewPos) {
                for(int j=0; j < getFoodBucket() -> getSize(); j++) 
                {
                    if(getFoodBucket() -> getElement(j).isPosEqual(&newFood)) 
                    {
                        validNewPos = false;
                        break;
                    }
                }
            }
        } while(!validNewPos);
        getFoodBucket() -> insertTail(newFood);
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

void Food::setFoodCount(int x) {
    foodCount = x;
}