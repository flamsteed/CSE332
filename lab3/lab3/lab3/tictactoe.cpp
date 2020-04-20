#include "stdafx.h"
#include "lab3.h"
#include "tictactoe.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
void operator<<(ostream & ss, const TicTacToe & c){
	ss << "4" << endl;
	ss << "3 " << c.arr[6] << c.arr[7] << c.arr[8] << endl;
	ss << "2 " << c.arr[3] << c.arr[4] << c.arr[5] << endl;
	ss << "1 " << c.arr[0] << c.arr[1] << c.arr[2] << endl;
	ss << "0" << endl;
	ss << " 01234" << endl;
}

/*
0 1 2
3 4 5
6 7 8
*/
bool TicTacToe::done() {
	if ((arr[0] == player) && (arr[0] == arr[3]) && (arr[0] == arr[6])) return true;//col1
	if ((arr[1] == player) && (arr[1] == arr[4]) && (arr[1] == arr[7])) return true;//col2
	if ((arr[2] == player) && (arr[2] == arr[5]) && (arr[2] == arr[8])) return true;//col3
	if ((arr[0] == player) && (arr[0] == arr[1]) && (arr[0] == arr[2])) return true;//row1
	if ((arr[3] == player) && (arr[3] == arr[4]) && (arr[3] == arr[5])) return true;//row2
	if ((arr[6] == player) && (arr[6] == arr[7]) && (arr[6] == arr[8])) return true;//row3
	if ((arr[0] == player) && (arr[0] == arr[4]) && (arr[0] == arr[8])) return true;//dia1
	if ((arr[2] == player) && (arr[2] == arr[4]) && (arr[2] == arr[6])) return true;//dia2
	return false;
}

bool TicTacToe::draw() {
	if (done())
	{
		return false;
	}
	for (int k = 0; k <= 8; k++) {
		if (arr[k] == ' ') {
			return false; // still have empty place to play, not a draw yet
		}
	}
	return true;
}

int TicTacToe::prompt(unsigned int &column, unsigned int &row) {
	cout << "Please enter 'quit' to quit the game or enter a valid coordinate to do the move" << endl;
	string coordinate;
	cin >> coordinate;
	if (coordinate == "quit") {
		return quit;
	}
	else {
		istringstream iss(coordinate);
		if (iss >> column) {
			if (column >= 1 && column <= 3) {// within range
				char c;
				if (iss >> c&&c == ',') { // a comma in the middle
					if (iss >> row) {
						if (row >= 1 && row <= 3) {
							if (arr[3 * row + column - 4] == ' ') { // empty location
								arr[3 * row + column - 4] = player;
								move.push_back(3 * row + column - 4); // store the location
								return success;
							}
						}
					}
				}
			}
		}
		cout << "Invalid input" << endl;
		return prompt(column, row);// input again 
	}
}

int TicTacToe::turn() {
	cout << "Player" << player << "'s turn:" << endl;
	unsigned int column, row;
	int l = prompt(column, row);
	if (l == quit) {
		return quit;
	}
	else if (l == success) {
		cout << *this;
	}
	cout << endl;
	if (player == 'X') {
		cout << "Player X: ";
		for (unsigned int i = 0; i < move.size(); i += 2) {
			cout << move[i] % 3 + 1 << "," << move[i] / 3 + 1 << "; "; // print the move made by X
		}
		cout << endl;
	}
	if (player == 'O') {
		cout << "Player O: ";
		for (unsigned int i = 1; i < move.size(); i += 2) {
			cout << move[i] % 3 + 1 << "," << move[i] / 3 + 1 << "; "; // print the move made by O
		}
		cout << endl;
	}
	return success;
}

int TicTacToe::play() {
	cout << *this;
	this->player = 'O';
	while (this->done() == false && this->draw() == false) {
		player = 'X' + 'O' - player; //Change turn
		int p = this->turn();
		if (p == quit) {
			cout << "Player " << this->player << " quitted the game." << endl;
			return p;
		}
	}
	if (this->done() == true) {
		cout << "Player " << this->player << " won the game." << endl;
		return success;
	}
	if (this->draw() == true) {
		cout << move.size() << " turns played; the game comes to a draw." << endl;
		return drawgame;
	}
	return unexpected_extra_ending;
}
