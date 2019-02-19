#pragma once
#include <fstream>
using namespace std;


//int readBoard(ifstream & file, unsigned int & b, unsigned int & c);


//int readPieces(ifstream & file, vector<game_piece> & pieces, unsigned int row, unsigned int col);


int readBoard(ifstream & file, unsigned int & width, unsigned int & height);

//int printBoard(const vector<game_piece> & board, unsigned int a, unsigned int b);
