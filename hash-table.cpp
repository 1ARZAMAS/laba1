#include "header.h"
#include "node.h"

const int SIZE = 500;

// struct Node {
//     string data;
//     Node* next;
//     Node* prev;

//     Node(const string& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
//         : data(value), next(nextNode), prev(prevNode) {
//     }
// };

struct HashTableItem {
    string key;
    int data;
    HashTableItem* next; // Указатель на следующий элемент в цепочке
};

struct HashTable {
    HashTableItem* items[SIZE];
    int count;

    HashTable() : count(0) {//заполнение таблицы
        for (int i = 0; i < SIZE; i++) { // все элементы nullptr
            items[i] = nullptr;
        }
    }
    int HashFun(const string& key);
    HashTableItem* createItem(const string& key, int data);
    void push(const string& key, int data);
    void search(const string& key);
    void pop(const string& key);
};

int HashTable::HashFun(const string& key) {//хэш функция
    const int prime = 43; // простое число
    int hash = 0;
    for (char letter : key) {
        hash = (hash * prime + static_cast<int>(letter)) % SIZE;//хэширование через ASCII
    } // остаток от деления, чтобы гарантировать, что значение будет в пределах массива
    return hash;
}

HashTableItem* HashTable::createItem(const string& key, int data) {//создание элемента таблицы
    return new HashTableItem{ key, data, NULL };
}

void HashTable::push(const string& key, int data) {
    if (count >= SIZE) {
        cout << "Table is full" << endl;
        return;
    }

    int index = HashFun(key);
    HashTableItem* item = createItem(key, data);

    if (items[index] == NULL) {
        items[index] = item; // вставляем как первый элемент в ячейке
        count++;
    }
    else {
        HashTableItem* current = items[index];
        if (current->key == key) {
            current->data = data; // Обновляем существующий ключ
            delete item; // Удаляем новый элемент, так как ключ уже существует
        }
        else {
            current->next = item; // Добавляем новый элемент в конец цепочки
            count++;
        }
    }
}

void HashTable::search(const string& key) {
    if (count == 0) {
        cout << "Table is empty" << endl;
        return;
    }

    int index = HashFun(key);
    HashTableItem* current = items[index];
    while (current != NULL) {
        if (current->key == key) {
            cout << "такой элемент существует" << current->data << endl; // Найден элемент с указанным ключом
            return;
        }
        current = current->next;
    }

    cout << "Такого элемента не существует" << endl; // Элемент не найден
}

void HashTable::pop(const string& key) { // Функция удаления

    if (count == 0) { // Если таблица пустая, ничего не делаем
        return;
    }

    int index = HashFun(key); // Находим элемент по ключу
    HashTableItem* item = items[index];

    if (item != nullptr) { // Если элемент есть

        if (item->key == key && item->next == NULL) { // Если ключ совпадает и это единственный элемент в списке
            delete items[index];
            items[index] = NULL;
            count--;
            return;
        }
        else {
            // если ключ совпадает, но это не единственный элемент
            if (item->key == key) {
                delete items[index];
                items[index] = item->next;
                return;
            }
            //если ключ не совпал
            else {
                //пока не найдем элемент в списке с таким ключом, или пока список не закончился
                while (item->next->key != key && item->next != NULL) {
                    item = item->next;
                }
                //если нашли
                if (item->next->key == key) {
                    delete item->next;
                    item->next = NULL;
                    return;
                }
            }
        }
    }
    cout << "Такого элемента нет в таблице" << endl;
}


// int main(){
//     HashTable table;
//     table.push("key1", 1);
//     table.push("key2", 2);
//     table.push("key3", 3);//заполнение

//     table.search("key2");//поиск значения по ключу
//     table.push("key2", 10);//если ввели одинаковый ключ - то перезаписываем
//     table.search("key2");

//     table.search("key1");  // 1
//     table.search("key4");  // 0
//     table.pop("key2");//удаление 
//     table.search("key2");  // 0
//     table.push("1key", 50);
//     table.search("1key");  // 0

// }