#include "stdafx.h"
#include "gameboard.h"
#include "Lab2.h"
#include <iostream>

// requirement 11
int readDimensions(ifstream & fileName, unsigned int& row, unsigned int& col) {
	string localS; // define local string
	if (getline(fileName, localS)) {
		istringstream iss(localS);
		if (iss >> row) {
			if (iss >> col) 
				return success;
			else
				return cannot_get_dimension;
		}
		else return cannot_get_dimension;
	}
	else return cannot_get_line;
}

//requirement 12 w denotes width, h denotes height
int readGamePieces(ifstream & fileName, vector<game_piece> & vector, unsigned int h, unsigned int w) {
	string localS; // local string
	status condition = failed_to_findwell_formed_piece;
	while (getline(fileName, localS)) {
		istringstream iss(localS); 
		string piece_Color;
		string piece_Name;
		string display;
		unsigned int row, col;
		if ((iss >> piece_Color) && (iss >> piece_Name) && (iss >> display) && (iss >> col) && (iss >> row)) {
			piece_color color = StringToEnum(piece_Color);
			if (color == piece_color::invalid_color) {
				//invalid color just continue
				continue;
			}
			if (row >= h || col >= w) {
				continue;    // skip to next
			}
			// insert the piece 
			vector[w * row + col].name = piece_Name;
			vector[w * row + col].color = color;
			vector[w * row + col].display = display;
			condition = success;
		}
	}
	return condition;
}

//requirement 13
int printPiecesOnBoard(const vector<game_piece>& vector, unsigned int h, unsigned int w) {
	if (vector.size() == h * w) {
		for (int row = int(h - 1); row >= 0; --row) {
			for (int col = 0; col <= int(w - 1); ++col) {
				cout << vector[w*row + col].display;
			}
			cout << endl;// enter a line
		}
		return success;
	}
	else {  // size mismatch, printing fails
		cout << "dimensions mismatches the size of the vector" << endl;
		return fail_to_print;
	}
}

int printNearbyPieceOnBoard(const vector<game_piece>& vector, unsigned int h, unsigned int w) {
	if (vector.size() == h * w) {
		for (int row = int(h - 1); row >= 0; --row) {
			for (int col = 0; col <= int(w - 1); ++col) {
				int i = h - 1 - row;
				int j = col;
				if (vector[w*i + j].color != no_color) {
					cout << i << "," << j << " " << enumToString(vector[w*i + j].color) << vector[w*i + j].name << ": ";
					printnearby(vector, i - 1, j - 1, h, w);
					printnearby(vector, i - 1, j, h, w);
					printnearby(vector, i - 1, j + 1, h, w);
					printnearby(vector, i, j - 1, h, w);
					printnearby(vector, i, j + 1, h, w);
					printnearby(vector, i + 1, j - 1, h, w);
					printnearby(vector, i + 1, j, h, w);
					printnearby(vector, i + 1, j + 1, h, w);
					cout << endl;
				}
			}
		}
		return success;
	}
	else {  // size mismatch, printing fails
		cout << "dimensions mismatches the size of the vector" << endl;
		return fail_to_print;
	}
}

void printnearby(const vector<game_piece>& vector, unsigned int i, unsigned int j, unsigned int h, unsigned int w) {
	if (i >= 0 && i <= h - 1 && j >= 0 && j <= w - 1 && vector[w*i + j].color != no_color) {
		cout << i << "," << j << " " << enumToString(vector[w*i + j].color) << vector[w*i + j].name << " ; ";
	}

}
