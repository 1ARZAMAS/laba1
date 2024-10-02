#include "header.h"
#include "node.h"

void Array::add(int index, int value) {
    if (index < 0 || index > size || size >= capacity) {
        cout << "Невозможно добавить элемент. Ошибка индекса или превышен максимальный размер." << endl;
        return;
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

void Array::addToTheEnd(int value) { // вызываем предыдущую функцию и как параметр указываем 
    add(size, value); //текущий размер массива, чтобы добавить в конец
}

int Array::get(int index) {
    if (index < 0 || index >= size) {
        cout << "Неверный индекс!" << endl;
        return -1; // Возвращаем -1 в случае ошибки
    }
    Node* current = head;
    for (int i = 0; i < index; i++) { // проходимся до нужного индекса
        current = current->next;
    }
    return current->data; // и возвращаем значение узла
}

void Array::remove(int index) {
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

void Array::replace(int index, int value) {
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

int Array::length() {
    return size;
}

void Array::display() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// int main() {
//     system("chcp 65001");
//     Array arr(5); // Максимальный размер 5

//     arr.addToTheEnd(10);
//     arr.addToTheEnd(20);
//     arr.add(1, 15);
//     arr.display(); // вывод: 10 15 20

//     arr.replace(1, 12);
//     arr.display(); // вывод: 10 12 20

//     arr.remove(0);
//     arr.display(); // вывод: 12 20

//     cout << "Элемент по индексу 0: " << arr.get(0) << "\n"; // вывод: 12
//     cout << "Длина массива: " << arr.length() << "\n"; // вывод: 2

//     // Попробуем добавить больше элементов, чем максимальный размер
//     arr.addToTheEnd(30);
//     arr.display();
//     arr.addToTheEnd(40);
//     arr.display();
//     arr.addToTheEnd(50);
//     arr.display();
//     arr.addToTheEnd(60); // Это должно вызвать сообщение об ошибке

//     return 0;
// }
