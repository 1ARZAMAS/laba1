#include "header.h"
#include "node.h"

void Stack::push(int value){
    Node* node = new Node{value, nullptr};
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
        Node* temp = top;
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
        Node* current = top;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// int main(){
//     system("chcp 65001");
//     Stack stack;

//     stack.push(10);
//     stack.display();

//     stack.push(20);
//     stack.display();

//     stack.push(30);
//     stack.display();

//     stack.pop();
//     stack.display();

//     stack.pop();
//     stack.display();

//     stack.pop();
//     stack.display();
//     stack.pop(); // Проверка на пустой стек

//     return 0;
// }