#ifndef LIST_H
#define LIST_H
#include "../Nodes/GenericNode.h"

template < class T >
class List {
    GenericNode< T > *head;
    int numNodes;
    public:
        List() { head = nullptr; numNodes = 0; };
        bool exist(T object);
        bool empty();
        void destroy();
        void deleteObject(GenericNode< T > *node);
        void insert(T object);
        T getObject(GenericNode< T > *node);
        GenericNode< T > *searchNode(T object);
        GenericNode< T > *searchBefore(GenericNode< T > *node);
};

/*
    EFECTO: elimina la lista
    REQUIERE: lista creada 
    MODIFICA: lista
*/
template < typename T >
void List< T > :: destroy() {
    delete this;
}

/*
    EFECTO: devuelve true si hay un nodo con un objeto determinado en la lista
    REQUIERE: lista creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool List< T > :: exist(T object) {
    return this -> searchNode(new GenericNode< T >(object)) ? true : false;
}

/*
    EFECTO: devuelve true si la lista está vacía y false si no
    REQUIERE: lista creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool List< T > :: empty() {
    return numNodes == 0 ? true : false;
}

/*
    EFECTO: devuelve el objeto de un nodo
    REQUIERE: lista creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
T List< T > :: getObject(GenericNode< T > *node) {
    return node -> getObject();
}

/*
    EFECTO: devuelve un nodo con un objeto determinado en la lista
    REQUIERE: lista creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
GenericNode< T >* List< T > :: searchNode(T object) {
    GenericNode< T > *temp = head;
    if(!this -> empty()) {
        while(temp && temp -> getObject() != object) 
            temp = temp -> getNext();
    }
    return temp;
}

/*
    EFECTO: devuelve el nodo anterior si hay
    REQUIERE: lista creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
GenericNode< T >* List< T > :: searchBefore(GenericNode< T >* node) {
    if(numNodes > 1) {
        GenericNode< T > *temp = head;
        while(temp -> getNext() && temp -> getNext() != node)
            temp = temp -> getNext();
    }
    return temp;
}

/*
    EFECTO: inserta un nodo al final de la lista
    REQUIERE: lista creada
    MODIFICA: lista
*/
template < typename T >
void List< T > :: insert(T object) {
    GenericNode< T > *temp = head;
    if(this -> empty())
        head = new GenericNode< T >(object);
    else {
        while(temp)
            temp = temp -> getNext();
        temp = new GenericNode< T >(object);
    }
    ++numNodes;
}

/*
    EFECTO: elimina un nodo de la lista
    REQUIERE: lista creada
    MODIFICA: lista
*/
template < typename T >
void List< T > :: deleteObject(GenericNode< T > *node) {
    if(!this -> empty) {
        if(!node -> getNext()) {
            node = nullptr;
            delete node;
        }
        else {
            GenericNode< T > *temp = searchBefore(node);
            temp -> setNext(node -> getNext());
            node = nullptr;
            delete node;
        }
    }
}

#endif //LIST_H