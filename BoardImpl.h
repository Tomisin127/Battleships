/**
 *  @file BoardImpl.h
 *  @brief contains header for game board implementation class
 */
#ifndef BOARDIMPL_INCLUDED
#define BOARDIMPL_INCLUDED

#include "Globals.h"

class Game;
/**
 *  BoardImpl: class for board implementation
 */
class BoardImpl{
    public:
        BoardImpl(const Game& g);
        void clear();
        void block();
        void unblock();
        void display(bool showShots) const;
        bool placeShip(Point tl, int shipID, Direction d);
        bool removeShip(Point tl, int shipID, Direction d);
        bool attack(Point p, bool& hit, bool& destroyed, int& shipID);
        bool allDestroyed() const;
    private:
        char mArr[MAXROWS][MAXCOLS];    ///< Member array for rows and columns
        const Game& mGame;  ///< Member object referencing to game object
};

#endif // BOARDIMPL_INCLUDED
