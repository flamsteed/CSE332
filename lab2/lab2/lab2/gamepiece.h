#pragma once

#include <string>

using namespace std;
// requirement 7
enum piece_color {
	color_red = 0,
	color_black = 1,
	color_white = 2,
	invalid_color = 3,
	no_color = 4
};


// requirement 10
struct game_piece {
	piece_color color;
	string display;
	string name;
};

string enumToString(piece_color colorOfPiece);
piece_color StringToEnum(string string);