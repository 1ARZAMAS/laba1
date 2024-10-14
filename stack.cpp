#include "header.h"

struct StackNode {
    std::string data;
    StackNode* next;

    StackNode(std::string value) : data(value), next(nullptr) {}
};

struct Stack {
    StackNode* top;
    Stack(){
        top = nullptr;
    }
    ~Stack() {
        clear();  // Очистка памяти при удалении стека
    }
    void push(std::string value); //добавление
    void pop(); //удаление
    void display(); //вывод стека
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

void Stack::push(std::string value){
    StackNode* node = new StackNode(value);
    if (top == nullptr){ // если стек пустой
        top = node; // то top = введеное значение
    } else {
        node->next = top; // если стек не пустой, то тогда предыдущая top 
        top = node; // станет 2м значением, новое значение = top
    }
}

void Stack::pop(){
    if (top == nullptr){
        cout << "Стек пустой, удалить значение невозможно" << endl;
    } else {
        StackNode* temp = top;
        top = top->next;
        cout << "Удаленный элемент: " << temp->data << endl;
        delete temp;
    }
}
    
void Stack::display(){
    if (top == nullptr){
        cout << "Стек пустой" << endl;
    } else {
        cout << "Стек состоит из следующих элементов: ";
        StackNode* current = top;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void Stack::saveToFile(const std::string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    StackNode* current = top;
    while (current != nullptr) {
        file << current->data << endl;
        current = current->next;
    }
    file.close();
}

// Загрузка стека из файла
void Stack::loadFromFile(const std::string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }
    std::string value;
    clear();  // Сбрасываем текущий стек перед загрузкой
    while (file >> value) {
        push(value);
    }
    file.close();
}