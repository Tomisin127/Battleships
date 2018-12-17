/**
 *  @file EasyPlayer.h
 *  @brief contains header for easy player class
 */

#ifndef EASYPLAYER_INCLUDED
#define EASYPLAYER_INCLUDED

#include "Player.h"

/**
 * EasyPlayer: class declaration of easy bot
 */
class EasyPlayer : public Player{
    public:
        Player* create(std::string nm, const Game& g){
            return new EasyPlayer(nm, g);
        }
        EasyPlayer(std::string nm, const Game& g);   ///< Constructor for easy player
        virtual bool placeShips(Board& b);  ///< Method for placing ships
        virtual Point recommend();    ///< Recommends attack for easy player
        virtual void recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID); ///< Record attack result
        virtual void recordOpponent(Point p);   ///< Records opponent's result
    private:
        Point mLastCell;    ///Last cell attacked
};

#endif // EASYPLAYER_INCLUDED
