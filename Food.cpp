#include "Food.h"
#include "GameMechs.h"

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