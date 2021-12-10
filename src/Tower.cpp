#include "Tower.hpp"
#include "Disk.hpp"
#include <iostream>

Tower::Tower()
{
}

Tower::Tower(int towerNum)
    : towerNum(towerNum)
{
}

Disk *Tower::PopDisk()
{
  Disk *disk = disks.back();
  std::cout << "disk: " << disks.back()->GetSize() << std::endl;
  disks.back() = nullptr;
  return disk;
}

void Tower::PushDisk(Disk *disk)
{
  disks.emplace_back(disk);
}