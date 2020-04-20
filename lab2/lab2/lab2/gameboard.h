#pragma once

#include "gamepiece.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int readDimensions(ifstream & fileName, unsigned int& row, unsigned int& col);
int readGamePieces(ifstream & fileName, vector<game_piece> & vector, unsigned int h, unsigned int w);
int printPiecesOnBoard(const vector<game_piece>& vector, unsigned int h, unsigned int w);   // print the board
int printNearbyPieceOnBoard(const vector<game_piece>& vector, unsigned int h, unsigned int w); // extra credit
void printnearby(const vector<game_piece>& vector, unsigned int i, unsigned int j, unsigned int h, unsigned int w);