/**
 *  @file MediumPlayer.h
 *  @brief contains header for medium player class
 */

#ifndef MEDIUMPLAYER_INCLUDED
#define MEDIUMPLAYER_INCLUDED

#include "Player.h"

/**
 * MediumPlayer: class declaration for player class that's controlled by medium bot
 */
class MediumPlayer : public Player{
    public:
        Player* create(std::string nm, const Game& g) override {
            return new MediumPlayer(nm, g);
        }
        ///Constructor for medium bot
        MediumPlayer(std::string nm, const Game& g) : Player(nm, g), state1(true), numShots(0){
            for(int i = 0; i < 100; i++){
                mShots[i].r = 69;
                mShots[i].c = 69;
            }
        };
        ~MediumPlayer() {}; ///< Destructor for medium player
        virtual bool placeShips(Board& b);
        virtual Point recommend();
        virtual void recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID);
        virtual void recordOpponent(Point p);
        /// Method for helping medium bot's operations
        bool mediumHelper(Board& b, int shipID, int r, int c, Direction ld);
        virtual bool getState() const { return state1; };   ///< Getter for the last state
        virtual void changeState(bool state) { state1 = state; };   ///< Method for changing state
        virtual Point getLastP() const { return lastState; };   ///< Getter for last point
        ///Method for changing last point
        virtual void changeLastP(Point p) { lastState.r = p.r; lastState.c = p.c; };
        virtual bool alreadyShot(Point p);  ///< Method for checking if player has already shot
        virtual void addPoint(Point p); ///< Method for adding point into shots

    private:
        bool state1;    ///< Boolean for state1
        Point mShots[100];  ///< Point for shots
        Point lastState;    ///< Point for last state
        int numShots;       ///< Integer containing number of shots
};

#endif // MEDIUMPLAYER_INCLUDED
