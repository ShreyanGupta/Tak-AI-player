#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <cstdint>
#include <algorithm>

namespace Tak {

using namespace std;

using Bit = uint64_t;
using eval_t = int32_t;

// enum Player
enum class Player {
  Black,
  White
};

// Contains information about pieces left
// for each player
struct Pieces {
  uint8_t black_flat;
  uint8_t white_flat;
  uint8_t black_cap;
  uint8_t white_cap;
  uint8_t num_black() const {return black_flat + black_cap;}
  uint8_t num_white() const {return black_flat + black_cap;}
};

// Global variables
extern int size;
extern Pieces default_pieces;

// Used for generating moves
namespace SlideVec {
  extern vector<vector<vector<Bit>>> cap_slides;
  extern vector<vector<vector<Bit>>> all_slides;
} // namespace SlideVec

// Used for BitBoard bits manipulation
namespace Bits {
  extern Bit Mask;
  extern Bit L;
  extern Bit R;
  extern Bit U;
  extern Bit D;
  extern Bit Edge;
} // namespace Bit

// Initialize value of pieces
namespace InitPieces {
  extern Pieces init3;
  extern Pieces init4;
  extern Pieces init5;
  extern Pieces init6;
  extern Pieces init7;
  extern Pieces init8;
  extern Pieces init_default;
} // namespace InitPieces

// Weights used by Feature
namespace Weights {
  extern eval_t GROUPS[];       // groups of connected components
  extern eval_t WIN;            // win
  extern eval_t CHECKWIN;       // used to check if any player has won
  extern eval_t INF;            // best guess of infinity
  extern eval_t FLAT;           // flat piece at top
  extern eval_t WALL;           // wall at top
  extern eval_t CAP;            // capstone at top
  extern eval_t HARD_FCAPTIVE;  // hard captives are pieces of the 
  extern eval_t SOFT_FCAPTIVE;  // current_player of the stack below
  extern eval_t HARD_SCAPTIVE;  // a given stack position
  extern eval_t SOFT_SCAPTIVE;  // soft captives are pieces of opponent
  extern eval_t HARD_CCAPTIVE;  // 
  extern eval_t SOFT_CCAPTIVE;  // 
  extern eval_t CENTER;         // a weight closer to center is preferred
  extern eval_t ENDGAMEFLAT;    // increase weight of flat towards endgame
  extern float ENDGAMECUTOFF;   // how many pieces left of either player
} // namespace Weights

// init function
void init(int board_size);

inline bool is_black(const Player &p){
  return p == Player::Black;
}

inline bool is_white(const Player &p){
  return !is_black(p);
}

inline void switch_player(Player &p){
  if(is_black(p)) p = Player::White;
  else p = Player::Black;
}

inline bool test_bit(Bit b, uint8_t pos){
  return (b >> pos) & 1; 
}

inline void set_bit(Bit &b, uint8_t pos){
  b |= (Bit(1) << pos);
}

inline void reset_bit(Bit &b, uint8_t pos){
  b &= ~(Bit(1) << pos);
}

inline int popcnt(Bit b){
  return __builtin_popcountll(b);
}

} // namespace Tak

#endif