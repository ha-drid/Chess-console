#pragma once 
#include <vector>
#include <iostream>
#include <cstring>

class ChessMan
{
public:
	ChessMan() {}
	virtual wchar_t put(int color) = 0;
	virtual std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, std::vector<std::vector<wchar_t>> arr) = 0;
	virtual ~ChessMan() {}
};

class ChessPawn: public ChessMan
{
public:
	ChessPawn() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, std::vector<std::vector<wchar_t>> arr) override;
	~ChessPawn() {}
};

class ChessKing :public ChessMan
{
public:
	ChessKing() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, std::vector<std::vector<wchar_t>> arr) override;
	~ChessKing() {}
};

class ChessRook :public ChessMan
{
public:
	ChessRook() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, std::vector<std::vector<wchar_t>> arr) override;
	~ChessRook() {}
};