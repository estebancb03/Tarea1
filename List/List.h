#ifndef LIST_H
#define LIST_H
#include "../Nodes/GenericNode.h"

template < class T >
class List {
    GenericNode< T > *head;
    public:
        List() { head = nullptr; };
        bool exist(T object);
        bool empty();
        void destroy();
        void deleteObject(GenericNode< T > *node);
        void insert(T object);
        T getObject(GenericNode< T > *node);
        GenericNode< T > *searchNode(T object);
        GenericNode< T > *searchNodeByPosition(int position);
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
    return !head ? true : false;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
T List< T > :: getObject(GenericNode< T > *node) {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
GenericNode< T >* List< T > :: searchNode(T object) {
    GenericNode< T > *temp = head;
    if(!this -> empty()) {
        bool enabled = true;
        while(temp && enabled) {
            if(temp -> getObject() == object)
                enabled = false; 
            else
                temp = temp -> getNext();
        }
    }
    return temp;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
GenericNode< T >* List< T > :: searchNodeByPosition(int position) {

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
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void List< T > :: deleteObject(GenericNode< T > *node) {

}

#endif //LIST_H