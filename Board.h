/**
 *  @file Board.h
 *  @brief contains header for game board class
 */

#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

#include "Globals.h"

class Game;
class BoardImpl;

class Board{
    public:
        Board(const Game& g);   ///< Constructor for game board
        ~Board();   ///< Destructor for board object
        void clear();   ///< Clears screen
        void block();   ///< Blocks cells
        void unblock(); ///< Unblocks cells
        void display(bool showShots) const; ///< Displays the board
        bool placeShip(Point tl, int shipID, Direction d);  ///< Places ships on game board
        bool removeShip(Point tl, int shipID, Direction d);    ///< Removes ships from board
        bool attack(Point p, bool& hit, bool& destroyed, int& shipID);  ///< Attacks target cell
        bool allDestroyed() const;  ///< Checks if all ships are destroyed
        /// Prevents board object from being copied/assigned
        Board(const Board&) = delete;
        Board& operator=(const Board&) = delete;
    private:
        BoardImpl * mImpl;  ///Board implementation
};

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

#endif // BOARD_INCLUDED
