/**
 *  @file Player.cpp
 *  @brief contains implementation for Player classes and assisting functions
 */

#include "Player.h"
#include "HumanPlayer.h"
#include "EasyPlayer.h"
#include "MediumPlayer.h"
#include "HardPlayer.h"
#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
//#include <cmath>

using namespace std;

/**
 * Function for getting two integers from user input
 * @param r reference to row
 * @param c reference to column
 */
bool getTwoIntegers(int& r, int& c){
	bool result(cin >> r >> c);
	if (!result)    ///< Checks if result isn't valid
		cin.clear();  ///< Clear error state so can't do more input operations
	cin.ignore(10000, '\n');
	return result;
}

/**
 * Method for placing ships
 * @param b reference to board
 */
bool HumanPlayer::placeShips(Board& b){
    cout << name() << " must place 5 ships." << endl;
    bool answer = true;
    int r, c;
    Direction d;
    ///Loops through ships
    for(int i = 0; i < 5; i++){
        b.display(false);
        int choice;
        switch(i){
        case 0:
            cout << "Aircraft carrier (length 5)"<< endl;
            cout << "Enter 1 for horizontal and 2 for vertical: ";
            cin >> choice;
            ///Checks if choice is 1, then ship's direction is horizontal
            if(choice == 1){
                d = HORIZONTAL;
            } else if(choice == 2){ ///< Checks if choice is 2, then ship's direction is vertical
                d = VERTICAL;
            } else {    ///< Not a valid choice
                cout << "Enter a valid direction: " << endl;
                i--;
                break;
            }
            cout << "Enter row and column of the leftmost cell (e.g. 4 2): " << endl;
            getTwoIntegers(r, c);   ///< Get row and column from user input
            ///Checks if ship isn't placed into valid cell
            if(!b.placeShip(Point(r, c), i, d)){
                cout << "Enter a valid location" << endl;
                i--;
            }
            break;

        case 1:
            cout << "Battleship (length 4)" << endl;
            cout << "Enter 1 for horizontal and 2 for vertical: " << endl;
            cin >> choice;
            ///Checks if choice is 1, then ship's direction is horizontal
            if(choice == 1){
                d = HORIZONTAL;
            } else if(choice == 2){ ///< Checks if choice is 2, then ship's direction is vertical
                d = VERTICAL;
            } else {    ///< Not a valid direction
                cout << "Enter a valid direction" << endl;
                i--;
                break;
            }
            cout << "Enter row and column of the leftmost cell (e.g. 4 2): " << endl;
            getTwoIntegers(r, c);   ///< Get row and column from user input
            ///Checks if ship is placed into valid location
            if(!b.placeShip(Point(r, c), i, d)){
                cout << "Select a valid location";
                i--;
            }
            break;

        case 2:
            cout << "Destroyer (length 3)" << endl;
            cout << "Enter 1 for horizontal and 2 for vertical: " << endl;
            cin >> choice;
            ///Checks if choice is 1 then ship is horizontal
            if(choice == 1){
                d = HORIZONTAL;
            } else if(choice == 2){ ///< Checks if choice is 2 then ship is vertical
                d = VERTICAL;
            } else {    ///< Direction is not valid
                cout << "Enter a valid direction" << endl;
                i--;
                break;
            }
            cout << "Enter row and column of the leftmost cell (e.g. 4 2): " << endl;
            getTwoIntegers(r, c);   ///< Get row and column from user input
            if(!b.placeShip(Point(r, c), i, d)){ ///< Checks if ship is placed into valid cell
                cout << "Enter a valid location" << endl;
                i--;
            }
            break;

        case 3:
            cout << "Submarine (length 3)" << endl;
            cout << "Enter 1 for horizontal and 2 for vertical: " << endl;
            cin >> choice;
            ///Checks if choice is 1 then ship is horizontal
            if(choice == 1){
                d = HORIZONTAL;
            } else if(choice == 2){ ///< Checks if choice is 2 then ship is vertical
                d = VERTICAL;
            } else {    ///< Direction is not valid
                cout << "Enter a valid direction" << endl;
                i--;
                break;
            }
            cout << "Enter row and column of the leftmost cell (e.g. 4 2): " << endl;
            getTwoIntegers(r, c);   ///< Get rows and columns from user input
            ///Checks if ship is placed into valid cell
            if(!b.placeShip(Point(r, c), i, d)){
                cout << "Enter a valid location" << endl;
                i--;
            }
            break;

        case 4:
            cout << "Patrol boat (length 2)" << endl;
            cout << "Enter 1 for horizontal and 2 for vertical: " << endl;
            cin >> choice;
            ///Checks if choice is 1 then ship is horizontal
            if(choice == 1){
                d = HORIZONTAL;
            } else if(choice == 2){ ///< Checks if choice is 2 then ship is vertical
                d = VERTICAL;
            } else {    ///< Direction is not valid
                cout << "Enter a valid direction" << endl;
                i--;
                break;
            }
            cout << "Enter row and column of the leftmost cell (e.g. 4 2): " << endl;
            getTwoIntegers(r, c);   ///< Get row and column from user input
            ///Checks if ship is placed into valid cell
            if(!b.placeShip(Point(r, c), i, d)){
                cout << "Enter a valid location" << endl;
                i--;
            }
            break;
        }
    }
    return answer;
}
/**
 *  Method for getting user input for target cell
 */
Point HumanPlayer::recommend(){
    int r, c;
    cout << "Enter the row and column to attack (e.g. 4 2): " << endl;
    getTwoIntegers(r, c);
    return Point(r, c);
}
/**
 * Method for recording result
 * @param p Point where player attacked
 * @param validShot boolean that checks if shot is valid
 * @param hit boolean that checks if shot hit
 * @param destroyed boolean that checks if ship was destroyed
 * @param shipID integer containing ship ID
 */
void HumanPlayer::recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID){
    //Null
}

/**
 * Method for recording opponent's result
 * @param p Point containing targetted cell
 */
void HumanPlayer::recordOpponent(Point p){
    //Null
}

/**
 * Method for creating easy player
 * @param nm string containing player name
 * @param g reference to game object
 */
EasyPlayer::EasyPlayer(string nm, const Game& g) : Player(nm, g), mLastCell(0, 0) {}

/**
 * Method for placing easy player's ships
 * @param b Reference to game board object
 */
bool EasyPlayer::placeShips(Board& b){
	///Loops through ships in game
	for (int i = 0; i < game().nShips(); i++){
        ///Checks if ship is placed on the game board
		if (!b.placeShip(Point(i, 0), i, HORIZONTAL)){
			return false;
		}
	}
    return true;
}

/**
 *  Method that recommends attack for easy player
 */
Point EasyPlayer::recommend(){
    ///Checks if last attacked cell's column is larger than 0
    if(mLastCell.c > 0){
        mLastCell.c--;
    } else {
        ///Decreases last attacked cell's column with game's columns - 1
        mLastCell.c = game().cols() - 1;
        ///Checks if last attacked cell's rows is larger than 0
        if(mLastCell.r > 0){
            mLastCell.r--;
        } else {
            ///Decreases last attacked cell's rows with game's rows - 1
            mLastCell.r = game().rows() - 1;
        }
    }
    return mLastCell;
}

/**
 * Method for recording result
 * @param p Point containing attacked cell
 * @param validShot boolean that checks if attack was valid
 * @param hit boolean to check if ship was hit
 * @
 */
void EasyPlayer::recordResult(Point p , bool validShot, bool hit, bool destroyed, int shipID){
	//Null
}
/**
 * Method for recording opponent's result
 * @param p Point containing attacked cell
 */
void EasyPlayer::recordOpponent(Point p){
    //Null
}

/**
 * Method for checking if medium bot has already shot
 * @param p Point containing target cell
 */
bool MediumPlayer::alreadyShot(Point p){
    ///Checks if given point's rows and columns are greater than game's or less than 0
    if(p.r >= game().rows() || p.c >= game().cols() ||p.r < 0 || p.c < 0){
        return true;
    }
    ///Loops through number of shots
    for(int i = 0; i < numShots; i++){
        ///Checks if point's rows and columns correspond to shot's rows and columns
        if(p.r == mShots[i].r && p.c == mShots[i].c){
            return true;
        }
    }
    return false;
}

/**
 * Method for adding point into shots
 * @param p Point for target cell
 */
void MediumPlayer::addPoint(Point p){
    mShots[numShots].r = p.r;
    mShots[numShots].c = p.c;
}

/**
 * Method for medium bot's operations
 * @param b reference to game board object
 * @param shipID integer containing ship's ID
 * @param r integer containing row
 * @param c integer containing column
 * @param ld Direction object containing last direction
 */
bool MediumPlayer::mediumHelper(Board& b, int shipID, int r, int c, Direction ld){
    ///Checks if we are at the last ship
    if(shipID == game().nShips() - 1){
        ///Loops through point's rows
        for(int r = 0; r < game().rows(); r++){
            ///Loops through point's columns
            for(int c = 0; c < game().cols(); c++){
                ///Try to place ship horizontally
                if(b.placeShip(Point(r, c), shipID, HORIZONTAL)){
                    return true;
                }
                ///Try to place ship vertically
                if(b.placeShip(Point(r, c), shipID, VERTICAL)){
                    return true;
                }
            }
        }
    }

    bool success = false;

    ///Checks if ship id is less than game's number of ships - 1
    if(shipID < game().nShips() - 1){
        ///Loops through game's rows
        for(int newR = 0; newR < game().rows(); newR++){
            ///Loops through game's columns
            for(int newC = 0; newC < game().cols(); newC++){
                ///Try to place ship horizontally
                if(b.placeShip(Point(newR,newC), shipID, HORIZONTAL)){
                    ld = HORIZONTAL;
                    success = true;
                    break;
                }
                ///Try to place ship vertically
                if(b.placeShip(Point(newR, newC), shipID, VERTICAL)){
                    ld = VERTICAL;
                    success = true;
                    break;
                }
            }
            ///Checks if method has been success
            if(success){
                break;
            }
        }
    }
    ///Checks if method has been success
    if(success){
        return mediumHelper(b, shipID + 1, 0, 0, ld);
    } else if(!success && shipID > 0){  ///< Checks if method hasn't been success and backtracks the move
        b.removeShip(Point(r, c), shipID - 1, ld);
        return mediumHelper(b, shipID - 1, r, c, ld);
    } else{ ///< Otherwise this is a first ship and we have failed
        return false;
    }
}
/**
 * Method for placing ships
 * @param b reference to game board object
 */
bool MediumPlayer::placeShips(Board& b){
    int c = 0;  ///< Integer for count
    ///Loops while count is less than 50
    while(c < 50){
        b.block();  ///< Blocks the game board
        ///Checks if medium helper is success with 0 values
        if(mediumHelper(b, 0, 0, 0 , VERTICAL)){
            b.unblock();    ///< Unblocks the game board
            return true;
        } else{
            c++;    ///< Increases count
        }
        b.unblock(); ///< Unblocks the game board
    }
    b.unblock();    ///< Unblocks the game board
    return false;
}

/**
 * Method for recommending attack for medium bot
 */
Point MediumPlayer::recommend(){
    int x = randomInt(4) + 1; ///< Random integer with limit 4 + 1
    Point answer(1, 1); ///< Point for answer cell

    int rnd1 = randomInt(2);    ///< Random integer with limit 2
    int rnd2 = randomInt(2);    ///< Random integer with limit 2
    int c = 0;  ///< integer for count

    ///Checks if state isn't 1
    if(!getState()){
        ///Loops from 1 to 5
        for(int i = 1; i < 5; i++){
            ///Checks if cells around the last point haven't been shot
			if (!alreadyShot(Point(getLastP().r + i, getLastP().c))){
				break;
			}
			if (!alreadyShot(Point(getLastP().r - i, getLastP().c))){
				break;
			}
			if (!alreadyShot(Point(getLastP().r, getLastP().c + i))){
				break;
			}
			if (!alreadyShot(Point(getLastP().r, getLastP().c - i))){
				break;
			}
            c++;
        }
        ///Checks if while loop finished
        if(c == 4){
            changeState(true);
        }
    }

    ///Checks if state is 1
    if(getState()){
        ///Get random point
        Point rndP(randomInt(game().rows()), randomInt(game().cols()));
        ///Checks if random point has already been shot
        if(alreadyShot(rndP)){
            return recommend(); ///< Recommends attack
        } else{
            return rndP;    ///< Returns random point
        }
    } else{
        ///Checks if first random integer is 0
        if(rnd1 == 0){
            ///Checks if second random integer is 1
            if(rnd2 == 1){
                answer.r = getLastP().r;
                answer.c = getLastP().c + x;
            } else{ ///< Second random integer is 0
                answer.r = getLastP().r;
                answer.c = getLastP().c - x;
            }
        } else {    ///< First random integer is 1
            /// Checks if second random integer is 0
            if(rnd2 == 0){
                answer.r = getLastP().r + x;
                answer.c = getLastP().c;
            } else{ ///< First random integer is 1
                answer.r = getLastP().r - x;
                answer.c = getLastP().c;
            }
        }

        ///Checks if answer cell has already been shot or target is OoB
        if(alreadyShot(answer)){
            return recommend();
        } else {
            return answer;
        }
    }
}   // Some problems? fix this

/**
 * Method for recording attack result
 * @param p Point object of cell
 * @param validShot boolean for checking if shot was valid
 * @param hit boolean for checking if ship was hit
 * @param destroyed boolean for checking if ship was destroyed
 * @param shipID integer containing ship id
 */
void MediumPlayer::recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID){
    ///Checks if shot wasn't valid
    if(!validShot){
        return;
    }
    ///Checks if target cell hasn't already been shot
    if(!alreadyShot(p)){
        addPoint(p);    ///< Adds point into shots
        numShots++;     ///< Increases number of shots
    }

    ///Checks if ship was hit and state is 1
    if(hit && getState() == true){
        changeLastP(p); ///< Last point updated
        changeState(false); ///< Shot hit so turn to state 2
    }

    ///Checks if ship was destroyed
    if(destroyed){
        changeState(true); ///< Ship was destroyed so turn to state 1
    }

    return;
}

/**
 * Method for recording opponent's attacks
 * @param p Point containing target cell
 */
void MediumPlayer::recordOpponent(Point p){
    // Null
}

/**
 * Method for checking if there are targets close by
 * @param p Point containing targeted cell
 */
bool HardPlayer::closeBy(Point p){
    ///Loops through number of shots
    for(int i = 0; i < numShots; i++){
        if(p.r + 1 == mShots[i].r && p.c == mShots[i].c){
            return true;
        }
        if(p.r - 1 == mShots[i].r && p.c == mShots[i].c){
            return true;
        }
        if(p.r == mShots[i].r && p.c + 1 == mShots[i].c){
            return true;
        }
        if(p.r == mShots[i].r && p.c - 1 == mShots[i].c){
            return true;
        }
    }
    return false;
}

/**
 * Method for placing a ship on a grid to track it
 * @param p Point containing target cell
 * @param d Direction of ship
 * @param shipID Integer containing ship's id
 */
void HardPlayer::recordShip(Point p, Direction d, int shipID){
    ///Checks if direction is horizontal
    if(d == HORIZONTAL){
        ///Loops through ship length by ID
        for(int i = 0; i < game().shipLength(shipID); i++){
            myShips[p.r][p.c + i] = 'S';
        }
    } else {    ///< Direction is vertical
        ///Loops through ship length by ID
        for(int i = 0; i < game().shipLength(shipID); i++){
            myShips[p.r + i][p.c] = 'S';
        }
    }
    return;
}

/**
 * Method for checking ship's location
 * @param p Point containing target cell
 * @param d Direction of the ship
 * @param shipID Integer containing ship's id
 */
bool HardPlayer::checkShips(Point p, Direction d, int shipID){
    ///Checks if ship's direction is horizontal
    if(d == HORIZONTAL){
        ///Loops through ship length by ship's ID
        for(int i = 0; i < game().shipLength(shipID); i++){
            ///Checks if target cell is valid and contains space next to it
            if(game().valid(Point(p.r + 2, p.c + i))){
                ///Checks if ship has been tracked on location
                if(myShips[p.r + 2][p.c + i] == 'S' || myShips[p.r + 1][p.c + i] == 'S'){
                    return true;
                }
            }
            ///Checks if target cell is valid and contains space next to it
            if(game().valid(Point(p.r - 2, p.c + i))){
                ///Checks if myShips contains a ship mark next to it
                if(myShips[p.r - 2][p.c + i] == 'S' || myShips[p.r - 1][p.c + i] == 'S'){
                    return true;
                }
            }
        }

        ///Checks if target cell is valid for the ship
        if(game().valid(Point(p.r, p.c + game().shipLength(shipID)))){
            ///Checks if ship has been tracked on location
            if(myShips[p.r][p.c + game().shipLength(shipID)] == 'S'){
                return true;
            }
        }
        ///Checks if target cell is valid and has a column next to it
        if(game().valid(Point(p.r, p.c - 2))){
            ///Checks if myShips contains a ship symbol next to it
            if(myShips[p.r][p.c - 2] == 'S' || myShips[p.r][p.c - 1] == 'S'){
                return true;
            }
        }
        ///Checks if target is valid and has a column next to it
        if(game().valid(Point(p.r, p.c - 1))){
            ///Checks if myShips contains a ship symbol next to it
            if(myShips[p.r][p.c - 1] == 'S'){
                return true;
            }
        }
        ///Checks if target cell is valid for the ship
        if(game().valid(Point(p.r, p.c + game().shipLength(shipID) + 1))){
            ///Checks if ship has been tracked on location
            if(myShips[p.r][p.c + game().shipLength(shipID) + 1] == 'S'){
                return true;
            }
        }
    } else {    ///< Ship is vertical
        ///Loops through ship length by ship's ID
        for(int i = 0; i < game().shipLength(shipID); i++){
            ///Checks if target cell is valid and has a row it
            if(game().valid(Point(p.r + i, p.c + 2))){
                ///Checks if there is a ship under it
                if(myShips[p.r + i][p.c + 2] == 'S' || myShips[p.r + i][p.c + 1] == 'S'){
                    return true;
                }
            }
            ///Checks if target cell is valid and has a row under it
            if(game().valid(Point(p.r + i, p.c - 2))){
                ///Checks if there is a ship under it
                if(myShips[p.r + i][p.c - 2] == 'S'){
                    return true;
                }
            }
        }

        ///Checks if target cell is valid
        if(game().valid(Point(p.r + game().shipLength(shipID), p.c))){
            ///Checks if ship has been tracked on location
            if(myShips[p.r + game().shipLength(shipID)][p.c] == 'S'){
                return true;
            }
        }
        ///Checks if target cell is valid and has a row on top of it
        if(game().valid(Point(p.r - 2, p.c))){
            ///Checks if rows above it contain a ship
            if(myShips[p.r - 2][p.c] == 'S' || myShips[p.r - 1][p.c] == 'S'){
                return true;
            }
        }
        ///Checks if target cell is valid
        if(game().valid(Point(p.r - 1, p.c))){
            ///Checks if ship has been tracked on location
            if(myShips[p.r - 1][p.c] == 'S'){
                return true;
            }
        }
        ///Checks if target cell is valid for the ship
        if(game().valid(Point(p.r + game().shipLength(shipID), p.c))){
            ///Checks if ship has been tracked on location
            if(myShips[p.r + game().shipLength(shipID) + 1][p.c] == 'S'){
                return true;
            }
        }
    }
    return false;
}

/**
 * Method for checking if player has already shot targeted location
 * @param p Point containing target cell
 */
bool HardPlayer::alreadyShot(Point p){
    ///Checks if target is OoB
    if(p.r >= game().rows() || p.c >= game().cols() || p.r < 0 || p.c < 0){
        return true;
    }

    ///Loops through number of shots
    for(int i = 0; i < numShots; i++){
        ///Checks if shots contain targeted cell
        if(p.r == mShots[i].r && p.c == mShots[i].c){
            return true;
        }
    }
    return false;
}

/**
 * Method for adding target location to shots
 * @param p Point containing targeted cell
 */
void HardPlayer::addPoint(Point p){
    mShots[numShots].r = p.r;
    mShots[numShots].c = p.c;
}

/**
 * Method for helping hard bot's operations
 * @param b reference to game board
 * @param shipID integer containing ship's id
 * @param c integer containing count
 * @param track integer containing track of ships
 */
bool HardPlayer::hardHelper(Board& b, int shipID, int c, int track){
    ///Checks if all the ship's have been placed
    if(shipID == game().nShips()){
        return true;
    }

    Point p(5,5);
    Direction d;

    ///Checks if we just need to place some ships
    if(track > 50){
        b.clear();
        b.placeShip(Point(2,3), 0, HORIZONTAL);
        b.placeShip(Point(5, 6), 1, VERTICAL);
		b.placeShip(Point(4, 7), 2, VERTICAL);
		b.placeShip(Point(9, 6), 3, HORIZONTAL);
		b.placeShip(Point(0, 9), 4, VERTICAL);
        return true;
    }

    ///Top left
    if(c % 5 == 0){
        p.r = randomInt(game().rows() / 2);
        p.c = randomInt(game().cols() / 2);
    } else if(c % 5 == 1){ ///< Top right
        p.r = randomInt(game().rows() / 2);
        p.c = randomInt(game().cols() / 2) + (game().cols() / 2);
    } else if(c % 5 == 2){ ///< Bottom left
        p.r = randomInt(game().rows() / 2) + (game().rows() / 2);
        p.c = randomInt(game().cols() / 2);
    } else if(c % 5 == 3){ ///< Bottom right
        p.r = randomInt(game().rows() / 2) + (game().rows() / 2);
        p.c = randomInt(game().rows() / 2) + (game().cols() / 2);
    } else { ///< Anywhere
        p.r = randomInt(game().rows());
        p.c = randomInt(game().cols());
    }

    ///Switch case for random direction
    switch(randomInt(2)){
        case 0: ///< Place vertical ship
            ///Checks if ship can't be placed
            if(!b.placeShip(p, shipID, VERTICAL)){
                track++; ///< increase track
                return hardHelper(b, shipID, c, track);
            }
            ///Checks tracked ships
            if(checkShips(p, VERTICAL, shipID)){
                b.removeShip(p, shipID, VERTICAL); ///< Removes ship
                track++;    ///< Increase track
                return hardHelper(b, shipID, c, track);
            }
            d = VERTICAL;   ///< Change direction to vertical
            break;

        case 1: ///< Place horizontal ship
            ///Checks if ship can't be placed
            if(!b.placeShip(p, shipID, HORIZONTAL)){
                track++;    ///< Increase track
                return hardHelper(b, shipID, c, track);
            }
            ///checks tracked ship
            if(checkShips(p, HORIZONTAL, shipID)){
                b.removeShip(p, shipID, HORIZONTAL);   ///< Removes ship
                track++;    ///< Increase track
                return hardHelper(b, shipID, c, track);
            }
            d = HORIZONTAL; ///< Change direction to horizontal
            break;
    }

    recordShip(p, d, shipID);   ///< Place ship into grid to track it
    return hardHelper(b, shipID + 1, c + 1, track);
}

/**
 * Method for placing ships
 * @param b reference to game board
 */
bool HardPlayer::placeShips(Board& b){
    return hardHelper(b, 0, randomInt(5), 0);
}

/**
 * Method for recommending attack
 */
Point HardPlayer::recommend(){
    nextShot nxt; ///< Ford figuring out next shot
    Point answer(1,1);

    ///Checks if state is 1
    if(getState()){
        Point rnd = game().rndPoint();  ///< Get random point
        ///Checks random point has already been shot
        if(alreadyShot(rnd)){
            return recommend();
        }
        ///Checks if number of shots is under 30 and there is a ship close to target cell
        if(numShots < 30 && closeBy(rnd)){
            return recommend();
        } else{ ///< Return random cell
            return rnd;
        }
    } else {    ///< State is 2
        /// Checks if hits since state change is ore than 1
        if(hitSinceChng > 1){
            ///Checks if ship is horizontal
            if(hitShots[hitShots.size() - 1].r == hitShots[hitShots.size() - 2].r){
                ///Checks if ship is heading to right
                if(hitShots[hitShots.size() - 1].c == hitShots[hitShots.size() - 2].c + 1){
                    nxt = RIGHT;    ///< Shoot to the right side next
                    answer.r = hitShots[hitShots.size() - 1].r;
                    answer.c = hitShots[hitShots.size() - 1].c + 1;
                } else {    ///< Ships is probably heading left
                    nxt = LEFT; ///< Shoot to the left side next
                    answer.r = hitShots[hitShots.size() - 1].r;
                    answer.c = hitShots[hitShots.size() - 1].c -1;
                }

                ///Checks if we have reached the end of grid
                if(nxt == RIGHT && alreadyShot(answer)){
                    ///Loop while we are still targeting the end
                    while(alreadyShot(answer)){
                        answer.c--; ///< Go back left
                        ///Checks if target column is less than 0
                        if(answer.c < 0){
                            break;
                        }
                    }
                } else if(nxt == LEFT && alreadyShot(answer)){ ///< Checks if we have reached the end of grid
                    ///Loop while we are still targeting the end
                    while(alreadyShot(answer)){
                        answer.c++; ///< Go back right
                        ///Checks if target column is more than game's columns
                        if(answer.c > game().cols()){
                            break;
                        }
                    }
                }
            } else if(hitShots[hitShots.size() - 1].c == hitShots[hitShots.size() - 2].c){ ///< Checks if ship is vertical
                ///Checks if ship is heading up
                if(hitShots[hitShots.size() - 1].r == hitShots[hitShots.size() - 2].r - 1){
                    nxt = UP;   ///< Shoot up next
                    answer.r = hitShots[hitShots.size() - 1].r - 1;
                    answer.c = hitShots[hitShots.size() - 1].c;
                } else {    ///< Ship is heading down
                    nxt = DOWN; ///< Shoot down next
                    answer.r = hitShots[hitShots.size() - 1].r + 1;
                    answer.c = hitShots[hitShots.size() - 1].c;
                }
                /// Check if we have reached the end of grid
                if(nxt == DOWN && alreadyShot(answer)){
                    ///Loop while we are still targeting the end
                    while(alreadyShot(answer)){
                        answer.r--; ///< Go back up
                        ///Check if rows are less than 0
                        if(answer.r < 0){
                            break;
                        }
                    }
                } else if(nxt == UP && alreadyShot(answer)){    ///< Check if we have reached the end of grid
                    ///Loop while we are still targeting the end
                    while(alreadyShot(answer)){
                        answer.r++; ///< Go back down
                        ///If rows is less than game's rows
                        if(answer.r > game().rows()){
                            break;
                        }
                    }
                }
            }
        } else {    ///< Target has been hit, circle around
            answer.r = hitShots[hitShots.size() - 1].r + 1; ///< Look down
            answer.c = hitShots[hitShots.size() - 1].c;
            ///Check if target hasn't been already shot
            if(!alreadyShot(answer)){
                return answer;
            }

            answer.r = hitShots[hitShots.size() - 1].r;
            answer.c = hitShots[hitShots.size() - 1].c -1;  ///< Look left
            ///Check if target hasn't been already shot
            if(!alreadyShot(answer)){
                return answer;
            }

            answer.r = hitShots[hitShots.size() - 1].r - 1; ///< Look up
            answer.c = hitShots[hitShots.size() - 1].c;
            ///Check if target hasn't been already shot
            if(!alreadyShot(answer)){
                return answer;
            }

            answer.r = hitShots[hitShots.size() - 1].r;
            answer.c = hitShots[hitShots.size() - 1].c + 1; ///< Look right
            ///If target hasn't already been shot
            if(!alreadyShot(answer)){
                return answer;
            } else {    ///< Just shoot somewhere
                answer.r = randomInt(game().rows());
                answer.c = randomInt(game().cols());
                ///Checks if target has already been shot
                if(alreadyShot(answer)){
                    return recommend();
                } else {
                    return answer;
                }
            }
        }
        ///Check if target has already been shot
        if(alreadyShot(answer)){
            changeState(true);
            return recommend();
        }
        return answer;
    }
}

/**
 * Method for recording attack result
 * @param p Point containing target cell
 * @param validShot boolean for checking if shot is valid
 * @param hit boolean for checking if shot was hit
 * @param destroyed boolean for checking if ship was destroyed
 * @param shipID Integer that contains ship's ID
 */
void HardPlayer::recordResult(Point p, bool validShot, bool hit, bool destroyed, int shipID){
    ///Checks if shot wasn't valid
    if(!validShot){
        return;
    }

    ///Checks if target hasn't been already shot
    if(!alreadyShot(p)){
        addPoint(p);    ///< Add the point to the array
        numShots++;
    }
    ///Checks if target was hit
    if(hit){
        hitShots.push_back(p);  ///< Adds target point to the vector
        hitSinceChng++; ///< Increase hits since last state change
        changeState(false); ///< Changes state to 2
    }

    ///Checks if ship was destroyed
    if(destroyed){
        hitSinceChng = 0;   ///< Reset hits since last state change
        changeState(true);  ///< Return back to state 1
    }
    return;
}

/**
 * Method for recording opponent's attacks
 * @param p Point containing targeted cell
 */
void HardPlayer::recordOpponent(Point p){
    //Null
}
