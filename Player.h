/**
 *  @file Player.h
 *  @brief contains header for player class
 */

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include "Board.h"
#include "Game.h"
#include "Globals.h"

/**
 *  Declaration for Player class
 */
class Player{
    public:
        /**
        * Pure virtual method for creating a player
        * @param nm string containing player's name
        * @param g reference to game object
        */
        virtual Player* create(std::string nm, const Game& g) = 0;
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


///Enumeration containing directions for next shot
enum nextShot { LEFT, RIGHT, UP, DOWN };

#endif // PLAYER_INCLUDED
