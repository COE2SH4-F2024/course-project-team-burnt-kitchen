#include "Player.h"
#include <iostream>

using namespace std;


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    food = foodRef;
    myDir = STOP;
    playerPos = objPos(3, 3, '@');
    playerPosList = new objPosArrayList();
    playerPosList -> insertHead(objPos(2, 3, '@'));
    playerPosList -> insertTail(objPos(3, 3, '@'));
    playerPosList -> insertTail(objPos(4, 3, '@'));
    growCount = 0;
    // playerPosList -> insertHead(objPos(3, 4, '@'));
    // playerPosList -> insertHead(objPos(3, 5, '@'));
    // playerPosList -> insertHead(objPos(3, 6, '@'));

}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
    delete playerPosList;
}

objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos array list
}

objPosArrayList* Player::getPlayerPosList() const
{
    return playerPosList;
}

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

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if(myDir == STOP) return;
    int x = getPlayerHead().pos -> x;
    int y = getPlayerHead().pos -> y;
    if(myDir == UP) {
        y--;
        if(y < 0) {
            y = (mainGameMechsRef -> getBoardSizeY())-3;
        }
    } else if (myDir == DOWN) {
        y = (y + 1) % ((mainGameMechsRef -> getBoardSizeY())-2);

    } else if (myDir == LEFT) {
        x --;
        if(x < 0) {
            x = (mainGameMechsRef -> getBoardSizeX())-3;
        }
    } else if (myDir == RIGHT) {
        x = (x + 1) % ((mainGameMechsRef -> getBoardSizeX())-2);
    }
    objPos newHead = objPos(x, y, sym);
    cout << "A: " << newHead.pos -> x << ", " << newHead.pos -> y << endl;

    
    playerPosList -> insertHead(newHead);
    if(growCount > 0) {
        growCount--;
    } else {
        playerPosList -> removeTail();
    }
    // getPlayerHead().pos -> x = x;
    // getPlayerHead().pos -> y = y;

}

// More methods to be added
objPos Player::getPlayerHead() {
    return playerPosList -> getHeadElement();
}

void Player::increasePlayerLength(int x) {
    growCount += x;
}
