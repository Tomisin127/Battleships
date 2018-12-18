/**
 *  @file Main.cpp
 *  @brief contains Main function of the program with assisting functions
 */

#include "Setup.h"
#include "PlayerFactory.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

/**
 * Public method for starting the setup
 */
Setup::Setup(){
    init();
}


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

    string input;
    getline(cin, input);
    if(input[0] == '1'){
        return '1';
    } else if(input[0] == '2'){
        return '2';
    } else if(input[0] == '3'){
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
    string input;
    getline(cin, input);
    if(input[0] == '1'){
        return '1';
    } else if(input[0] == '2'){
        return '2';
    } else if(input[0] == '3'){
        return '3';
    } else {
        cout << "Invalid choice" << endl;
        return '0';
    }
}

/**
 *  Method for setup and starting the game
 */
void Setup::init(){
    cout << "BATTLESHIPS" << endl;
    int answer1 = selectMode();
    PlayerFactory pf; ///< Creates a player factory object

    ///Checks if player selected Human vs Human
    if(answer1 == '1'){
        Game g(10, 10); ///< Creates a game object
        ///Calls Player Factory for creating players
        Player* p1 = pf.clone(1, "Player1", g);
        Player* p2 = pf.clone(1, "Player2", g);
        addShips(g);    ///< Adds ships into the game
        g.play(p1, p2); ///< Starts game

        ///Deletes players
        delete p1;
        delete p2;

    } else if(answer1 == '2'){ ///< Checks if player selected Human vs Bot
        int answer2 = selectBot();   ///< Asks user for bot difficulty
        ///Checks if bot difficulty is easy
        if(answer2 == '1'){
            Game g(10, 10); ///< Creates a game object
            ///Creates pointers into player objects
            Player* p1 = pf.clone(1, "Player1", g);
            Player* p2 = pf.clone(2, "EasyBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;

        } else if(answer2 == '2'){   ///< Checks if bot difficulty is medium
            Game g(10, 10); ///< Creates a game object
            ///Creates pointers into player objects
            Player* p1 = pf.clone(1, "Player1", g);
            Player* p2 = pf.clone(3, "MediumBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;

        } else if(answer2 == '3'){   ///< Checks if bot difficulty is hard
            Game g(10, 10); ///< Creates a game object
            ///Creates pointers player objects
            Player* p1 = pf.clone(1, "Player1", g);
            Player* p2 = pf.clone(4, "HardBot", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;
        }
    } else if(answer1 == '3'){ ///< Checks if player selected MediumBot vs HardBot
            string input; ///< String for user input
            ///Loops until input is valid
            while(true){
                cout << "How many trials? : " << endl;
                getline(cin, input);    ///< Gets user input
                stringstream str(input);   ///< Puts user input to string stream
                if(str >> nTrials)  ///< Checks if user input can be moved to number of trials
                    break;
                cout << "Invalid number" << endl;
            }

            for(auto i = 0 ; i < nTrials; i++){
                Game g(10, 10); ///< Creates a game object
                addShips(g);    ///< Adds ships into the game
                ///Creates pointers into player objects
                Player* p1 = pf.clone(3, "MediumBot", g);
                Player* p2 = pf.clone(4, "HardBot", g);
                Player* winner = g.play(p1, p2, false); ///< Starts game and returns winner

                ///Checks if first player won
                if(winner == p1 ){
                    p1wins++;    ///< Increments first player's victory count
                } else {    ///< Else second player won
                    p2wins++;   ///< Increments second player's victory count
                }
                ///Deletes players
                delete p1;
                delete p2;
            }
            if(p1wins > p2wins){
                cout << "MediumBot won with " << p1wins << " wins out of " << nTrials << " games." << endl;
            } else{
                cout << "HardBot won with " << p2wins << " wins out of " << nTrials << " games." << endl;
            }
    } else {    ///< Else choice was invalid
        cout << "Invalid choice" << endl;
    }
}

