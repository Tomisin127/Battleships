#include "PlayerFactory.h"


using namespace std;

/**
 * Method for getting prototype
 * @param choice Integer containing chosen player type
 * @param nm string containing player name
 * @param g reference to game
 */
Player* PlayerFactory::getPrototypes(int choice, string nm, const Game& g){
    static Player* sPrototypes[] = {
        0, new HumanPlayer(nm, g), new EasyPlayer(nm, g), new MediumPlayer(nm, g), new HardPlayer(nm ,g)
    };
    return sPrototypes[choice];
}

/**
 * Method for creating a clone of Player
 * @param choice Integer containing chosen player type
 * @param nm string containing player's name
 * @param g reference to game object
 */
Player* PlayerFactory::createPlayer(int choice, string nm, const Game& g){
    return getPrototypes(choice, nm, g)->create(nm, g);
}


