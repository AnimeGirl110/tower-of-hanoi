#pragma once

class Disk
{
public:
  Disk(int size);

  int GetSize() { return size; }

private:
  int size;
};