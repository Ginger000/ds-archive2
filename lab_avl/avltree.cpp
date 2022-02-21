/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node* newRoot = t->right;
    t->right = newRoot->left;
    newRoot->left = t;
    t->height=getHeight(t);
    newRoot->height = getHeight(newRoot);
    t = newRoot;
}

template <class K, class V>
int AVLTree<K, V>::getHeight(Node* root){
    if(root == NULL) {
        return -1;
    } else if (getHeight(root->left) > getHeight(root->right)) {
        return getHeight(root->left) + 1;
    } else {
        return getHeight(root->right) + 1;
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    Node* newRoot = t->left;
    t->left = newRoot->right;
    newRoot->right = t;
    t->height=getHeight(t);
    newRoot->height = getHeight(newRoot);
    t = newRoot;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (subtree == NULL)
    {
        return;
    }
    int leftHeight = getHeight(subtree->left);
    int rightHeight = getHeight(subtree->right);
    int d = leftHeight-rightHeight;
    
    // std::cout<<"test4" <<std::endl;
    if ( -1 <= d <= 1)
    {
        subtree->height = getHeight(subtree);
    }
    
    if (d == 2) {
        int subLeftHeight1 = getHeight(subtree->left->left);
        int subRightHeight1 = getHeight(subtree->left->right);
        int d1 = subLeftHeight1 - subRightHeight1;
        if (d1== 1){
            rotateRight(subtree);
        } else {
            rotateLeftRight(subtree);
        }     
    } 
    
    if(d == -2) {
        int subLeftHeight1 = getHeight(subtree->right->left);
        int subRightHeight1 = getHeight(subtree->right->right);
        int d1 = subLeftHeight1 - subRightHeight1;
        if (d1== -1)
        {
            rotateLeft(subtree);
        } else {
            rotateRightLeft(subtree);
        }    
    }
    
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL){
        subtree = new Node(key, value);
    }
    
    if(subtree->key == key) {
        subtree->value = value;
    } 
    
    if (subtree->key > key) {
        insert(subtree->left, key, value);
    } 
    
    if (subtree->key < key){
        insert(subtree->right, key, value);
    }
    // std::cout<<"test3" <<std::endl;
    rebalance(subtree);
    // std::cout<<"test4" <<std::endl;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left,key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            Node* temp=subtree;
            subtree=NULL;
            delete temp;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* temp =subtree;
            temp = subtree->left;
            while(temp->right!=NULL){
              temp = temp ->right;
            }
            swap(temp ,subtree);
            remove(subtree->left,key);
        } else {
            /* one-child remove */
            // your code here
            Node* temp=subtree;
            if(temp->left!=NULL){
              subtree=temp->left;
            }
            else{
              subtree=temp->right;
            }
            delete temp;
        }
        // your code here
        
    }
    rebalance(subtree);
}
