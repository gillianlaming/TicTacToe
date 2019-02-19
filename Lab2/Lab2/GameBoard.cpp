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

int readBoard(ifstream & file, unsigned int & width, unsigned int & height)
{
	string newbie;
	
	if (file.is_open()) //open that file up
	{
		if (!getline(file, newbie)) { 
			return cannotReadLine;
		}
		istringstream iss(newbie);
		if (!(iss >> width)) { //if cannot extract dimensions
			//continue;
			return cannotExtractDemensions;
		}
		cout << "first int " << width << endl;
		if (!(iss >> height)) { //if cannot extract dimensions

			return cannotExtractDemensions;
		}
		cout << "second int " << height << endl;
		return success;	
	}
	else {
		return unableToOpenFileFailure;
	}

}

int readPieces(ifstream & file, vector<game_piece> & pieces, unsigned int width, unsigned int height)
{
	string placeHolder;
	string pieceColor;
	string pieceName;
	string displayPiece;
	unsigned int col;
	unsigned int row;

	while (getline(file, placeHolder)) { //while it's not the end of the file

		istringstream iss(placeHolder); // wrap in iss
		if (!(iss >> pieceColor)) {// if cant read into piecename 
			continue; //skip line
		}
		if (!(iss >> pieceName)) { //if cannot read into piececolor 
			continue;
		}
		if (!(iss >> displayPiece)) { //if cannot read into displayPiece
			continue;
		}
		if (!(iss >> col)) { //if cannot read into col
			continue;
		}
		if (!(iss >> row)) { //if cannot read into row
			continue;
		}
		piece_color colorMe = whatColor(pieceColor); //(1) convert the first string into an enumeration value for the game piece color
		if (colorMe == invalidColor) {
			continue;
		}
		if ((row > height || col > width)) { //if the parameters for board size are out of bounds -- too big
			continue;
		}
		if ((row < 0 || col < 0)) { //if the parameters for board size are out of bounds -- too small
			continue;
		}

		int index = width*row + col; //calculate index based on equation given
		game_piece newPiece;//make the new gamepiece
		newPiece.color = colorMe; //set color to extracted color
		newPiece.display = displayPiece; // set display to extracted display
		newPiece.name = pieceName; //set name to extracted name
		pieces[index] = newPiece; // put into vector

	}

	return success;
}

int printBoard(const vector<game_piece> & board, unsigned int width, unsigned int height)
{
	int theSize = board.size();
	if (theSize != width*height) { //if extracted size does not match size of board
		return wrongBoardDimensions;
	}
	
	for (unsigned int c = 0; c < height; c++) {
		for (unsigned int r = width - 1; r >= 0; r--) { //start at top lefthand corner and work across and then down
												 //int index = (c+1)*r + c;
			if (r > height) {
				break;
			}
			//equation = width*row + col;
			int index = width*(height - 1 - c) + (width - 1 - r);
			cout << board[index].display;
		}
		cout << "" << endl;
	}
	return success;
}


