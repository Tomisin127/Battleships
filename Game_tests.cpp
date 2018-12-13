/**
 *  @file Game_tests.cpp
 *  @brief contains test cases for game class
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Globals.h"

TEST_CASE("Game tests", "[game]"){
    Game tg(10, 10);
    Board tb(tg);

    SECTION("Test ship lengths"){
        REQUIRE(tg.addShip(0, 'A', "Ship") == false);
        REQUIRE(tg.addShip(-5, 'A', "Ship") == false);
        REQUIRE(tg.addShip(-10, 'A', "Ship") == false);
        REQUIRE(tg.addShip(-100, 'A', "Ship") == false);
        REQUIRE(tg.addShip(-1000, 'A', "Ship") == false);
        REQUIRE(tg.addShip(11, 'A', "Ship") == false);
        REQUIRE(tg.addShip(15, 'A', "Ship") == false);
        REQUIRE(tg.addShip(100, 'A', "Ship") == false);
        REQUIRE(tg.addShip(1000, 'A', "Ship") == false);
        REQUIRE(tg.addShip(1, 'A', "Ship") == true);
        REQUIRE(tg.addShip(5, 'B', "ShiB") == true);
        REQUIRE(tg.addShip(10, 'C', "ShiC") == true);
    }

    tg.addShip(1, 'H', "TestShip");

    SECTION("Test ship symbols"){
        REQUIRE(tg.addShip(5, '.', "Ship") == false);
        REQUIRE(tg.addShip(5, 'X', "Ship") == false);
        REQUIRE(tg.addShip(5, 'o', "Ship") == false);
        REQUIRE(tg.addShip(5, 'H', "Ship") == false);
        REQUIRE(tg.addShip(5, 'K', "Ship") == true);
        REQUIRE(tg.addShip(5, 'I', "Ship") == true);
        REQUIRE(tg.addShip(5, 'J', "Ship") == true);
        CHECK(tg.addShip(5, 'AAA', "Ship") == false);
        CHECK(tg.addShip(5, 'aa', "Ship") == false);
        CHECK(tg.addShip(5, 'A', "Ship") == true);
    }

    Point tp1(0, 0);
    Point tp2(-1, 0);
    Point tp3(-5, -10);
    Point tp4(10, 10);
    Point tp5(100, 100);
    Point tp6(1000, 1000);
    Point tp7(0, 1);
    Point tp8(5, 5);
    Point tp9(2, 3);
    Point tp10(15, 15);

    SECTION("Test shot validity"){
        REQUIRE(tg.valid(tp1) == true);
        REQUIRE(tg.valid(tp2) == false);
        REQUIRE(tg.valid(tp3) == false);
        REQUIRE(tg.valid(tp4) == true);
        REQUIRE(tg.valid(tp5) == false);
        REQUIRE(tg.valid(tp6) == false);
        REQUIRE(tg.valid(tp7) == true);
        REQUIRE(tg.valid(tp8) == true);
        REQUIRE(tg.valid(tp9) == true);
        REQUIRE(tg.valid(tp10) == false);
    }
}
