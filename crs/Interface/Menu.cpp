#include "Menu.h"

Menu::Menu()
{
	std::cout << "Привет дорогой игрок добро пожаловать в игру\n";
}

int Menu::show()
{
	int i;
	std::cout << "Хочешь за белых играть тогда веди цифру 1 или 2 если хочешь за черную \n";
	std::cout << "Выбери сторону ;";

	std::cin >> i;

	return i % 3;
}

Menu::~Menu()
{
}
