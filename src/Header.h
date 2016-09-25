#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <string>

using namespace std;

enum Player_Type{
	Black, White, None
};

enum Stone{
	F,S,C,
};

typedef std::pair<Stone,Player_Type> Piece;
typedef long double eval_type;

struct Position
{
	std::deque<Piece> Stack;
	int black = 0;
	int white = 0;
	string to_string();
	Piece get_piece();
};

struct Move
{
	bool Type; 			// false if antimove else true
	bool Place_move; 	// true if place else false
	int x;
	int y;
	Piece p; // rakhna hai ye/uthaana hai ye.
	char Direction; 	// + U, - D, > R, < L
	vector<int> Drops;
	string to_string(); // print ke liye!
};


class Board
{
private:
	string to_string();
public:
	vector< vector<Position> > GameBoard;
	Board(int);
	~Board();
	eval_type eval();
	void makemove(Move);		// inputs yet to define
	void generate_valid_moves(bool,std::multimap<eval_type,Move> &);
};

class Player{
private:
	int StonesLeft;
	int CapsLeft;
	bool Max;
public:
	Player(bool,int,int);
	~Player();
	std::pair<Move,eval_type> decide_move(Board,int);
};

#endif