#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//define the class TicTacToe

class TicTacToe {  // game class
	friend void operator<<(ostream &, const TicTacToe &);
private:
	char player; // X or O
	vector<int> move; // move made by each player
public:
	bool done();
	bool draw();
	int prompt(unsigned int &, unsigned int &);
	int turn();
	int play();
	char arr[9];
};
