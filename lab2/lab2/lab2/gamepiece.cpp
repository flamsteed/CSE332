#include "stdafx.h"
#include "gamepiece.h"

// requirement 8
string enumToString(piece_color colorOfPiece) {
	string colorName;
	switch (colorOfPiece) {
	case piece_color::color_black:
		colorName = "black";
		break;
	case piece_color::color_white:
		colorName = "white";
		break;
	case piece_color::color_red:
		colorName = "red";
		break;
	case piece_color::invalid_color:
		colorName = "invalid color";
		break;
	default:
		colorName = "no color";
		break;
	}
	return colorName;
}

// requirement 9
piece_color StringToEnum(string string) {
	piece_color inputColor;
	if (string == "black") {
		inputColor = piece_color::color_black;
	}
	else if (string == "white") {
		inputColor = piece_color::color_white;
	}
	else if (string == "red") {
		inputColor = piece_color::color_red;
	}
	else if (string == " ") {
		inputColor = piece_color::no_color;
	}
	else {
		inputColor = piece_color::invalid_color;
	}
	return inputColor;
}
