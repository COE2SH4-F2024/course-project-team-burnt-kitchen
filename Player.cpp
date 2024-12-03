/**
 * @file Player.cpp
 * @author Caden Chan (chanc167), Tyler Fong (fongt5)
 * @date 2024-12-02
 * 
 */

#include "Player.h"
#include <iostream>

using namespace std;


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    food = foodRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPosList -> insertHead(objPos(2, 3, '@'));
    growCount = 0;

}


Player::~Player()
{
    // delete heap members
    delete mainGameMechsRef;
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPosList() const
{
    return playerPosList;
}

/**
 * Take keystrokes, update player direction variable `myDir` accordingly
 * Only 90deg changes in direction allowed
 */
void Player::updatePlayerDir()
{
    if(mainGameMechsRef -> getInput() == 0) return;
    switch(mainGameMechsRef -> getInput())
    {
        case 27:  // exit - escape
            mainGameMechsRef -> setExitTrue();
            break;
        case 'w':
        case 'W':
            if (myDir == DOWN) break;
            myDir = UP;
            break;
        
        case 'a':
        case 'A':
            if (myDir == RIGHT) break;
            myDir = LEFT;
            break;
        
        case 's':
        case 'S':
            if(myDir == UP) break;
            myDir = DOWN;
            break;

        case 'd':
        case 'D':
            if (myDir == LEFT) break;
            myDir = RIGHT;
            break;
    }       
}

/**
 * Move the player in the direction given by `myDir`
 * Apply wraparound logic to player position
 * Grow the player if necessary
 */
void Player::movePlayer()
{
    if(myDir == STOP) return;
    int x = getPlayerHead().pos -> x;
    int y = getPlayerHead().pos -> y;
    // Adjust position + WRAPAROUND LOGIC
    if(myDir == UP) {
        y--;
        if(y < 0) {
            y = (mainGameMechsRef -> getBoardSizeY())-3;  // -2 to account for borders, -1 for 0-based indexing 
        }
    } else if (myDir == DOWN) {
        y = (y + 1) % ((mainGameMechsRef -> getBoardSizeY())-2); // -2 for borders

    } else if (myDir == LEFT) {
        x --;
        if(x < 0) {
            x = (mainGameMechsRef -> getBoardSizeX())-3; // -2 for borders, -1 for 0-based indexing
        }
    } else if (myDir == RIGHT) {
        x = (x + 1) % ((mainGameMechsRef -> getBoardSizeX())-2); // -2 for borders
    }
    // CREATE AND ADD NEW PLAYER HEAD
    objPos newHead = objPos(x, y, sym);
    
    playerPosList -> insertHead(newHead);

    // If growing, do not remove tail
    if(growCount > 0) {
        growCount--;
    } else {
        playerPosList -> removeTail();
    }

}


objPos Player::getPlayerHead() {
    return playerPosList -> getHeadElement();
}

void Player::increasePlayerLength(int x) {
    growCount += x;
}

/**
 * Checks if the player head has collided with any food on the playing field
 * @return The symbol of the food that was consumed OR 0 if no collision with food
 */
char Player::checkFoodConsumption() {
    for(int i=0; i < 5; i++)
    {
        if(mainGameMechsRef -> isSamePosition(getPlayerHead(), food -> getFoodBucket() -> getElement(i))) 
        {
            return food -> getFoodBucket() -> getElement(i).symbol;
        }
    }
    return 0;
}

/**
 * Checks if the player head has collided with any other pieces of the player body.
 * @return true/false
 */
bool Player::checkSelfCollision() {
    for(int i=1;i<getPlayerPosList() -> getSize();i++) {
        if(mainGameMechsRef -> isSamePosition(getPlayerHead(), getPlayerPosList() -> getElement(i))) return true;
    }
    return false;
}