#include <iostream>
#include <Windows.h>
#include <stdexcept>

#include "auxiliary.h"
#include "Board.h"
#include "ChessMan.h"

char map[height][width + 1];
Board board;

int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		int n = WHITE;
		while(1)
		{
			if(n == 3)
				n %= 2;
			board.init(map);
			board.show(map, n);
			board.move_figure(map, n);
			Sleep(1000);
			system("cls");
			++n;
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "except" << e.what() << std::endl;
		return -1;
	}
	

	return 0;
}
