#include "Menu.h"

Menu::Menu()
{
	std::cout << "������ ������� ����� ����� ���������� � ����\n";
}

int Menu::show()
{
	int i;
	std::cout << "������ �� ����� ������ ����� ���� ����� 1 ��� 2 ���� ������ �� ������ \n";
	std::cout << "������ ������� ;";

	std::cin >> i;

	return i % 3;
}

Menu::~Menu()
{
}
