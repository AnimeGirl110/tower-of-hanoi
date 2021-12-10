#include "Game.hpp"
#include "Disk.hpp"
#include "Tower.hpp"
#include <iostream>

Game::Game(int numDisks)
{

  towers[0].SetTowerNum(0);
  towers[1].SetTowerNum(1);
  towers[2].SetTowerNum(2);

  for (int i = numDisks; i > 0; i--)
  {
    towers[0].PushDisk(new Disk(i));
  }
  Solve(0, numDisks, -1);
}

Game::~Game()
{
}

void Game::Solve(int towerIndex, int numDisks, int delta)
{
  if (!numDisks)
  {
    return;
  }

  Solve(towerIndex, numDisks - 1, -delta);
  Shift(towerIndex, delta);
  std::cout << "shifting" << std::endl;
  Solve(towerIndex - delta, numDisks - 1, -delta);
}

void Game::Shift(int towerIndex, int delta)
{
  // something wrong here
  Disk *disk = towers[towerIndex].PopDisk();
  towers[towerIndex + delta].PushDisk(disk);
  // std::cout <<"disk at top" <<towers[towerIndex + delta].disks.back()->GetSize() << std::endl;
  // std::cout << disk << "," << towers[towerIndex].GetTowerNum() << std::endl;
}