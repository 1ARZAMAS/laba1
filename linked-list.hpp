#include "header.h"

struct LLNode {
    std::string data;
    LLNode* next;

    LLNode(std::string value) : data(value), next(nullptr) {}
};

struct LinkedList {
    LLNode* head;

    LinkedList() : head(nullptr) {
        loadFromFile("linkedlist.data"); // Загружаем данные из файла при создании объекта
    }

    void addToTheHead(std::string value);
    void addToTheEnd(std::string value);
    void removeFromTheHead();
    void removeFromTheEnd();
    void removeByValue(std::string value);
    void searchByValue(std::string value);
    void display();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};

void LinkedList::addToTheHead(std::string value) {
    LLNode* newNode = new LLNode(value);
    newNode->next = head;
    head = newNode;
    saveToFile("linkedlist.data"); // Сохраняем после добавления
}

void LinkedList::addToTheEnd(std::string value) {
    LLNode* newNode = new LLNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        LLNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    saveToFile("linkedlist.data"); // Сохраняем после добавления
}

void LinkedList::removeFromTheHead() {
    if (head == nullptr) {
        std::cout << "Deletion is not possible: the list is empty" << std::endl;
        return;
    }
    LLNode* temp = head;
    head = head->next;
    delete temp;
    saveToFile("linkedlist.data"); // Сохраняем после добавления
}

void LinkedList::removeFromTheEnd() {
    if (head == nullptr) {
        std::cout << "Deletion is not possible: the list is empty" << std::endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        saveToFile("linkedlist.data"); // Сохраняем после добавления
        return;
    }
    LLNode* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next; // Удаляем последний узел
    current->next = nullptr; // Обнуляем указатель на последний элемент
    saveToFile("linkedlist.data"); // Сохраняем после добавления
}

void LinkedList::removeByValue(std::string value) {
    if (head == nullptr) {
        std::cout << "Deletion is not possible: the list is empty" << std::endl;
        return;
    }
    if (value == head->data) {
        removeFromTheHead();
        return;
    }
    LLNode* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }
    if (current->next == nullptr) {
        std::cout << "This value is not in the list" << std::endl;
        return;
    }
    LLNode* temp = current->next;
    current->next = temp->next;
    delete temp;
    saveToFile("linkedlist.data"); // Сохраняем после добавления
}

void LinkedList::searchByValue(std::string value) {
    LLNode* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }
    if (current != nullptr) {
        std::cout << "Value " << current->data << " is in the list" << std::endl;
    } else {
        std::cout << "There is no " << value << " in the list" << std::endl;
    }
}

void LinkedList::display() {
    LLNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Cannot open file for writing: " << filename << std::endl;
        return;
    }
    LLNode* current = head;
    while (current != nullptr) {
        file << current->data << std::endl;
        current = current->next;
    }
}

void LinkedList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Cannot open file for reading: " << filename << std::endl;
        return;
    }
    std::string value;
    while (file >> value) {
        addToTheEnd(value);
    }
}
