/**
 *  @file Globals.h
 *  @brief contains header for global classes and functions
 */

#ifndef GLOBALS_INCLUDED
#define GLOBALS_INCLUDED

#include <random>

const int MAXROWS = 10; ///< Integer for maximum rows
const int MAXCOLS = 10; ///< Integer for maximum columns

///Enumeration for ship's direction
enum Direction {
    HORIZONTAL, VERTICAL
};

/**
 * Point: class for a cell in game
 */
class Point{
    public:
        Point() : r(0), c(0) {} ///< Constructor for point
        Point(int rr, int cc) : r(rr), c(cc) {}
        int r, c;   ///< Integers containing row and column
};

/**
 * Function for getting random integer
 * @param limit integer containing upper limit of the randomized number
 */
inline int randomInt(int limit){
    static std::random_device rd;   ///< Creates a random device
    static std::mt19937 gen(rd()); ///< Creates a Mersenne twister 19937 generator
    std::uniform_int_distribution<> distr(0, limit -1);     ///< Produces random int in a range
    return distr(gen);
}

#endif // GLOBALS_INCLUDED
