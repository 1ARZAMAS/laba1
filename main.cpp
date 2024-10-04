#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "header.h"
#include "node.h"

using namespace std;

map<string, HashTable> hashTables;
map<string, Stack> stacks;
map<string, Queue> queues;

// Обработка команды
void processQuery(const string& query) {
    stringstream ss(query);
    string command;
    ss >> command;
    // ----------ARRAY------

    // void add(int index, int value);
    // void addToTheEnd(int value);
    // int get(int index);
    // void remove(int index);
    // void replace(int index, int value);
    // int length();
    // void display();
    if (command == "APUSH"){ // добавление элемента в конец

    }
    else if (command == "AINSERT"){ // добавление элемента по индексу

    }
    else if (command == "APOP"){ // удаление элемента по индексу

    }
    else if (command == "AREPLACE"){ // замена элемента по индексу

    }
    else if (command == "ALENGTH"){ // длина массива

    }
    else if (command == "AGET"){ // получение элемента по индексу

    }
    else if (command == "AREAD"){ // чтение 

    }

    // ----------LIST-------

    // void addToTheHead(int value); // добавление элемента в голову
    // void addToTheEnd(int value); // добавление элемента в хвост
    // void removeFromTheHead(); // удаление элемента с головы
    // void removeFromTheEnd(); // удаление элемента с хвоста
    // void removeByValue(int value); // удаление элемента по значению
    // void searchByValue(int value); // поиск элемента по значению
    // void display();
    else if (command == "LPUSH_HEAD"){ // добавление элемента в голову

    }
    else if (command == "LPUSH_TAIL"){ // добавление элемента в хвост

    }
    else if (command == "LPOP_HEAD"){ // удаление элемента с головы

    }
    else if (command == "LPOP_TAIL"){ // удаление элемента с хвоста

    }
    else if (command == "LPOP_VALUE"){ // удаление элемента по значению

    }
    else if (command == "LSEARCH"){ // поиск элемента по значению

    }
    else if (command == "LREAD"){ // чтение

    }

    // ----------QUEUE-------


    else if (command == "QPUSH"){ // Добавление элемента

    }
    else if (command == "QPOP"){ // удаление элемента
        string queueName;
        ss >> queueName;
        queues[queueName].pop();
    }
    else if (command == "QREAD"){ //вывод на экран

    }
    
    // ----------STACK-------
    else if (command == "SPUSH"){ // Добавление элемента
        string stackName;
        int item;
        ss >> stackName >> item;
        stacks[stackName].push(item);
    }
    else if (command == "SPOP"){ // удаление элемента

    }
    else if (command == "SREAD"){ //вывод на экран

    }

    // ----------HASH-TABLE-------
    // void push(const string& key, int data);
    // void search(const string& key);
    // void pop(const string& key);

    else if (command == "HPUSH"){ // Добавление элемента
        string hashName, key;
        int value;
        ss >> hashName >> key >> value;
        hashTables[hashName].push(key, value);
    }
    else if (command == "HPOP"){ // Удаление элемента

    }
    else if (command == "HGET"){ // Получение значения по ключу

    }

    // ----------TREE-------
    // Node2* insert(Node2* node, int key); // вставляем узел в дерево и балансируем
    // Node2* remove(Node2* node, int key); // удаляем узел и балансируем
    // bool search(Node2* node, int key); // проверяем есть ли узел в дереве с нужным значением
    // void inOrder(Node2* node); // симметричный обход

    else if (command == "TPUSH"){

    }
    else if (command == "TSEARCH"){

    }
    else if (command == "TPOP"){

    }
    else if (command == "TREAD"){

    }
    else {
        cout << "Неизвестная команда: " << command << endl;
    }
}

// Загрузка данных из файла
void loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        processQuery(line);
    }
    file.close();
}

// Сохранение данных в файл
void saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    // Сохранение хэш-таблиц
    for (const auto& [name, hashTable] : hashTables) {
        for (int i = 0; i < SIZE; ++i) {
            HashTableItem* item = hashTable.items[i];
            while (item != nullptr) {
                file << "HSET " << name << " " << item->key << " " << item->data << endl;
                item = item->next;
            }
        }
    }

    // Сохранение стеков
    for (const auto& [name, stack] : stacks) {
        Node* current = stack.top;
        while (current != nullptr) {
            file << "SPUSH " << name << " " << current->data << endl;
            current = current->next;
        }
    }

    // Сохранение очередей
    for (const auto& [name, queue] : queues) {
        Node* current = queue.head;
        while (current != nullptr) {
            file << "QPOP " << name << endl; // Просто указываем имя очереди, так как QPOP удаляет элемент
            current = current->next;
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {
    system("chcp 65001");
    string filename;

    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--file") {
            if (i + 1 < argc) {
                filename = argv[++i];
            }
        }
    }

    // Загружаем данные из файла
    if (!filename.empty()) {
        loadFromFile(filename);
    }

    // Интерактивный ввод команд
    string query;
    cout << "Введите команды (или 'exit' для выхода):" << endl;
    while (true) {
        cout << "> ";
        getline(cin, query);
        if (query == "exit") {
            break; // Выход из цикла
        }
        processQuery(query);
    }

    // Сохраняем данные обратно в файл
    if (!filename.empty()) {
        saveToFile(filename);
    }

    return 0;
}
