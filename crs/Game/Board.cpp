#include "Board.h"
#include "Color.h"
#include "../printer.h"

Board::Board()
{
	
}

void Board::init()
{
	for (int i = 0; i < Height_Map; ++i) {
		for (int n = 0; n < Width_Map; ++n) {
			map[i][n] = cell.put();
		}
	}
	for (int i = 0; i < Width_Map; ++i)
		map[1][i] = pawn.put(White);

	map[0][7] = rook.put(White);
	map[0][6] = cavalary.put(White);
	map[0][5] = bishop.put(White);
	map[0][4] = queen.put(White);
	map[0][3] = king.put(White);
	map[0][2] = bishop.put(White);
	map[0][1] = cavalary.put(White);
	map[0][0] = rook.put(White);

	for (int i = 0; i < Width_Map; ++i)
		map[6][i] = pawn.put(Black);

	map[7][7] = rook.put(Black);
	map[7][6] = cavalary.put(Black);
	map[7][5] = bishop.put(Black);
	map[7][4] = queen.put(Black);
	map[7][3] = king.put(Black);
	map[7][2] = bishop.put(Black);
	map[7][1] = cavalary.put(Black);
	map[7][0] = rook.put(Black);
}

void Board::show(int color)
{
	//эта операци€ выводит буквы
	char alfabet = 'A';
	std::cout << "   ";
	for (int i = 1; i <= 8; ++i) {
		std::cout << " " << alfabet << " ";
		alfabet += 1;
	}

	std::cout << std::endl;
	if (color == White) {
		for (int i = Height_Map - 1; i >= 0; --i)
		{
			std::cout << " " << i + 1 << " ";
			for (int n = 0; n < Width_Map; ++n)
			{
				if ((i + n) % 2 == 0) {
					fillColor(39);
					std::wcout << L" " << map[i][n] << L" ";
				}
				else
				{
					fillColor(55);
					std::wcout << L" " << map[i][n] << L" ";
				}
				if (n == Width_Map - 1) {
					fillColor(7);
					std::wcout << L" " << i + 1 << "\n";
				}
			}
		}
	}
	else if (color == Black) {
		for (int i = 0; i < Height_Map; ++i)
		{
			std::cout << " " << i + 1 << " ";
			for (int n = 0; n < Width_Map; ++n)
			{
				if ((i + n) % 2 == 0) {
					fillColor(39);
					std::wcout << L" " << map[i][n] << L" ";
				}
				else
				{
					fillColor(55);
					std::wcout << L" " << map[i][n] << L" ";
				}
				if (n == Width_Map - 1) {
					fillColor(7);
					std::wcout << L" " << i + 1 << "\n";
				}
			}
		}
	}
	
	fillColor(7);
	//эта операци€ выводит буквы
	alfabet = 'A';
	std::cout << "   ";
	for (int i = 1; i <= 8; ++i) {
		std::cout << " " << alfabet << " ";
		alfabet += 1;
	}
	std::cout << std::endl;
}

void Board::get_moves_chessman(int color)
{
	int x_pos, y_pos;

	std::cout << "¬едите х кординату: ";
	x_pos = _getch();
	symbol_identy(x_pos);

	std::cout << "¬едите у кординату: ";
	y_pos = _getch();
	number_identy(y_pos);

	if (color == White) {
		chessman_move(White, x_pos, y_pos, "пешка", &pawn);
		chessman_move(White, x_pos, y_pos, "кароль", &king);
		chessman_move(White, x_pos, y_pos, "ладь€", &rook);
		chessman_move(White, x_pos, y_pos, "слон", &bishop);
		chessman_move(White, x_pos, y_pos, "кавалери€", &cavalary);
		chessman_move(White, x_pos, y_pos, "каралева", &queen);
	}
	else if (color == Black) {
		chessman_move(Black, x_pos, y_pos, "пешка", &pawn);
		chessman_move(Black, x_pos, y_pos, "кароль", &king);
		chessman_move(Black, x_pos, y_pos, "ладь€", &rook);
		chessman_move(Black, x_pos, y_pos, "слон", &bishop);
		chessman_move(Black, x_pos, y_pos, "кавалери€", &cavalary);
		chessman_move(Black, x_pos, y_pos, "каралева", &queen);
	}
}
//ƒвижени€ фигуры.„тобы код не дублировалс€
void Board::chessman_move(int color, int x_pos, int y_pos, std::string name_figure, ChessMan* f)
{
	if (f == NULL) {
		std::cout << "ќшибка нет такой фигуры\n";
	}
	else {
		if (chessman_is_cell(x_pos, y_pos, map) == f->put(color)) {
			int x_move, y_move;

			move_figure_input(x_move, y_move, name_figure);
			std::string moves;
			moves = f->get_moves(x_pos, y_pos, x_move, y_move, map);
			if (moves == "yes") {
				map[y_move][x_move] = cell.put();
				map[y_move][x_move] = f->put(color);
				map[y_pos][x_pos] = cell.put();
			}
			else if (moves == "no") {
				chessman_move(color, x_pos, y_pos, name_figure, f);
			}
		}
	}
}

Board::~Board()
{

}