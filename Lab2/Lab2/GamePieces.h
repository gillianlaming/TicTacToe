#pragma once
#include <string>
using namespace std;

enum piece_color {red, black, white, invalidColor, noColor};

struct game_piece {
	int noName(string color);
	int whatColor(string color);
	string name; //why doesn't it like this?
	piece_color color;
	string display;
};

