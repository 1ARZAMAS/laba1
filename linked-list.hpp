#include "header.h"

struct LLNode {
    std::string data;
    LLNode* next;

    LLNode(std::string value) : data(value), next(nullptr) {}
};

struct LinkedList {
    LLNode* head;

    LinkedList() : head(nullptr) {}

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
}

void LinkedList::removeFromTheHead() {
    if (head == nullptr) {
        std::cout << "Удаление невозможно: список пустой" << std::endl;
        return;
    }
    LLNode* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::removeFromTheEnd() {
    if (head == nullptr) {
        std::cout << "Удаление невозможно: список пустой" << std::endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    LLNode* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next; // Удаляем последний узел
    current->next = nullptr; // Обнуляем указатель на последний элемент
}

void LinkedList::removeByValue(std::string value) {
    if (head == nullptr) {
        std::cout << "Невозможно удалить элемент: список пуст" << std::endl;
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
        std::cout << "Такого значения нет в списке" << std::endl;
        return;
    }
    LLNode* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void LinkedList::searchByValue(std::string value) {
    LLNode* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }
    if (current != nullptr) {
        std::cout << "Значение " << current->data << " существует в списке" << std::endl;
    } else {
        std::cout << "Такого элемента нет в списке" << std::endl;
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
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
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
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }
    std::string value;
    while (file >> value) {
        addToTheEnd(value);
    }
}
