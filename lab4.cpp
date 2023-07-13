#include <iostream>
#include "termcolor.hpp"

using namespace std;

struct tsp {
    int num;
    tsp* next;
};

class List {
private: 
    tsp *P, *Q, *T;

public:
    List() {
        P = NULL;
    }

    ~List() {
        Q = P;

        while (Q -> next) {
            T = Q -> next;
            Q -> next = Q -> next -> next;
            T -> next = NULL;
            delete T;
        }
        P -> next = NULL;
        delete P;
    }

    void creation() {
        T = new tsp;
        P = T;

        int n;
        cout << "Введите количество элементов списка: ";
        cin >> n;
        cout << endl;

        for (int i = 1; i <= n; i++) {
            Q = new tsp;
            cout << "Введите " << i << " элемент списка: ";
            cin >> Q -> num;
            cout << endl;
            T -> next = Q;
            T = Q;
        }
        Q -> next = NULL;
    }

    

    void display() {
        Q = P -> next;

        while (Q) {
            if (Q -> num > 0){
                cout << termcolor::red << Q -> num << termcolor::reset << " ";
            }
            else cout << Q -> num << " ";
            Q = Q -> next;
        }
    }

    void displayNew() {
        Q = P -> next;

        while (Q) {
            if (Q -> num > 0) {
                cout << termcolor::red << Q -> num << termcolor::reset << " ";
            if (Q -> next) {
                cout << termcolor::blue << Q -> next -> num << termcolor::reset << " ";
            }
            Q = Q -> next -> next;
        } else {
            cout << Q -> num << " ";
            Q = Q -> next;
        } 
        }
    }

    void insertNumberAfterPositive() {
        Q = P -> next;
        int count = 1;

        while (Q) {
            if (Q -> num > 0){
                T = new tsp;
                T -> num = count;
                T -> next = Q -> next;
                Q -> next = T;
                Q = Q -> next -> next;
            }
            else {
                Q = Q -> next;
            }
            count++;
        }
    }

    void createNewElemAndIndex() {
        Q = P->next;
        int count = 1;

        while (Q) {
            if (Q->num > 0) {
                if (Q->next) {
                    Q = Q->next->next;
                } else {
                Q = Q->next;
                }
            } else {
                Q = Q->next;
            }
            count++;
        }

        int n;
        cout << endl << "Введите количество элементов, которые хотите добавить: ";
        cin >> n;
        cout << endl;

        Q = P; // Возвращаемся в начало списка

        while (Q->next) {
            Q = Q->next; // Переходим к последнему элементу списка
        }

        for (int i = 1; i <= n; i++) {
            T = new tsp;
            cout << "Введите " << i << " элемент: ";
            cin >> T->num;
            cout << endl;

            T->next = NULL; // Новый элемент становится последним
            Q->next = T; // Присоединяем новый элемент к концу списка
            Q = T; // Обновляем Q для указания на новый последний элемент

            if (T->num > 0) {
                T = new tsp;
                T->num = count;
                T->next = NULL;
                Q->next = T; // Присоединяем элемент с числом count после текущего элемента
                Q = T; // Обновляем Q для указания на новый последний элемент
                count++;
            }
            else {
                count++;
            }
        }
    }
};

int main() {

    int flag = 1;
    List lst;

    while (flag) {
        cout << "\n\n" << termcolor::bold << termcolor::yellow << "Menu items:" << termcolor::reset;
        cout << "\n\n1  -- CREATE LIST"<<endl<<
                "2  -- LOOK"<<endl<<
                "3  -- INSERT INDEX AFTER POSITIVE"<<endl<<
                "4  -- LOOK NEW LIST"<<endl<<
                "5  -- ADD TO END"<<endl<<
                "0  -- EXIT"<<endl;

        cout << "Enter menu number: ";
        cin >> flag;
        switch (flag) {
            case 1: {
                lst.creation(); break;
            }    
            case 2: {
                cout << endl << termcolor::green << "Первоначальный список: " << termcolor::reset;
                lst.display();
                break;
            }
            case 3: {
                lst.insertNumberAfterPositive();
                break;
            }
            case 4: {
                cout << endl << termcolor::green << "Новый список: "<< termcolor::reset;
                lst.displayNew();
                break;
            }
            case 5: {
                lst.createNewElemAndIndex();
                break;
            }
            case 0: return 0;
        }
    }
}
