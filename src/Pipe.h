#ifndef PIPE_H
#define PIPE_H
#include "Node.h"
#include <sstream>
using namespace std;
template < class T >

class Pipe {
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
void Pipe< T > :: create() {
    head = nullptr;
}

/*
    EFECTO: elimina la estructura de datos
    REQUIERE: pila creada
    MODIFICA: pila
*/
template < typename T >
void Pipe< T > :: destroy() {
    delete head;
}

/*
    EFECTO: introduce element en tope de la pila
    REQUIERE: pila creada
    MODIFICA: pila
*/
template < typename T >
void Pipe< T > :: push(T element) {
    Node< T > *temp = new Node< T >(element);
    if(empty()) {
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
void Pipe< T > :: clear() {
    if(!empty()) {
        Node< T > *temp = head;
        while(head != nullptr) {
            head = temp -> getNext();
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
bool Pipe< T > :: empty() {
    return head == nullptr ? true : false;
}

/*
    EFECTO: devuelve el elemento superior y a su vez lo elimina de la pila
    REQUIERE: pila creada
    MODIFICA: pila
*/
template < typename T >
T Pipe< T > :: pop() {
    Node< T > *temp = head;
    T element = temp -> getObject();
    head = head -> getNext();
    delete temp;
    return element;
}

/*
    EFECTO: devuelve el elemento superior de la pila
    REQUIERE: pila creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
T Pipe< T > :: top() {
    return head -> getObject();
}

/*
    EFECTO: imprime los elementos de la pila
    REQUIERE: pila creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
void Pipe< T > :: print() {
    if(!this -> empty()) {
        cout << "---------------------------" << endl;
        Node< T > *temp = head;
        while(temp != nullptr) {
            stringstream sstream; 
            sstream << temp -> getObject();
            string element = sstream.str();
            string espacios;
            int cantidad = (26 - element.length()) / 2;
            for (int i = 0; i < cantidad - 1; i++) 
                espacios += " ";
            cout << "|" << espacios;
            if(element.length() % 2 != 0)
                cout << " ";
            cout << element << espacios << " |";
            cout << endl << "---------------------------" << endl;
            temp = temp -> getNext();
        }
    }
    else
        cout << "Pila vacia";
}

#endif