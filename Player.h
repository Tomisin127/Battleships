/**
 *  @file Player.h
 *  @brief contains header for player class
 */

#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <string>

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

///Method for creating player
Player* create(std::string type, std::string nm, const Game& g);

#endif // PLAYER_INCLUDED
