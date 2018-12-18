/**
 *  @file HumanPlayer.h
 *  @brief contains header for human player class
 */

#ifndef HUMANPLAYER_INCLUDED
#define HUMANPLAYER_INCLUDED

#include "Player.h"

/**
 * HumanPlayer: declaration for player class that's controlled by human
 */
class HumanPlayer : public Player{
    public:
        Player* create(std::string nm, const Game& g) override {
            return new HumanPlayer(nm, g);
        }
        HumanPlayer(std::string nm, const Game& g) : Player(nm, g){};
        ~HumanPlayer() {};  ///< Destructor for human player
        virtual bool human() const { return true; };
        virtual bool placeShips(Board& b);
        virtual Point recommend();
        virtual void recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID);
        virtual void recordOpponent(Point p);
};

#endif // HUMANPLAYER_INCLUDED
