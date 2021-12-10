#pragma once
#include <vector>

class Tower
{
public:
  Tower();
  Tower(int towerNum);

  void SetTowerNum(int i) { towerNum = i; }

  void PushDisk(class Disk *disk);
  Disk *PopDisk(); // get and remove disk from this tower
  int GetSize() { return disks.size(); }

  int GetTowerNum() { return towerNum; }

private:
  std::vector<class Disk *> disks;
  int towerNum = -1;
};