/**
 *  @file Game.cpp
 *  @brief contains implementation for Game class which delegates into game implementation
 */

#include "Game.h"
#include "Globals.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Delegates to game implementation
 * @param nRows integer containing number of rows
 * @param nCols integer containing number of columns
 */
Game::Game(int nRows, int nCols){
    ///Checks if the number of rows is valid
    if(nRows < 1 || nRows > MAXROWS){
        cout << "Number of rows must be equal or less than " << MAXROWS << " and more than 0" << endl;
        exit(1);
    } else if(nCols < 1 || nCols > MAXCOLS){
        cout << "Number of columns must be equal or less than " << MAXCOLS << " and more than 0" << endl;
        exit(1);
    } else {
        mImpl = new GameImpl(nRows, nCols);
    }
}

/**
 * Deletes to game implementation
 */
Game::~Game(){
    delete mImpl;
}

/**
 *  Delegates to game implementations rows method
 */
int Game::rows() const{
    return mImpl->rows();
}

/**
 *  Delegates to game implementations columns method
 */
int Game::cols() const{
    return mImpl->cols();
}

/**
 *  Delegates to game implementations valid method
 */
bool Game::valid(Point p) const{
    return mImpl->valid(p);
}

/**
 * Delegates to game implementations addShips method
 * Checks if the ship's parameters are valid
 * @param length integer containing ship's length
 * @param symbol character containing ship's symbol
 * @param name string containing ship's name
 */
bool Game::addShip(int length, char symbol, string name){
    ///Checks if ship's length is less than 1
    if(length < 1){
        cout << "Ship length must be equal to or greater than 1" << endl;
        return false;
    }
    ///Checks if ship fits into the board
    if(length >  rows() && length > cols()){
        cout << "Ship can't fit into game board" << endl;
        return false;
    }
    ///Checks if ship's character is valid
    if(!isascii(symbol) || !isprint(symbol)){
        cout << "Character can't be used as a ship symbol" << endl;
        return false;
    }
    ///Checks if ship's symbol is already in use for other reasons
    if(symbol == 'X' || symbol == '.' || symbol == 'o'){
        cout << "Character can't be used as a ship symbol" << endl;
        return false;
    }

    int totalLength = 0;    ///< Total length of the ships
    ///Loops through ships and adds into total length
    for(int s = 0; s < nShips(); s++){
        totalLength += shipLength(s);
        ///Checks if ship symbol is already used by another ship
        if(shipSymbol(s) == symbol){
            cout << "Ship symbol can't be used for more than one ship" << endl;
            return false;
        }
    }
    ///Checks if the game board is too small for all the ships
    if(totalLength + length > rows() * cols()){
        cout << "Board is too small to fit all ships" << endl;
        return false;
    }
    return mImpl->addShip(length, symbol, name);
}

/**
 * Delegates into game implementation's random point method
 */
Point Game::rndPoint() const{
    return mImpl->rndPoint();
}

/**
 *  Delegates into game implementations number of ships method
 */
int Game::nShips() const{
    return mImpl->nShips();
}

/**
 * Delegates to game implementations ship length method
 * Asserts that shipID is more than 0 and less than number of ships
 * @param shipID integer containing ship's id
 */
int Game::shipLength(int shipID) const{
    assert(shipID >= 0 && shipID < nShips());
    return mImpl->shipLength(shipID);
}

/**
 * Delegates to game implementations ship symbol method
 * Asserts that shipID is more than 0 and less than number of ships
 * @param shipID integer containing ship's id
 */
char Game::shipSymbol(int shipID) const{
    assert(shipID >= 0 && shipID < nShips());
    return mImpl->shipSymbol(shipID);
}

/**
 * Delegates to game implementations ship name method
 * Asserts that shipID is more than 0 and less than number of ships
 * @param shipID integer containing ship's id
 */
string Game::shipName(int shipID) const{
    assert(shipID >= 0 && shipID < nShips());
    return mImpl->shipName(shipID);
}

/**
 * Delegates to game implementations play method
 * @param p1 pointer for first player
 * @param p2 pointer for second player
 * @param pause boolean for pausing game
 */
Player* Game::play(Player* p1, Player* p2, bool pause){
    ///Checks if players are null pointers and there are no ships
    if(p1 == nullptr || p2 == nullptr || nShips() == 0){
        return nullptr;
    }
    ///Uses copy of this object to create boards
    Board b1(*this);
    Board b2(*this);
    return mImpl->play(p1, p2, b1, b2, pause);
}
