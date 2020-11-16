#pragma once 
#include <iostream>
#include <cstring>
#include <memory>

#include "../size.h"

class ChessMan
{
public:
	ChessMan() {}
	virtual wchar_t put(int color) = 0;
	virtual std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map]) = 0;
	virtual ~ChessMan() {}
};

class ChessPawn: public ChessMan
{
public:
	ChessPawn() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map]) override;
	~ChessPawn() {}
};

class ChessKing :public ChessMan
{
public:
	ChessKing() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map]) override;
	~ChessKing() {}
};

class ChessRook :public ChessMan
{
public:
	ChessRook() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map]) override;
	~ChessRook() {}
};

class ChessBishop :public ChessMan
{
public:
	ChessBishop() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map]) override;
	~ChessBishop() {}
};

class ChessCavalary :public ChessMan
{
public:
	ChessCavalary() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map]) override;
	~ChessCavalary() {}
};

class ChessQueen :public ChessMan
{
public:
	ChessQueen() {}
	wchar_t put(int color) override;
	std::string get_moves(int x_pos, int y_pos, int x_move, int y_move, wchar_t arr[Height_Map][Width_Map]) override;
	~ChessQueen() {}
};