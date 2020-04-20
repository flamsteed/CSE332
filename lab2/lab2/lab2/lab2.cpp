#include "stdafx.h"
#include "Lab2.h"
#include "gamepiece.h"
#include "gameboard.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// requirement 6
string ToLowercase(string& inputString) {  // a function a lowercase the string
	string c = inputString;
	int k = 0;
	while (c[k] != '\0')
	{
		if (c[k] >= 'A' && c[k] <= 'Z') {
			c[k] += 32;      // lowercase the letter
		}
		k++;
	}
	return c;
}

int usage_message(string program_name, string command1) {
	cout << "illegal number of command lines inserted, please insert" << expected_num_of_command_line << " lines" << endl;
	cout << "Usage " << program_name << " <input_file_name>" << endl;
	return wrong_arguments_num;
}

int main(int argc, char * argv[]) {
	if (argc != expected_num_of_command_line) {// check if exactly one argument has been passed to it
		return usage_message(argv[program_name],argv[input_file_name]);
	}
	else {
		//check file type
		string filename = argv[input_file_name];
		unsigned int horizon, vert;
		int row = cannot_get_dimension;
		ifstream file;
		file.open(argv[input_file_name]);
		if (file.is_open()) {
			while (row == cannot_get_dimension) {
				row = readDimensions(file, horizon, vert);
				if (row == cannot_get_line) {
					cout << "Fail to extract dimensions." << endl;
					return dimension_extraction_failed;
				}
				if (row != cannot_get_dimension) break;
			}
			vector<game_piece> vecc;
			game_piece tempGamePiece;
			tempGamePiece.name = " ";
			tempGamePiece.display = " ";
			tempGamePiece.color = no_color;
			for (unsigned int k = 0; k < horizon*vert; k++) {
				vecc.push_back(tempGamePiece);
			}
			int g = readGamePieces(file, vecc, horizon, vert);
			if (g == failed_to_findwell_formed_piece) {
				cout << "An absence of well formed piece is found." << endl;
				return failed_to_findwell_formed_piece;
			}
			else {
				int result = printPiecesOnBoard(vecc, horizon, vert) + printNearbyPieceOnBoard(vecc, horizon, vert);;
				return result;
			}
		}
		else {    // open file error
			cout << "fail to open input file" << endl;
			return fail_to_open_file;
		}


		return 0;
	}
}

