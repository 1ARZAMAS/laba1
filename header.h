#include <iostream>
#pragma once

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(const int& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
        : data(value), next(nextNode), prev(prevNode) {
    }
};

struct Array {
    Node* head; // указываем на первый узел
    int size; //текущий размер списка
    int capacity; // максимальная вместимость массива

    Array(int max) : head(nullptr), size(0), capacity(max) {}
    // инициализируем head с nullptr, размер нулевой и максимальное значение массива

    void add(int index, int value);
    void addToTheEnd(int value);
    int get(int index);
    void remove(int index);
    void replace(int index, int value);
    int length();
    void display();
};

struct doubleLinkedList{
    Node* head;
    Node* tail;

    doubleLinkedList() : head(nullptr), tail(nullptr) {}

    void addToTheHead(int value); // добавление элемента в голову
    void addToTheEnd(int value); // добавление элемента в хвост
    void removeFromTheHead(); // удаление элемента с головы
    void removeFromTheEnd(); // удаление элемента с хвоста
    void removeByValue(int value); // удаление элемента по значению
    void searchByValue(int value); // поиск элемента по значению
    void display();
};

struct linkedList{
    Node* head;
    Node* tail;

    linkedList() : head(nullptr), tail(nullptr) {}

    void addToTheHead(int value); // добавление элемента в голову
    void addToTheEnd(int value); // добавление элемента в хвост
    void removeFromTheHead(); // удаление элемента с головы
    void removeFromTheEnd(); // удаление элемента с хвоста
    void removeByValue(int value); // удаление элемента по значению
    void searchByValue(int value); // поиск элемента по значению
    void display();
};

struct Queue{
    Node* head;
    Node* tail;
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    void push(int value); //добавление
    void pop(); //удаление
    void display(); //вывод на экран
};

struct Stack {
    Node* top;
    Stack(){
        top = nullptr;
    }
    void push(int value); //добавление
    void pop(); //удаление
    void display(); //вывод стека
};

struct AVLTree {
    Node* root;

    AVLTree() : root(nullptr) {}

    int height(Node* node); // высота узла
    int balanceFactor(Node* node); // вычисляет баланс
    void updateHeight(Node* node); // обновляет высоту дерева на основе дочерних узлов
    Node* rotateRight(Node* y); // правый поворот для балансировки дерева
    Node* rotateLeft(Node* x); // левый поворот для балансировки дерева
    Node* balance(Node* node); // проверяет баланс и выполняет повороты, если нужно
    Node* insert(Node* node, int key); // вставляем узел в дерево и балансируем
    Node* minValueNode(Node* node); // находим самый левый узел (минимальное значение)
    Node* remove(Node* node, int key); // удаляем узел и балансируем
    bool search(Node* node, int key); // проверяем есть ли узел в дереве с нужным значением
    void inOrder(Node* node); // симметричный обход
};