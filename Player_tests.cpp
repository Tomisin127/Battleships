/**
 *  @file Player_tests.cpp
 *  @brief contains test cases for Player classes
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Globals.h"

using namespace std;

TEST_CASE("Test human player", "[player]"){

    Game tg(10, 10);
    Board tb(tg);

    Player* tp1 = create("Human", "TestHuman", tg);
    Player* tp2 = create("Easy", "TestEasy", tg);
    Player* tp3 = create("Medium", "TestMedium", tg);
    Player* tp4 = create("Hard", "TestHard", tg);

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
