#include <iostream>
#include "node.h"
#pragma once

using namespace std;

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
    Node2* root;

    AVLTree() : root(nullptr) {}

    int height(Node2* node); // высота узла
    int balanceFactor(Node2* node); // вычисляет баланс
    void updateHeight(Node2* node); // обновляет высоту дерева на основе дочерних узлов
    Node2* rotateRight(Node2* y); // правый поворот для балансировки дерева
    Node2* rotateLeft(Node2* x); // левый поворот для балансировки дерева
    Node2* balance(Node2* node); // проверяет баланс и выполняет повороты, если нужно
    Node2* insert(Node2* node, int key); // вставляем узел в дерево и балансируем
    Node2* minValueNode(Node2* node); // находим самый левый узел (минимальное значение)
    Node2* remove(Node2* node, int key); // удаляем узел и балансируем
    bool search(Node2* node, int key); // проверяем есть ли узел в дереве с нужным значением
    void inOrder(Node2* node); // симметричный обход
};

const int SIZE = 500;

struct HashTableItem {
    string key;
    int data;
    HashTableItem* next; // Указатель на следующий элемент в цепочке
};

struct HashTable {
    HashTableItem* items[SIZE];
    int count;

    HashTable() : count(0) {//заполнение таблицы
        for (int i = 0; i < SIZE; i++) { // все элементы nullptr
            items[i] = nullptr;
        }
    }
    int HashFun(const string& key);
    HashTableItem* createItem(const string& key, int data);
    void push(const string& key, int data);
    void search(const string& key);
    void pop(const string& key);
};
