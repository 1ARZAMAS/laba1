#include "header.h"

struct CustomArray {
    string* data; // Массив строк
    int size; // Текущий размер списка
    int capacity; // Максимальная вместимость массива

    // Конструкторы
    CustomArray(int max);
    ~CustomArray();

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

CustomArray::CustomArray(int capacity) : capacity(capacity), size(0) {
    data = new string[capacity];
}

CustomArray::~CustomArray() {
    delete[] data; // Освобождаем память при уничтожении объекта
}

void CustomArray::add(int index, string value) {
    if (index < 0 || index > size || size >= capacity) {
        cout << "Index invalid or array is full" << endl;
        return;
    }
    // Сдвигаем элементы вправо начиная с указанного индекса
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value; // Вставляем элемент
    size++;
}

void CustomArray::addToTheEnd(string value) {
    if (size >= capacity) {
        cout << "Array is full" << endl;
        return;
    }
    data[size] = value; // Вставляем элемент в конец
    size++;
}

void CustomArray::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Index invalid" << endl;
        return;
    }
    // Сдвигаем элементы влево начиная с указанного индекса
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
}

void CustomArray::replace(int index, string value) {
    if (index < 0 || index >= size) {
        cout << "Index invalid" << endl;
        return;
    }
    data[index] = value; // Замена элемента на заданном индексе
}

void CustomArray::display() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void CustomArray::length() {
    std::cout << "Size of the array is: " << size << endl;
    return;
}

void CustomArray::get(int index) {
    if (size == 0) {
        std::cout << "Массив пуст!" << std::endl;
        return;
    }
    if (index < 0 || index >= size) {
        std::cout << "Неверный индекс!" << std::endl;
        return;
    }
    std::cout << "Элемент по индексу " << index << ": " << data[index] << std::endl;
}

void CustomArray::saveToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cout << "Cannot open file for writing: " << filename << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        outFile << data[i] << endl;
    }
    outFile.close();
}

void CustomArray::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cout << "Cannot open file for reading: " << filename << endl;
        return;
    }
    string line;
    size = 0; // Очищаем массив перед загрузкой
    while (getline(inFile, line) && size < capacity) {
        data[size] = line;
        size++;
    }
    inFile.close();
}