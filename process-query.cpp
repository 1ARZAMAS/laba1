#include "header.h"
#include "node.h"

// Array array; // создание массива
// LinkedList linkedList; // создание односвзяного листа
// DoubleLinkedList doubleLinkedList; // создание двусвязного листа
// Queue queue; // создание очереди
// Stack stack; // создание стэка
// AVLTree tree; // создание дерева
// HashTable hash_table = HashTable(); // создание хэш-таблицы

void processQuery(const std::string& query) {
    std::stringstream ss(query);
    std::string command;
    ss >> command;
    // ----------ARRAY------
    // if (command == "APUSH"){ // добавление элемента в конец
    //     std::string arrayName;
    //     std::string value;
    //     ss >> arrayName >> value;
    //     if (arrays.find(arrayName) != arrays.end()) {
    //         arrays[arrayName].addToTheEnd(value);
    //     } else {
    //         cout << "Массив не найден: " << arrayName << endl;
    //     }
    // }
    //  else if (command == "AINSERT") { // добавление элемента по индексу 
    //     std::string arrayName;
    //     int index;
    //     std::string value;
    //     ss >> arrayName >> index >> value;
    //     arrays[arrayName].add(index, value);
    // }
    // else if (command == "APOP") { // удаление элемента по индексу
    //     std::string arrayName;
    //     int index;
    //     ss >> arrayName >> index;
    //     arrays[arrayName].remove(index);
    // }
    // else if (command == "AREPLACE") { // замена элемента по индексу
    //     std::string arrayName;
    //     int index;
    //     std::string value;
    //     ss >> arrayName >> index >> value;
    //     arrays[arrayName].replace(index, value);
    // }
    // else if (command == "ALENGTH") { // длина массива
    //     std::string arrayName;
    //     ss >> arrayName;
    //     cout << arrays[arrayName].length() << endl;
    // }
    // else if (command == "AGET") { // получение элемента по индексу
    //     std::string arrayName;
    //     int index;
    //     ss >> arrayName >> index;
    //     cout << arrays[arrayName].get(index) << endl;
    // }
    // else if (command == "AREAD") { // чтение
    //     std::string arrayName;
    //     ss >> arrayName;
    //     arrays[arrayName].display();
    // }

    // ----------LIST-------
    // else if (command == "LPUSH_HEAD"){ // добавление элемента в голову
    //     std::string listName;
    //     std::string value;
    //     ss >> listName >> value;
    //     doubleLinkedLists[listName].addToTheHead(value);
    // }
    // else if (command == "LPUSH_TAIL"){ // добавление элемента в хвост
    //     std::string listName;
    //     std::string value;
    //     ss >> listName >> value;
    //     doubleLinkedLists[listName].addToTheEnd(value);
    // }
    // else if (command == "LPOP_HEAD"){ // удаление элемента с головы !!!!!!!!!!!!!!!!!!!!!!!!!!! убежище завершил мне программу после этой команды >:(
    //     std::string listName;
    //     ss >> listName;
    //     doubleLinkedLists[listName].removeFromTheHead();
    // }
    // else if (command == "LPOP_TAIL"){ // удаление элемента с хвоста
    //     std::string listName;
    //     ss >> listName;
    //     doubleLinkedLists[listName].removeFromTheEnd();
    // }
    // else if (command == "LPOP_VALUE"){ // удаление элемента по значению
    //     std::string listName;
    //     std::string value;
    //     ss >> listName >> value;
    //     doubleLinkedLists[listName].removeByValue(value);
    // }
    // else if (command == "LSEARCH"){ // поиск элемента по значению
    //     std::string listName;
    //     std::string value;
    //     ss >> listName >> value;
    //     cout << (doubleLinkedLists[listName].searchByValue(value) ? "Found" : "Not Found") << endl;
    // }
    // else if (command == "LREAD"){ // чтение
    //     std::string listName;
    //     ss >> listName;
    //     doubleLinkedLists[listName].display();
    // }

    // ----------QUEUE-------
    // else if (command == "QPUSH"){ // Добавление элемента
    //     std::string queueName;
    //     std::string value;
    //     ss >> queueName >> value;
    //     queues[queueName].push(value);
    // }
    // else if (command == "QPOP"){ // удаление элемента
    //     std::string queueName;
    //     ss >> queueName;
    //     queues[queueName].pop();
    // }
    // else if (command == "QREAD"){ //вывод на экран
    //     std::string queueName;
    //     ss >> queueName;
    //     queues[queueName].display();
    // }
    
    // ----------STACK-------
    // else if (command == "SPUSH"){ // Добавление элемента
    //     std::string stackName;
    //     std::string item;
    //     ss >> stackName >> item;
    //     stacks[stackName].push(item);
    // }
    // else if (command == "SPOP"){ // удаление элемента
    //     std::string stackName;
    //     ss >> stackName;
    //     stacks[stackName].pop();
    // }
    // else if (command == "SREAD"){ //вывод на экран
    //     std::string stackName;
    //     ss >> stackName;
    //     stacks[stackName].display();
    // }

    // ----------HASH-TABLE-------
    // else if (command == "HPUSH"){ // Добавление элемента
    //     std::string hashName, key;
    //     std::string value;
    //     ss >> hashName >> key >> value;
    //     hashTables[hashName].push(key, value);
    // }
    // else if (command == "HPOP"){ // Удаление элемента
    //     std::string hashName, key;
    //     ss >> hashName >> key;
    //     hashTables[hashName].pop(key);
    // }
    // else if (command == "HGET"){ // Получение значения по ключу  дурка нихрена не выводит 
    //     std::string hashName, key;
    //     ss >> hashName >> key;
    //     hashTables[hashName].get(key); // Просто вызовите функцию без вывода
    // }

    // ----------TREE-------
    // else if (command == "TPUSH"){
    //     std::string treeName;
    //     std::string value;
    //     ss >> treeName >> value;
    //     trees[treeName].root = trees[treeName].insert(trees[treeName].root, value); // Обновите корень после вставки
    // }
    // else if (command == "TSEARCH"){
    //     std::string treeName;
    //     std::string value;
    //     ss >> treeName >> value;
    //     cout << (trees[treeName].search(trees[treeName].root, value) ? "Found" : "Not Found") << endl; // Передайте корень
    // }
    // else if (command == "TPOP"){
    //     std::string treeName;
    //     std::string value;
    //     ss >> treeName >> value;
    //     trees[treeName].root = trees[treeName].remove(trees[treeName].root, value); // Обновите корень после удаления
    // }
    // else if (command == "TREAD"){
    //     std::string treeName;
    //     trees[treeName].inOrder(trees[treeName].root); // Передайте корень
    // }
}