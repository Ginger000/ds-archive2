/* Your code here! */
#include "dsets.h"
#include <iostream>
using namespace std;

void DisjointSets::addelements(int num)
{
  for(int i = 0; i < num; i++)
  {
    upTrees.push_back(-1);
  }
}

int DisjointSets::find(int  elem)
{ 
  if(elem >= (int)upTrees.size())
  {
    return -1;
  }
  if(upTrees[elem] < 0) 
  {
    return elem;
  } else {
    int root=find(upTrees[elem]);
    upTrees[elem] = root;
    return root;
  }
}

void DisjointSets::setunion(int a, int b)
{
  int temp1 = find(a);
  int temp2 = find(b);
  if(temp1 == temp2)
  {
    return;
  }
  if(upTrees[temp1] > upTrees[temp2]){
    upTrees[temp2] += upTrees[temp1];
    upTrees[temp1] = temp2;
  }
  else{
    upTrees[temp1] += upTrees[temp2];
    upTrees[temp2] = temp1;
  }
}

int DisjointSets::size(int elem)
{
  int temp = find(elem);
  return (-1)*upTrees[temp];
}