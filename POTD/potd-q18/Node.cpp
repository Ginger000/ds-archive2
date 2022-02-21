#include "Node.h"

using namespace std;

void sortList(Node **head) {
  // your code here!
 
  
class Solution {
public:
    Node* tail = new Node();
    Node* nextSubList = new Node();

    Node* sortList(Node* head) {
        if (!head || !head -> next_)
            return head;
        int n = getCount(head);
        Node* start = head;
        Node dummyHead;
        for (int size = 1; size < n; size = size * 2) {
            tail = &dummyHead;
            while (start) {
                if (!start->next_) {
                    tail->next_ = start;
                    break;
                }
                Node* mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next_;
        }
        return dummyHead.next_;
    }

    Node* split(Node* start, int size) {
        Node* midPrev = start;
        Node* end = start->next_;
        //use fast and slow approach to find middle and end of second linked list
        for (int index = 1; index < size && (midPrev->next_ || end->next_); index++) {
            if (end->next_) {
                end = (end->next_->next_) ? end->next_->next_ : end->next_;
            }
            if (midPrev->next_) {
                midPrev = midPrev->next_;
            }
        }
        Node* mid = midPrev->next_;
        nextSubList = end->next_;
        midPrev->next_ = nullptr;
        end->next_ = nullptr;
        // return the start of second linked list
        return mid;
    }

    void merge(Node* list1, Node* list2) {
        Node dummyHead;
        Node* newTail = &dummyHead;
        while (list1 && list2) {
            if (list1->data_ < list2->data_) {
                newTail->data_ = list1;
                list1 = list1->data_;
                newTail = newTail->data_;
            } else {
                newTail->next_ = list2;
                list2 = list2->next_;
                newTail = newTail->next_;
            }
        }
        newTail->next = (list1) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail->next) {
            newTail = newTail->next;
        }
        // link the old tail with the head of merged list
        tail->next = dummyHead.next;
        // update the old tail with the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while (ptr) {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }
};


}
   


Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;

