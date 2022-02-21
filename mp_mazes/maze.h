/* Your code here! */
#pragma once
#include "dsets.h"
#include <vector>
#include "cs225/PNG.h"
using namespace cs225;
using std::vector;

class SquareMaze{
public:
  SquareMaze();
  void makeMaze(int width,int	height);
  bool 	canTravel(int x, int y, int dir) const ;
  void 	setWall (int x, int y, int dir, bool exists);
  vector<int> solveMaze();
  PNG * drawMaze()	const;
  PNG * drawMazeWithSolution ();
  int width_;
  int height_;
  //the first value is rightwall, the second value is downwall
  vector<vector<bool>> walls;
  DisjointSets mazeSets;
};