/**
 *  @file Main.cpp
 *  @brief contains Main function of the program with assisting functions
 */

#include "Setup.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
/**
 * Adds all the ships into the game
 * @param g reference to game object
 */
bool Setup::addShips(Game& g){
    return g.addShip(5, 'A', "Aircraft Carrier") &&
           g.addShip(4, 'B', "Battleship") &&
           g.addShip(3, 'D', "Destroyer") &&
           g.addShip(3, 'S', "Submarine") &&
           g.addShip(2, 'P', "Patrol boat");
}

/**
 * Method for selecting bot difficulty
 */
int Setup::selectBot(){
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
 * Method for selecting game mode
 */
int Setup::selectMode(){
    cout << "Select choice for game mode: " << endl;
    cout << "1. Human vs Human" << endl;
    cout << "2. Human vs Bot" << endl;
    cout << "3. MediumBot vs HardBot" << endl;
    string line1;
    getline(cin, line1);
    if(line1[0] == '1'){
        return '1';
    } else if(line1[0] == '2'){
        return '2';
    } else if(line1[0] == '3'){
        return '3';
    } else {
        cout << "Invalid choice" << endl;
        return '0';
    }
}
/**
 * Public method for starting the setup
 */
void Setup::start(){
    cout << "BATTLESHIPS" << endl;
    init();
}

/**
 *  Method for setup and starting the game
 */
void Setup::init(){
    int answer1 = selectMode();
    Game g(10, 10); ///< Creates a game object

    ///Checks if player selected Human vs Human
    if(answer1 == '1'){
        ///Creates pointers into player objects
        Player* p1 = create("Human", "Player1", g);
        Player* p2 = create("Human", "Player2", g);
        addShips(g);    ///< Adds ships into the game
        g.play(p1, p2); ///< Starts game

        ///Deletes players
        delete p1;
        delete p2;

    } else if(answer1 == '2'){ ///< Checks if player selected Human vs Bot
        int answer2 = selectBot();   ///< Asks user for bot difficulty
        ///Checks if bot difficulty is easy
        if(answer2 == '1'){
            ///Creates pointers into player objects
            Player* p1 = create("Human", "Player1", g);
            Player* p2 = create("Easy", "EasyBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;

        } else if(answer2 == '2'){   ///< Checks if bot difficulty is medium
            ///Creates pointers into player objects
            Player* p1 = create("Human", "Player1", g);
            Player* p2 = create("Medium", "MediumBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;

        } else if(answer2 == '3'){   ///< Checks if bot difficulty is hard
            ///Creates pointers player objects
            Player* p1 = create("Human", "Player1", g);
            Player* p2 = create("Hard", "HardBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;
        }
    } else if(answer1 == '3'){ ///< Checks if player selected MediumBot vs HardBot
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
