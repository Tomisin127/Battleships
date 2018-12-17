/**
 *  @file Player_tests.cpp
 *  @brief contains test cases for Player classes
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "PlayerFactory.h"
#include "Globals.h"

using namespace std;

TEST_CASE("Test human player", "[player]"){

    Game tg(10, 10);
    Board tb(tg);

    PlayerFactory tf;

    Player* tp1 = tf.createPlayer(1, "TestHuman", tg);
    Player* tp2 = tf.createPlayer(2, "TestEasy", tg);
    Player* tp3 = tf.createPlayer(3, "TestMedium", tg);
    Player* tp4 = tf.createPlayer(4, "TestHard", tg);

    SECTION("Test human flag"){
        REQUIRE(tp1->human() == true);
        REQUIRE(tp2->human() == false);
        REQUIRE(tp3->human() == false);
        REQUIRE(tp4->human() == false);
    }

    tg.addShip(3, 'S', "Ship1");
    tg.addShip(3, 'A', "Ship2");
    tg.addShip(4, 'D', "Ship3");

    SECTION("Test placing ships"){
        CHECK(tp2->placeShips(tb) == true);
        CHECK(tp3->placeShips(tb) == true);
        CHECK(tp4->placeShips(tb) == true);
    }

}
