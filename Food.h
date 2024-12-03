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
        // void generateFood(objPos blockOff);
        objPosArrayList* getFoodBucket() const;
        void generateFood(objPosArrayList* blockOff);
        int getFoodCount() const;

    private:
        GameMechs* mainGameMechsRef;
        objPosArrayList* foodBucket;
        int foodCount;
};


#endif