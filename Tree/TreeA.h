#ifndef TREEA_H
#define TREEA_H
#include <vector>
#include "../Nodes/Tree1Node.h"

template < class T >
class Tree {
    int size;
    int nodesNumber;
    vector< Node<T>* > tree;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(Node<T> *father, T sonTag);
        void deleteLeaf(Node<T> *node);
        void modifyTag(Node<T> *node, T newTag);
        T tag(Node<T> *node);
        Node<T> *father(Node<T> *node);
        Node<T> *leftmostSon(Node<T> *node);
        Node<T> *rightBrother(Node<T> *node);
        Node<T> *getRoot();
        Node<T> *search(Node<T> *newRoot, T tag);
        int numNodes();
        int numSons(Node<T> *node);
        bool empty();
        bool exist(T tag);
};

/*
    EFECTO: crea la instancia del árbol
    REQUIERE: árbol sin crear o destruido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: create() {
    size = 10;
    nodesNumber = 0;
    tree.reserve(size);
    for(int i = 0; i < size; ++i)
        tree[i] = nullptr;
}

/*
    EFECTO: destruye el árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: destroy() {
    delete this;
}

/*
    EFECTO: elimina todos los nodos del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: clear() {
    for(int i = 0; i < nodesNumber; ++i)
        tree[i] = nullptr;
    nodesNumber = 0;
}

/*
    EFECTO: pone el nod raíz del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: setRoot(T tag) {
    Node<T>* root = new Node<T>(tag, 0, -1);
    tree.push_back(root);
    nodesNumber++;
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(Node<T> *father, T sonTag) {
    Node<T> *temp = new Node<T>(sonTag, nodesNumber, father -> getPosition());
    tree[nodesNumber] = temp;
    nodesNumber++;
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(Node<T> *node) {
    for(int i = node -> getFatherPosition() + 1; i  < nodesNumber ; i++){
        tree[i-1] = tree[i];
    }
    tree[nodesNumber] = nullptr;
    --nodesNumber;
}

/*
    EFECTO: modifica la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: modifyTag(Node<T> *node, T newTag) {
    node -> setObject(newTag);
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: getRoot() {
    return this -> tree[0];
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: father(Node<T> *node) {
    return tree[node -> getFatherPosition()];
}

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: leftmostSon(Node<T> *node) {
    int i = node -> getPosition() + 1;
    bool enabled = true;
    while(enabled) {
        if(i > size) 
            enabled = false;
        else {
            if(tree[i] -> getFatherPosition() == node -> getPosition())
                enabled = false;
            else
                ++i;
        }
    }
    return tree[i];
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: rightBrother(Node<T> *node) {
    int i = node -> getPosition() + 1;
    bool enabled = true;
    while(enabled) {
        if(i > size) 
            enabled = false;
        else {
            if(tree[i] -> getFatherPosition() == node -> getFatherPosition())
                enabled = false;
            else
                ++i;
        }
    }
    return tree[i];
}

/*
    EFECTO: devuelve el número de nodos que hay en el árbol
    REQUIERE: árbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Tree< T > :: numNodes() {
    return nodesNumber;
}

/*
    EFECTO: devuelve el número de hijos de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Tree< T > :: numSons(Node<T> *node) {
    int result = 0;
    for(int i = node -> getPosition() + 1; i < nodesNumber; ++i) {
        if(tree[i] -> getFatherPosition() == node -> getPosition())
            ++result;
    }
    return result;
}

/*
    EFECTO: devuelve un verdadero si el árbol tiene nodos, si no devuelve falso
    REQUIERE: árbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Tree< T > :: empty() {
    return nodesNumber == 0 ? true : false;
}

/*
    EFECTO: devuelve la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
T Tree< T > :: tag(Node<T> *node) {
   return tree[node -> getPosition()] -> getObject();
}

/*
    EFECTO: devuelve un verdadero si el nodo existe, si no devuelve falso
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Tree< T > :: exist(T tag) {
    bool enabled = true;
    bool result = false;
    int i = 0;
    while(enabled) {
        if(i > nodesNumber) 
            enabled = false;
        else {
            if(tree[i] -> getObject() == tag) {
                result = true;
                enabled = false;
            }
            ++i;
        }
    }
    return result;
}

/*
    EFECTO: devuelve el nodo que contiene deteerminada etiqueta
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: search(Node<T> *newRoot, T tag) {
    Node<T> *temp = nullptr;
    bool enabled = true;
    int i = 0;
    while(enabled) {
        temp = tree[i];
        if(i >= size) 
            enabled = false;
        else {
            if(temp -> getObject() == tag) {
                enabled = false;
            }
            ++i;
        }
    }
    return temp;
}

#endif //TREEA_H