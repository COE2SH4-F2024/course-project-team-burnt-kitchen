#ifndef FOOD_H
#define FOOD_H

#include "objPos.h" 
#include "objPosArrayList.h"
#include <cstdlib>
class Food 
{
    public:
        Food();
        ~Food();
        // void generateFood(objPos blockOff);
        objPos* getFoodBucket() const;;
        void generateFood(objPosArrayList* blockOff);

    private:
        objPos* foodBucket;
        int foodCount;
};


#endif