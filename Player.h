#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* foodRef);
        ~Player();

        objPos getPlayerPos() const; // Upgrade this in iteration 3. 
        objPosArrayList* getPlayerPosList() const;   
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here
        objPos getPlayerHead();
        void increasePlayerLength(int x);
        bool checkFoodConsumption();
        bool checkSelfCollision();

    private:
        objPos playerPos; // Upgrade this in iteration 3. 
        objPosArrayList* playerPosList;      
        enum Dir myDir;
        char const sym = '@';
        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        Food* food;
        int growCount = 0;
};

#endif