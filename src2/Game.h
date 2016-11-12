#ifndef GAME_H
#define GAME_H

#include "Position.h"
#include "Transposition.h"
using namespace Types;

class Game{
private:
	vector<unordered_map<string, Transposition> > TTable; // length 2.
	
	// helper functions
	bool pathable(s_int x, s_int y, bool player);
	void search(bool type, s_int x, s_int y, bool player, vector< vector<bool> > &explored, bool &found);
	void newsearch(s_int x, s_int y, bool player, vector< vector<bool> > &explored, vector<int> &lrud);

	// eval functions
	eval_type path();
	eval_type newpath();
	eval_type center(int,int);
	eval_type captive(char,pair<s_int,s_int>&);
	eval_type piece_type(char);

	void UpdatePlayer(Player_Type, Move&, bool);
	void GetStackable(s_int, s_int, bool, vector<s_int> &);
public:
	s_int size;
	vector< vector<Position> > GameBoard;
	Player p_black, p_white;
	// eval_type w[18];

	Game(s_int, s_int);
	eval_type eval(Player_Type);
	string to_string();
	void make_opponent_move(string, bool);
	void makemove(Move &);
	void antimove(Move &);
	eval_type features();
	Transposition& getTransposition(Player_Type);
	
	string ids(int);
	int decide_Depth();
	bool isMoveValid(Move&,bool);
	void generate_place_1(Player_Type, list<Move>&);
	void generate_place_2(Player_Type, list<Move>&);
	void generate_stack_moves(Player_Type, list<Move>&);

	void generate_valid_moves(Player_Type, multimap<pair<eval_type,eval_type>,Move>&);

	eval_type negaMax(bool,s_int,eval_type,eval_type, pair<Move, Move> &);
	// CALL decide_move after negaMax?

	// temp
	void print_move_seq(int depth);
};

inline bool Game::pathable(s_int x, s_int y, bool player){
	return (!GameBoard[x][y].empty() && GameBoard[x][y].top_piece() != 'S' && GameBoard[x][y].player() == player);
}

inline Transposition& Game::getTransposition(Player_Type p){
	auto &t = TTable[p][to_string()];
	if(t.flag == 'x'){
		t.flag = 'e';
		t.score = eval(p);
		t.depth = 0;
	}
	// cout << "Depth of trans = " << t.depth << endl;
	return t;
}

inline eval_type Game::eval(Player_Type player){
	eval_type value = 0;
	value += newpath();
	string s = (player == White) ? "White" : "Black";
	cerr << "Val of newpath is " << value << ", with player = " << s << endl;
	if (abs(value) > FLWIN/2)
		return ((player == White) ? value : -value);
	value += features();
	return ((player == White) ? value : -value);
}

#endif
