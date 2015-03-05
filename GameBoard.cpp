/************************************************************************************
 Title:         GameBoard.cpp
 
 Author:        Anton Desilva
 
 Created On:    February 16, 2014
 
 Description:   The implementation of GameBoard.h. A representation of the Tic-Tac-Toe
                game board; A 3X3 two-dimensional array of Locations are used.
 
 Purpose:       Provides functionality to keep accurate records of Player/Computer
                positions, drawing a visual representation of the game board, as well as methods
                to advance and terminate an instance of a game.
 
 Usage:         An instance of GameBoard must be initialized to play the game.
 
 Build with:    Compile with main.cpp. Written with Xcode on OS X 10.8.5.
 
 Modifications: N/A
 ***********************************************************************************/


#include "GameBoard.h"
#include <iostream>
using namespace std;

/*
 *Description: Constructor that initializes the GameBoard
 *Precondition: N/A
 *Postcondition: Each of the Locations of the GameBoard is initialized and the board is drawn
 */
GameBoard::GameBoard()
{
    isGameOver = false;
    //Initialize the Board by giving each Location its corresponding 3x3 matrix location
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            gameBoard[i][j].x = i;
            gameBoard[i][j].y = j;
        }
    drawBoard();
}

/*
 *Description: Allows player to make a move to a Location on the GameBoard provided the current game
 *             has not ended. Then checks to see if the game should terminate via updateGameStatus(see
 *             below for description). Also displays information regarding who made the move.
 *Precondition: The Location must be initialized and string parameter must contain either 'X' or 'O'
 *Error Checking: Inputed Location is validated to see if it is already occupied.
 *Postcondition: locationID(see Location.h) is updated to either 'X' or 'O'.
 */
void GameBoard::makeMove(Location loc, string id)
{
    if(!isGameOver)
    {
        if(!gameBoard[loc.x][loc.y].isUsed)
        {
            gameBoard[loc.x][loc.y].isUsed = true;
            gameBoard[loc.x][loc.y].locationId = id;
            updateGameStatus();
            
            if(id == computerID)
                cout << "\nComputer made move:\n ";
            else
                cout << "\nYour move:\n ";
        }
        else
            cout << "Location entered was invalid !" << endl;
    }
    
}

/*
 *Description: Provides a visual representation of the current game
 *Precondition: N/A
 *Postcondition: The game board drawn in the User's output
 */
void GameBoard::drawBoard()
{
    cout << endl;
    
    for(int i = 0; i < 3; i++){
        
        cout << "------------------" << endl;
        
        for(int j = 0; j < 3; j++)
        {
            cout << gameBoard[i][j].locationId << "  |   ";
        }
        
        cout << endl;
    }
    cout << "------------------" << endl;

}

/*
*Description: Accessor function for the GameBoard primary array
*Precondition: N/A
*Postcondition: A pointer to the Locations array is returned
*/
Location* GameBoard::getBoard()
{
    return *gameBoard;
}

/*
 *Description: Accessor function for the isGameOver local boolean variable.
 *             Returns true if game is over; else false.
 *Precondition: N/A
 *Postcondition: A boolean value is returned
 */
bool GameBoard::getGameStatus()
{
    return isGameOver;
}

/*
 *Description: Checks if any of the game terminating scenarios(tie, player won, computer won)
 *             has occured. Then update 'isGameOver' local variable accordingly
 *Precondition: N/A
 *Postcondition: A isGameOver is either true or false
 */
void GameBoard::updateGameStatus()
{
    //Following set of bool variable record whether a winning scenario occured for Player/Computer
    bool winCheckHorizontalPlayer = true;
    bool winCheckVerticalPlayer = true;
    bool winCheckHorizontalComputer = true;
    bool winCheckVerticalComputer = true;
    
    //Checks whether horizontal/vertical winning combinations occured
    for(int i = 0; i < 3; i++){
        
        for(int j = 0; j < 3; j++){
            
            if(gameBoard[i][j].locationId != playerID)
                winCheckHorizontalPlayer = false;
            if(gameBoard[j][i].locationId != playerID)
                winCheckVerticalPlayer = false;
            
            if(gameBoard[i][j].locationId != computerID)
                winCheckHorizontalComputer = false;
            if(gameBoard[j][i].locationId != computerID)
                winCheckVerticalComputer = false;

        }
        if(winCheckHorizontalPlayer || winCheckVerticalPlayer)
        {
            isGameOver = true;
            playerWon = true;
            
        }
        else if(winCheckHorizontalComputer || winCheckVerticalComputer)
        {
            isGameOver = true;
            computerWon = true;
           
        }
        else
        {
            winCheckHorizontalPlayer = true;
            winCheckVerticalPlayer = true;
            winCheckVerticalComputer = true;
            winCheckHorizontalComputer = true;
        }
        
    }
    //Checks whether any diagnoal winning combinations occured
    if( (gameBoard[0][0].locationId == playerID && gameBoard[1][1].locationId == playerID && gameBoard[2][2].locationId == playerID) || (gameBoard[0][2].locationId == playerID && gameBoard[1][1].locationId == playerID && gameBoard[2][0].locationId == playerID))
    {
        isGameOver = true;
        playerWon = true;
        
    }
    if( (gameBoard[0][0].locationId == computerID && gameBoard[1][1].locationId == computerID && gameBoard[2][2].locationId == computerID) || (gameBoard[0][2].locationId == computerID && gameBoard[1][1].locationId == computerID && gameBoard[2][0].locationId == computerID))
    {
        isGameOver = true;
        computerWon = true;
      
    }
    if(!isGameOver)
    {
        //Check whether a tie occured
        bool tieIndicator = true;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(gameBoard[i][j].locationId == "?")
                    tieIndicator = false;
        if(tieIndicator)
        {
            isGameOver = true;
            tie = true;
        }
    }
}

/*
 *Description: Gives player the option to use whichever ID(either 'X' or 'O') for their play and then update
 *             Computer ID accordingly.
 *Precondition: N/A
 *Postcondition: The local string variables playerId and computerId are initialized appropriately
 */
void GameBoard::setPlayerID()
{
    int ans;
    cout << "Please select which symbol to use(1.'X' 2.'O'): ";
    cin >> ans;
    
    if(ans == 1){
        playerID = "X";
        setComputerID("O");
    }
    else if(ans == 2)
    {
        playerID= "O";
        setComputerID("X");
    }
    else
    {
        playerID = "X";
        setComputerID("O");
    }
    
}

/*
 *Description: Accessor function the gets Players ID
 *Precondition: N/A
 *Postcondition: Returns a string representing Player's ID
 */
string  GameBoard::getPlayerID() const
{
    return playerID;
}

/*
 *Description: Accessor function the gets Players ID
 *Precondition: N/A
 *Postcondition: Returns a string representing Player's ID
 */
string GameBoard::getComputerID() const
{
    return computerID;
}

/*
 *Description: Updates Computer ID
 *Precondition: N/A
 *Postcondition: computerID has value either 'X' or 'O'
 */
void GameBoard::setComputerID(string id)
{
    computerID = id;
}

/*
 *Description: Provided the game is still active, inputs the Player's
 *             next move and returns a Location of that move.
 *Precondition: isGameOver is false.
 *Postcondition: Location is returned representing the Player's next move
 */
Location GameBoard::getPlayerMove()
{
    Location nextMove;
    
    if(!isGameOver){
        cout << "\nPlease enter next move[Ex. 1 1 ]: ";
        cin >> nextMove.x >> nextMove.y;
    }
    return nextMove;
}

/*
 *Description: Displays game terminating message indicating who won
 *             or whether the game is a tie.
 *Precondition: playerWon, computerWon, tie local boolean variables
 *              are initialized.
 *Postcondition: Appropriate message is displayed on game status.
 */
void GameBoard::displayGameStatus()
{
    if(playerWon)
        cout << "\n***The PLAYER won !***" << endl;
    if(computerWon)
        cout << "\n***The COMPUTER won !***" << endl;
    if(tie)
        cout << "\n***The game is a TIE!***" << endl;
}
