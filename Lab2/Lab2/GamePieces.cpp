#include "stdafx.h"
#include "Header.h"
#include "string"
#include "GamePieces.h"
using namespace std;


int lowerCaseMe(string & a) {
	//modifies that string so that all of the alphabetic characters in it become lowercase
	for (char& c : a) { //iterate char by char thru string
		if (isupper(c)) {

			char d = tolower(c); //convert the character to lowercase
			c = d; //replace the uppercase string w lowercase string
		}
	}
	return success;

}

string noName(piece_color color)
{
	//returns (again by value) the element of the enumerated type
	//(e.g., piece_color) that corresponds to that string.
	int val = color;
	string enumColors[] = { "red", "black", "white", "invalidColor", "noColor" };
	//go thru enum of type piece_color
	//find string that matches param
	//return index of that element

	//call lowerCaseMe from this!!
	return enumColors[val];
}

int game_piece::whatColor(string color) 
{


	return piece_color::red;

}


