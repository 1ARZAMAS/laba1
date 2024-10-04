#include "header.h"
#include "node.h"

void DoubleLinkedList::addToTheHead(std::string value){ // Добавление в самое начало
    Node* newNode = new Node(value);
    if (head == nullptr){
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoubleLinkedList::addToTheEnd(std::string value){
    Node* newNode = new Node(value);
    if (head == nullptr){
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void DoubleLinkedList::removeFromTheHead(){// удаление элемента с головы
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

void DoubleLinkedList::removeFromTheEnd(){// удаление элемента с хвоста
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

void DoubleLinkedList::removeByValue(std::string value){ // удаление элемента по значению
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

bool DoubleLinkedList::searchByValue(std::string value){ // поиск элемента по значению
    Node* current = head;
    while (current->next && current->data != value) {
        current = current->next;
    }
    if (current->data == value){
        cout << "Значение " << current->data << " существует в списке" << endl;
        return true;
    } else {
        cout << "Такого элемента " << current->data << " нет в списке" << endl;
        return false;
    }
}

void DoubleLinkedList::display(){
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
