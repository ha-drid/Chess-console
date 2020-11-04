#pragma once

/*
* Этот загаловочный файл я создаю в целях читабелности кода и сокрашения строк кода на файле ChessMan.cpp .
* Здесь будут функции для джижения фигур по доске.
*/

#ifndef MOVE_FIGURE_METHOD

#include "auxiliary.h"

//эта функция запрашивает пользователя куда нужно ходить
static void MoveFigureInput(int& x_move, int& y_move, std::string figure_name, int Color)
{
	std::cout << "Под вашим контролем " << figure_name << std::endl;

	std::cout << "Ведите кординаты по x: ";
	x_move = _getch();
	Symbol_Identy(x_move);

	if ((x_move > -1) && (x_move < 8)) {
		std::cout << "Ведите кординаты по y: ";
		y_move = _getch();
		Number_Identy(y_move);
		if ((y_move > -1) && (y_move < 8)) {
			
		}
		else {
			std::cout << "Вы неправильно вели кординаты\n";
		}
	}
	else {
		std::cout << "Вы неправильно вели кординаты\n";
	}
}

static void Rook_Move_X(int& x, int& y, int x_move, int y_move, char arr[height][width + 1], int Color, int Enemy, bool& isAttack) {
	int iX = x;
	int min, max, cnt;
	int* p_min = &min, * p_max = &max, * p_cnt = &cnt;

	if (x < x_move) {
		*p_max = x_move;
		*p_min = x;
		*p_cnt = 1;
	}
	else if (x > x_move) {
		*p_max = x;
		*p_min = x_move;
		*p_cnt = -1;
	}
	int i = x + cnt;
	while (min <= i <= max)
	{
		if ((arr[y][x_move] == ' ') ||
		(arr[y][x_move] == chess_f[0][Enemy]) ||
		(arr[y][x_move] == chess_f[1][Enemy]) ||
		(arr[y][x_move] == chess_f[2][Enemy]) ||
		(arr[y][x_move] == chess_f[3][Enemy]) ||
		(arr[y][x_move] == chess_f[4][Enemy])) 
		{
			if (arr[y][i] == ' ') {
				if (i == x_move) {
					x = i;
					break;
				}
			}
			else if ((i == x) && (arr[y][i] == chess_f[1][Color])) 
				continue;
			else if ((i != x) && (i == x_move) &&
				((arr[y][i] == chess_f[0][Enemy]) ||
					(arr[y][i] == chess_f[1][Enemy]) ||
					(arr[y][i] == chess_f[2][Enemy]) ||
					(arr[y][i] == chess_f[3][Enemy]) ||
					(arr[y][i] == chess_f[4][Enemy]))) {
				isAttack = true;
				x = i;
				break;
			}
			else { std::cout << "Хренос два!!!\n"; x = iX; break; }
		}
		else {
			x = iX;
			std::cout << "Хренос два!!!\n";
			break;
		}
		i += cnt;
	}
}

static void Rook_Move_Y(int& x, int& y, int x_move, int y_move, char arr[height][width + 1], int Color, int Enemy, bool& isAttack) {
	int iY = y;
	int min, max, cnt;
	int* p_min = &min, * p_max = &max, * p_cnt = &cnt;

	if (y < y_move) {
		*p_max = y_move;
		*p_min = y;
		*p_cnt = 1;
	}
	else if (y > y_move) {
		*p_max = y;
		*p_min = y_move;
		*p_cnt = -1;
	}
	int i = y + cnt;
	while (min <= i <= max)
	{
		if ((arr[y_move][x] == ' ') ||
		(arr[y_move][x] == chess_f[0][Enemy]) ||
		(arr[y_move][x] == chess_f[1][Enemy]) ||
		(arr[y_move][x] == chess_f[2][Enemy]) ||
		(arr[y_move][x] == chess_f[3][Enemy]) ||
		(arr[y_move][x] == chess_f[4][Enemy]))
		{
			if (arr[i][x] == ' ') {
				if (i == y_move) {
					y = i;
					break;
				}
			}
			else if ((i == y) && (arr[i][y] == chess_f[1][Color])) 
				continue;
			else if ((i != y) && (i == y_move) &&
				((arr[i][x] == chess_f[0][Enemy]) ||
					(arr[i][x] == chess_f[1][Enemy]) ||
					(arr[i][x] == chess_f[2][Enemy]) ||
					(arr[i][x] == chess_f[3][Enemy]) ||
					(arr[i][x] == chess_f[4][Enemy]))) {
				isAttack = true;
				y = i;
				break;
			}
			else { std::cout << "Хренос два!!!\n"; y = iY; break; }
		}
		else {
			y = iY;
			std::cout << "Хренос два!!!\n";
			break;
		}
		i += cnt;
	}
}

static void Bishop_Move(int& x, int& y, int x_move, int y_move, char arr[height][width + 1], int Color, int Enemy, bool& isAttack)
{
	int iX = x, iY = y;
	int yCnt, xCnt;
	int yMin, xMin, yMax, xMax;

	int* p_yCnt = &yCnt, * p_xCnt = &xCnt;
	int* p_yMin = &yMin, * p_xMin = &xMin;
	int* p_yMax = &yMax, * p_xMax = &xMax;

	if ((x < x_move) && (y > y_move)) {
		*p_xMin = x;
		*p_xMax = x_move;
		*p_xCnt = 1;
		*p_yMin = y_move;
		*p_yMax = y;
		*p_yCnt = -1;
	}
	else if ((x > x_move) && (y < y_move)) {
		*p_xMin = x_move;
		*p_xMax = x;
		*p_xCnt = -1;
		*p_yMin = y;
		*p_yMax = y_move;
		*p_yCnt = 1;
	}
	else if ((x < x_move) && (y < y_move)) {
		*p_xMin = x;
		*p_xMax = x_move;
		*p_xCnt = 1;
		*p_yMin = y;
		*p_yMax = y_move;
		*p_yCnt = 1;
	}
	else if ((x > x_move) && (y > y_move)) {
		*p_xMin = x_move;
		*p_xMax = x;
		*p_xCnt = -1;
		*p_yMin = y_move;
		*p_yMax = y;
		*p_yCnt = -1;
	}

	int i = y + yCnt;
	int n = x + xCnt;

	while ((xMin <= n <= xMax) && (yMin <= i <= yMax))
	{
		if ((arr[y_move][x_move] == ' ') ||
			(arr[y_move][x_move] == chess_f[0][Enemy]) ||
			(arr[y_move][x_move] == chess_f[1][Enemy]) ||
			(arr[y_move][x_move] == chess_f[2][Enemy]) ||
			(arr[y_move][x_move] == chess_f[3][Enemy]) ||
			(arr[y_move][x_move] == chess_f[4][Enemy]))
		{
			if (arr[i][n] == ' ') {
				if ((i == y_move) && (n == x_move)) {
					y = i;
					x = n;
					break;
				}
			}
			else if ((i == y) && (n == x) && (arr[i][n] == chess_f[3][Color])) {
				continue;
			}
			else if ((i != y) && (i == y_move) && (n != x) && (n == x_move) &&
					((arr[i][n] == chess_f[0][Enemy]) ||
					(arr[i][n] == chess_f[1][Enemy]) ||
					(arr[i][n] == chess_f[2][Enemy]) ||
					(arr[i][n] == chess_f[3][Enemy]) ||
					(arr[i][n] == chess_f[4][Enemy]))) {
				isAttack = true;
				y = i;
				x = n;
				break;
			}
			else {
				y = iY;
				x = iX;
				std::cout << "Ты че д%*#л №2!!!\n";
				break;
			}
		}
		else {
			y = iY;
			x = iX;
			std::cout << "Ты че д%*#л №1!!!\n";
			break;
		}
		n += xCnt;
		i += yCnt;
	}
}
#define MOVE_FIGURE_METHOD
#endif // !MOVE_FIGURE_METHOD//
