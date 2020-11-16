#pragma once
#include <Windows.h>

#include "../size.h"

static const int Empty = 0;
static const int White = 1;
static const int Black = 2;

static wchar_t chessman_is_cell(int x, int y, wchar_t arr[Height_Map][Width_Map])
{
	return arr[y][x];
}

static int get_color(int x, int y, wchar_t arr[Height_Map][Width_Map])
{
	std::shared_ptr<int> p_color(new int());

	if ((chessman_is_cell(x, y, arr) == L'P') ||
		(chessman_is_cell(x, y, arr) == L'R') ||
		(chessman_is_cell(x, y, arr) == L'K') ||
		(chessman_is_cell(x, y, arr) == L'B') ||
		(chessman_is_cell(x, y, arr) == L'Q') ||
		(chessman_is_cell(x, y, arr) == L'C')) {
		*p_color = White;
	}
	else if ((chessman_is_cell(x, y, arr) == L'p') ||
		(chessman_is_cell(x, y, arr) == L'r') ||
		(chessman_is_cell(x, y, arr) == L'k') ||
		(chessman_is_cell(x, y, arr) == L'b') ||
		(chessman_is_cell(x, y, arr) == L'q') ||
		(chessman_is_cell(x, y, arr) == L'c')) {
		*p_color = Black;
	}
	else if(chessman_is_cell(x,y,arr) == ' ')
		*p_color = Empty;

	return *p_color;
}

//для покраски текста
static HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
static void fillColor(int fillcolor)
{
	SetConsoleTextAttribute(hwnd, fillcolor);
}