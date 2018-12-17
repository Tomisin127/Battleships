/**
 *  @file PlayerFactory.h
 *  @brief contains header for Player Factory class
 */

#ifndef PLAYERFACTORY_INCLUDED
#define PLAYERFACTORY_INCLUDED

#include "HumanPlayer.h"
#include "EasyPlayer.h"
#include "MediumPlayer.h"
#include "HardPlayer.h"

class PlayerFactory{
    public:
        static Player* createPlayer(int choice, std::string nm, const Game& g);
    private:
        static Player* getPrototypes(int choice, std::string nm, const Game& g);
};

#endif // PLAYERFACTORY_INCLUDED
