/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
    template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);
}

//helper function
template <typename T>
void BinaryTree<T>::mirror(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left != NULL)
    {
        mirror(root->left);
    }

    if (root->right != NULL)
    {
        mirror(root->right);
    }

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
      
}

/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{   
    // your code here
    // return false;
    InorderTraversal<int> inTra(this->getRoot());
    Node* temp = NULL;
    for (TreeTraversal<int>::Iterator it = inTra.begin(); it != inTra.end(); ++it) {
        if (temp == NULL)
        {
            temp = *it;
        }

        if (temp->elem >(*it)->elem)
        {
            return false;
        } else if ((temp->elem <(*it)->elem) || (temp->elem ==(*it)->elem))
        {
            temp= *it;
        }
               
    }
    return true;
}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{   
    // your code here
    // return false;
    // return isBST(root);
    Node *prev = NULL;
    return isBST(root, prev);
}

template <typename T>
bool BinaryTree<T>::isBST( Node* root,Node *&prev) const
{
  if(root != NULL){
    if(!isBST(root->left, prev)){
      return false;
    }
    if(prev != NULL && root->elem <= prev->elem){
      return false;
    }

    prev = root;

    return isBST(root->right, prev);
  }
  return true;
}
// template <typename T>
// bool BinaryTree<T>::isBST(Node* root) const{
//     std::cout << "start" << std::endl;
//     if(root == NULL) {
//         return true;
//     } else {
//         std::cout << "test" << std::endl;
//         if(findMax(root) <= root->elem && findMin(root) >= root->elem){
//             std::cout << "test2" << std::endl;
//             return isBST(root->left) && isBST(root->right);
//             std::cout << "test3" << std::endl;
//         } 
        
//         return false;
        
//     }
//     std::cout << "end" << std::endl;
// }

// template <typename T>
// int BinaryTree<T>::findMin(Node* root) const
// {
//     if(root->left == NULL) {
//         return root->elem;
//     } else {
//         return std::min(root->elem, findMin(root->left));
//     }
// }

// template <typename T>
// int BinaryTree<T>::findMax(Node* root) const
// {
//     if(root->right == NULL) {
//         return root->elem;
//     } else {
//         return std::max(root->elem, findMax(root->left));
//     }
// }





