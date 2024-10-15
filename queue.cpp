#include "header.h"

struct QueueNode {
    std::string data;
    QueueNode* next;

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
    QueueNode* newNode = new QueueNode(value);
    if (head == nullptr){
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode; //устанавливаем указатель текущего хвоста на новый узел
        tail = newNode;
    }
}

void Queue::pop(){
    if(head == nullptr){
        cout << "Очередь пуста!" << endl;
    } else {
        QueueNode* temp = head;
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
        QueueNode* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Сохранение очереди в файл
void Queue::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
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
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }
    std::string value;
    while (std::getline(file, value)) {
        push(value);
    }
    file.close();
}
