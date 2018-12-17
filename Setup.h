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
        void start();
    private:
        bool addShips(Game& g);
        int selectMode();
        int selectBot();
        void init();
};
#endif // SETUP_INCLUDED
