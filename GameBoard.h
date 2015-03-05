/************************************************************************************
 Title:         GameBoard.cpp
 
 Author:        Anton Desilva
 
 Created On:    February 16, 2014
 
 Description:   A representation of the Tic-Tac-Toe
                game board; A 3X3 two-dimensional array of Locations are used.
 
 Purpose:       Provides functionality to keep accurate records of Player/Computer
                positions, drawing a visual representation of the game board, as well as methods
                to advance and terminate an instance of a game.
 
 Usage:         An instance of GameBoard must be initialized to play the game.
 
 Build with:    Compile with main.cpp. Written with Xcode on OS X 10.8.5.
 
 Modifications: N/A
 ***********************************************************************************/
#ifndef TicTacToe_GameBoard_h
#define TicTacToe_GameBoard_h

#include "GameBoard.h"
#include "Location.h"
#include <string>

class GameBoard {
    
public:
    GameBoard();
    /*
     *Description: Constructor that initializes the GameBoard
     *Precondition: N/A
     *Postcondition: Each of the Locations of the GameBoard is initialized and the board is drawn
     */

    void makeMove(Location, string);
    /*
     *Description: Allows player to make a move to a Location on the GameBoard provided the current game
     *             has not ended. Then checks to see if the game should terminate via updateGameStatus(see
     *             below for description). Also displays information regarding who made the move.
     *Precondition: The Location must be initialized and string parameter must contain either 'X' or 'O'
     *Error Checking: Inputed Location is validated to see if it is already occupied.
     *Postcondition: locationID(see Location.h) is updated to either 'X' or 'O'.
     */

    Location* getBoard();
    /*
     *Description: Accessor function for the GameBoard primary array
     *Precondition: N/A
     *Postcondition: A pointer to the Locations array is returned
     */

    Location gameBoard[3][3]; //3x3 Two-dimensional array to represent the game board
    
    void drawBoard();
    /*
     *Description: Provides a visual representation of the current game
     *Precondition: N/A
     *Postcondition: The game board drawn in the User's output
     */
    
    bool getGameStatus();
    /*
     *Description: Accessor function for the isGameOver local boolean variable.
     *             Returns true if game is over; else false.
     *Precondition: N/A
     *Postcondition: A boolean value is returned
     */

    void displayGameStatus();
    /*
     *Description: Displays game terminating message indicating who won
     *             or whether the game is a tie.
     *Precondition: playerWon, computerWon, tie local boolean variables
     *              are initialized.
     *Postcondition: Appropriate message is displayed on game status.
     */
    
    void setComputerID(string);
    /*
     *Description: Updates Computer ID
     *Precondition: N/A
     *Postcondition: computerID has value either 'X' or 'O'
     */
    
    void setPlayerID();
    /*
     *Description: Gives player the option to use whichever ID(either 'X' or 'O') for their play and then update
     *             Computer ID accordingly.
     *Precondition: N/A
     *Postcondition: The local string variables playerId and computerId are initialized appropriately
     */
    
    string getComputerID() const;
    /*
     *Description: Accessor function the gets Players ID
     *Precondition: N/A
     *Postcondition: Returns a string representing Player's ID
     */
    
    string getPlayerID() const;
    /*
     *Description: Accessor function the gets Players ID
     *Precondition: N/A
     *Postcondition: Returns a string representing Player's ID
     */
    
    Location getPlayerMove();
    /*
     *Description: Provided the game is still active, inputs the Player's
     *             next move and returns a Location of that move.
     *Precondition: isGameOver is false.
     *Postcondition: Location is returned representing the Player's next move
     */
    
private:
    bool isGameOver; //Maintains whether the current game should be terminated
    bool playerWon; //Initializes to 'true' if the Player activates a winning combination
    bool tie; // Initializes to 'true' when niether Player nor Computer wins
    bool computerWon; //Initializes to 'true' if the Computer activates a winning combination
    void updateGameStatus();
    /*
     *Description: Checks if any of the game terminating scenarios(tie, player won, computer won)
     *             has occured. Then update 'isGameOver' local variable accordingly
     *Precondition: N/A
     *Postcondition: A isGameOver is either true or false
     */
    string playerID; //stores whether the Player is 'X' or 'O'
    string computerID; //stores whether the Computer is 'X' or 'O'
};

#endif
