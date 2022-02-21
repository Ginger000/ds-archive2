/* Your code here! */
#include "maze.h"
#include <queue>
using std::vector;
using std::queue;
using namespace cs225;
#include <stdlib.h>

SquareMaze::SquareMaze(){}

void SquareMaze::makeMaze(int width,int	height)
{
  width_ = width;
  height_ = height;
  int numSets = width_*height_;
  mazeSets.addelements(numSets);
  walls = vector<vector<bool>>(numSets);
  
  for (int i = 0; i < numSets; i++)
  { 
    walls[i] = vector<bool>(2);
    //the first is for right wall
    walls[i][0] = true;
    //the second is for bottom wall
    walls[i][1] = true;
  }
  
//helper function, check whether the set is valid

  
  while(numSets>1){
    int x=rand()%width_;
    int y=rand()%height_;
    //index is the index in mazeSets
    int currIndex = x + y * width_;
    int rightIndex = (x + 1) + y * width_;
    int bottomIndex = x + (y + 1) * width_;
    //remove right wall
    if(rand()%2==0){
        if(x!=(width_-1)){
          if(mazeSets.find(currIndex)!=mazeSets.find(rightIndex)){
            walls[currIndex][0] = false;
            mazeSets.setunion(currIndex, rightIndex);
            numSets--;
          }
      }
    }
    else{
      if(y!=(height_-1)){
        if(mazeSets.find(currIndex)!=mazeSets.find(bottomIndex)){
        walls[currIndex][1] = false;
        mazeSets.setunion(currIndex,bottomIndex);
        numSets--;
        }
      }
    }
  }
}

PNG * SquareMaze::drawMaze() const{
  int newWidth=width_*10+1;
  int newHeight=height_*10+1;
  PNG* picture=new PNG(newWidth,newHeight);
  //left most column
  for(int y = 0; y < newHeight; y++){
    HSLAPixel& p = picture->getPixel(0,y);
    p.l = 0;
    p.h = 0;
    p.s = 0;
  }
  //top row
  for(int x=10;x<newWidth;x++){
    HSLAPixel& p=picture->getPixel(x,0);
    p.l = 0;
    p.h = 0;
    p.s = 0;
  }
  
  for(int x=0;x<width_;x++){
    for(int y=0;y<height_;y++){
      int index = x + y * width_;
      if(walls[index][0]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p = picture->getPixel((x+1)*10,y*10+k);
          p.l = 0;
          p.h = 0;
          p.s = 0;
        }
      }
      if(walls[index][1]){
        for(int k=0;k<=10;k++){
          HSLAPixel& p = picture->getPixel(x*10+k,(y+1)*10);
          
          p.l = 0;
          p.h = 0;
          p.s = 0;
        }
      }
    }
  }
  return picture;
}

bool 	SquareMaze::canTravel(int x, int y, int dir) const{
  int index = x + y * width_;
  int leftIndex = (x - 1) + y * width_;
  int topIndex = x + (y - 1) * width_;
  if(dir == 0) {
    return walls[index][0] == false;
  } else if (dir == 1) {
    return walls[index][1] == false;
  } else if (dir == 2) {
    return (x>0)&&walls[leftIndex][0] == false;
  } else {
    return (y>0)&&walls[topIndex][1] == false;
  }
  
  return false;
}



void 	SquareMaze::setWall (int x, int y, int dir, bool exists){
  int index = x + y * width_;
  if(dir == 0) {
    walls[index][0] = exists;   
  } else {
    walls[index][1] = exists;   
  }
  
}

vector<int> SquareMaze::solveMaze(){
  queue<int> q;
  vector<int> dist;
  vector<int> visited;
  int currIndex = 0;
  // int rightIndex = currIndex + 1;
  // int bottomIndex = currIndex + width_;
  // int leftIndex = currIndex - 1;
  // int UpIndex = currIndex - width_;
  // currIndex = 0;
  // val above need to be declared about starting using q
  q.push(0);
  int numSets = width_*height_;
  for(int i=0; i < numSets ; i++){
    visited.push_back(-1);
    dist.push_back(0);
  }
  visited[0]=0;
  int x,y;
  while(!q.empty()){
    
    currIndex=q.front();
    int rightIndex = currIndex + 1;
    int bottomIndex = currIndex + width_;
    int leftIndex = currIndex - 1;
    int UpIndex = currIndex - width_;
    q.pop();
    // int index = x + y * width_;
    x=currIndex%width_;
    y=currIndex/width_;
    if(canTravel(x,y,0) && (visited[rightIndex] == -1)){
      q.push(rightIndex);
      visited[rightIndex] = currIndex;
      dist[rightIndex] = dist[currIndex] + 1;
    }
    if(canTravel(x,y,1) && (visited[bottomIndex] == -1)){
      q.push(bottomIndex);
      visited[bottomIndex] = currIndex;
      dist[bottomIndex] = dist[currIndex] + 1;
    }
    if(canTravel(x,y,2) && (visited[leftIndex] == -1)){
      q.push(leftIndex);
      visited[leftIndex] = currIndex;
      dist[leftIndex] = dist[currIndex] + 1;
    }
    if(canTravel(x,y,3) && (visited[UpIndex] == -1)){
      q.push(UpIndex);
      visited[UpIndex] = currIndex;
      dist[UpIndex] = dist[currIndex] + 1;
    }
  }
  int destination = width_*(height_-1);
  for(int i = 1; i < width_; i++){
    if(dist[width_*(height_-1)+i] > dist[destination]){
      destination=width_*(height_-1)+i;
    }
  }
  vector<int> path;
  currIndex = destination;
  
  while(currIndex > 0){
    int rightIndex = currIndex + 1;
    int bottomIndex = currIndex + width_;
    int leftIndex = currIndex - 1;
    int UpIndex = currIndex - width_;
    if(visited[currIndex] == leftIndex){
      path.push_back(0);
    }
    else if(visited[currIndex]== UpIndex){
      path.push_back(1);
    }
    else if(visited[currIndex] == rightIndex){
      path.push_back(2);
    }
    else if(visited[currIndex] == bottomIndex){
      path.push_back(3);
    }
    currIndex = visited[currIndex];
  }
  reverse(path.begin(), path.end());
  return path;

}



PNG * SquareMaze::drawMazeWithSolution (){
  PNG* mazeImg = drawMaze();
  vector<int> path = solveMaze();
  int x = 5;
  int y = 5;
  for(size_t i = 0;i < path.size(); i++){
    if(path[i] == 0) {
      for(int k = 0; k <= 10; k++){
        HSLAPixel& pixel=mazeImg->getPixel(x+k,y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
      }
      x+=10;
    } else if (path[i] == 1) {
      for(int k = 0;k <= 10; k++){
        HSLAPixel& pixel = mazeImg->getPixel(x,y+k);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
      }
      y+=10;
    } else if (path[i] == 2) {
      for(int k = 0; k<=10; k++){
        HSLAPixel& pixel = mazeImg->getPixel(x-k,y);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
      }
      x-=10;
    } else if (path[i] == 3) {
      for(int k=0; k <= 10; k++){
        HSLAPixel& pixel = mazeImg->getPixel(x,y-k);
        pixel.h=0;
        pixel.s=1;
        pixel.l=0.5;
      }
      y-=10;
    }
  }

  x -= 5;
  y += 5;
  for(int k=1; k <= 9; k++){
    HSLAPixel& pixel = mazeImg->getPixel(x+k,y);
    pixel.l=1;
  }
  return mazeImg;
}


