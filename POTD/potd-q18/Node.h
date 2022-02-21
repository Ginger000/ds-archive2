#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
using namespace std;

class Node {
    public:
        int data_;
        Node *next_;
        Node();
        Node(Node &other);
        ~Node();
        static int getNumNodes() {
            return numNodes;
        }
    private:
        static int numNodes;
};

void sortList(Node **head);

#endif
