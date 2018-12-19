/**
 *  @file GameImpl.cpp
 *  @brief contains implementation for Game classes and assisting functions
 */

#include "GameImpl.h"
#include "Player.h"
#include "Globals.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * Ship constructor
 * @param length integer containing ship's length
 * @param symbol character containing ship's symbol
 * @param name string containing ship's name
 * @param id integer containing ship's ID
 */
Ship::Ship(int length, char symbol, string name, int id){
    sLength = length;
    sSymbol = symbol;
    sName = name;
    sShipID = id;
}

/**
 *  Function for pausing the game
 */
void wait(){
    cout << "Press enter to continue ";
    cin.ignore(10000, '\n');
}

/**
 * GameImpl constructor
 * @param nRwos integer containing number of rows
 * @param nCols integer containing number of columns
 */
GameImpl::GameImpl(int nRows, int nCols){
    gRows = nRows;
    gCols = nCols;
}

/**
 * Method for getting rows
 */
int GameImpl::rows() const{
    return gRows;
}

/**
 * Method for getting columns
 */
int GameImpl::cols() const{
    return gCols;
}

/**
 * Method for checking if target is valid
 * @param p Point containing the cell
 */
bool GameImpl::valid(Point p) const{
    return p.r >= 0 && p.r < rows() && p.c >= 0 && p.c < cols();
}

/**
 * Method for getting random point from the game grid
 */
Point GameImpl::rndPoint() const{
    return Point(randomInt(rows()), randomInt(cols()));
}

/**
 * Method for checking if it's possible to add ship
 * @param length integer containing length of the ship
 * @param symbol character that contains symbol of the ship
 * @param name string containing ship's name
 */
bool GameImpl::addShip(int length, char symbol, string name){
	bool answer = true;

    ///If ship is too big or value is negative
	if (length < 0 || (length > gRows && length > gCols)){
		answer = false;
	}

	///If any of the symbols are reserved
	if (symbol == 'X' || symbol == 'o' || symbol == '.'){
		answer = false;
	}

    ///Loops through ships
	for (int i = 0; (gShips.begin() + i) != gShips.end(); i++){
        ///Check to see if symbol exists
		if (symbol == gShips[i].getSymbol()){
			answer = false;
			break;
		}
	}

    ///Checks if wee can create a ship
	if (answer){
        ///Add the ship into the vector
		gShips.push_back(Ship(length, symbol, name, gShips.size()));
    }
    return answer;
}

/**
 * Method for getting size of ships vector
 */
int GameImpl::nShips() const{
    return gShips.size();
}

/**
 * Method for getting ship's length
 * @param shipID integer containing ship's id
 */
int GameImpl::shipLength(int shipID) const{
    int answer = 0;
    ///Loops through ships
    for(int i = 0; (gShips.begin() + i) != gShips.end(); i++){
        ///Checks if the ship is right
        if(shipID == gShips[i].getShipID()){
            answer = gShips[i].getLength();
            break;
        }
    }
    return answer;
}

/**
 * Method for getting ship's symbol
 * @param shipID integer containing ship's id
 */
char GameImpl::shipSymbol(int shipID) const{
    char answer = '~';  ///< For the chance that there is no ship with that ID
    ///Loops through ships
    for(int i = 0; (gShips.begin() + i) != gShips.end(); i++){
        ///Checks if the ID is right
        if(shipID == gShips[i].getShipID()){
            answer = gShips[i].getSymbol();
            break;
        }
    }
    return answer;
}

/**
 * Method for getting ship's name
 * @param shipID integer containing ship's ID
 */
string GameImpl::shipName(int shipID) const{
    string answer;
    ///Loops through ships
    for(int i = 0; (gShips.begin() + i) != gShips.end(); i++){
        ///Checks if the ID is right
        if(shipID == gShips[i].getShipID()){
            answer = gShips[i].getName();
            break;
        }
    }
    return answer;
}

/**
 * Method for game play
 * @param p1 Pointer to first player
 * @param p2 Pointer to second player
 * @param b1 Reference to first player's board
 * @param b2 Reference to second player's board
 * @param pause Boolean for pausing game
 */
Player* GameImpl::play(Player* p1, Player* p2, Board& b1, Board& b2, bool pause){
    ///Clear the game boards
    b1.clear();
    b2.clear();

    ///Return null pointer if first player didn't place ships
    if(!p1->placeShips(b1)){
        return nullptr;
    }
    ///Return null pointer if second player didn't place ships
    if(!p2->placeShips(b2)){
        return nullptr;
    }

    ///Run while there are still ships left
    while(!b1.allDestroyed() && !b2.allDestroyed()){
        ///Checks if pause method returns true
        if(pause){
            wait(); ///< Wait for input
        }
        ///Checks if first player is human
        if(p1->human()){
            b2.display(true);   ///< Displays the second game board with shots only
        } else {
            b2.display(false);  ///< Displays the whole second game board
        }

        Point p = p1->recommend();  ///< Recommends attack for bots and asks human user for input
        bool hit1 = false;
        bool destroyed1 = false;
        int shipID1 = 10;
        bool result1 = b2.attack(p, hit1, destroyed1, shipID1); ///< Shoots cell and returns result
        p1->recordResult(p, result1, hit1, destroyed1, shipID1);    ///< Records attack result
        p2->recordOpponent(p);  ///< Records attack result for opponent

        ///Checks if the target is valid
        if(result1){
            ///Checks result of the hit
            if(hit1){
                ///Checks if ship isn't destroyed
                if(!destroyed1){
                    cout << p1->name() << " attacked (" << p.r << ","
                    << p.c << ") and hit something, resulting in: " << endl;
                } else {    ///< Ship is destroyed
                    cout << p1->name() << " attacked (" << p.r << ","
                    << p.c << ") and destroyed the " << shipName(shipID1) << ", resulting in: " << endl;
                }
            } else {    ///< Player missed a shot
                cout << p1->name() << " attacked (" << p.r << ","
                << p.c << ") and missed, resulting in: " << endl;
            }

            ///Checks if first player is human
            if(p1->human()){
                b2.display(true);   ///< Displays second game board with shots only
            } else{
                b2.display(false);  ///< Displays the whole second game board
            }
        } else {    ///< Player not valid
            cout << p1->name() << " missed a shot at (" << p.r << ","
            << p.c << ")" << endl;
        }

        ///Checks if game is paused
        if(pause){
            wait(); ///< Wait for user input
        }

        ///Checks if second player's all boats have been destroyed
        if(b2.allDestroyed()){
            break;
        }

        ///Checks if the second player is human
        if(p2->human()){
            b1.display(true);   ///< Shows the first game board with shots only
        } else{
            b1.display(false);  ///< Shows the whole first game board
        }

        Point f = p2->recommend();  ///< Recommends attacks for bots and asks for user input
        bool hit2 = false;
        bool destroyed2 = false;
        int shipID2 = 10;

        bool result2 = b1.attack(f,hit2, destroyed2, shipID2);  ///< Shoots cell and returns result
        p2->recordResult(f, result2, hit2, destroyed2, shipID2);    ///< Records attack result
        p1->recordOpponent(f);  ///< Records attack result for opponent

        ///Checks if the target is valid
        if(result2){
            ///Checks result of the hit
            if(hit2){
                ///Checks if ship isn't destroyed
                if(!destroyed2){
                    cout << p2->name() << " attacked (" << f.r << ","
                    << f.c << ") and hit something, resulting in: " << endl;
                } else {    ///< Ship was destroyed
                    cout << p1->name() << " attacked (" << p.r << ","
                    << p.c << ") and destroyed the " << shipName(shipID2) << ", resulting in: " << endl;
                }
            } else {    ///< Shot missed
                cout << p2->name() << " attacked (" << f.r << ","
                << f.c << ") and missed, resulting in: " << endl;
            }

            ///Checks if second player is human
            if(p2->human()){
                b1.display(true);   ///< Displays the first board with shots only
            } else{
                b1.display(false);  ///< Displays the first second board
            }
        } else{ ///< Shot was not valid
            cout << p2->name() << " missed a shot at (" << f.r << ","
            << f.c << ")" << endl;
        }
    }

    ///Checks if all first player's ships have been destroyed
    if(b1.allDestroyed()){
        cout << "All first player's boats have been destroyed" << endl;
        ///Checks if second player is human
        if(p2->human()){
            b2.display(false);
        }
        return p2;
    } else{ ///< All second player's ships have been destroyed
        cout << "All second player's boats are destroyed" << endl;
        ///< Checks if first player is human
        if(p1->human()){
            b1.display(false);
        }
        return p1;
    }
}
