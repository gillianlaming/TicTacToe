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
		
		bool a1 = false;
		bool a2 = false;
		bool a3 = false;
		
		//tested: this part is working
		//do once
		//if (getline(file, newbie)) { //for some reason this is causing issues
			//a1 = true;
		//}
		getline(file, newbie);
		istringstream iss(newbie);
		//if (iss >> b) {
			//a2 = true;
		//}
		iss >> b;
		cout << "first int " << b << " done" << endl;
		//if (iss >> c) {
			//a3 = true;
		//}
		iss >> c;
		cout << "second int " << c << " done" << endl;
		return success;
		/*
		if ((a1 && a2) && (a1 && a3)) {
			cout << "successfully extracted things" << endl;
			return success;
		}
		else if (a1){
			cout << "not all 3 conditions were met" << endl;
			return cannotExtractDemensions;
		}
		else {
			//unable to read in line from file
			return cannotReadLine;
		}
		*/
		
		
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
	bool apple = true;
	while (!file.eof()) { //while it's not the end of the file
		if (getline(file, hello)) {
			getline(file, hello);
			istringstream iss(hello);
			iss >> pieceColor; //wrap in input stream
			cout << pieceColor << endl; //for debugging, print off the string
		}
		else {
			apple = false;
		}
		if (getline(file, hello)) {
			getline(file, hello);
			istringstream iss(hello);
			iss >> pieceName; //wrap in input stream
			cout << pieceName << endl; //for debugging, print off the string
		}
		else {
			apple = false;
		}
		if (getline(file, hello)) {
			getline(file, hello);
			istringstream iss(hello);
			iss >> displayPiece; //wrap in input stream
			cout << displayPiece << endl; //for debugging, print off the string
		}
		else {
			apple = false;
		}
		if (getline(file, hello)) {
			getline(file, hello);
			istringstream iss(hello);
			iss >> col; //wrap in input stream
			cout << col << endl; //for debugging, print off the string
		}
		else {
			apple = false;
		}
		if (getline(file, hello)) {
			getline(file, hello);
			istringstream iss(hello);
			iss >> row; //wrap in input stream
			cout << row << endl; //for debugging, print off the string
		}
		else {
			apple = false;
		}
		if (apple) { //extraction was a success
			piece_color colorMe = whatColor(pieceColor); //(1) convert the first string into an enumeration value for the game piece color
			if (colorMe == invalidColor) {
				//do something
			}
			else if (!(row > height || col > width)) { //is the boolean still correct here after i used !
				int index = width*row + col;
				pieces[index].color = colorMe;
				pieces[index].name = pieceName;



			}
		}
		
	}


	
	
	return success;
}

int printBoard(const vector<game_piece> & board, unsigned int row, unsigned int col)
{
	int a = board.size();
	if (a != row*col) { //is this the correct way to do this?
		return wrongBoardDimensions;
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {

		}
	}
	return success;
}


