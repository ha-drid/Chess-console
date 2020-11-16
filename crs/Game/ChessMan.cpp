#include "ChessMan.h"
#include "Color.h"
#include "../size.h"

wchar_t ChessPawn::put(int color)
{
	if (color == 1)
		return L'P';
	else if (color == 2)
		return L'p';
	else
		return L'~';
}

std::string ChessPawn::get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map])
{
	int cnt, * p_cnt = &cnt;
	int self_color = get_color(x_pos, y_pos, arr);//свой цвет
	std::shared_ptr<int> p_EnemyColor(new int());
	std::shared_ptr<int> p_iy_pos(new int ()); //»значальна€ позици€. Ёто делаетс€ дл€ того чтобы пешка могла ходить свой первый ход в две клетки

	if (self_color == White) {
		*p_cnt = 1;
		*p_iy_pos = 1;
		*p_EnemyColor = Black;
	}
	else if (self_color == Black) {
		*p_cnt = -1;
		*p_iy_pos = 6;
		*p_EnemyColor = White;
	}
	
	//если мы правильно ведем позици€ куда нужно идти то возвратитьс€ "Yes", а иначе "No"
	if ((y_pos + cnt == y_move) && (x_pos == x_move) && (get_color(x_move, y_move, arr) == Empty))
		return "yes";
	else if ((y_pos + (cnt * 2) == y_move) && (x_pos == x_move) && (get_color(x_move, y_move, arr) == Empty) && (get_color(x_move, y_pos + cnt, arr) == Empty) && (y_pos == *p_iy_pos))
		return "yes";
	else if ((y_pos + cnt == y_move) && ((x_pos - 1== x_move) || (x_pos + 1 == x_move)) && (get_color(x_move, y_move, arr) == *p_EnemyColor))
		return "yes";
	else
		return "no";
}

wchar_t ChessKing::put(int color)
{
	if (color == 1)
		return L'K';
	else if (color == 2)
		return L'k';
	else
		return L'~';
}

std::string ChessKing::get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map])
{
	int self_color = get_color(x_pos, y_pos, arr);//свой цвет
	std::shared_ptr<int> p_EnemyColor(new int()); //цвет вражеской армии
	//здесь мы должны инитиализировать переменые если какого они цвета 
	if (self_color == White) {
		*p_EnemyColor = Black;
	}
	else if (self_color == Black) {
		*p_EnemyColor = White;
	}
	
	if (((x_pos == x_move) || (x_pos + 1 == x_move) || (x_pos - 1 == x_move)) &&
		((y_pos == y_move) || (y_pos + 1 == y_move) || (y_pos - 1 == y_move)) &&
		((get_color(x_move, y_move, arr) == Empty) || (get_color(x_move, y_move, arr) == *p_EnemyColor))) {
		return "yes";
	}
	else
		return "no";
}

wchar_t ChessRook::put(int color)
{
	if (color == 1)
		return L'R';
	else if (color == 2)
		return L'r';
	else
		return L'~';
}

std::string ChessRook::get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map])
{
	int self_color = get_color(x_pos, y_pos, arr);//свой цвет
	std::shared_ptr<int> p_EnemyColor(new int());
	std::shared_ptr<int> p_Cnt(new int());
	std::shared_ptr<int> p_iY(new int());
	std::shared_ptr<int> p_iX(new int());
	std::shared_ptr<int> p_Pos(new int());
	std::shared_ptr<int> p_Min(new int());
	std::shared_ptr<int> p_Max(new int());
	std::shared_ptr<int> p_I(new int());
	std::shared_ptr<std::string> p_Succes(new std::string("no"));

	//здесь мы должны инитиализировать переменые если какого они цвета 
	if (self_color == White) {
		*p_EnemyColor = Black;
	}
	else if (self_color == Black) {
		*p_EnemyColor = White;
	}
	if ((x_pos != x_move) && (y_pos == y_move)) {//движени€ по оси ’ 
		//узнаем кака€ перемена€ больше или меньше
		if (x_pos < x_move) {
			*p_Cnt = 1;
			*p_Min = x_pos;
			*p_Max = x_move;
		}
		else if (x_pos > x_move) {
			*p_Cnt = -1;
			*p_Min = x_move;
			*p_Max = x_pos;
		}
		*p_I = x_pos - *p_Cnt;
		*p_iX = x_pos - *p_Cnt;
		*p_iY = y_move;
		*p_Pos = x_move;
	}
	else if ((x_pos == x_move) && (y_pos != y_move)) {//движени€ по оси ”
		//узнаем кака€ перемена€ больше или меньше
		if (y_pos < y_move) {
			*p_Cnt = 1;
			*p_Min = y_pos;
			*p_Max = y_move;
		}
		else if (y_pos > y_move) {
			*p_Cnt = -1;
			*p_Min = y_move;
			*p_Max = y_pos;
		}
		*p_I = y_pos + *p_Cnt;
		*p_iY = y_pos + *p_Cnt;
		*p_iX = x_move;
		*p_Pos = y_move;
	}
	if ((get_color(x_pos, y_move, arr) == Empty) || (get_color(x_pos, y_move, arr) == *p_EnemyColor))
		while (*p_Min <= *p_I <= *p_Max)
		{
			if (*p_I == *p_Pos) {
				*p_Succes = "yes";
				break;
			}

			if (get_color(*p_iX, *p_iY, arr) == Empty)
				*p_I += *p_Cnt;
			else
				break;

		}
	else if (get_color(x_move, y_move, arr) == self_color)
		std::cout << "бей своих чтобы чужие бо€лись\n\n";
	return *p_Succes; //если p_succes равен "yes" то возвратиьс€ "yes"
}

wchar_t ChessBishop::put(int color)
{
	if (color == 1)
		return L'B';
	else if (color == 2)
		return L'b';
	else
		return L'~';
}

std::string ChessBishop::get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map])
{
	int self_color = get_color(x_pos, y_pos, arr);//свой цвет
	std::shared_ptr<int> p_EnemyColor(new int());
	std::shared_ptr<int> p_yCnt(new int());
	std::shared_ptr<int> p_xCnt(new int());
	std::shared_ptr<int> p_iY(new int());
	std::shared_ptr<int> p_iX(new int());
	std::shared_ptr<int> p_yMin(new int());
	std::shared_ptr<int> p_xMin(new int());
	std::shared_ptr<int> p_yMax(new int());
	std::shared_ptr<int> p_xMax(new int());
	std::shared_ptr<std::string> p_Succes(new std::string("no"));
	//здесь мы должны инитиализировать переменые если какого они цвета 
	if (self_color == White) {
		*p_EnemyColor = Black;
	}
	else if (self_color == Black) {
		*p_EnemyColor = White;
	}
	
	if ((x_pos + y_pos) == (x_move + y_move)) {
		if ((x_pos < x_move) && (y_pos > y_move)) {
			*p_xMin = x_pos;
			*p_xMax = x_move;
			*p_xCnt = 1;
			*p_yMin = y_move;
			*p_yMax = y_pos;
			*p_yCnt = -1;
		}
		else if ((x_pos > x_move) && (y_pos < y_move)) {
			*p_xMin = x_move;
			*p_xMax = x_pos;
			*p_xCnt = -1;
			*p_yMin = y_pos;
			*p_yMax = y_move;
			*p_yCnt = 1;
		}
	}
	else if ((x_pos - y_pos) == (x_move - y_move)) {
		if ((x_pos < x_move) && (y_pos < y_move)) {
			*p_xMin = x_pos;
			*p_xMax = x_move;
			*p_xCnt = 1;
			*p_yMin = y_pos;
			*p_yMax = y_move;
			*p_yCnt = 1;
		}
		else if ((x_pos > x_move) && (y_pos > y_move)) {
			*p_xMin = x_move;
			*p_xMax = x_pos;
			*p_xCnt = -1;
			*p_yMin = y_move;
			*p_yMax = y_pos;
			*p_yCnt = -1;
		}
	}
	
	if ((get_color(x_move, y_move, arr) == Empty) || (get_color(x_move, y_move, arr) == *p_EnemyColor))
	{
		int iY = y_pos + *p_yCnt;
		int iX = x_pos + *p_xCnt;
		while ((*p_xMin <= iX <= *p_xMax) && (*p_yMin <= iY <= *p_yMax))
		{
			if ((iX == x_move) && (iY == y_move))
				*p_Succes = "yes";

			if (get_color(iX, iY, arr) == Empty) {
				iY += *p_yCnt;
				iX += *p_xCnt;
			}
			else
				break;
		}
	}
	return *p_Succes;
}

wchar_t ChessCavalary::put(int color)
{
	if (color == 1)
		return L'C';
	else if (color == 2)
		return L'c';
	else
		return L'~';
}

std::string ChessCavalary::get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map])
{
	int self_color = get_color(x_pos, y_pos, arr);//свой цвет
	std::shared_ptr<int> p_EnemyColor(new int());
	std::shared_ptr<std::string> p_Succes(new std::string("no"));

	if (self_color == White) {
		*p_EnemyColor = Black;
	}
	else if (self_color == Black) {
		*p_EnemyColor = White;
	}

	if (((x_pos + 1 == x_move) || (x_pos - 1 == x_move)) &&
		((y_pos + 2 == y_move) || (y_pos - 2 == y_move)) &&
		((get_color(x_move, y_move, arr) == Empty) || (get_color(x_move, y_move, arr) == *p_EnemyColor))) {
		*p_Succes = "yes";
	}
	else if (((x_pos + 2 == x_move) || (x_pos - 2 == x_move)) &&
		((y_pos + 1 == y_move) || (y_pos - 1 == y_move)) &&
		((get_color(x_move, y_move, arr) == Empty) || (get_color(x_move, y_move, arr) == *p_EnemyColor))) {
		*p_Succes = "yes";
	}
	return *p_Succes;
}

wchar_t ChessQueen::put(int color)
{
	if (color == 1)
		return L'Q';
	else if (color == 2)
		return L'q';
	else
		return L'~';
}

std::string ChessQueen::get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map])
{
	ChessBishop bishop;
	ChessRook rook;
	std::shared_ptr<std::string> p_Succes(new std::string("no"));

	if (((x_pos - y_pos) == (x_move - y_move)) || ((x_pos + y_pos) == (x_move + y_move))) {
		*p_Succes = bishop.get_moves(x_pos, y_pos, x_move, y_move, arr);
	}
	else if (((x_pos != x_move) && (y_pos == y_move)) || ((x_pos == x_move) && (y_pos != y_move))) {
		*p_Succes = rook.get_moves(x_pos, y_pos, x_move, y_move, arr);
	}
	return *p_Succes;
}
