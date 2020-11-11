#include <iostream>
#include <Windows.h>
#include <stdexcept>

#include "Board.h"
int main()
{
	try
	{
		setlocale(0, "ru");
		Board board;
		board.init();
		do
		{
			board.show();
			board.get_moves_chessman();
		}while (GetKeyState(VK_ESCAPE) >= 0);//для GetKeyState нужен файл Window.h

	}
	catch (const std::runtime_error& e)//для runtime_error нужен файл stdexcept
	{
		std::cout << "Except" << e.what() << std::endl;
		return -1;
	}
	return 0;
}