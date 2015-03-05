/************************************************************************************
 Title:         Computer.cpp
 
 Author:        Anton Desilva
 
 Created On:    February 16, 2014
 
 Description:   The implementation of Computer.h. The artificial intelligence of the Computer
                is implemented here.
 
 Purpose:       Provides functionality that gathers information regarding Player positions,
                current game status, and vacant positions as well as the mechanism that the 
                computer uses to make best available moves from this information.
 
 Usage:         This class is not meant for external usage.
 
 Build with:    Compile with main.cpp. Written with Xcode on OS X 10.8.5.
 
 Modifications: N/A
 ***********************************************************************************/

#include "Computer.h"
#include <cstdlib>
using namespace std;

/*
 *Description: Constructor that initializes the member arrays with all the possible WinningCombinations.
 *              The Computer will use these two arrays to keep track of all the possible ways it or the player
 *              can win.
 *Precondition: N/A
 *Postcondition: The computer has access to two arrays consisting of same set of all possible WinningCombinations
 */
Computer::Computer()
{
    computerWin[0] = WinningCombination(Location(0,0), Location(0,1), Location(0,2));
    computerWin[1] = WinningCombination(Location(1,0), Location(1,1), Location(1,2));
    computerWin[2] = WinningCombination(Location(2,0), Location(2,1), Location(2,2));
    computerWin[3] = WinningCombination(Location(0,0), Location(1,0), Location(2,0));
    computerWin[4] = WinningCombination(Location(0,1), Location(1,1), Location(2,1));
    computerWin[5] = WinningCombination(Location(0,2), Location(1,2), Location(2,2));
    computerWin[6] = WinningCombination(Location(0,0), Location(1,1), Location(2,2));
    computerWin[7] = WinningCombination(Location(0,2), Location(1,1), Location(2,0));
    
    playerWin[0] = WinningCombination(Location(0,0), Location(0,1), Location(0,2));
    playerWin[1] = WinningCombination(Location(1,0), Location(1,1), Location(1,2));
    playerWin[2] = WinningCombination(Location(2,0), Location(2,1), Location(2,2));
    playerWin[3] = WinningCombination(Location(0,0), Location(1,0), Location(2,0));
    playerWin[4] = WinningCombination(Location(0,1), Location(1,1), Location(2,1));
    playerWin[5] = WinningCombination(Location(0,2), Location(1,2), Location(2,2));
    playerWin[6] = WinningCombination(Location(0,0), Location(1,1), Location(2,2));
    playerWin[7] = WinningCombination(Location(0,2), Location(1,1), Location(2,0));
}
/*
 *Description: Updates the validity of all the WinningCombination by calling each WinningCombination's 
 *             checkValidity(see WinningCombination.h) function.
 *Precondition: N/A
 *Postcondition: All the WinningCombinations are appropriately marked as valid or invalid. Consquently,
 *                computer 'knows' which WinningCombinations to consider when attempting to win or defend.
 */
void Computer::updateCombinations(const GameBoard& board)
{
    for(int i = 0; i < 8; i++)
    {
        //Validates all the WinningCombinations
        //The function resetRank ensures that the rank is not updated over the max value of 2
        playerWin[i].resetRank();
        playerWin[i].checkValidity(board, board.getPlayerID());
        
        computerWin[i].resetRank();
        computerWin[i].checkValidity(board, board.getComputerID());
        
    }
}
/*
 *Description: Finds and return a vacant position randomly
 *Precondition: N/A
 *Postcondition: A random location is returned
 */
Location Computer::getRandomLocation(const GameBoard& board)
{
    vector<Location> randomLocations;
    //Cycle through all the positions of the game board and add all unused locations
    //to the vector 'randomLocations'
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board.gameBoard[i][j].isUsed == false)
            {
                randomLocations.push_back(Location(i,j));
            }
    //Return a random Location from the vector
    return randomLocations[rand() % static_cast<int>(randomLocations.size())];
}

/*
 *Description: Returns the Computer's next move Location after analyzing the Board.
 *Precondition: N/A
 *Postcondition: Computer's next Location is returned.
 */
Location Computer::chooseNextMove(const GameBoard& board)
{
    
    //This function maintains which combinations are valid for use
    //It calls 'checkValidity' function that decides whether a particular
    //combination is valid.
    updateCombinations(board);
    
    //'getHighestRankedMoves' function returns the highest ranking winning combinations
    //as vectors by accepting any set of winning moves
    vector<WinningCombination> computerMoves = getHighestRankedMoves(computerWin);
    vector<WinningCombination> playerMoves = getHighestRankedMoves(playerWin);
    
    int computerSize = computerMoves.size();
    int playerSize = playerMoves.size();
    
    if(playerSize == 0) //The Player does not have any valid WinningCombinations(i.e. Player can NOT win the game)
    {
        if(computerSize == 0)
            //if computer and player are out of winning
            //combinations, let the computer pick any
            //available place on board mark '0' there
            return getRandomLocation(board);
        else
            //if player is out of moves, but computer
            //is not, then let computer randomly pick one of its highest ranking WinningCombinations
            //and advance it
            return getNextLocation(computerMoves[rand() % computerSize]);
    }
    else //Player still has valid WinningCombinations(i.e. Player can still win the game)
    {
        if(playerMoves[0].getRank() == 2)
        {
            //If player does have rank 2 WinningCombination
            //but computer has no moves left, then let computer just block that move
            if(computerSize == 0)
                return getNextLocation(playerMoves[0]);
            
           //If computer does have moves left, check to see if they rank 2 WinningCombination, and
           //play any WinningCombination for the win
            if(computerMoves[0].getRank() == 2)
                return getNextLocation(computerMoves[rand() % computerSize]);
            
            //If the computer's higest ranked moves are 1, then
            //play to block
            if(computerMoves[0].getRank() == 1)
                return getNextLocation(playerMoves[0]);
        }
        if(playerMoves[0].getRank() == 1)
        {
            //If player does have high ranking moves and
            //but computer has no moves left, then let computer just block that move
            if(computerSize == 0)
                return getNextLocation(playerMoves[0]);
            
            //If computer does have moves left, check to see if they rank 2, and
            //return a rank 2 if possible
            if(computerMoves[0].getRank() == 2)
                return getNextLocation(computerMoves[rand() % computerSize]);
            
            //If the computer's higest ranked moves are 1, then
            //advance any random combination
            if(computerMoves[0].getRank() == 1)
                return getNextLocation(computerMoves[rand() % computerSize]);
        }
    }
    return getRandomLocation(board);
    
}

/*
 *Description: Returns a list of highest ranked WinningCombinations (see WinningCombination.h)
 *Precondition: N/A
 *Postcondition: Returned vector contains highest ranked WinningCombinations
 */
vector<WinningCombination> Computer:: getHighestRankedMoves(WinningCombination winningCombos[])
{
    int highestRank = winningCombos[0].getRank();
    
    //Find the highest rank
    for(int i = 0; i < 8; i++)
        if(winningCombos[i].getRank() > highestRank)
            highestRank = winningCombos[i].getRank();
    
    vector<WinningCombination> combinations;
    
    //Add only the WinningCombinations with the highest rank
    for(int i = 0; i < 8; i++)
        if(winningCombos[i].getRank() == highestRank && winningCombos[i].getValidity())
            combinations.push_back(winningCombos[i]);
    
    return combinations;
    
}

/*
 *Description: Returns the next position necessay to advance the rank of a WinningCombination
 *Precondition: The WinningCombination parameter must be an initialized WinningCombination
 *Postcondition: Location is returned of the next unoccupied position of WinningCombination
 */
Location Computer:: getNextLocation( WinningCombination& winningCombo)
{
    Location temp;
    //Access each of the passed WinningCombination's 3 locations and returned the first unused location
    for(int i = 0; i < 3; i++)
    {
        temp =(winningCombo.getLocationSet())[i];
        if(temp.isUsed == false )
            return temp;
    }
    return Location(0,0);
}

/*
 *Description: Accessor function to the list of Computer's WinningCombinations
 *Precondition: N/A
 *Postcondition: A pointer to the array consisting of Computer's possible WinningCombinations are returned
 */
WinningCombination* Computer::getWinningCombinations()
{
    return computerWin;
}
