#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//initialize enum's 

enum arrayIndices {
	program_name = 0, input_file_name = 1, expected_num_of_command_line = 2
};

enum status {
	success = 0, 
	fail_to_open_file = 1, 
	wrong_arguments_num = 2, 
	cannot_get_line = 3,
	cannot_get_dimension = 4,
	failed_to_findwell_formed_piece = 5,
	fail_to_print = 6,
	dimension_extraction_failed = 7
};


// initialize functions

string ToLowercase(string& inputString);

int usage_message(string program_name, string command1);

