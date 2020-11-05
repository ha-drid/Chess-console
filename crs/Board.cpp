#include "Board.h"

Board::Board()
{
	f1 = NULL;
	f2 = NULL;
	
	//инитиализация фигур

	/**Белые фигуры**/
	for (int i = 0; i < 8; ++i) {
		pawn[i].init(i, 1, WHITE);
	}
	rook[0].init(0, 0, WHITE);
	rook[1].init(7, 0, WHITE);
	bishop[0].init(2, 0, WHITE);
	bishop[1].init(5, 0, WHITE);
	cavalary[0].init(6, 0, WHITE);
	cavalary[1].init(1, 0, WHITE);
	queen[0].init(4, 0, WHITE);
	king[0].init(3, 0, WHITE);

	/**Черные фигуры**/
	for (int i = 8; i < 16; ++i) {
		pawn[i].init(i % 8, 6, BLACK);
	}
	rook[2].init(0, 7, BLACK);
	rook[3].init(7, 7, BLACK);
	bishop[2].init(2, 7, BLACK);
	bishop[3].init(5, 7, BLACK);
	cavalary[2].init(6, 7, BLACK);
	cavalary[3].init(1, 7, BLACK);
	queen[1].init(4, 7, BLACK);
	king[1].init(3, 7, BLACK);
}


void Board::init(char arr[height][width + 1])
{
	for (int n = 0; n < height; ++n) 
	{
		for (int i = 0; i < width; ++i)
		{
			arr[n][i] = ' ';
		}
	}
	for (int i = 0; i < 8; ++i)
		arr[i][width] = '1' + i;
	
	//вывод фигур
	for (int i = 0; i < 16; ++i)
		pawn[i].put(arr);
	
	for (int i = 0; i < 4; ++i) {
		rook[i].put(arr);
		bishop[i].put(arr);
		cavalary[i].put(arr);
	}

	for (int i = 0; i < 2; ++i) {
		queen[i].put(arr);
		king[i].put(arr);
	}
}

void Board::show(char arr[height][width + 1],int Color)
{
	char S = 'a';
	for (int i = 0; i < 8; ++i) {
		setColor(8);
		std::cout << " " << S << " ";
		S += 1;
	}
	std::cout << std::endl;
	
	if (Color == WHITE) {
		for (int i = height - 1; i >= 0; --i)
		{
			for (int n = 0; n < width; ++n)
			{
				if ((n + i) % 2 == 0) {
					setColor(128);
					std::cout << " " << arr[i][n] << " ";
				}
				else {
					setColor(8);
					std::cout << " " << arr[i][n] << " ";
				}
				if (n == width - 1) {
					setColor(8);
					std::cout << ' ' << arr[i][width] << ' ' << std::endl;
				}
			}
		}
	}
	else if (Color == BLACK)
	{
		for (int i = 0; i < height; ++i)
		{
			for (int n = 0; n < width; ++n)
			{
				if ((n + i) % 2 == 0) {
					setColor(128);
					std::cout << " " << arr[i][n] << " ";
				}
				else {
					setColor(8);
					std::cout << " " << arr[i][n] << " ";
				}
				if (n == width - 1) {
					setColor(8);
					std::cout << ' ' << arr[i][width] << ' ' << std::endl;
				}
			}
		}
	}
	S = 'a';
	for (int i = 0; i < 8; ++i) {
		std::cout << " " << S << " ";
		S += 1;
	}

	std::cout << std::endl;
}



void Board::move_figure(char arr[height][width + 1], int Color)
{
	int x_pos, y_pos;
	char x_symbol = NULL,y_symbol = NULL;

	std::cout << "Ведите х кординаты фигуры: ";
	x_pos = _getch();
	Symbol_Identy(x_pos);

	std::cout << "Ведите y кординаты фигуры: ";
	y_pos = _getch();
	Number_Identy(y_pos);

	//std::cout << x_pos << std::endl;
	//std::cout << y_pos << std::endl;
	if (Color == WHITE) {
		for (int i = 0; i < 8; ++i) {
			pawn[i].getMove(x_pos, y_pos, arr);
		}
		for (int i = 0; i < 2; i++)
		{
			rook[i].getMove(x_pos, y_pos, arr);
			bishop[i].getMove(x_pos, y_pos, arr);
			cavalary[i].getMove(x_pos, y_pos, arr);
		}
		queen[0].getMove(x_pos, y_pos, arr);
		king[0].getMove(x_pos, y_pos, arr);
	}
	else if (Color == BLACK) {
		for (int i = 8; i < 16; ++i) {
			pawn[i].getMove(x_pos % 7, y_pos, arr);
		}
		for (int i = 0; i < 4; i++)
		{
			rook[i].getMove(x_pos, y_pos, arr);
			bishop[i].getMove(x_pos, y_pos, arr);
			cavalary[i].getMove(x_pos, y_pos, arr);
		}
		queen[1].getMove(x_pos, y_pos, arr);
		king[1].getMove(x_pos, y_pos, arr);
	}
	

	for (int i = 0; i < 16; ++i) 
	{
		for (int n = 0; n < 16; ++n)
		{
			figure_colision_check(&pawn[i], &pawn[n]);
			figure_colision_check(&rook[i % 4], &rook[n % 4]);
			figure_colision_check(&bishop[i % 4], &bishop[n % 4]);
			figure_colision_check(&cavalary[i % 4], &cavalary[n % 4]);

			figure_colision_check(&king[i % 2], &pawn[n]);
			figure_colision_check(&rook[i % 4], &pawn[n]);
			figure_colision_check(&bishop[i % 4], &pawn[n]);
			figure_colision_check(&cavalary[i % 4], &pawn[n]);
			figure_colision_check(&queen[i % 2], &pawn[n]);

			figure_colision_check(&rook[i % 4], &bishop[n % 4]);
			figure_colision_check(&rook[i % 4], &cavalary[n % 4]);
			figure_colision_check(&cavalary[i % 4], &bishop[n % 4]);
			figure_colision_check(&queen[i % 2], &bishop[n % 4]);
			figure_colision_check(&queen[i % 2], &rook[n % 4]);
			figure_colision_check(&queen[i % 2], &cavalary[n % 4]);
			figure_colision_check(&king[i % 2], &rook[n % 4]);
			figure_colision_check(&king[i % 2], &bishop[n % 4]);
			figure_colision_check(&king[i % 2], &cavalary[n % 4]);
			figure_colision_check(&king[i % 2], &queen[n % 2]);
		}
	}
	figure_colision_check(&queen[0], &queen[1]);
}

void Board::figure_colision_check(ChessMan* f1, ChessMan* f2)
{
	if ((f1 == 0) || (f2 == 0)) {  }
	else {
		if (f1->Color != f2->Color) 
		{
			if ((f1->x == f2->x) && (f1->y == f2->y))
			{
				if (f1->isAttack)
				{
					f2->isBoard = false;
					f2->x = -1;
					f2->y = -1;
					f1->isAttack = false;
				}
				if (f2->isAttack)
				{
					f1->isBoard = false;
					f1->x = -1;
					f1->y = -1;
					f2->isAttack = false;
				}
			}
		}
	}
}

Board::~Board() {}