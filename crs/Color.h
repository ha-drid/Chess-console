#pragma once

static const int Empty = 0;
static const int White = 1;
static const int Black = 2;

static wchar_t chessman_is_cell(int x, int y, std::vector<std::vector<wchar_t>> arr)
{
	return arr[y][x];
}


static int get_color(int x, int y, std::vector<std::vector<wchar_t>> arr)
{
	if ((chessman_is_cell(x, y, arr) == L'P') ||
		(chessman_is_cell(x, y, arr) == L'R') ||
		(chessman_is_cell(x, y, arr) == L'K') ||
		(chessman_is_cell(x, y, arr) == L'B') ||
		(chessman_is_cell(x, y, arr) == L'Q') ||
		(chessman_is_cell(x, y, arr) == L'C')) {
		return White;
	}
	else if ((chessman_is_cell(x, y, arr) == L'p') ||
		(chessman_is_cell(x, y, arr) == L'r') ||
		(chessman_is_cell(x, y, arr) == L'k') ||
		(chessman_is_cell(x, y, arr) == L'b') ||
		(chessman_is_cell(x, y, arr) == L'q') ||
		(chessman_is_cell(x, y, arr) == L'c')) {
		return Black;
	}
	else 
		return Empty;
}