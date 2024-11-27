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
}