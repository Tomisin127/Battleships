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
 * Constructor for setup
 */
Setup::Setup(){
    init();
}

///Function which prints out the instructions
void instructions(){
    cout << "\nIn battleships your objective is to destroy all of your opponent's ships." << endl;
    cout << "Both players have 5 ships at their disposal: " << endl;
    cout << "* (A)ircraft Carrier with length of 5 cells." << endl;
    cout << "* (B)attleship with length of 4 cells." << endl;
    cout << "* (D)estroyer with length of 3 cells." << endl;
    cout << "* (S)ubmarine with length of 3 cells." << endl;
    cout << "* (P)atrol Boat with length of 2 cells" << endl;
    cout << "Players can place these boats where they like on their own 10x10 game board." << endl;
    cout << "Players take turns shooting their opponents board with coordinates (e.g. 5 2)." << endl;
    cout << "Note that rows and columns start from 0." << endl;
    cout << "\nPress enter to continue." << endl;
    cin.ignore(10000, '\n');
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
           g.addShip(2, 'P', "Patrol Boat");
}

/**
 * Method for selecting bot difficulty
 */
int Setup::selectBot(){
    string input;
    /// Loops while user input is invalid
    while(true){
        cout << "\nSelect bot difficulty:\n " << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        getline(cin, input);
        if(input[0] == '1'){    ///< Checks if choice was 1
            return 1;
        } else if(input[0] == '2'){ ///< Checks if choice was 2
            return 2;
        } else if(input[0] == '3'){ ///< Checks if choice was 3
            return 3;
        } else {    ///< Else choice was invalid
            cout << "\nInvalid choice" << endl;
        }
    }
}

/**
 * Method for selecting game mode
 */
int Setup::selectMode(){
    string input;
    ///Loops while user's input is invalid
    while(true){
        cout << "\nSelect choice for game mode: \n" << endl;
        cout << "0. Instructions" << endl;
        cout << "1. Human vs Human" << endl;
        cout << "2. Human vs Bot" << endl;
        cout << "3. MediumBot vs HardBot" << endl;
        getline(cin, input);
        ///Checks if choice was 1
        if(input[0] == '1'){
            return 1;
        } else if(input[0] == '2'){ ///< Checks if choice was 2
            return 2;
        } else if(input[0] == '3'){ ///< Checks if choice was 3
            return 3;
        } else if(input[0] == '0'){ ///< Checks if choice was 0
            instructions();
        } else{    ///< Else choice was invalid
            cout << "\nInvalid choice" << endl;
        }
    }
}

/**
 *  Method for checking if user wants to play again
 */
bool Setup::rematch(){
    string input;
    cout << "\nDo you want to play again?" << endl;
    cout << "(Y)es/(N)o :" << endl;
    getline(cin, input);
    ///Checks user input
    if(input[0] == 'Y' || input[0] == 'y'){
        return true;
    } else{
        return false;
    }
}

/**
 *  Method for setup and starting the game
 */
void Setup::init(){
    PlayerFactory pf; ///< Creates a player factory object
    ///Loops while player wants a rematch
    while(true){
        cout << " " << endl;
        cout << "  *=========================*" << endl;
        cout << "  || B A T T L E S H I P S ||" << endl;
        cout << "  *=========================*\n" << endl;
        int answer1 = selectMode(); ///< Prompts user to select game mode
        ///Checks if player selected Human vs Human
        if(answer1 == 1){
            Game g(10, 10); ///< Creates a game object
            ///Calls Player Factory for creating players
            Player* p1 = pf.clone(1, "Player1", g);
            Player* p2 = pf.clone(1, "Player2", g);
            addShips(g);    ///< Adds ships into the game
            g.play(p1, p2); ///< Starts game

            ///Deletes players
            delete p1;
            delete p2;
            ///Checks if user wants to play again
            if(!rematch())
                break;
        } else if(answer1 == 2){ ///< Checks if player selected Human vs Bot
            int answer2 = selectBot();   ///< Prompts user to select bot difficulty
            ///Checks if bot difficulty is easy
            if(answer2 == 1){
                Game g(10, 10); ///< Creates a game object
                ///Creates pointers into player objects
                Player* p1 = pf.clone(1, "Player1", g);
                Player* p2 = pf.clone(2, "EasyBot", g);
                addShips(g);    ///< Adds ships into the game
                g.play(p1, p2); ///< Starts game

                ///Deletes players
                delete p1;
                delete p2;

                ///Checks if user wants to play again
                if(!rematch())
                    break;
            } else if(answer2 == 2){   ///< Checks if bot difficulty is medium
                Game g(10, 10); ///< Creates a game object
                ///Creates pointers into player objects
                Player* p1 = pf.clone(1, "Player1", g);
                Player* p2 = pf.clone(3, "MediumBot", g);
                addShips(g);    ///< Adds ships into the game
                g.play(p1, p2); ///< Starts game

                ///Deletes players
                delete p1;
                delete p2;

                ///Checks if user wants to play again
                if(!rematch())
                    break;
            } else if(answer2 == 3){   ///< Checks if bot difficulty is hard
                Game g(10, 10); ///< Creates a game object
                ///Creates pointers player objects
                Player* p1 = pf.clone(1, "Player1", g);
                Player* p2 = pf.clone(4, "HardBot", g);
                addShips(g);    ///< Adds ships into the game
                g.play(p1, p2); ///< Starts game

                ///Deletes players
                delete p1;
                delete p2;

                ///Checks if user wants to play again
                if(!rematch())
                    break;
            }
        } else if(answer1 == 3){ ///< Checks if player selected MediumBot vs HardBot
                int p1wins = 0;     ///< Integer containing number of first player's victories
                int p2wins = 0;     ///< Integer containing number of second player's victories

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
                ///Checks if user wants to play again
                if(!rematch())
                    break;
        } else {    ///< Else something went wrong and choice was invalid
            cout << "Invalid choice" << endl;
        }
    }
    cout << "Thanks for playing!" << endl;
}
