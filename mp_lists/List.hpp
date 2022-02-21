/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    // ListNode* head_ = NULL;
    // ListNode* tail_ = NULL;
    head_ = NULL;
    tail_ = NULL;
    length_= 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  // return List<T>::ListIterator(NULL);
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  // return List<T>::ListIterator(NULL);
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode* node = head_;
  ListNode* tempNode;

  while ( node != nullptr)
  {
    tempNode = node;
    node = node->next;
    delete tempNode;
  }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  // newNode -> next = head_;
  // newNode -> prev = NULL;
  
  // if (head_ != NULL) {
  //   head_ -> prev = newNode;
  // }
  // if (tail_ == NULL) {
  //   tail_ = newNode;
  // }

  if (head_ == nullptr)
  {
    head_ = newNode;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    length_++;
    return;
  }

  newNode->next = head_;
  newNode->prev = nullptr;
  head_->prev = newNode;
  head_ = newNode;

  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  if(head_ == nullptr)
  {
    head_ = newNode;
    tail_ = head_;
    length_++;
    return;
  }

  tail_->next = newNode;
  newNode->prev = tail_;
  tail_ = newNode;

  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;

  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      tail_ = curr->prev;
      if(curr->prev != NULL) {
        curr->prev->next = NULL;
        curr->prev = NULL;
      }
  } 
  
  return curr;
  // return NULL;
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
  // ListNode * temp = new ListNode();
  // ListNode * headOfThree = new ListNode();
  // ListNode * endOfThree = new ListNode();
  ListNode * temp = NULL;
  ListNode * headOfThree = NULL;
  ListNode * endOfThree = NULL;
  
  int n = 0;

  temp = head_;

  while (temp != NULL)
  {
    
    n++;
    //get small group of three nodes
    if(n % 3 == 0) {
        // headOfThree is the node will be rotated to the end of the three
        headOfThree = temp->prev->prev;
        endOfThree = temp;

        //if headOfThree is head_ and endOfThree is tail_
        if(headOfThree->prev == NULL && endOfThree->next == NULL) {
          
          //delete headOfThree from the list
          headOfThree->next->prev = NULL;
          head_ = temp->prev;
          //insert headOfThree after the tail
          headOfThree->next = NULL;
          endOfThree->next = headOfThree;
          headOfThree->prev = endOfThree;
          tail_= headOfThree;
          temp = temp->next;
        }
        //if the node "headOfThree" is the head, but "endOfThree" is not the tail
        else if (headOfThree->prev == NULL && endOfThree->next != NULL)
        {
          
          //delete the node "headOfThree" from the list
          headOfThree->next->prev = NULL;
          head_ = temp->prev;
          //insert the node "headOfThree" to a point within the list
          ListNode * temp2 = endOfThree->next;
          endOfThree->next = headOfThree;
          headOfThree->next = temp2;
          temp2->prev = headOfThree;
          headOfThree->prev = endOfThree;
          temp = temp->next;
        }
        
        //if the node "headOfThree" is within the list and "endOfThree is the tail"
        else if (headOfThree->prev != NULL && endOfThree->next == NULL)
        {
          
          //delete the node "headOfThree" from the list
          ListNode * temp3 = headOfThree->prev;
          temp3->next = headOfThree->next;
          headOfThree->next->prev = temp3;
          //insert the node "headOfThree" to the end of the list
          headOfThree->next = NULL;
          endOfThree->next = headOfThree;
          headOfThree->prev = endOfThree;
          tail_= headOfThree;
          temp = temp->next;
        }

        //if both "headOfThree" and "endOfThree" are within list
        else if(headOfThree->prev != NULL && endOfThree->next != NULL) {
          
          //delete the node "headOfThree" from the list
          ListNode * temp3 = headOfThree->prev;
          temp3->next = headOfThree->next;
          headOfThree->next->prev = temp3;
          //insert the node "headOfThree" to a point within the list
          ListNode * temp2 = endOfThree->next;
          endOfThree->next = headOfThree;
          headOfThree->next = temp2;
          temp2->prev = headOfThree;
          headOfThree->prev = endOfThree;
          temp = temp->next;
        }
    }
    temp = temp->next;
  }

  // delete temp;
  // delete headOfThree;
  // delete endOfThree;
  
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  // reverse(head_->next->next, tail_);
  // reverse(head_, tail_->prev->prev);
  reverse(head_->next, tail_->prev);
  // reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
   ListNode * tempstart = startPoint;
  ListNode * startPrev = startPoint;
  ListNode * endNext = endPoint->next;
  if(startPoint == endPoint)
  {
    return;
  }
  /*while(startPoint!=NULL)
  {
    temp = startPoint;
    startPoint= endPoint;
    endPoint = startPoint;
  }*/
  while (tempstart != endNext)
  {
      startPrev = tempstart->prev;
      tempstart->prev = tempstart->next;
      tempstart->next = startPrev;
      tempstart = tempstart->prev;
  }
  //std::cout<<"pass";
  //startPrev = endPoint;
  startPrev = endPoint->prev;
  ListNode * temp22 = startPoint->next;
  if(temp22!=NULL)
  {
    endPoint->prev = startPoint->next;
    startPoint->next->next = endPoint;
  }
  else
  {
    endPoint->prev = NULL;//NULL;
  }
  //std::cout<<"pass";
  if(startPrev!=NULL)
  {
    startPoint->next = startPrev;
    startPrev->prev = startPoint;
  }
  else
  {
    startPoint->next = nullptr;
  }
  //std::cout<<"pass";
  tempstart = startPoint;
  startPoint = endPoint;
  endPoint = tempstart;
  // ListNode * temp = startPoint;
  
  // ListNode * cur = startPoint;
  // ListNode * endNext = endPoint->next;
  // ListNode * temp1 = NULL;
  // ListNode * temp2 = NULL;
  // ListNode * temp3 = NULL;
  // ListNode * temp4 = NULL;
  

  // if (startPoint == endPoint)
  // {
  //   return;
  // }

  // while (cur != endNext) {
  //   temp = cur->prev;
  //   cur->prev = cur->next;
  //   cur->next = temp;
  //   cur = cur->prev;
  // }  

  // temp1 = endPoint->prev;
  // temp2 = endPoint->next;
  // temp2 = startPoint->prev;
  // temp4 = startPoint->next;

  // if (temp1 != NULL && temp4 == NULL){
  //   startPoint->next = temp1;
  //   temp1->prev = startPoint;
  //   // endPoint->prev = NULL;
  // } else if (temp1 == NULL && temp4 != NULL){
  //   endPoint->prev = temp4;
  //   temp4->next = endPoint;
  //   startPoint->next = NULL;
  //   startPoint->prev = temp2;
    
  // } else if (temp1 != NULL && temp4 != NULL){
  //   startPoint->next = temp1;
  //   temp1->prev = startPoint;
  //   endPoint->prev = temp4;
  //   temp4->next = endPoint;
  // } else if (temp1 == NULL && temp4 == NULL){
  //   temp = startPoint;
  //   startPoint = endPoint;
  //   endPoint = temp;
  // }
  

  // if (temp2 != NULL) {
  //   endPoint->prev = startPoint->next;
  //   //startPoint changed here
  //   temp3->next = endPoint;
  // } else {
  //   endPoint->prev = NULL;
  // }

  // if(temp != NULL) {
  //   startPoint->next = temp;
  //   temp->prev = startPoint;
  // } else {
  //   startPoint->next = NULL;
  //   startPoint->prev = temp->prev;
  // }

  // endPoint->prev = NULL;
  // startPoint->next = NULL;

  

}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  
  if(n <= 1) {
    return;
  }

  if(length_<=1){
    return;
  }

  if(n>=length_)
  {
    reverse();
  }

  ListNode * tempStart = head_;
  ListNode * tempEnd = NULL;
  ListNode * cur = head_;
  int m = 0;

  while(cur != NULL){
      m++;
      if(m % n == 0) {
        tempEnd = cur->prev;
        reverse(tempStart, tempEnd);
        tempStart = cur;
      }
      cur = cur->next;
  }

  if (m % n != 0)
  {
    int left = m % n;
    tempStart = tempEnd->next;
    tempEnd = tail_;
    reverse(tempStart, tempEnd);
  }
  

}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  return NULL;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if (chainLength == 1){
	return start;
  }
  else {
	int length = chainLength/2;
	ListNode * temp;
	temp = split(start, length);
	ListNode * begin = mergesort(start, length);
	ListNode * end = mergesort(temp, chainLength - length);
	return merge(begin, end);
  }
}
