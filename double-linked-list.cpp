#include "header.h"
#include "node.h"

// struct Node{
//     int data;
//     Node* next; // Указатель на следующий узел
//     Node* prev; // Указатель на предыдущий узел

//     Node(int value) : data(value), next(nullptr), prev(nullptr) {}
// };



void doubleLinkedList::addToTheHead(int value){ // Добавление в самое начало
    Node* newNode = new Node(value);
    if (head == nullptr){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void doubleLinkedList::addToTheEnd(int value){
    Node* newNode = new Node(value);
    if (head == nullptr){
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void doubleLinkedList::removeFromTheHead(){// удаление элемента с головы
    if (head == nullptr){
        cout << "Удаление невозможно: список пустой" << endl;
        return;
    } else{
        Node* temp = head;
        head->next->prev = nullptr;
        head = head->next;//удаляем первый элемент
        delete temp;
    }
}

void doubleLinkedList::removeFromTheEnd(){// удаление элемента с хвоста
    if (head == nullptr){
        cout << "Удаление невозможно: список пустой" << endl;
        return;
    }
    if (head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    
    Node* current = tail;
    tail->prev->next = nullptr;
    tail = tail->prev; // Удаляем последний элемент
    delete current;
}

void doubleLinkedList::removeByValue(int value){ // удаление элемента по значению
    if (head == nullptr){
        cout << "Невозможно удалить элемент: список пуст" << endl;
        return;
    }
    if (value == head->data){
        removeFromTheHead();
        return;
    }
    if (value == tail->data){
        removeFromTheEnd();
        return;
    }
    
    Node* current = head;
    while (current->next && current->next->data != value){ // Пока вообще можем идти по списку
    // и пока значение не будет равно нужному
        current = current->next;
    }
    if (current->next == nullptr){
        cout << "Такого значения нет в списке" << endl;
        return;
    }

    if (current->prev){ // если существует предудущий узел, то мы указываем предыдущему
        current->prev->next = current->next; // указывать на следующий текущему
    } else { // если это голова, те предыдущего узла нет, то обновляем, чтобы голова 
        head = current->next; // указывала на следующий узел
    }

    if (current->next){ // если существует следующий узел, то мы указываем чтобы следующий
        current->next->prev = current->prev; // указывал на предыдущий текущему
    } else { // если это хвост, то следующего нет, то обновляем, чтобы он указывал на предыдущий
        tail = current->prev;
    }
    delete current; // и удаляем текущий
}

void doubleLinkedList::searchByValue(int value){ // поиск элемента по значению
    Node* current = head;
    while (current->next && current->data != value) {
        current = current->next;
    }
    if (current->data == value){
        cout << "Значение " << current->data << " существует в списке" << endl;
    } else {
        cout << "Такого элемента " << current->data << " нет в списке" << endl;
    }
}

void doubleLinkedList::display(){
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// int main(){
//     doubleLinkedList list;

//     // Добавление элементов в список
//     list.addToTheEnd(10);
//     list.addToTheEnd(20);
//     list.addToTheEnd(30);
//     list.addToTheHead(5);

//     // Отображение списка
//     cout << "Список после добавления элементов: ";
//     list.display();

//     // Поиск элемента
//     list.searchByValue(20);
//     list.searchByValue(5);

//     // Удаление элемента с головы
//     list.removeFromTheHead();
//     cout << "Список после удаления головы: ";
//     list.display();

//     // Удаление элемента с хвоста
//     list.removeFromTheEnd();
//     cout << "Список после удаления хвоста: ";
//     list.display();

//     // Удаление элемента по значению
//     list.removeByValue(20);
//     cout << "Список после удаления элемента 20: ";
//     list.display();

//     list.removeByValue(40); // Пытаемся удалить несуществующий элемент

//     return 0;
// }