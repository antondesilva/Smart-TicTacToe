/************************************************************************************
 Title:         WinningCombination.h
 
 Author:        Anton Desilva
 
 Created On:    February 16, 2014
 
 Description:   Stores a winning combination, that is a set of 3 Locations that must be in the same row,
                column, or diagonal needed to win the game. Each 'WinningCombination' has a rank(0-2) that is based
                on how many locations of that particular combination is occupied by the same
                player. A WinningCombination is marked invalid if any two of its positions are
                occupied by different players.
 
 Purpose:       Provides functionality to initialize the 3 Locations, update and advance 'rank' of
                the WinningCombination, and check the validity of the combination.
 
 Usage:         Initialize a WinningCombinations with three locations. Default constructor
                creates WinningCombination with position(0,0)
 
 Build with:    Compile with main.cpp. Written with Xcode on OS X 10.8.5 .
 
 Modifications: N/A
 ***********************************************************************************/

#ifndef TicTacToe_WinningCombination_h
#define TicTacToe_WinningCombination_h

#include "Location.h"
#include "GameBoard.h"
#include <string>
#include <vector>
using namespace std;

class WinningCombination {
    
public:
    WinningCombination(Location, Location, Location);
    /*
     *Description:Constructor that initializes the three Locations of WinningCombinations to supplied locations
     *Precondition: N/A
     *Postcondition: The WinningCombination has three Locations
     */
    
    WinningCombination();
     /*
     *Description:Constructor that initializes the three Locations of WinningCombinations to position (0,0)
     *Precondition: N/A
     *Postcondition: The WinningCombination has three Locations.
     */

    void checkValidity(GameBoard, string);
    /*
     *Description: Ensures that the WinningCombination is "valid". A WinningCombination
     *             is considered to be valid if only one player(Computer or Player) occupies
     *             its Locations. If both Computer and Player occupies any two locations of
     *             the WinningCombination, the WinningCombination is considered invalid. See
     *             implementation for further detail. 
     *Precondition: The current playing GameBoard along with an string ID('X' or 'O') must
     *              be passed in.
     *Postcondition: The WinningCombination is either valid or invalid..
     */

    void setRank(int);
    /*
     *Description: Mutator function that updates the local variable 'rank'
     *Precondition: The int parameter must be between 0 and 2, inclusive.
     *              Error message is displayed if an incorrect value is entered.
     *Postcondition: The 'rank' is updated.
     */

    void resetRank();
    /*
     *Description: Resets the rank of WinningCombination.
     *Precondition:  N/A
     *Postcondition: Rank of WinningCombination is 0.
     */

    void setValidity(bool);
    /*
     *Description: Mutator function that updates the local bool variable 'isValid'
     *Precondition: N/A
     *Postcondition: The 'isValid' is updated.
     */
    
    void setLocation(Location,Location,Location);
    /*
     *Description: Mutator function that updates the set of 3 locations of the WinningCombinaion.
     *Precondition:  Three Location entered must be initialized.
     *Postcondition: The WinningCombination has its 3 locations.
     */
    
    int getRank();
    /*
     *Description: Accessor function that returns the value of 'rank' variable
     *Precondition:  N/A
     *Postcondition: Value of 'rank' variable is returned.
     */
    
    vector<Location> getLocationSet();
    /*
     *Description: Accessor function that returns 3 Location of the WinningCombination
     *Precondition:  N/A
     *Postcondition: A vector containing the 3 Locations are returned.
     */
    
    bool getValidity();
    /*
     *Description: Accessor function that returns the validity of the WinningCombination
     *Precondition:  N/A
     *Postcondition: A boolean value representing the validity of the WinningCombination is returned.
     */

private:
    vector<Location> locationSet; //Stores the WinningCombination's 3 Locations
    bool isValid; //Stores the validity of the WinningCombination
    int rank; //Stores the rank of the WinningCombination
};
#endif
