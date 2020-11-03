#include "ChessMan.h"

void Pawn::init(int x, int y, int Color)
{
	this->x = x;
	this->y = y;
	this->Color = Color;
	isAttack = false;
	isBoard = true;
}

void Pawn::put(char arr[height][width + 1])
{
	if (isBoard)
	{
		if (Color == WHITE)
			arr[y][x] = chess_f[0][Color];
		else if (Color == BLACK)
			arr[y][x] = chess_f[0][Color];
	}
}

void Pawn::getMove(int x_pos, int y_pos, char arr[height][width + 1])
{
	if ((x_pos == x) && (y_pos == y) && (isBoard))
	{
		int x_move, y_move;
		int moves, * p_move = &moves;
		int Enemy_Color, * p_Color = &Enemy_Color;

		MoveFigureInput(x_move, y_move, "Пешка", Color);

		if (Color == WHITE) {
			*p_move = 1;
			*p_Color = BLACK;
		}
		else {
			*p_move = -1;
			*p_Color = WHITE;
		}

		if (((y + moves) == y_move) && (arr[y + moves][x] == ' ') && (x == x_move))
			y = y_move;
		else if (((y + (moves * 2)) == y_move) && (arr[y + moves][x] == ' ') && (arr[y + (moves * 2)][x] == ' ') && ((y == 1) || (y == 6)) && (x == x_move))
			y = y_move;
		else if (((y + moves) == y_move) && (((x - 1) == x_move) || (x + 1) == x_move)) {
			for(int i = 0;i < 5;++i)
				if (arr[y_move][x_move] == chess_f[i][Enemy_Color]) {
					x = x_move;
					y = y_move;
					isAttack = true;
					std::cout << "мы схавали\n";
				}
		}
	}
}

void Rook::init(int x, int y, int Color)
{
	this->x = x;
	this->y = y;
	this->Color = Color;
	isAttack = false;
	isBoard = true;
}

void Rook::put(char arr[height][width + 1])
{
	if (isBoard)
	{
		if (Color == WHITE)
			arr[y][x] = chess_f[1][Color];
		else if (Color == BLACK)
			arr[y][x] = chess_f[1][Color];
	}
}

void Rook::getMove(int x_pos, int y_pos, char arr[height][width + 1])
{
	if ((x_pos == x) && (y_pos == y) && (isBoard))
	{
		int x_move, y_move;
		int Enemy, * p_Color = &Enemy;

		if (Color == WHITE) 
			*p_Color = BLACK;
		else if (Color == BLACK) 
			*p_Color = WHITE;
			
		MoveFigureInput(x_move, y_move, "Ладья", Color);
		if ((x != x_move) && (y == y_move))
			Rook_Move_X(x, y, x_move, y_move, arr, Color, Enemy, isAttack);
		else if ((x == x_move) && (y != y_move))
			Rook_Move_Y(x, y, x_move, y_move, arr, Color, Enemy, isAttack);;
	}
}

void Bishop::init(int x, int y, int Color)
{
	this->x = x;
	this->y = y;
	this->Color = Color;
	isAttack = false;
	isBoard = true;
}

void Bishop::put(char arr[height][width + 1])
{
	if (isBoard)
	{
		if (Color == WHITE)
			arr[y][x] = chess_f[3][Color];
		else if (Color == BLACK)
			arr[y][x] = chess_f[3][Color];
	}
}

void Bishop::getMove(int x_pos, int y_pos, char arr[height][width + 1]) {
	if ((x_pos == x) && (y_pos == y) && (isBoard))
	{
		int x_move, y_move;
		int Enemy, * p_Color = &Enemy;

		if (Color == WHITE)
			*p_Color = BLACK;
		else if (Color == BLACK)
			*p_Color = WHITE;

		MoveFigureInput(x_move, y_move, "Слон", Color);

		if (((x + y) == (x_move + y_move)) || ((x - y) == (x_move - y_move))) 
			Bishop_Move(x, y, x_move, y_move, arr, Color, Enemy, isAttack);
	}
}

void Cavalary::init(int x, int y, int Color)
{
	this->x = x;
	this->y = y;
	this->Color = Color;
	isAttack = false;
	isBoard = true;
}

void Cavalary::put(char arr[height][width + 1])
{
	if (isBoard)
	{
		if (Color == WHITE)
			arr[y][x] = chess_f[2][Color];
		else if (Color == BLACK)
			arr[y][x] = chess_f[2][Color];
	}
}

void Cavalary::getMove(int x_pos, int y_pos, char arr[height][width + 1]) {

}