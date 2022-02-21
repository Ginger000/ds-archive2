#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  
  int left, right;
  left = 0;
  right = 0;
  if (this->left_== NULL && this->right_ == NULL)
  {
    return 0;
  }
  if (this->left_ !=NULL) 
  {
    left = this->left_->getHeight();
  }
  if(this->right_ != NULL) {
    right = this->right_->getHeight();
  }
  if(left > right) {
    return left + 1;
  } else {
    return right + 1;
  }
  
  // if (this != NULL)
  // {
  //   return 1 + max(this->left_->getHeight(), this->left_->getHeight());
  // } else {
  //   return -1;
  // }
}
