/************************************************************************************
 Title:       Location.h
 
 Author:      Anton Desilva
 
 Created On:  February 2, 2014
 
 Description: Auxliary Structure that defines a location on the 3x3 
              Tic-Tac-Toe board.
 
 Purpose:     Contains a 'x' and 'y' coordinate for any location on the board.
              Provides functionality to identify if a particular location on the
              game board is already used and by whom(player or computer). When the 
              player/computer makes a move, Location must be used.
 
 Usage:       Location, Location(int,int)
              Initialize to default location to (0,0) or any (x,y) that falls within:
              0 <= x <= 2, 0 <= y <= 2
 
 Build with:  Compile with main.cpp. Written with Xcode on OS X 10.8.5 
 
 Modifications: N/A
***********************************************************************************/
#ifndef TicTacToe_Location_h
#define TicTacToe_Location_h

#include "Location.h"
#include <string>
using namespace std;

struct Location {
    
    /*Initializes a Location object to supplied 'x' and 'y' coordinates.
     *Precondition: N/A
     *Postcondition: Member variables x and y are updated accordingly.
     */
    Location (int xCoordinate, int yCoordinate) : x(xCoordinate), y(yCoordinate), isUsed(false), locationId("?") {}
    
    /*Initializes a Location object to default (0,0) coordinates.
     *Precondition: N/A
     *Postcondition: Member variables x and y are updated to 0.
     */
    Location() : x(0), y(0), isUsed(false), locationId("?") {}
    
    //Integers to hold x, y coordinates.//
    int x;
    int y;
    
    //Stores whether current Location is occupied
    bool isUsed;
    
    //Stores the 'id'(i.e. 'X' or 'O') that is in this Location
    //Default value is '?'
    string locationId;
};
#endif
