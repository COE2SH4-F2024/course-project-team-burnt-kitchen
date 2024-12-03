/**
 * @file Food.h
 * @author Caden Chan (chanc167), Tyler Fong (fongt5)
 * @date 2024-12-02
 * 
 */

#ifndef FOOD_H
#define FOOD_H

#include "objPos.h" 
#include "objPosArrayList.h"
#include <cstdlib>
#include "GameMechs.h"

class Food 
{
    public:
        Food(GameMechs* thisGMRef);
        ~Food();
        objPosArrayList* getFoodBucket() const;
        void generateFood(objPosArrayList* blockOff);
        int getFoodCount() const;

    private:
        GameMechs* mainGameMechsRef;
        objPosArrayList* foodBucket;
        int foodCount;
};


#endif