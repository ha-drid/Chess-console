#pragma once

#ifndef SIZE

/*
* В этом файле будуть фунции и переменые которые не впсисваются в другие файлы,
* это делаеться чтобы не засорять другие файлы и чтобы код не дублировался
*/


#include <conio.h>
#include <iostream>
#include <Windows.h>

//глобалная переменая размер доски и номер цвета фигуры
#define width 8
#define height 8
const int WHITE = 1;
const int BLACK = 2;

//символы фигур
static char chess_f[6][3] = { { ' ','P','p' }, 
						      { ' ','R','r' }, 
							  { ' ','C','c' },
							  { ' ','B','b' },
							  { ' ','Q','q' },
							  { ' ','K','k' } };
//через функцию getch() мы будем узнавать нажатие на кнопки клавиатуры
static void Symbol_Identy(int &x)
{
	switch (x)
	{
	case(97):  std::cout << "a\n" ; x = 0; break;
	case(98):  std::cout << "b\n" ; x = 1; break;
	case(99):  std::cout << "c\n" ; x = 2; break;
	case(100): std::cout << "d\n" ; x = 3; break;
	case(101): std::cout << "e\n" ; x = 4; break;
	case(102): std::cout << "f\n" ; x = 5; break;
	case(103): std::cout << "g\n" ; x = 6; break;
	case(104): std::cout << "h\n" ; x = 7; break;
	}
}

static void Number_Identy(int &y)
{
	switch (y)
	{
	case(49): std::cout << "1\n"; y = 0; break;
	case(50): std::cout << "2\n"; y = 1; break;
	case(51): std::cout << "3\n"; y = 2; break;
	case(52): std::cout << "4\n"; y = 3; break;
	case(53): std::cout << "5\n"; y = 4; break;
	case(54): std::cout << "6\n"; y = 5; break;
	case(55): std::cout << "7\n"; y = 6; break;
	case(56): std::cout << "8\n"; y = 7; break;
	}
}
//покраска доски
static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
static void setColor(int color)
{
	SetConsoleTextAttribute(hConsole, color);
	return;
}

#define SIZE
#endif // !SIZE
