#include "stdafx.h"
#include "Header.h"
#include "GameBoard.h"
#include "GamePieces.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



int main(int argc, char * argv[])
{

	//first check to make sure correct number of arguments are being passed through
	if (argc != commandLineArguments) {
		return messageFunct(argv[programName]);
	}
	//construct and open an input file stream
	ifstream ifs(argv[inputFile]);
	if (ifs.is_open()) {
		unsigned int horizontal;
		unsigned int vertical;
		
		int x = readBoard(ifs, horizontal, vertical);
		
		while (x == cannotExtractDemensions)
		{
			x = readBoard(ifs, horizontal, vertical); //is this the issue?
		}
		
		
		vector<game_piece> gameTime; //the program should declare a vector of game pieces and then for each position on the board
		
		for (unsigned int j = 0; j < vertical; j++) {
			for (unsigned int i = 0; i < horizontal; i++) {
				game_piece newPiece; //make new game piece
				newPiece.color = noColor; //no color
				newPiece.display = " "; //empty display
				newPiece.name = ""; //no name
				gameTime.push_back(newPiece); //push back onto vectors
			}
		}
		if (!(readPieces(ifs, gameTime, horizontal, vertical)==0)) {
			return cantReadPieces;
		}

		//return printBoard(gameTime, horizontal, vertical); //print out the board
		printBoard(gameTime, horizontal, vertical);
		return printInfo(gameTime, horizontal, vertical);
	}
	else {
		return fileFailure();
	}

	return success;

}


int messageFunct(const char * programName) //takes a C style string or a reference to a const C++ style string as its only parameter
{
	cout << "usage: " << programName << " input_file.txt" << endl; //print usage message
	return commandLineFail; //return failure number
}

int fileFailure() {
	cout << "the file was not able to be opened" << endl;
	return unableToOpenFileFailure; //unable to open file failure
}


