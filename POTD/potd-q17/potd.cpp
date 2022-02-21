#include "potd.h"
#include <iostream>

using namespace std;

void insertSorted(Node **head, Node *insert) {
  // your code here!
if (*head == NULL)
{
  *head = insert;
}

Node* next_node = (*head)->next_;
Node* prev_node = *head;  

  if (next_node == NULL)
  {
    if(insert->data_ < (*head)->data_)
    { 
      insert->next_ = *head;
      //*head is change the memory store by the pointer
      //head is change the pointer, but don't change the memory
      *head = insert;
      //head= &insert;
    } else if (insert->data_ > (*head)->data_) {
      insert->next_ = NULL;
      (*head)->next_ = insert;
    }   
  }

  
   
  while (next_node != NULL)
  {
    if(insert->data_ < (*head)->data_)
    { 
      insert->next_ = *head;
      *head = insert;
    } else if (insert->data_ <= next_node->data_){
      insert->next_ = next_node;
      prev_node->next_=insert;
    }
    next_node = next_node->next_;
    prev_node = prev_node->next_;
      
  }

}
