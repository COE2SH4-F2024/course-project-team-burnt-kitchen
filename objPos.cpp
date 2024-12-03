/**
 * @file objPos.cpp
 * @author Caden Chan (chanc167), Tyler Fong (fongt5)
 * @date 2024-12-02
 * 
 */

#include "objPos.h"
#include <iostream>

using namespace std;
//objPos name = objPos();
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos::~objPos() {
    // delete pos;
}

objPos::objPos(const objPos &o) {
    pos = new Pos;
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

objPos& objPos::operator=(const objPos &o) {
    if(this == &o) return *this;

    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
    return *this;
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}

void objPos::printPos() {
    cout << "objPos : { " << endl;
    cout << "x: " << pos->x << "," << endl;
    cout << "y: " << pos->y << "," << endl;
    cout << "sym: " << symbol << endl;
    cout << "}" << endl;
}