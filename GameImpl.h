/**
 *  @file GameImpl.h
 *  @brief contains header for Game implementation class
 */

#ifndef GAMEIMPL_INCLUDED
#define GAMEIMPL_INCLUDED

#include "Board.h"
#include "Ship.h"
#include <string>
#include <cassert>

class Point;    ///< Declaration for Point class
class Player;   ///< Declaration for Player class

/**
 * GameImpl: class for game implementation
 */
class GameImpl{
    public:
        GameImpl(int nRows, int nCols);
        int rows() const;
        int cols() const;
        int nShips() const;
        int shipLength(int shipID) const;
        char shipSymbol(int shipID) const;
        std::string shipName(int shipID) const;
        bool valid(Point p) const;
        bool addShip(int length, char symbol, std::string name);
        Point rndPoint() const;
        Player* play(Player* p1, Player* p2, Board& b1, Board& b2, bool pause);
    private:
        int gRows;  ///< Game rows
        int gCols;  ///< Game columns
        std::vector<Ship> gShips = {};    ///< Vector for game's ships
};

#endif // GAMEIMPL_INCLUDED
