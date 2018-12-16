/**
 *  @file Board.cpp
 *  @brief delegates to Board implementation
 */

#include "Board.h"

/**
 * Delegates to board implementation
 * @param g reference to game object
 */
Board::Board(const Game& g){
    mImpl = new BoardImpl(g);
}

/**
 * Deletes board implementation
 */
Board::~Board(){
    delete mImpl;
}

/**
 * Delegates to board implementation's clear method
 */
void Board::clear(){
    mImpl->clear();
}

/**
 * Delegates to board implementation's block method
 */
void Board::block(){
    return mImpl->block();
}

/**
 * Delegates to board implementation's unblock method
 */
void Board::unblock(){
    return mImpl->unblock();
}

/**
 * Delegates to board implementation's display method
 * @param showShots boolean for showing shots
 */
void Board::display(bool showShots) const{
	mImpl->display(showShots);
}

/**
 * Delegates to board implementation's placeShip method
 * @param tl Point containing top left cell
 * @param shipID integer for ship id
 * @param d Direction the ship is facing
 */
bool Board::placeShip(Point tl, int shipID, Direction d){
	return mImpl->placeShip(tl, shipID, d);
}

/**
 * Delegates to board implementation's removeShip method
 * @param tl Point containing top left cell
 * @param shipID integer for ship id
 * @param d Direction the ship is facing
 */
bool Board::removeShip(Point tl, int shipID, Direction d){
	return mImpl->removeShip(tl, shipID, d);
}

/**
 * Delegates to board implementation's attack method
 * @param p Point that has the targeted cell
 * @param hit reference to boolean which indicates if ship was hit
 * @param destroyed reference to boolean which indicates if ship was destroyed
 * @param shipID reference to integer which returns ID of ship that was hit
 */
bool Board::attack(Point p, bool& hit, bool& destroyed, int& shipID){
	return mImpl->attack(p, hit, destroyed, shipID);
}

/**
 * Delegates to board implementation's allDestroyed method
 */
bool Board::allDestroyed() const{
	return mImpl->allDestroyed();
}
