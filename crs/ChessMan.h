#pragma once
#include "auxiliary.h"
#include "move_figure_methods.h"

class Board;

class ChessMan
{
public:
	ChessMan() {}
	virtual void init(int x,int y,int Color) = 0;
	virtual void put(char arr[height][width + 1]) = 0;
	virtual void getMove(int x_pos, int y_pos, char arr[height][width + 1]) = 0;
	virtual ~ChessMan() {}
	friend Board;
protected:
	int x, y, Color;
	bool isBoard, isAttack;
};

class Pawn :public ChessMan
{
public:
	Pawn() {}
	void init(int x, int y, int Color) override;
	void put(char arr[height][width + 1]) override;
	void getMove(int x_pos, int y_pos, char arr[height][width + 1]) override;
	~Pawn() {}
};

class Rook :public ChessMan
{
public:
	Rook() {}
	void init(int x, int y, int Color) override;
	void put(char arr[height][width + 1]) override;
	void getMove(int x_pos, int y_pos, char arr[height][width + 1]) override;
	~Rook() {}
};

class Bishop : public ChessMan
{
public:
	Bishop() {}
	void init(int x, int y, int Color) override;
	void put(char arr[height][width + 1]) override;
	void getMove(int x_pos, int y_pos, char arr[height][width + 1]) override;
	~Bishop() {}
};

class Cavalary :public ChessMan
{
public:
	Cavalary() {}
	void init(int x, int y, int Color) override;
	void put(char arr[height][width + 1]) override;
	void getMove(int x_pos, int y_pos, char arr[height][width + 1]) override;
	~Cavalary() {}
};

class Queen :public ChessMan
{
public:
	Queen() {}
	void init(int x, int y, int Color) override;
	void put(char arr[height][width + 1]) override;
	void getMove(int x_pos, int y_pos, char arr[height][width + 1]) override;
	~Queen() {}
};

class King :public ChessMan
{
public:
	King() {}
	void init(int x, int y, int Color) override;
	void put(char arr[height][width + 1]) override;
	void getMove(int x_pos, int y_pos, char arr[height][width + 1]) override;
	~King() {}
};

