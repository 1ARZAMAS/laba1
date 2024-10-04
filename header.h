#include <iostream>
#include "node.h"
#pragma once

using namespace std;

struct Array {
    Node* head; // указываем на первый узел
    int size; //текущий размер списка
    int capacity; // максимальная вместимость массива
    
    Array() : head(nullptr), size(0), capacity(0) {}

    Array(int max) : head(nullptr), size(0), capacity(max) {}
    // инициализируем head с nullptr, размер нулевой и максимальное значение массива

    void add(int index, std::string value);
    void addToTheEnd(std::string value);
    std::string get(int index);
    void remove(int index);
    void replace(int index, std::string value);
    int length();
    void display();
};

struct DoubleLinkedList{
    Node* head;
    Node* tail;

    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void addToTheHead(std::string value); // добавление элемента в голову
    void addToTheEnd(std::string value); // добавление элемента в хвост
    void removeFromTheHead(); // удаление элемента с головы
    void removeFromTheEnd(); // удаление элемента с хвоста
    void removeByValue(std::string value); // удаление элемента по значению
    bool searchByValue(std::string value); // поиск элемента по значению
    void display();
};

struct linkedList{
    Node* head;
    Node* tail;

    linkedList() : head(nullptr), tail(nullptr) {}

    void addToTheHead(std::string value); // добавление элемента в голову
    void addToTheEnd(std::string value); // добавление элемента в хвост
    void removeFromTheHead(); // удаление элемента с головы
    void removeFromTheEnd(); // удаление элемента с хвоста
    void removeByValue(std::string value); // удаление элемента по значению
    void searchByValue(std::string value); // поиск элемента по значению
    void display();
};

struct Queue{
    Node* head;
    Node* tail;
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    void push(std::string value); //добавление
    void pop(); //удаление
    void display(); //вывод на экран
};

struct Stack {
    Node* top;
    Stack(){
        top = nullptr;
    }
    void push(std::string value); //добавление
    void pop(); //удаление
    void display(); //вывод стека
};

struct AVLTree {
    Node2* root; // Указатель на корень дерева

    AVLTree() : root(nullptr) {}

    int height(Node2* node); // высота узла
    int balanceFactor(Node2* node); // вычисляет баланс
    void updateHeight(Node2* node); // обновляет высоту дерева на основе дочерних узлов
    Node2* rotateRight(Node2* y); // правый поворот для балансировки дерева
    Node2* rotateLeft(Node2* x); // левый поворот для балансировки дерева
    Node2* balance(Node2* node); // проверяет баланс и выполняет повороты, если нужно
    Node2* insert(Node2* node, std::string key); // вставляем узел в дерево и балансируем
    Node2* minValueNode(Node2* node); // находим самый левый узел (минимальное значение)
    Node2* remove(Node2* node, std::string key); // удаляем узел и балансируем
    bool search(Node2* node, std::string key); // проверяем есть ли узел в дереве с нужным значением
    void inOrder(Node2* node); // симметричный обход
};

const int SIZE = 500;

struct HashTableItem {
    std::string key;
    std::string data;
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
    int HashFun(const std::string& key);
    HashTableItem* createItem(const std::string& key, std::string data);
    void push(const std::string& key, std::string data);
    void get(const std::string& key);
    void pop(const std::string& key);
};
