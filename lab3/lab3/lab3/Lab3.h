#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//initialize enum's 

enum argument {
	program_name = 0,
	game_file_name = 1,
	expected_num_of_commands = 2
};

enum status {
	success = 0,
	drawgame = 1,
	quit = 2,
	wrong_argument = 3,
	unexpected_extra_ending = 4
};


// initialize functions

string ToLowercase(string& inputString);

int usage_message(string program_name);

