/**
 *  @file Player.h
 *  @brief contains header for player classes
 */

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "Board.h"
#include "Game.h"

class Point;    ///< Declaration for Point class
class Board;    ///< Declaration for Board class
class Game;     ///< Declaration for Game class

class Player{
    public:
        Player(std::string nm, const Game& g) : mName(nm), mGame(g) {}  ///< Constructor for player
        virtual ~Player() {}    ///< Destructor for player
        std::string name() const { return mName; }  ///< Getter for name
        const Game& game() const  { return mGame; } ///< Getter for reference of game
        virtual bool human() const { return false; }    ///< Checks if player is human
        virtual bool placeShips(Board& b) = 0;  ///< Places ships on game board
        virtual Point recommend() = 0;  ///< Recommends attack
        ///Records attack result
        virtual void recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID) = 0;
        virtual void recordOpponent(Point p) = 0;   ///< Records opponent's attack
        ///Prevents player object from being copied/assigned
        Player (const Player&) = delete;
        Player& operator=(const Player&) = delete;
    private:
        std::string mName;  ///< String containing player's name
        const Game& mGame;  ///< Reference to game object
};

/**
 * HumanPlayer: implementation for player class that's controlled by human
 */
class HumanPlayer : public Player{
    public:
        HumanPlayer(std::string nm, const Game& g) : Player(nm, g){};
        ~HumanPlayer() {};  ///< Destructor for human player
        virtual bool human() const { return true; };
        virtual bool placeShips(Board& b);
        virtual Point recommend();
        virtual void recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID);
        virtual void recordOpponent(Point p);
};

/**
 * EasyPlayer: class containing implementation of easy bot
 */
class EasyPlayer : public Player{
    public:
        EasyPlayer(std::string nm, const Game& g);   ///< Constructor for easy player
        virtual bool placeShips(Board& b);  ///< Method for placing ships
        virtual Point recommend();    ///< Recommends attack for easy player
        virtual void recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID); ///< Record attack result
        virtual void recordOpponent(Point p);   ///< Records opponent's result
    private:
        Point mLastCell;    ///Last cell attacked
};


/**
 * MediumPlayer: class implementation for player class that's controlled by medium bot
 */
class MediumPlayer : public Player{
    public:
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


/**
 *  HardPlayer: implementation for player class that's controlled by hard bot
 */
class HardPlayer : public Player{
    public:
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

///Enumeration containing directions for next shot
enum nextShot { LEFT, RIGHT, UP, DOWN };



///Method for creating player
Player* create(std::string type, std::string nm, const Game& g);

#endif // PLAYER_INCLUDED
