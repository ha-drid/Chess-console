#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

static void symbol_identy(int& x)
{
	switch (x)
	{
	case(65):
	case(97): 
	case(128):
	case(160):
		std::cout << "A\n"; x = 0; break;
	case(66):
	case(98): 
	case(129):
	case(161):
		std::cout << "B\n"; x = 1; break;
	case(67):
	case(99):
	case(130):
	case(162):
		std::cout << "C\n"; x = 2; break;
	case(68):
	case(100):
	case(131):
	case(163):
		std::cout << "D\n"; x = 3; break;
	case(69):
	case(101):
	case(132):
	case(164):
		std::cout << "E\n"; x = 4; break;
	case(70):
	case(102):
	case(133):
	case(165):
		std::cout << "F\n"; x = 5; break;
	case(71):
	case(103):
	case(134):
	case(166):
		std::cout << "G\n"; x = 6; break; 
	case(72):
	case(104):
	case(135):
	case(167):
		std::cout << "H\n"; x = 7; break;
	}
}

static void number_identy(int& y)
{
	switch (y)
	{
		case(49): 
			std::cout << "1\n" << std::endl; y = 0; break;
		case(50): 
			std::cout << "2\n" << std::endl; y = 1; break;
		case(51): 
			std::cout << "3\n" << std::endl; y = 2; break;
		case(52): 
			std::cout << "4\n" << std::endl; y = 3; break;
		case(53): 
			std::cout << "5\n" << std::endl; y = 4; break;
		case(54): 
			std::cout << "6\n" << std::endl; y = 5; break;
		case(55):
			std::cout << "7\n" << std::endl; y = 6; break;
		case(56):
			std::cout << "8\n" << std::endl; y = 7; break;
	}
}

static void move_figure_input(int& x, int& y,std::string name_figure)
{
	std::cout << "Теперь под вашим контролем " << name_figure << std::endl;

	std::cout << "Ведите x кординату:";
	x = _getch();
	symbol_identy(x);

	std::cout << "Ведите y кординату:";
	y = _getch();
	number_identy(y);
}
