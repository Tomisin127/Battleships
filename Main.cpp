/**
 *  @file Main.cpp
 *  @brief contains Main function of the program with assisting functions
 */

#include "Game.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/**
 * Adds all the ships into the game
 * @param g reference to game object
 */
bool addShips(Game& g){
    return g.addShip(5, 'A', "Aircraft Carrier") &&
           g.addShip(4, 'B', "Battleship") &&
           g.addShip(3, 'D', "Destroyer") &&
           g.addShip(3, 'S', "Submarine") &&
           g.addShip(2, 'P', "Patrol boat");
}

/**
 * Function for selecting bot difficulty
 */
int selectBot(){
    cout << "Select bot difficulty: " << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;

    string line2;
    getline(cin, line2);
    if(line2[0] == '1'){
        return '1';
    } else if(line2[0] == '2'){
        return '2';
    } else if(line2[0] == '3'){
        return '3';
    } else {
        cout << "Invalid choice" << endl;
        return '0';
    }
}

/**
 * Main function of the program
 */
int main(){
    Game g(10, 10); ///< Creates a game object

    ///Prints game modes for player
    cout << "BATTLESHIPS" << endl;
    cout << "Select choice for game mode: " << endl;
    cout << "1. Human vs Human" << endl;
    cout << "2. Human vs Bot" << endl;
    cout << "3. MediumBot vs HardBot" << endl;
    string line1;
    getline(cin, line1);

    ///Checks if player selected Human vs Human
    if(line1[0] == '1'){
        ///Creates pointers into player objects
        Player* p1 = create("Human", "Player1", g);
        Player* p2 = create("Human", "Player2", g);
        addShips(g);    ///< Adds ships into the game
        g.play(p1, p2); ///< Starts game

        ///Deletes players
        delete p1;
        delete p2;

    } else if(line1[0] == '2'){ ///< Checks if player selected Human vs Bot
        int answer = selectBot();   ///< Asks user for bot difficulty
        ///Checks if bot difficulty is easy
        if(answer == '1'){
            ///Creates pointers into player objects
            Player* p1 = create("Human", "Player1", g);
            Player* p2 = create("Easy", "EasyBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;
        } else if(answer == '2'){   ///< Checks if bot difficulty is medium
            ///Creates pointers into player objects
            Player* p1 = create("Human", "Player1", g);
            Player* p2 = create("Medium", "MediumBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;
        } else if(answer == '3'){   ///< Checks if bot difficulty is hard
            ///Creates pointers player objects
            Player* p1 = create("Human", "Player1", g);
            Player* p2 = create("Hard", "HardBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;
        }
    } else if(line1[0] == '3'){ ///< Checks if player selected MediumBot vs HardBot
            ///Creates pointers into player objects
            Player* p1 = create("Medium", "MediumBot", g);
            Player* p2 = create("Hard", "HardBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;
    } else {    ///< Else choice was invalid
        cout << "Invalid choice" << endl;
    }
}
