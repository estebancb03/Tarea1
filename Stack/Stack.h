#ifndef STACK_H
#define STACK_H
#include <sstream>
#include "../Nodes/GenericNode.h"
using namespace std;
template < class T >

class Stack {
    GenericNode< T > *head;
    public:
        void create();
        void destroy();
        void print();
        void push(T element);
        void clear();
        bool empty();
        bool exist(T elements);
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
    GenericNode< T > *temp = new GenericNode< T >(element);
    if(this -> empty()) 
        head = temp;
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
    this -> destroy();
    this -> create();
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
        GenericNode< T > *temp = head;
        T element = temp -> getObject();
        head = head -> getNext();
        delete temp;
        return element;
    }
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
}

/*
    EFECTO: devuelve un true si el elemento se encuentra en la pila
    REQUIERE: pila creada
    MODIFICA: no hace modificaciones
*/
template< typename T >
bool Stack< T > :: exist(T element) {
    bool result = false;
    bool enabled = true;
    if(!this -> empty()) {
        GenericNode< T > *temp = head;
        while(temp != nullptr && enabled) {
            if(temp -> getObject() == element) {
                result = true;
                enabled = false;
            }
            else
                temp = temp -> getNext();
        }   
    }
    return result;
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
        GenericNode< T > *temp = head;
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

#endif //STACK_H