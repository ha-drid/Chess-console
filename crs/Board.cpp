#include "Board.h"
#include "Color.h"
#include "printer.h"

Board::Board()
{
	map.resize(height_map);
	for (int i = 0; i < height_map; ++i)
	{
		map[i].resize(width_map);
	}
}

void Board::init()
{
	for (int i = 0; i < height_map; ++i) {
		for (int n = 0; n < width_map; ++n) {
			map[i][n] = cell.put();
		}
	}
	map[0][7] = rook.put(White);
	map[1][2] = pawn.put(White);
	map[1][3] = pawn.put(White);
	map[1][4] = pawn.put(White);
	map[0][3] = king.put(White);
	map[0][0] = rook.put(White);

	map[7][7] = rook.put(Black);
	map[6][2] = pawn.put(Black);
	map[6][3] = pawn.put(Black);
	map[6][4] = pawn.put(Black);
	map[7][3] = king.put(Black);
	map[7][0] = rook.put(Black);
}

void Board::show()
{
	//эта операция выводит буквы
	char alfabet = 'A';					
	std::cout << ' ';					
	for (int i = 1; i <= 8; ++i) {		
		std::cout << alfabet;	
		alfabet += 1;					
	}

	std::cout << std::endl;
	for (int i = 0; i < height_map; ++i) 
	{
		std::cout << i + 1;
		for (int n = 0; n < width_map; ++n) 
		{
			std::wcout << map[i][n];
			if (n == width_map - 1)
				std::wcout << i + 1<< "\n";
		}
	}
	//эта операция выводит буквы
	alfabet = 'A';
	std::cout << ' ';
	for (int i = 1; i <= 8; ++i) {
		std::cout << alfabet;
		alfabet += 1;
	}
	std::cout << std::endl;
}

void Board::get_moves_chessman()
{
	int x_pos, y_pos;
	std::cout << "Ведите x кординату:";
	x_pos = _getch();
	symbol_identy(x_pos);

	std::cout << "Ведите y кординату:";
	y_pos = _getch();
	number_identy(y_pos);


	if ((chessman_is_cell(x_pos, y_pos, map) == L'P') || (chessman_is_cell(x_pos, y_pos, map) == L'p')) {
		int x_move, y_move;

		move_figure_input(x_move, y_move, " пешка");
		std::string moves;
		moves = pawn.get_moves(x_pos, y_pos, x_move, y_move, map);
		if (moves == "yes") {
			map[y_move][x_move] = cell.put();
			map[y_move][x_move] = pawn.put(get_color(x_pos, y_pos, map));
			map[y_pos][x_pos] = cell.put();
		}
	}
	else if ((chessman_is_cell(x_pos, y_pos, map) == L'K') || (chessman_is_cell(x_pos, y_pos, map) == L'k')) {
		int x_move, y_move;

		move_figure_input(x_move, y_move, " кароль");
		std::string moves = "no";
		moves = king.get_moves(x_pos, y_pos, x_move, y_move, map);
		if (moves == "yes") {
			map[y_move][x_move] = cell.put();
			map[y_move][x_move] = king.put(get_color(x_pos, y_pos, map));
			map[y_pos][x_pos] = cell.put();
		}
	}
	else if ((chessman_is_cell(x_pos, y_pos, map) == L'R') || (chessman_is_cell(x_pos, y_pos, map) == L'r')) {
		int x_move, y_move;

		move_figure_input(x_move, y_move, " ладья");
		std::string moves = "no";
		moves = rook.get_moves(x_pos, y_pos, x_move, y_move, map);
		if (moves == "yes") {
			map[y_move][x_move] = cell.put();
			map[y_move][x_move] = rook.put(get_color(x_pos, y_pos, map));
			map[y_pos][x_pos] = cell.put();
		}
	}
	else
		std::cout << "Error input\n";

}

Board::~Board()
{

}