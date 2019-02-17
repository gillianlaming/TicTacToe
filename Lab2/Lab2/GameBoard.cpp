#include "GameBoard.h"
#include "stdafx.h"
#include "GamePieces.h"
#include "Header.h"
#include "string"
#include <vector>
using namespace std;

int readBoard(ifstream & file, unsigned int & b, unsigned int & c);

int readBoard(ifstream & file, unsigned int & b, unsigned int & c) 
{
	string newbie;

	//call the C++ IO library's getline function with the input file stream and the string
	//wrap the string variable in an input string stream and use the input string stream's >>
	//(extraction) operator to extract a value from the string into the first unsigned integer
	//parameter and then use it again to extract another value from the string into the second
	//unsigned integer parameter.


	//check all 3 return values 
	//return unique value for each case
	return success;
}

int readPieces(ifstream & file, vector<game_piece> & pieces, unsigned int row, unsigned int col)
{
	//function should then wrap the string variable in an input string stream and use the input string stream's >> (extraction) operator to extract five values from the string
	//1) a string for the color of the game piece, 
	//(2) a string for the name of the game piece, 
	//(3) a string with which to display the game piece when the game board is printed out, 
	//(4) an unsigned integer for the horizontal position of the piece on the game board, and 
	//(5) an unsigned integer for the vertical position of the piece on the game board.


	//if success, then:
	//(1) convert the first string into an enumeration value for the game piece color (by calling the function you wrote earlier to do that) and 
	//(2) compare the values of the horizontal and vertical coordinates of the game piece to the horizontal and vertical dimensions of the game board.
	return success;
}

int printBoard(const vector<game_piece> & board, unsigned int a, unsigned int b)
{
	return success;
}