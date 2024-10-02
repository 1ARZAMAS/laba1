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

struct Node2 {
    int key; // значение узла
    Node2* left; // указатели на левые и правые дочерние узлы
    Node2* right;
    int height; // высота узла
    // инициализируем дерево
    Node2(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};
