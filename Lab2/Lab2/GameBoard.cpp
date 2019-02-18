#include "GameBoard.h"
#include "stdafx.h"
#include "GamePieces.h"
#include "Header.h"
#include "string"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int readBoard(ifstream & file, unsigned int & b, unsigned int & c) 
{
	string newbie;
	
	if (file.is_open()) //open that file up
	{
		//tested: this part is working
		//do once
		getline(file, newbie);
		istringstream iss(newbie);
		iss >> b;
		cout << "first int " << b << endl;
		

		//do again
		getline(file, newbie);
		iss >> c;
		cout << "second int " << c << endl;
		
		return success;

	}
	else {
		return unableToOpenFileFailure;
	}
	//check all 3 return values 
	//return unique value for each case
}

int readPieces(ifstream & file, vector<game_piece> & positions, unsigned int row, unsigned int col)
{
	string hello;
	vector<string> b;
	string pieceColor;
	string pieceName;
	string displayPiece; 
	unsigned int horPos;
	unsigned int vertPos;
	while (!file.eof()) { //while it's not the end of the file 
		getline(file, hello);
		istringstream iss(hello);
		iss >> hello; //wrap in input stream
		cout << hello << endl; //for debugging, print off the string
		b.push_back(hello); //how to do this??
	}
	if (b.size() != 5) {//b should (hopefully) contain 5 values
		return inputFileWrongSize;
	}
	else {
		pieceColor = b[0]; //1) a string for the color of the game piece,
		pieceName = b[1]; //(2) a string for the name of the game piece, 
		displayPiece = b[2];	//(3) a string with which to display the game piece when the game board is printed out, 
		horPos = b[3];	//(4) an unsigned integer for the horizontal position of the piece on the game board, and 
		vertPos = b[4];  //(5) an unsigned integer for the vertical position of the piece on the game board.
	}
	int colorMe = whatColor(pieceColor); //(1) convert the first string into an enumeration value for the game piece color
	if (colorMe == invalidColor) {
		//do something
	}
										 //(2) compare the values of the horizontal and vertical coordinates of the game piece to the horizontal and vertical dimensions of the game board.

	
	
	return success;
}

int printBoard(const vector<game_piece> & board, unsigned int a, unsigned int b)
{
	return success;
}