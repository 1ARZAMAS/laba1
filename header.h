#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include "node.h"
#pragma once

using namespace std;

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


void processQuery(const std::string& query);