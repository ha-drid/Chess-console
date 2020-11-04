#pragma once

#ifndef BOARD

#include <iostream>
#include "auxiliary.h"
#include "ChessMan.h"

class Board
{
public:
	Board();
	void init(char arr[height][width + 1]);					
	void show(char arr[height][width + 1]);					
	void move_figure(char arr[height][width + 1]);
	void figure_colision_check(ChessMan* f1, ChessMan* f2);
	~Board();
private:
	ChessMan* f1, * f2;
	Pawn pawn[16];
	Rook rook[4];
	Bishop bishop[4];
	Cavalary cavalary[4];
	Queen queen[2];
};

#define BOARD
#endif