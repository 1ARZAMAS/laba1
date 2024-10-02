#pragma once
#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(const int& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
        : data(value), next(nextNode), prev(prevNode) {
    }
};
