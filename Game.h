/**
 *  @file Game.h
 *  @brief contains header for Game class
 */

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include "Board.h"
#include "Ship.h"
#include <string>
#include <cassert>

class Point;    ///< Declaration for Point class
class Player;   ///< Declaration for Player class
class GameImpl; ///< Declaration for game implementation class

class Game{
    public:
        Game(int nRows, int nCols); ///< Constructor for game object
        ~Game();    ///< Destructor for game object
        int rows() const;   ///< Getter for game's rows
        int cols() const;   ///< Getter for game's columns
        int nShips() const; ///< Getter for number of ships
        int shipLength(int shipID) const;   ///< Getter for ship's length
        char shipSymbol(int shipID) const;  ///< Getter for ship's symbol
        std::string shipName(int shipID) const; ///< Getter for ship's name
        bool valid(Point p) const;  ///< Checks if shot is valid
        bool addShip(int length, char symbol, std::string name);    ///< Adds ship into game
        Point rndPoint() const; ///< Getter for random point
        Player* play(Player* p1, Player* p2, bool pause = true);    ///< Method for playing game
        ///Prevents game object from being copied/assigned
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
    private:
        GameImpl* mImpl;    ///< Game implementation
};

#endif // GAME_INCLUDED
