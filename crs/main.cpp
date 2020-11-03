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
	//system("Color 70");
	//for (int i = 0; i < 500; ++i) {
	//	setColor(i);
	//	std::cout << i << "text  ";
	//}
	try
	{
		while (1) 
		{
			board.init(map);
			board.show(map);
			board.move_figure(map);
			Sleep(1000);
			system("cls");
		}
		std::cout << "s";
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "except" << e.what() << std::endl;
		return -1;
	}
	

	return 0;
}
