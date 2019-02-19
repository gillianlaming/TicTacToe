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
		if (!getline(file, newbie)) { 
			return cannotReadLine;
		}
		istringstream iss(newbie);
		if (!(iss >> b)) { //if cannot extract dimensions
			return cannotExtractDemensions;
		}
		cout << "first int " << b << endl;
		if (!(iss >> c)) { //if cannot extract dimensions
			return cannotExtractDemensions;
		}
		cout << "second int " << c << endl;
		return success;	
	}
	else {
		return unableToOpenFileFailure;
	}

}

int readPieces(ifstream & file, vector<game_piece> & pieces, unsigned int width, unsigned int height)
{
	string hello;
	string pieceColor;
	string pieceName;
	string displayPiece;
	unsigned int col;
	unsigned int row;

	while (getline(file, hello)) { //while it's not the end of the file

		istringstream iss(hello); // wrap in iss
		if (!(iss >> pieceColor)) {// if cant read into piecename -> return something
			return unableToExtract;
		}
		if (!(iss >> pieceName)) { //if cannot read into piececolor -> return failure
			return unableToExtract;
		}
		if (!(iss >> displayPiece)) { //if cannot read into displayPiece -> return failure
			return unableToExtract;
		}
		if (!(iss >> col)) { //if cannot read into col -> return failure
			return unableToExtract;
		}
		if (!(iss >> row)) { //if cannot read into row -> return failure
			return unableToExtract;
		}
		piece_color colorMe = whatColor(pieceColor); //(1) convert the first string into an enumeration value for the game piece color
		if (colorMe == invalidColor) {
			return badColor;
		}
		if ((row > height || col > width)) { //is the boolean still correct here after i used !
			return wrongBoardDimensions;
		}
		if ((row < 0 || col < 0)) {
			return wrongBoardDimensions;
		}
		int index = width*row + col;
		game_piece newPiece;//make the new gamepiece
		newPiece.color = colorMe;
		newPiece.display = displayPiece;
		newPiece.name = pieceName;
		pieces[index] = newPiece; // put into vector

	}

	return success;
}

int printBoard(const vector<game_piece> & board, unsigned int width, unsigned int height)
{
	int a = board.size();
	if (a != width*height) { //is this the correct way to do this?
		return wrongBoardDimensions;
	}
	for (int c = 0; c < width; c++) {
		for (int r = height; r > 0; r++) { //start at top lefthand corner and work across and then down
			int index = width*r + c;
			cout << board[index].display << endl;
		}
	}
	return success;
}


