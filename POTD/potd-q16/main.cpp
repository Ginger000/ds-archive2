#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  //Node* head = NULL; 
    Node* second = NULL; 
    Node* third = NULL; 
  
    // allocate 3 nodes in the heap 
    
  // Test 3: A list with more than one node
    head = new Node(); 
    second = new Node(); 
    third = new Node(); 
  
    head->data_ = 1; 
    head->next_ = second; 
  
    second->data_ = 2; 
    second->next_ = third; 
  
    third->data_ = 3; 
    third->next_ = NULL;
    string s = stringList(head);
    cout<< s << endl;

  return 0;
}
