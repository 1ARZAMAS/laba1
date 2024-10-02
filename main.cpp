#include "header.h"

int main(){
    system("chcp 65001");
    Array arr(5); // Максимальный размер 5

    arr.addToTheEnd(10);
    arr.addToTheEnd(20);
    arr.add(1, 15);
    arr.display(); // вывод: 10 15 20

    arr.replace(1, 12);
    arr.display(); // вывод: 10 12 20

    arr.remove(0);
    arr.display(); // вывод: 12 20

    cout << "Элемент по индексу 0: " << arr.get(0) << "\n"; // вывод: 12
    cout << "Длина массива: " << arr.length() << "\n"; // вывод: 2

    // Попробуем добавить больше элементов, чем максимальный размер
    arr.addToTheEnd(30);
    arr.display();
    arr.addToTheEnd(40);
    arr.display();
    arr.addToTheEnd(50);
    arr.display();
    arr.addToTheEnd(60); // Это должно вызвать сообщение об ошибке

    cout << "\n" << endl;
    cout << "\n" << endl;

    doubleLinkedList Dlist;

    // Добавление элементов в список
    Dlist.addToTheEnd(10);
    Dlist.addToTheEnd(20);
    Dlist.addToTheEnd(30);
    Dlist.addToTheHead(5);

    // Отображение списка
    cout << "Список после добавления элементов: ";
    Dlist.display();

    // Поиск элемента
    Dlist.searchByValue(20);
    Dlist.searchByValue(5);

    // Удаление элемента с головы
    Dlist.removeFromTheHead();
    cout << "Список после удаления головы: ";
    Dlist.display();

    // Удаление элемента с хвоста
    Dlist.removeFromTheEnd();
    cout << "Список после удаления хвоста: ";
    Dlist.display();

    // Удаление элемента по значению
    Dlist.removeByValue(20);
    cout << "Список после удаления элемента 20: ";
    Dlist.display();

    Dlist.removeByValue(40); // Пытаемся удалить несуществующий элемент

    cout << "\n" << endl;
    cout << "\n" << endl;

    linkedList list;

    // Добавление элементов в список
    list.addToTheEnd(10);
    list.addToTheEnd(20);
    list.addToTheEnd(30);
    list.addToTheHead(5);

    // Отображение списка
    cout << "Список после добавления элементов: ";
    list.display();

    // Поиск элемента
    list.searchByValue(20);
    list.searchByValue(5);

    // Удаление элемента с головы
    list.removeFromTheHead();
    cout << "Список после удаления головы: ";
    list.display();

    // Удаление элемента с хвоста
    list.removeFromTheEnd();
    cout << "Список после удаления хвоста: ";
    list.display();

    // Удаление элемента по значению
    list.removeByValue(20);
    cout << "Список после удаления элемента 20: ";
    list.display();

    list.removeByValue(40); // Пытаемся удалить несуществующий элемент

    cout << "\n" << endl;
    cout << "\n" << endl;

    HashTable table;
    table.push("key1", 1);
    table.push("key2", 2);
    table.push("key3", 3);//заполнение

    table.search("key2");//поиск значения по ключу
    table.push("key2", 10);//если ввели одинаковый ключ - то перезаписываем
    table.search("key2");

    table.search("key1");  // 1
    table.search("key4");  // 0
    table.pop("key2");//удаление 
    table.search("key2");  // 0
    table.push("1key", 50);
    table.search("1key");  // 0

    
    cout << "\n" << endl;
    cout << "\n" << endl;

    Queue queue;

    queue.push(10);
    queue.display();

    queue.push(20);
    queue.display();

    queue.push(30);
    queue.display();

    queue.pop();
    queue.display();

    queue.pop();
    queue.display();

    queue.pop();
    queue.display();

    cout << "\n" << endl;
    cout << "\n" << endl;

    Stack stack;

    stack.push(10);
    stack.display();

    stack.push(20);
    stack.display();

    stack.push(30);
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();

    stack.pop();
    stack.display();
    stack.pop(); // Проверка на пустой стек

    
    cout << "\n" << endl;
    cout << "\n" << endl;

    AVLTree tree;

    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    cout << "Симметричный обход: ";
    tree.inOrder(tree.root);
    cout << endl;

    tree.root = tree.remove(tree.root, 30);
    cout << "После удаления 30, симметричный обход: ";
    tree.inOrder(tree.root);
    cout << endl;

}