/**
 *  @file Ship.h
 *  @brief contains header for ship class
 */

#ifndef SHIP_INCLUDED
#define SHIP_INCLUDED

/**
 *  Ship class
 */
class Ship{
    public:
        Ship(int length, char symbol, std::string name, int id); ///< Creates Ship class
        int getLength() const { return sLength; };  ///< Getter for ship's length
        int getShipID() const { return sShipID; };  ///< Getter for ship's ID
        char getSymbol() const { return sSymbol; }; ///< Getter for ship's symbol
        std::string getName() const { return sName; };   ///< Getter for ship's name
    private:
        int sLength;    ///< Ship's length
        int sShipID;    ///< Ship's ID
        char sSymbol;   ///< Ship's symbol
        std::string sName;   ///< Ship's name
};

#endif // SHIP_INCLUDED
