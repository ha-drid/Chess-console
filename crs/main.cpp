#include <iostream>
#include <Windows.h>
#include <stdexcept>
#include <memory>

#include "Game/Color.h"
#include "Game/Board.h"

#include "Interface/Menu.h"

int main()
{
	//for (int i = 0; i < 200; ++i) {
	//	fillColor(i);
	//	std::cout << i << "qwerty";
	//}
	//fillColor(7);
	//std::cout << std::endl;
	try
	{
		setlocale(LC_ALL, "ru");
		Board board;
		Menu m;
		board.init();
		int i = m.show();
		int* p_i = &i;
		system("cls");
		do
		{
			if (i == 3)
				*p_i %= 2;
			board.show(i);
			board.get_moves_chessman(i);
			++i;
		}while (GetKeyState(VK_ESCAPE) >= 0);//для GetKeyState нужен файл Window.h

	}
	catch (const std::runtime_error& e)//для runtime_error нужен файл stdexcept
	{
		std::cout << "Except" << e.what() << std::endl;
		return -1;
	}
	return 0;
}