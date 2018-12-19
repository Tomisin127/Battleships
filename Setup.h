/**
 *  @file Setup.h
 *  @brief contains header for setup class
 */

#ifndef SETUP_INCLUDED
#define SETUP_INCLUDED

#include "functional"
#include "Game.h"

/**
 *  Setup class
 */
class Setup{
    public:
        Setup();
    private:
        std::function <void()> instruction;
        bool addShips(Game& g);
        int selectMode();
        int selectBot();
        bool rematch();
        void init();
        int nTrials = 0;    ///< Integer containing number of trials
};
#endif // SETUP_INCLUDED
