#pragma once
#include <string>
using namespace std;

enum piece_color {red, black, white, invalidColor, noColor};

int whatColor(string color);

int lowerCaseMe(string & a);
string noName(piece_color color);
//int piece_color whatColor(string color);

struct game_piece {
	
	string name; //why doesn't it like this?
	piece_color color;
	string display;
};

