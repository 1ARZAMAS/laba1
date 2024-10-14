#include "header.h"

struct QueueNode {
    std::string data;
    Node* next;

    QueueNode(std::string value) : data(value), next(nullptr) {}
};

struct Queue{
    QueueNode* head;
    QueueNode* tail;
    Queue(){
        head = nullptr;
        tail = nullptr;
    }
    void push(std::string value); //добавление
    void pop(); //удаление
    void display(); //вывод на экран
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

void Queue::push(std::string value){
    QueueNode* node = new QueueNode {value, nullptr};
    if (head == nullptr){
        head = node;
        tail = node;
    } else {
        tail->next = node; //устанавливаем указатель текущего хвоста на новый узел
        tail = node;
    }
}

void Queue::pop(){
    if(head == nullptr){
        cout << "Очередь пуста!" << endl;
    } else {
        Node* temp = head;
        head = head->next; //удаляем первый элемент очереди
        cout << "Удаленный элемент: " << temp->data << endl;
        delete temp;
        if (head == nullptr){ //если очередь пуста, то голова и конец = nullptr
            tail = nullptr;
        }
    }
}
    
void Queue::display(){
    if (head == nullptr){
        cout << "Очередь пуста!" << endl;
    } else {
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Сохранение очереди в файл
void Queue::saveToFile(const std::string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    QueueNode* current = head;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Загрузка очереди из файла
void Queue::loadFromFile(const std::string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    std::string value;
    while (file >> value) {
        enqueue(value);
    }
    file.close();
}
