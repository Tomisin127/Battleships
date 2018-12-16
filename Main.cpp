/**
 *  @file Main.cpp
 *  @brief contains Main function of the program
 */

#include "Setup.h"

/**
 * Main function of the program
 */
int main(void){
    Setup * s = new Setup();    ///< Creates a setup
    s->start();   ///< Starts the setup process
    delete s;
    return 0;
}
