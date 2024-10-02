#include "header.h"
#include "node.h"

int AVLTree::height(Node2* node) { // высота узла
    if (node){// возвращает высоту узла 0, если узел пуст
        return node->height;
    } else {
        return 0;
    }
}

int AVLTree::balanceFactor(Node2* node) {// вычисляет баланс
    if (node){
        return height(node->left) - height(node->right);
    } else {
        return 0;
    }
}

void AVLTree::updateHeight(Node2* node) {// обновляет высоту дерева на основе дочерних узлов
    if (node) {
        node->height = max(height(node->left), height(node->right)) + 1; // максимальное значение + 1 для текущего узла
    }
}

// Когда у баланс больше 1, а х больше 0
Node2* AVLTree::rotateRight(Node2* y) {// правый поворот для балансировки дерева
    Node2* x = y->left; // x - левый ребенок y
    Node2* T2 = x->right; // T2 - правый ребенок x
    x->right = y; // x становится новым корнем, y - правым ребенком x
    y->left = T2; // T2 теперь - левым ребенком y
    updateHeight(y); // обновляем высоту y
    updateHeight(x); // обновляем высоту x
    return x; // возвращаем новый корень
}

// используется, когда х меньше -1, у имеет баланс <0
Node2* AVLTree::rotateLeft(Node2* x) {// левый поворот для балансировки дерева
    Node2* y = x->right; // y - правый ребенок x
    Node2* T2 = y->left; // T2 - левый ребенок y
    y->left = x; // y становится новым корнем, x - левым ребенком y
    x->right = T2; // T2 теперь - правым ребенком x
    updateHeight(x); // обновляем высоту x
    updateHeight(y);// обновляем высоту y
    return y; // возвращаем новый корень
}

Node2* AVLTree::balance(Node2* node) {// проверяет баланс и выполняет повороты, если нужно
    updateHeight(node);
    int balance = balanceFactor(node);
    if (balance > 1) {
        if (balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    if (balance < -1) {
        if (balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    return node;
}

Node2* AVLTree::insert(Node2* node, int key) {// вставляем узел в дерево и балансируем
    if (!node) { // если узел пустой, то создаем новый
        return new Node2(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key); // вставлем в левое поддерево, если новое значение меньше текущего
    } else if (key > node->key) {
        node->right = insert(node->right, key); // вставляем в правое поддерево
    } else {
        return node; // дубликаты не допускаются
    }
    return balance(node);
}

Node2* AVLTree::minValueNode(Node2* node) {// находим самый левый узел (минимальное значение)
    Node2* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

Node2* AVLTree::remove(Node2* node, int key) {// удаляем узел и балансируем
    if (!node) {
        return node; // если узел пустой, то ничего не делаем
    }
    if (key < node->key) {
        node->left = remove(node->left, key); //рекурсивно удаляем из левого поддерева
    } else if (key > node->key) {
        node->right = remove(node->right, key); // рекурсивно удаляем из правого поддерева
    } else {
        // узел найден
        if (!node->left) {
            Node2* temp = node->right; // если нет левого дочернего узла
            delete node; //удаляем текущий узел
            return temp; // возвращаем правое поддерево
        } else if (!node->right) {
            Node2* temp = node->left; // если нет правого дочернего узла
            delete node; // удаляем текущий узел
            return temp; // возвращаем левое поддерево
        }
        // узел с двумя дочерними узлами
        Node2* temp = minValueNode(node->right); //находим минимальный узел в правом поддереве
        node->key = temp->key; // копируем в текущий узел
        node->right = remove(node->right, temp->key); // удаляем минимальный узел в правом поддереве
    }
    return balance(node); //балансируем
}

bool AVLTree::search(Node2* node, int key) {// проверяем есть ли узел в дереве с нужным значением
    if (!node){
        return false;
    } 
    if (key == node->key) {
        return true;
    }
    if (key < node->key) {
        return search(node->left, key); // Если ключ меньше, ищем в левом поддереве
    } else {
        return search(node->right, key); // В противном случае, ищем в правом поддереве
    }
}

void AVLTree::inOrder(Node2* node) {// симметричный обход
    if (node) {
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }
}

// int main() {
//     system("chcp 65001");
//     AVLTree tree;

//     tree.root = tree.insert(tree.root, 10);
//     tree.root = tree.insert(tree.root, 20);
//     tree.root = tree.insert(tree.root, 30);
//     tree.root = tree.insert(tree.root, 40);
//     tree.root = tree.insert(tree.root, 50);
//     tree.root = tree.insert(tree.root, 25);

//     cout << "Симметричный обход: ";
//     tree.inOrder(tree.root);
//     cout << endl;

//     tree.root = tree.remove(tree.root, 30);
//     cout << "После удаления 30, симметричный обход: ";
//     tree.inOrder(tree.root);
//     cout << endl;

//     return 0;
// }
