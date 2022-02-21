#include "TreeNode.h"

int* getHeightBalance(TreeNode* root) {
  // your code here
  if (root == NULL)
  {
    return 0;
  }
  
  int diff = getHeight(root->left_) - getHeight(root->right_);
  return &diff;
}

int getHeight(TreeNode* root) {
  if (root == NULL)
  {
    return -1;
  }
  if (getHeight(root->left_) > getHeight(root->right_))
  {
    return getHeight(root->left_) + 1;
  } else {
    return getHeight(root->right_) + 1;
  }
  
  
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

