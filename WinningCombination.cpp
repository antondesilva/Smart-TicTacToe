/************************************************************************************
 Title:       WinningCombination.cpp
 
 Author:      Anton Desilva
 
 Created On:  February 16, 2014
 
 Description: The implementation of WinningCombination.h. Stores a winning combination,
              that is, a set of 3 Locations that must be in the same row, column, or diagonal
              needed to win the game. Each 'WinningCombination' has a rank(0-2) that is based
              on how many locations of that particular combination is occupied by the same
              player. A WinningCombination is marked invalid if any two of its positions are 
              occupied by different players.
 
 Purpose:     Provides functionality to initialize the 3 Locations, update and advance 'rank' of 
              the WinningCombination, and check the validity of the combination.
 
 Usage:       Initialize a WinningCombinations with three locations. Default constructor 
              creates WinningCombination with position(0,0)
 
 Build with:  Compile with main.cpp. Written with Xcode on OS X 10.8.5 .
 
 Modifications: N/A
 ***********************************************************************************/

#include "WinningCombination.h"
#include <iostream>
using namespace std;

/*
 *Description:Constructor that initializes the three Locations of WinningCombinations to supplied locations.
 *            Also sets default values for isValid local boolean variable and rank local int variable
 *Precondition: N/A
 *Postcondition: The WinningCombination has three Locations
 */
WinningCombination::WinningCombination(Location loc1, Location loc2, Location loc3)
{
    setLocation(loc1,loc2, loc3);
    setValidity(true);
    setRank(0);
}

/*
 *Description:Default constructor that initializes the three Locations of WinningCombinations to position (0,0)
 *            Also sets default values for isValid local boolean variable and rank local int variable
 *Precondition: N/A
 *Postcondition: The WinningCombination has three Locations.
 */
WinningCombination::WinningCombination()
{
    setLocation(Location(0,0), Location(0,0), Location(0,0) );
    setValidity(true);
    setRank(0);
}

/*
 *Description: Mutator function that updates the local variable 'rank'
 *Precondition: The int parameter must be between 0 and 2, inclusive.
 *              Error message is displayed if an incorrect value is entered.
 *Postcondition: The 'rank' is updated.
 */
void WinningCombination::setRank(int combinationRank)
{
    if(combinationRank >= 0 && combinationRank <= 2)
    {
        rank = combinationRank;
    }
    else
    {
        //Display error message if incorrect rank is entered.
        cout << "Erroneous rank entered !" << endl;
    }
}

/*
 *Description: Mutator function that updates the local bool variable 'isValid'
 *Precondition: N/A
 *Postcondition: The 'isValid' is updated.
 */
void WinningCombination::setValidity(bool validity)
{
    isValid = validity;
}

/*
 *Description: Mutator function that updates the set of 3 locations of the WinningCombinaion.
 *Precondition:  Three Location entered must be initialized.
 *Postcondition: The WinningCombination has its 3 locations.
 */
void WinningCombination::setLocation(Location loc1, Location loc2, Location loc3)
{
    
    locationSet.push_back(loc1);
    locationSet.push_back(loc2);
    locationSet.push_back(loc3);
}

/*
 *Description: Accessor function that returns the value of 'rank' variable
 *Precondition:  N/A
 *Postcondition: Value of 'rank' variable is returned.
 */
int WinningCombination::getRank()
{
    return rank;
}

/*
 *Description: Accessor function that returns 3 Locations of the WinningCombination
 *Precondition:  N/A
 *Postcondition: A vector containing the 3 Locations are returned.
 */
vector<Location> WinningCombination::getLocationSet()
{
    return locationSet;
}

/*
 *Description: Accessor function that returns the validity of the WinningCombination
 *Precondition:  N/A
 *Postcondition: A boolean value representing the validity of the WinningCombination is returned.
 */
bool WinningCombination::getValidity()
{
    return isValid;
}

/*
 *Description: Ensures that the WinningCombination is "valid". A WinningCombination
 *             is considered to be valid if only one player(Computer or Player) occupies
 *             its 3 Locations. If both Computer and Player occupies any two locations of
 *             the WinningCombination, the WinningCombination is considered invalid.
 *Precondition: The current playing GameBoard along with an string ID('X' or 'O') must
 *              be passed in.
 *Postcondition: The WinningCombination is either valid or invalid..
 */
void WinningCombination::checkValidity(GameBoard board, string id)
{
    //Temporary Locaion variable
    Location currentLocation;
    /*
     * The following loop cycles through the 3 Location of the WinningCombination. At each
     * iteration, it checks if the current Location is occupied by the passed in 'id'. If the
     * id doesn't match the occupant of Location, then WinningCombination is marked invalid. If 
     * the id does match, then 'rank' is updated. For instance, given the top row of the board as follows:
     * [X][X][O] and passed in id is "X". First two iterations would increase the rank of the WinningCombination
     * ([0,0],[0,1], [0,2]) but in the third iteration the location Id 'O' does not match "X". Thus, this
     *  WinningCombination is marked invalid.
     */
    for(int i = 0; i < 3; i++)
    {
        currentLocation = ( board.gameBoard[getLocationSet()[i].x][getLocationSet()[i].y]);
        locationSet[i].locationId = currentLocation.locationId;
        
        if( currentLocation.locationId == id )
        {
            setRank(getRank() + 1);
            locationSet[i].isUsed = true;
        }
        else if( currentLocation.locationId == "?"){
            //Do nothing
        }
        else
        {
            setValidity(false);
            locationSet[i].isUsed = true;
        }
        
    }
}

/*
 *Description: Resets the rank of WinningCombination.
 *Precondition:  N/A
 *Postcondition: Rank of WinningCombination is 0.
 */
void WinningCombination::resetRank()
{
    setRank(0);
}
