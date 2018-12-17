/**
 *  @file HardPlayer.h
 *  @brief contains header for hard player class
 */

#ifndef HARDPLAYER_INCLUDED
#define HARDPLAYER_INCLUDED

#include "Player.h"
/**
 *  HardPlayer: declaration for player class that's controlled by hard bot
 */
class HardPlayer : public Player{
    public:
        Player* create(std::string nm, const Game& g){
            return new HardPlayer(nm, g);
        }
        ///Constructor for hard bot
        HardPlayer(std::string nm, const Game& g) : Player(nm, g), state1(true), numShots(0), hitSinceChng(0){
            for(int i = 0; i < (MAXROWS * MAXCOLS); i++){
                mShots[i].r = 69;
                mShots[i].c = 69;
            }
            ///Loops through game's rows
            for(int i = 0; i < game().rows(); i++){
                ///Loops through games columns
                for(int j = 0; j < game().cols(); j++){
                    myShips[i][j] = '.';    ///< Clears screen
                }
            }
        };
        ~HardPlayer() {};   ///< Destructor for hard player
        virtual bool placeShips(Board& b);
        virtual Point recommend();
        virtual void recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID);
        virtual void recordOpponent(Point p);
        virtual bool getState() const { return state1; };
        virtual void changeState(bool state) { state1 = state; };
        virtual Point getLastP() const { return lastState; };
        virtual bool alreadyShot(Point p);
        virtual void addPoint(Point p);
        /// Method for helping hard bot's operations
        bool hardHelper(Board& b, int shipID, int c, int track);
        bool checkShips(Point p, Direction d, int shipID);  ///< Method for checking ships
        void recordShip(Point p, Direction d, int shipID);  ///< Method for recording ships
        bool closeBy(Point p);  ///< Method for checking target's that are close by
    private:
        bool state1;    ///< boolean for first state
        Point mShots[MAXCOLS * MAXROWS];    ///< Point object for possible shots
        Point lastState;    ///< Point object for last state
        int numShots;   ///< Integer containing number of shots
        std::vector<Point> hitShots; ///< Vector containing shots that have hit targets
        int hitSinceChng;   ///< Integer containing hits since last state change
        char myShips[MAXROWS][MAXCOLS]; ///< Char array containing player's ships
};

#endif // HARDPLAYER_INCLUDED
