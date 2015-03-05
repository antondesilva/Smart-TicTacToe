/************************************************************************************
 Title:         main.cpp
 
 Author:        Anton Desilva
 
 Created On:    February 16, 2014
 
 Description:   Invokes Location, Computer, and GameBoard classes create a game
                of Tic-Tac-Toe
 
 Purpose:       A Driver class to test the functionality of all the classes.
 
 Usage:         Initialize the GameBoard and Computer objects.
 
 Build with:    Written with Xcode on OS X 10.8.5 .
 
 Modifications: N/A
 ***********************************************************************************/
#include <iostream>
#include "Location.h"
#include "Computer.h"
#include "GameBoard.h"

using namespace std;

int main()
{
    //Creates instances of the Computer, the GameBoard, and the Location
    Computer cpu;
    GameBoard gameBoard;
    Location player;//Holds Player's moves
    
    char ans;
    
    //Asks user whether they like 'X' or 'O'
    gameBoard.setPlayerID();
    
    //Asks user if they want the first move
    cout << "Would you like to go first(y/n): ";
    cin >> ans;
    
    if(ans == 'y' || ans == 'Y')
    {
        //Gets the Player's move, enter it to the game board, and then draw the board
        player = gameBoard.getPlayerMove();
        gameBoard.makeMove(player, gameBoard.getPlayerID());
        gameBoard.drawBoard();
    }
    while( !gameBoard.getGameStatus())
    {
        //Allows the computer to select the move and, enter it to the game board, and then draw the board
        gameBoard.makeMove(cpu.chooseNextMove(gameBoard), gameBoard.getComputerID());
        gameBoard.drawBoard();
        
        player = gameBoard.getPlayerMove();
        gameBoard.makeMove(player, gameBoard.getPlayerID());
        gameBoard.drawBoard();
    }
    //Display the result of the game Player, Computer, or Tie
    gameBoard.displayGameStatus();
}

