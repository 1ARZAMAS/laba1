#include "header.h"
#include "node.h"
// struct Node{
//     int data;
//     Node* next;
// };



void Queue::push(int value){
    Node* node = new Node {value, nullptr};
    if (head == nullptr){
        head = node;
        tail = node;
    } else {
        tail->next = node; //устанавливаем указатель текущего хвоста на новый узел
        tail = node;
    }
}

void Queue::pop(){
    if(head == nullptr){
        cout << "Очередь пуста!" << endl;
    } else {
        Node* temp = head;
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
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// int main(){
//     system("chcp 65001");
//     Queue queue;

//     queue.push(10);
//     queue.display();

//     queue.push(20);
//     queue.display();

//     queue.push(30);
//     queue.display();

//     queue.pop();
//     queue.display();

//     queue.pop();
//     queue.display();

//     queue.pop();
//     queue.display();
//     return 0;
// }