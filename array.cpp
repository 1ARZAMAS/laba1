#include "header.h"
#include "node.h"

struct Array { // done
    std::string* array;
    Node* head;
    int size; //текущий размер списка
    int capacity; // максимальная вместимость массива
    
    Array(size_t cap = 15) : size(0), capacity(cap) { // конструктор для создания
        array = new string[capacity]; // выделение памяти
    }

    ~Array() {
        delete[] array; // освобождение памяти
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

void Array::resize() { // расширение
    capacity *= 2; // увеличиваем максимальный размер в 2 раза
    string* newArr = new string[capacity]; // выделяем память для нового массива
    for (size_t i = 0; i < size; ++i) {
        newArr[i] = array[i]; // копируем элементы в новый массив
    }
    delete[] array; // удаляем старый массив
    array = newArr;
}

void Array::add(int index, std::string value) {
    if (index < 0 || index > size) {
        cout << "Невозможно добавить элемент. Ошибка индекса." << endl;
        return;
    }
    if (size >= capacity){
        resize();
    }

    Node* newNode = new Node(value); // создаем новый узел с указанным значением
    if (index == 0) { // если индекс нулевой, то новый узел = голова списка
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) { // тут проходимся до указанного индекса
            current = current->next;
        }
        newNode->next = current->next; // вставляем новый узел
        current->next = newNode;
    }
    size++;
}

void Array::addToTheEnd(std::string value) { // вызываем предыдущую функцию и как параметр указываем 
    if (size >= capacity){
        resize();
    }
    add(size, value); //текущий размер массива, чтобы добавить в конец
}

void Array::get(int index) {
    if (size == 0){
        cout << "Массив пуст!" << endl;
        return;
    }
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!" << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) { // проходимся до нужного индекса
        current = current->next;
    }
    cout << "Элемент по индексу " << index << ": " << current->data << endl;
    return;
}

void Array::remove(int index) {
    if (size == 0){
        cout << "Массив пуст!" << endl;
        return;
    }
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!" << endl;
        return;
    }

    Node* toDelete = nullptr;
    if (index == 0) { // если индекс нулевой, удаляем голову
        toDelete = head;
        head = head->next;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++) { // находим узел перед удаляемым
            current = current->next;
        } 
        // и перенаправляем его указатель на следующий узел
        toDelete = current->next; // сохраняем указатель на узел, который хотим удалить
        current->next = toDelete->next; //перенаправляем указатель на следующий, после удаляемого
    }
    delete toDelete;
    size--;
}

void Array::replace(int index, std::string value) {
    if (size == 0){
        cout << "Массив пуст!" << endl;
        return;
    }
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!" << endl;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = value;
}

void Array::length() {
    cout << "Длина массива: " << size << endl;
    return;
}

void Array::display() {
    if (size == 0){
        cout << "Массив пуст!" << endl;
        return;
    }
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Загрузка данных из файла
void Array::loadFromFile(const std::string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        addToTheEnd(line); // добавляем в конец массива
    }
    file.close();
}

// Сохранение данных в файл
void Array::saveToFile(const std::string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла: " << filename << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr){
        file << current->data << endl;
        current = current->next;
    }

    file.close();
    const_cast<Array*>(this)->size = 0; // очистка массива
}