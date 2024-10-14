#include "header.h"

struct ArrayNode {
    std::string data;
    ArrayNode* next;
    ArrayNode* prev;

    ArrayNode(const std::string& value, ArrayNode* nextNode = nullptr, ArrayNode* prevNode = nullptr)
        : data(value), next(nextNode), prev(prevNode) {}
};

struct Array {
    ArrayNode* head; // Указатель на голову списка
    int size; // Текущий размер списка
    int capacity; // Максимальная вместимость массива

    Array() : head(nullptr), size(0), capacity(10) {
        head = nullptr;
    }

    void resize();
    void add(int index, std::string value);
    void addToTheEnd(std::string value);
    void get(int index);
    void remove(int index);
    void replace(int index, std::string value);
    void length();
    void display();
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
};

void Array::resize() {
    capacity *= 2; // Увеличиваем максимальный размер в 2 раза
}

void Array::add(int index, std::string value) {
    if (index < 0 || index > size) {
        std::cout << "Невозможно добавить элемент. Ошибка индекса." << std::endl;
        return;
    }

    ArrayNode* newNode = new ArrayNode(value); // Создаем новый узел с указанным значением
    if (index == 0) { // Если индекс нулевой, то новый узел = голова списка
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
        ArrayNode* current = head;
        for (int i = 0; i < index - 1; i++) { // Проходимся до указанного индекса
            current = current->next;
        }
        newNode->next = current->next; // Вставляем новый узел
        newNode->prev = current; // Устанавливаем указатель на предыдущий узел
        if (current->next != nullptr) {
            current->next->prev = newNode; // Обновляем указатель у следующего узла
        }
        current->next = newNode;
    }
    size++;
}

void Array::addToTheEnd(std::string value) {
    add(size, value); // Текущий размер массива, чтобы добавить в конец
}

void Array::get(int index) {
    if (size == 0) {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }
    if (index < 0 || index >= size) {
        std::cout << "Неверный индекс!" << std::endl;
        return;
    }
    ArrayNode* current = head;
    for (int i = 0; i < index; i++) { // Проходимся до нужного индекса
        current = current->next;
    }
    std::cout << "Элемент по индексу " << index << ": " << current->data << std::endl;
}

void Array::remove(int index) {
    if (size == 0) {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }
    if (index < 0 || index >= size) {
        std::cout << "Неверный индекс!" << std::endl;
        return;
    }

    ArrayNode* toDelete = nullptr;
    if (index == 0) { // Если индекс нулевой, удаляем голову
        toDelete = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr; // Обновляем указатель на предыдущий узел
        }
    } else {
        ArrayNode* current = head;
        for (int i = 0; i < index - 1; i++) { // Находим узел перед удаляемым
            current = current->next;
        }
        toDelete = current->next; // Сохраняем указатель на узел, который хотим удалить
        if (toDelete->next != nullptr) {
            toDelete->next->prev = current; // Обновляем указатель у следующего узла
        }
        current->next = toDelete->next; // Перенаправляем указатель на следующий
    }
    delete toDelete;
    size--;
}

void Array::replace(int index, std::string value) {
    if (size == 0) {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }
    if (index < 0 || index >= size) {
        std::cout << "Неверный индекс!" << std::endl;
        return;
    }
    ArrayNode* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}

void Array::length() {
    std::cout << "Длина массива: " << size << std::endl;
}

void Array::display() {
    if (size == 0) {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }
    ArrayNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Array::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        addToTheEnd(line); // Добавляем в конец массива
    }
    file.close();
}

void Array::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    ArrayNode* current = head;
    while (current != nullptr) {
        file << current->data << std::endl;
        current = current->next;
    }
    file.close();
}