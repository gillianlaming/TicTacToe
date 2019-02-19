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
	if (argc > commandLineArguments) {
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
			x = readBoard(ifs, horizontal, vertical);
		}
		//the program should declare a vector of game pieces and then for each position on the board
	}
	else {
		return fileFailure();
	}
	return success;

}


int messageFunct(const char * a) //takes a C style string or a reference to a const C++ style string as its only parameter
{
	cout << "usage: " << a << " input_file.txt" << endl; //print usage message
	return commandLineFail; //return failure number
}

int fileFailure() {
	cout << "the file was not able to be opened" << endl;
	return unableToOpenFileFailure; //unable to open file failure
}


