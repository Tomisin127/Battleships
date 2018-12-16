/**
 *  @file Setup.h
 *  @brief contains header for setup class
 */

#ifndef SETUP_INCLUDED
#define SETUP_INCLUDED

#include "Game.h"

/**
 *  Setup class
 */
class Setup{
    public:
        bool start();
    private:
        bool addShips(Game& g);
        int selectMode();
        int selectBot();
};
#endif // SETUP_INCLUDED
