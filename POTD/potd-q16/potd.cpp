#include "potd.h"
#include <iostream>

using namespace std;

string stringList(Node *head) {
    // your code here!

    Node* item = NULL;
    item = head;
    string stringItem;
    string stringFull;
    int index = 0;
    //item = new Node();

    if(item == NULL) {
        return "Empty list";
    }

    while (item != NULL) {
        stringItem = to_string(item->data_);
        if(item->next_ == NULL) {
            stringFull = stringFull + "Node " + to_string(index) + ": "+ stringItem;
        } else {
            stringFull = stringFull + "Node " + to_string(index) + ": "+ stringItem + " -> ";
        }
        index++;
        item = item->next_;
    } 

    return stringFull;
}
