/**
 *  @file Board_tests.cpp
 *  @brief contains test cases for Board classes
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Board.h"
#include "Game.h"
#include "Globals.h"

TEST_CASE("Board tests", "[board]"){
    Game tg(10, 10);
    Board tb(tg);

    Point tp1(0,0);
    Point tp2(-1,0);
    Point tp3(-5,-6);
    Point tp4(5,6);
    Point tp5(10,10);
    Point tp6(11, 16);
    Point tp7(100, 100);
    Point tp8(-100, -100);
    Point tp9(100, -100);
    Point tp10(-100, 100);
    Point tp11(1000, 1000);
    Point tp12(-1000, 1000);
    Point tp13(1000, -1000);

    SECTION("Test placing ship"){
        REQUIRE(tb.placeShip(tp1, 1, HORIZONTAL) == true);
        REQUIRE(tb.placeShip(tp2, 2, VERTICAL) == false);
        REQUIRE(tb.placeShip(tp3, 3, HORIZONTAL) == false);
        REQUIRE(tb.placeShip(tp4, 4, VERTICAL) == true);
        REQUIRE(tb.placeShip(tp5, 5, HORIZONTAL) == false);
        REQUIRE(tb.placeShip(tp6, 6, HORIZONTAL) == false);
        REQUIRE(tb.placeShip(tp7, 7, VERTICAL) == false);
        REQUIRE(tb.placeShip(tp8, 8, HORIZONTAL) == false);
        REQUIRE(tb.placeShip(tp9, 9, VERTICAL) == false);
        REQUIRE(tb.placeShip(tp10, 10, HORIZONTAL) == false);
        REQUIRE(tb.placeShip(tp11, 11, VERTICAL) == false);
        REQUIRE(tb.placeShip(tp12, 7, HORIZONTAL) == false);
        REQUIRE(tb.placeShip(tp13, 7, VERTICAL) == false);
    }

    SECTION("Test removing ship"){
        REQUIRE(tb.removeShip(tp1, 1, HORIZONTAL) == true);
        REQUIRE(tb.removeShip(tp2, 2, VERTICAL) == false);
        REQUIRE(tb.removeShip(tp3, 3, HORIZONTAL) == false);
        REQUIRE(tb.removeShip(tp4, 4, VERTICAL) == true);
        REQUIRE(tb.removeShip(tp5, 5, HORIZONTAL) == false);
        REQUIRE(tb.removeShip(tp6, 6, HORIZONTAL) == false);
        REQUIRE(tb.removeShip(tp7, 7, VERTICAL) == false);
        REQUIRE(tb.removeShip(tp8, 7, VERTICAL) == false);
        REQUIRE(tb.removeShip(tp9, 7, VERTICAL) == false);
        REQUIRE(tb.removeShip(tp10, 7, VERTICAL) == false);
        REQUIRE(tb.removeShip(tp11, 7, VERTICAL) == false);
        REQUIRE(tb.removeShip(tp12, 7, VERTICAL) == false);
        REQUIRE(tb.removeShip(tp13, 7, VERTICAL) == false);
    }

    tb.placeShip(tp1, 1, HORIZONTAL);
    Point tc1(0,1);
    Point tc2(0,2);
    Point tc3(0,3);
    bool hit = false;
    bool destroyed = false;
    int id = 10;

    SECTION("Test shooting"){
        CHECK(tb.allDestroyed() == false);
        REQUIRE(tb.attack(tp1, hit, destroyed, id) == true);
        REQUIRE(tb.attack(tc1, hit, destroyed, id) == true);
        REQUIRE(tb.attack(tc2, hit, destroyed, id) == true);
        REQUIRE(tb.attack(tc3, hit, destroyed, id) == true);
        CHECK(tb.allDestroyed() == true);
        REQUIRE(tb.attack(tp1, hit, destroyed, id) == false);
        REQUIRE(tb.attack(tp2, hit, destroyed, id) == false);
        REQUIRE(tb.attack(tp3, hit, destroyed, id) == false);
        REQUIRE(tb.attack(tp4, hit, destroyed, id) == false);
        REQUIRE(tb.attack(tp5, hit, destroyed, id) == false);
        REQUIRE(tb.attack(tp6, hit, destroyed, id) == false);
        CHECK(tb.allDestroyed() == false);
    }
}
