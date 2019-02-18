#pragma once
#include <string>
using namespace std;

enum piece_color {red, black, white, invalidColor, noColor};


int lowerCaseMe(string & a);
string noName(piece_color color);

struct game_piece {
	int whatColor(string color);
	string name; //why doesn't it like this?
	piece_color color;
	string display;
};

