#pragma once

enum piece_color {red, black, white, invalidColor, noColor};

struct game_piece {
	string name;
	piece_color color;
	string display;
};