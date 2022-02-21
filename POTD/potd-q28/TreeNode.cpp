#include "TreeNode.h"
#include <iostream>
//This root is just a local variable, a local copy of input value
TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  // return root;
  if (root == NULL)
  {
    return root;
  }
  //this is the base case
  if (root->val_ == key)
  {
    if (root->left_ == NULL && root->right_ == NULL)
    {
      delete root;
      root = NULL;
    } else if (root->left_ != NULL && root->right_ == NULL) {
      TreeNode* temp;
      temp = root;
      root = root->left_; //or root->left->left, another recursion?
      delete temp;
    } else if (root->left_ == NULL && root->right_ != NULL) {
      // root->right_ = root->right_->right_;
      // root->right_ = NULL;
      TreeNode* temp;
      temp = root;
      root = root->right_; 
      delete temp;
  
    } else if (root->left_ != NULL && root->right_ != NULL) {
      //this temp min not only copy the single node, but the whole subtree following that node.
      TreeNode* min = root->right_;
      while (min->left_ != NULL)
      {
        min = min->left_;
      }
      root->val_ = min->val_; 
      root->right_ = deleteNode(root->right_, min->val_);  
    }
    //Do I need a return here?
    return root;
  }

  if (root->val_ != key && root->val_ > key)
  {
    //deleteNode(root->left_,key); is wrong
    // deleteNode(root->left_,key);
    // return root->left_; is also wrong
    // reason: the root of left subtree may change after the deletion
    root->left_ = deleteNode(root->left_,key);
    //return deleteNode(root->left_,key); is also wrong
    
  } else if (root->val_ != key && root->val_ < key)
  {
    root->right_ = deleteNode(root->right_,key);
  }
return root;  
} 

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
