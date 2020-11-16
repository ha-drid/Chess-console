#pragma once
#include <iostream>
#include <memory>

#include "Cell.h"
#include "ChessMan.h"
#include "../size.h"

class Board 
{
public:
	Board();
	void init();
	void show(int color);
	void get_moves_chessman(int color);
	void chessman_move(int color, int x_pos, int y_pos, std::string name_figure, ChessMan* f = NULL);
	~Board();
private:
	wchar_t map[Height_Map][Width_Map];
	Cell cell;
	ChessPawn pawn;
	ChessKing king;
	ChessRook rook;
	ChessBishop bishop;
	ChessCavalary cavalary;
	ChessQueen queen;
};