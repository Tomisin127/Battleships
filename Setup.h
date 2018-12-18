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
        Setup();
    private:
        bool addShips(Game& g);
        int selectMode();
        int selectBot();
        void init();
        int nTrials = 0;
        int p1wins = 0;
        int p2wins = 0;
};
#endif // SETUP_INCLUDED
