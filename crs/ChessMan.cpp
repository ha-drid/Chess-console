#include "ChessMan.h"
#include "Color.h"

static int width_map = 8;
static int height_map = 8;

wchar_t ChessPawn::put(int color)
{
	if (color == 1)
		return L'P';
	else if (color == 2)
		return L'p';
	else
		return L'~';
}

std::string ChessPawn::get_moves(int x_pos, int y_pos, int x_move, int y_move, std::vector<std::vector<wchar_t>> arr)
{
	int cnt, * p_cnt = &cnt;
	int self_color = get_color(x_pos, y_pos, arr);//���� ����
	int enemy_color, * p_enemy_color = &enemy_color;
	int iY_pos; //���������� ������� 
	int* p_iY_pos = &iY_pos; // ��������� �� ������� ���������

	if (self_color == White) {
		*p_cnt = 1;
		*p_iY_pos = 1;
		*p_enemy_color = Black;
	}
	else if (self_color == Black) {
		*p_cnt = -1;
		*p_iY_pos = 6;
		*p_enemy_color = White;
	}
	
	//���� �� ��������� ����� ������� ���� ����� ���� �� ������������ "Yes", � ����� "No"
	if ((y_pos + cnt == y_move) && (x_pos == x_move) && (get_color(x_move, y_move, arr) == Empty))
		return "yes";
	else if ((y_pos + (cnt * 2) == y_move) && (x_pos == x_move) && (get_color(x_move, y_move, arr) == Empty) && (get_color(x_move, y_move + cnt, arr) == Empty) && (y_pos == iY_pos))
		return "yes";
	else if ((y_pos + cnt == y_move) && ((x_pos - 1== x_move) || (x_pos + 1 == x_move)) && (get_color(x_move, y_move, arr) == enemy_color))
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

std::string ChessKing::get_moves(int x_pos, int y_pos, int x_move, int y_move, std::vector<std::vector<wchar_t>> arr)
{
	int self_color = get_color(x_pos, y_pos, arr);//���� ����
	int enemy_color; //���� ��������� �����
	int *p_enemy_color = &enemy_color; 
	//����� �� ������ ���������������� ��������� ���� ������ ��� ����� 
	if (self_color == White) {
		*p_enemy_color = Black;
	}
	else if (self_color == Black) {
		*p_enemy_color = White;
	}
	
	if (((x_pos == x_move) || (x_pos + 1 == x_move) || (x_pos - 1 == x_move)) &&
		((y_pos == y_move) || (y_pos + 1 == y_move) || (y_pos - 1 == y_move)) &&
		((get_color(x_move, y_move, arr) == Empty) || (get_color(x_move, y_move, arr) == enemy_color))) {
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

std::string ChessRook::get_moves(int x_pos, int y_pos, int x_move, int y_move, std::vector<std::vector<wchar_t>> arr)
{
	int self_color = get_color(x_pos, y_pos, arr);//���� ����
	int enemy_color; //���� ��������� �����
	int* p_enemy_color = &enemy_color;
	int cnt, i;
	int min, max;
	int* p_min = &min, * p_max = &max;
	int* p_cnt = &cnt;
	std::string succes = "no";
	std::string* p_succes = &succes;

	//����� �� ������ ���������������� ��������� ���� ������ ��� ����� 
	if (self_color == White) {
		*p_enemy_color = Black;
	}
	else if (self_color == Black) {
		*p_enemy_color = White;
	}
	//�������� �� ��� � 
	if ((x_pos != x_move) && (y_pos == y_move)) {
		//������ ����� ��������� ����� ��� ������
		if (x_pos < x_move) {
			*p_cnt = 1;
			*p_min = x_pos;
			*p_max = x_move;
		}
		else if (x_pos > x_move) {
			*p_cnt = -1;
			*p_min = x_move;
			*p_max = x_pos;
		}

		i = x_pos + cnt;
		if ((get_color(x_move, y_pos, arr) == Empty) || (get_color(x_move, y_pos, arr) == enemy_color))
			while (min <= i <= max)
			{
				if (i == x_move)
					*p_succes = "yes";

				if (get_color(i, y_move, arr) == Empty)
					i += cnt;
				else 
					break;
				
			}
		else if (get_color(x_move, y_move, arr) == self_color)
			std::cout << "��� ����� ����� ����� �������\n\n";
	}
	//�������� �� ��� �
	else if ((x_pos == x_move) && (y_pos != y_move)) {
		//������ ����� ��������� ����� ��� ������
		if (y_pos < y_move) {
			*p_cnt = 1;
			*p_min = y_pos;
			*p_max = y_move;
		}
		else if (y_pos > y_move) {
			*p_cnt = -1;
			*p_min = y_move;
			*p_max = y_pos;
		}
		
		i = y_pos + cnt;
		if ((get_color(x_pos, y_move, arr) == Empty) || (get_color(x_pos, y_move, arr) == enemy_color))
			while (min <= i <= max)
			{
				if (i == y_move) {
					*p_succes = "yes";
					break;
				}

				if (get_color(x_move, i, arr) == Empty)
					i += cnt;
				else
					break;

			}
		else if (get_color(x_move, y_move, arr) == self_color)
			std::cout << "��� ����� ����� ����� �������\n\n";
	}
	if (succes == "yes")//���� succes ����� "yes" �� ����������� "yes"
		return "yes";
	else
		return "no";
}