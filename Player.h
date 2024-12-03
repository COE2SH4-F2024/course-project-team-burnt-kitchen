/**
 * @file Player.h
 * @author Caden Chan (chanc167), Tyler Fong (fongt5)
 * @date 2024-12-02
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{   
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* foodRef);
        ~Player();

        objPosArrayList* getPlayerPosList() const;   
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        objPos getPlayerHead();
        void increasePlayerLength(int x);
        char checkFoodConsumption();
        bool checkSelfCollision();

    private:
        objPosArrayList* playerPosList;      
        enum Dir myDir;
        char const sym = '*';
        GameMechs* mainGameMechsRef;
        Food* food;
        int growCount = 0;
};

#endif