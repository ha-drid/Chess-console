#pragma once
#include <iostream>

#include "Cell.h"
#include "ChessMan.h"

static const int width_map = 8;
static const int height_map = 8;

class Board 
{
public:
	Board();
	void init();
	void show();
	wchar_t get_chessman(int x, int y);
	void get_moves_chessman();
	~Board();
private:
	std::vector<std::vector<wchar_t>> map;
	Cell cell;
	ChessPawn pawn;
	ChessKing king;
	ChessRook rook;
};