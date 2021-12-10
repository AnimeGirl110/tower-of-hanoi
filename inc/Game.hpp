#pragma once

#include "Disk.hpp"
#include "Tower.hpp"

class Game
{
public:
  Game(int numDisks);
  ~Game();
  void Solve(int towerIndex, int numDisks, int delta); // delta is change

  void Shift(int towerIndex, int delta);

  int numMoves = 0;

private:
  Tower towers[3];
};