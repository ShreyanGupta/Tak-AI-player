#include "Header.h"

typedef std::pair<Stone,Player_Type> Piece;
typedef long double ll;

inline Piece Position::get_piece(){
	if(!Stack.empty()) return Stack.front();
	else return make_pair(F,None);
}

string Position::to_string(){
	int val=0;
	int mul = 1;
	string s = "";
	for(auto &i : Stack){
		if(i.second == Black) val += mul;
		mul << 1;
	}
	val += mul;
	s += std::to_string(val);
	if(!Stack.empty()){
		if(Stack.back().first == F) s += "!";
		else if(Stack.back().first == S) s+= "@";
		else s += "#";
	}
	return s;
}

Board::Board(int size){
	GameBoard = vector< vector<Position> >(size, vector<Position>(size));
}

Board::~Board()
{
	// do nothing!
}

string Board::to_string()
{
	string str = "";
	int s = GameBoard.size();
	for (int i = 0 ; i < s ; i ++)
	{
		for (int j = 0 ; j < s ; j ++)
		{
			str += GameBoard[i][j].to_string() + " "; // this is a position.
		}
	}
	return str;
}

ll Board::eval()
{
	// TODO
}

void Board::makemove(Move m)
{
	// TODO
}

void Board::generate_valid_moves(bool max, std::multimap<ll,Move> & moves)
{
	// TODO
}