#include "TreeNode.h"
#include <iostream>




int main() {

  // TreeNode * n1 = new TreeNode(8);
  // TreeNode * n2 = new TreeNode(5);
  // TreeNode * n3 = new TreeNode(13);
  // TreeNode * n4 = new TreeNode(10);

  TreeNode n11 = TreeNode(8);
  TreeNode n22 = TreeNode(5);
  TreeNode n33 = TreeNode(13);
  TreeNode n44 = TreeNode(10);

  TreeNode * n1 = &n11;
  TreeNode * n2 = &n22;
  TreeNode * n3 = &n33;
  TreeNode * n4 = &n44;

  n1->left_ = n2;
  n1->right_ = n3;
  n3->left_ = n4;
  n3->right_ = new TreeNode(14);
  n4->right_ = new TreeNode(11);
  n4->right_->right_ = new TreeNode(12);

  int* temp = (int*)getHeightBalance(n1);

  std::cout << "Height balance of n1: " << temp << std::endl;
  std::cout << "Height balance of n2: " << getHeightBalance(n2) << std::endl;
  std::cout << "Height balance of n3: " << getHeightBalance(n3) << std::endl;
  std::cout << "Height balance of n4: " << getHeightBalance(n4) << std::endl;

  //deleteTree(n1);
  return 0;

}
