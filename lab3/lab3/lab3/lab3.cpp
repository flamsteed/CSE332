// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab3.h"
#include "tictactoe.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


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

int usage_message(string program_name) { // usage message function
	cout << "please input: " << expected_num_of_commands << " commands" << endl;
	cout << "Usage " << program_name << " <game_file_name>" << endl;
	return wrong_argument;
}
int main(int argc, char * argv[]) {
	if (argc == game_file_name + 1 && strcmp(argv[game_file_name], "TicTacToe") == 0) {
		TicTacToe game;
		for (int k = 0; k < 9; k++) { // initialization
			game.arr[k] = ' ';
		}
		return game.play();
	}
	else {
		return usage_message(argv[program_name]);
	}
}


