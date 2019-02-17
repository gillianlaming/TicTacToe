#pragma once
#include "string"

enum piece_color {red, black, white, invalidColor, noColor};

struct game_piece {
	string name; //why doesn't it like this?
	piece_color color;
	string display;
};

int noName(string color);

piece_color whatColor(string color);