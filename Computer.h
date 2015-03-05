/************************************************************************************
 Title:         Computer.h
 Author:        Anton Desilva
 
 Created On:    February 16, 2014
 
 Description:   The artificial intelligence of the Computer is developed here.
 
 Purpose:       Provides functionality that gathers information regarding Player positions,
                current game status, vacant positions and make best available move
                from this information.
 
 Usage:         This class is not meant for external usage.
 
 Build with:    Compile with main.cpp. Written with Xcode on OS X 10.8.5.
 
 Modifications: N/A
 ***********************************************************************************/

#ifndef TicTacToe_Computer_h
#define TicTacToe_Computer_h

#include "WinningCombination.h"
#include "Location.h"
#include "GameBoard.h"
#include <vector>
using namespace std;


class Computer{
    
public:
    Computer();
    /*
     *Description:  Constructor that initializes the member arrays with all the possible WinningCombinations.
     *              The Computer will use these two arrays to keep track of all the possible ways it or the player
     *              can win.
     *Precondition: N/A
     *Postcondition: The computer has access to two arrays consisting of same set of all possible   WinningCombinations
     */
    Location chooseNextMove(const GameBoard&);
    /*
     *Description: Returns the Computers next move Location after analyzing the Board. For further detail
     *             check the implementation(Computer.cpp)
     *Precondition: N/A
     *Postcondition: Computer's next Location is returned.
     */
    WinningCombination* getWinningCombinations();
    /*
     *Description: Accessor function to the list of Computer's WinningCombinations
     *Precondition: N/A
     *Postcondition: A pointer to the array consisting of Computer's possible WinningCombinations are returned
     */
    
private:
    void updateCombinations(const GameBoard& board);
    /*
     *Description: Updates the validity of all the WinningCombination by calling each WinningCombination's
     *             checkValidity(see WinningCombination.h) function.
     *Precondition: N/A
     *Postcondition: All the WinningCombinations are appropriately marked as valid or invalid. Consquently,
     *               computer 'knows' which of its or the Player's WinningCombinations to consider when attempting    to win or defend.
     */
    vector<WinningCombination> getHighestRankedMoves(WinningCombination[]);
    /*
     *Description: Returns a list of highest ranked WinningCombinations (see WinningCombination.h)
     *Precondition: N/A
     *Postcondition: Returned vector contains highest ranked WinningCombinations
     */
    Location getRandomLocation(const GameBoard&);
    /*
     *Description: Finds and return a vacant position randomly
     *Precondition: N/A
     *Postcondition: A random location is returned
     */
    Location getNextLocation( WinningCombination&);
    /*
     *Description: Returns the next position necessay to advance the rank of a WinningCombination
     *Precondition: The WinningCombination parameter must be an initialized WinningCombination
     *Postcondition: Location is returned of the next unoccupied position of WinningCombination
     */
    
    WinningCombination computerWin[8]; //An array to hold Computer's possible WinningCombinations
    WinningCombination playerWin[8]; //An array to hold Player's possible WinningCombinations    
    
};
#endif
