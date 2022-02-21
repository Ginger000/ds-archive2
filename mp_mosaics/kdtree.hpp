/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */

    // return false;


  if(first[curDim]>second[curDim]){
  return false;
  }
  else if(first[curDim]<second[curDim]){
    return true;
  }
  else{
    return first<second;
  }
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */

    //  return false;
     double curBestDis=0;
     double potentialDis=0;
     for(int i=0;i<Dim;i++){
       curBestDis+=pow(currentBest[i]-target[i],2);
     }
     for(int j=0;j<Dim;j++){
       potentialDis+=pow(potential[j]-target[j],2);
     }
     if(potentialDis<curBestDis){
        return true;
      }
      else if(potentialDis>curBestDis){
        return false;
      }
     else{return potential < currentBest;}
}

template <int Dim>
int KDTree<Dim>::quickSelectHelper(vector<Point<Dim>>& points, int left, int right, unsigned pivotIndex, int dimension)
{
  Point<Dim> pivotValue=points[pivotIndex];
  swap(points[pivotIndex],points[right]);
  int temp =left;
  for(int i=left;i<right;i++){
    if(smallerDimVal(points[i],pivotValue,dimension)){
      swap(points[temp],points[i]);
      temp++;
      }
    }
  swap(points[right],points[temp]);
  return temp;
}

template<int Dim>
Point<Dim> KDTree<Dim>::quickSelect(vector<Point<Dim>>& points, int left, int right, int n, int dim)
{
  if(left==right){
    return points[left];
  }
  int pivotIndex=n;
  pivotIndex=quickSelectHelper(points, left, right,pivotIndex,dim);
  //k-1
  if(n==pivotIndex){
    return points[n];
  }
  else if(n<pivotIndex){
    return quickSelect(points, left, pivotIndex-1, n,dim);
  }
  else{
    return quickSelect(points,pivotIndex+1,right,n,dim);
  }
}

template<int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::constructorHelper(vector<Point<Dim>>& points, int dimension, unsigned left, unsigned right)
{
    //base case
    if(left<0||right>=points.size())
    return NULL;
    if(right<left){
      return NULL;
    }

    int median=(left+right)/2;
    KDTreeNode* root=new KDTreeNode(quickSelect(points,left,right,median,dimension%Dim));
    dimension++;
    size++;
    root->left=constructorHelper(points,dimension%Dim,left,median-1  );
    root->right=constructorHelper(points,dimension%Dim,median+1, right);
    return root;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
    if(newPoints.empty()){
       root=NULL;
       size=0;
     }
     else{
       vector<Point<Dim>> points=newPoints;
       size=0;
       root=constructorHelper(points,0,0,points.size()-1);
     }
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::copy(KDTreeNode* subRoot)
{
  if(subRoot==NULL){
    return NULL;
  }
  KDTreeNode* newRoot=new KDTreeNode(subRoot->point);
  newRoot->left=copy(subRoot->left);
  newRoot->right=copy(subRoot->right);
  return newRoot;
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
  size=other.size;
  root=copy(other.root);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  // return *this;
  if((*this)!=rhs){
   deleteHelper(this->root);
   size=0;
   root=copy(rhs.root);
   size=rhs.size;
    }
  return *this;
}

template<int Dim>
void KDTree<Dim>::deleteHelper(KDTreeNode* subRoot)
{
  if(subRoot==NULL){
    return;
  }
  deleteHelper(subRoot->left);
  deleteHelper(subRoot->right);
  delete subRoot;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
  deleteHelper(root);
   size=0;
}

template <int Dim>
void KDTree<Dim>::findHelper(KDTreeNode* curr, Point<Dim> &best, const Point<Dim>& query,int dim )const
{
  if(curr==NULL){
    return;
  }
  KDTreeNode* nextNode;
  KDTreeNode* otherNode;
  if(smallerDimVal(curr->point, query,dim)){
    nextNode=curr->right;
    otherNode=curr->left;
  }
  else{
    nextNode=curr->left;
    otherNode=curr->right;
  }
  findHelper(nextNode,best,query,(dim+1)%Dim);
  if(shouldReplace(query,best,curr->point)){
    best=curr->point;
  }
  double radius=0;
  for(int i=0;i<Dim;i++){
    radius+=pow((query[i]-best[i]),2);
  }
  double distance=pow((query[dim]-curr->point[dim]),2);
  if(radius>=distance){
    findHelper(otherNode,best,query,(dim+1)%Dim);
  }


}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    // return Point<Dim>();
    if(root==NULL){
       return Point<Dim>();
     }
     Point<Dim> best=root->point;
     Point<Dim> target=query;
     findHelper(root,best,target,0);
     return best;
}

