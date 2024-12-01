#include "Food.h"


Food::Food()
{
    foodPos = objPos(0, 0, '$');
}
Food::Food(int x, int y)
{
    foodPos = objPos(x, y, '$');
}

Food::~Food()
{
    
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

void Food::setFoodPos(objPos obj) {
    foodPos.pos -> x = obj.pos -> x;
    foodPos.pos -> y = obj.pos -> y;
    foodPos.symbol = obj.symbol;
}

void Food::setFoodPos(int newX, int newY) {
    foodPos.pos -> x = newX;
    foodPos.pos -> y = newY;
}

void Food::generateFood(objPosArrayList* blockOff) 
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
    
    setFoodPos(x_cord, y_cord);
    
}