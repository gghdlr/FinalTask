// FinlTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "AVLTree.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    AVLTree tree;
    int size;
    cout << "Введите количество элементов:" << endl;
    cin >> size;
    cout << "Введите элементы масива:" << endl;
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        if (tree.find(num) == nullptr) {
            tree.insert(num);
        }
    }
    cout<< "Сбалансированное AVL дерево:" << endl;
    tree.print();
    cout << "Последовательность для сбалансированного дерева:" << endl;
    tree.printBalanced();
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
