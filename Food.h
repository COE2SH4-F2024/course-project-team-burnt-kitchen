#ifndef FOOD_H
#define FOOD_H

#include "objPos.h" 
#include "objPosArrayList.h"
#include <cstdlib>
class Food 
{
    public:
        Food();
        Food(int x, int y);
        ~Food();
        // void generateFood(objPos blockOff);
        objPos getFoodPos() const;
        void setFoodPos(objPos obj);
        void setFoodPos(int newX, int newY);
        void generateFood(objPosArrayList* blockOff);

    private:
        objPos foodPos;
};


#endif