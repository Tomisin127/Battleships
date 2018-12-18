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
        int nTrials = 0;    ///< Integer containing number of trials
        int p1wins = 0;     ///< Integer containing number of first player's victories
        int p2wins = 0;     ///< Integer containing number of second player's victories
};
#endif // SETUP_INCLUDED
