#include "TreeNode.h"

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  TreeNode* temp = root;
  TreeNode* result = NULL;
  queue<TreeNode*> q;
  while(temp != NULL){
    if(!isHeightBalanced(temp)){
      result = temp;
    }
    q.push(temp->left_);
    q.push(temp->right_);
    temp = q.front();
    q.pop();
  }
  return result;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

int findHeight(TreeNode* root) {
  if (root == NULL){
    return -1;
  }
  int leftHeight = findHeight(root->left_);
  int rightHeight = findHeight(root->right_);
  return std::max(leftHeight, rightHeight)+1;
}

bool isHeightBalanced(TreeNode* root) {
  // your code here
  return (findHeight(root->left_) - findHeight(root->right_) == 1 ||
          findHeight(root->left_) - findHeight(root->right_) == -1||
          findHeight(root->left_) - findHeight(root->right_) == 0);
}

