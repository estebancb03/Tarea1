#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <sstream>
using namespace std;
template < class T >

class Stack {
    Node< T > *head;
    public:
        void create();
        void destroy();
        void print();
        void push(T element);
        void clear();
        bool empty();
        T pop();
        T top();
};

/*
    EFECTO: crea e inicializa la pila
    REQUIERE: pila no creada o pila destruida
    MODIFICA: pila
*/
template < typename T > 
void Stack< T > :: create() {
    head = nullptr;
}

/*
    EFECTO: elimina la estructura de datos
    REQUIERE: pila creada
    MODIFICA: pila
*/
template < typename T >
void Stack< T > :: destroy() {
    delete head;
}

/*
    EFECTO: introduce element en tope de la pila
    REQUIERE: pila creada
    MODIFICA: pila
*/
template < typename T >
void Stack< T > :: push(T element) {
    Node< T > *temp = new Node< T >(element);
    if(this -> empty()) {
        head = temp;
    }
    else {
        temp -> setNext(head);
        head = temp;
    }
}

/*
    EFECTO: elimina todos los elementos de la pila
    REQUIERE: pila creada
    MODIFICA: pila
*/
template <typename T>
void Stack< T > :: clear() {
    if(!this -> empty()) {
        Node< T > *temp = head;
        while(head) {
            head = head -> getNext();
            temp = nullptr;
            delete temp;
        }
    }
}

/*
    EFECTO: devuelve true si la pila está vacía y false si hay elementos en la pila
    REQUIERE: pila creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Stack< T > :: empty() {
    return head == nullptr ? true : false;
}

/*
    EFECTO: devuelve el elemento superior y a su vez lo elimina de la pila
    REQUIERE: pila creada
    MODIFICA: pila
*/
template < typename T >
T Stack< T > :: pop() {
    if(!this -> empty()) {
        Node< T > *temp = head;
        T element = temp -> getObject();
        head = head -> getNext();
        delete temp;
        return element;
    }
    else 
        return -1;
}

/*
    EFECTO: devuelve el elemento superior de la pila
    REQUIERE: pila creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
T Stack< T > :: top() {
    if(!this -> empty())
        return head -> getObject();
    else
        return -1;
}

/*
    EFECTO: imprime los elementos de la pila
    REQUIERE: pila creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
void Stack< T > :: print() {
    if(!this -> empty()) {
        cout << "---------------------------" << endl;
        Node< T > *temp = head;
        while(temp != nullptr) {
            stringstream sstream; 
            sstream << temp -> getObject();
            string element = sstream.str();
            string spaces;
            int number = (26 - element.length()) / 2;
            for (int i = 0; i < number - 1; i++) 
                spaces += " ";
            cout << "|" << spaces;
            if(element.length() % 2 != 0)
                cout << " ";
            cout << element << spaces << " |";
            cout << endl << "---------------------------" << endl;
            temp = temp -> getNext();
        }
    }
    else
        cout << "Pila vacia" << endl;
}

#endif