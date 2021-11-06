#ifndef TREEB_H
#define TREEB_H
#include <iostream>
#include "../Nodes/Tree2Node.h"
using namespace std; 

template < class T >
class Tree {
    Node< T >* root;
	int nodesNumber;
    public:
        void create();
        void destroy();
        void clear();
        bool empty();
        void setRoot(T);
        void addSon(Node<T> *father, T);
        Node<T>* getRoot();
        Node<T>* father(Node<T> *node);
        Node<T>* leftmostSon(Node<T> *node);
        Node<T>* rightBrother(Node<T> *node);
        int numSons(Node<T> *node);
        int numNodes();
        void deleteLeaf(Node<T> *);
        void modifyTag(Node<T>*, T);
        T tag(Node<T>*);
};

/*
    EFECTO: crea la instancia del árbol
    REQUIERE: árbol sin crear o destruido
    MODIFICA: árbol
*/
template<typename T>
void Tree< T > :: create() {
    root = nullptr;
	nodesNumber = 0;
}

template < typename T >
void Tree< T > :: destroy() {
	delete root;
}

template < typename T >
void Tree< T > :: clear() {
	this -> destroy();
    this -> create();
    nodesNumber = 0;
}

/*
    EFECTO: pone el nodo raíz del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: setRoot(T tag) {
    if(this -> empty())
        nodesNumber++;
	root = new Node<T>(tag);
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(Node< T > *father, T tag) {
    Node< T > *temp = new Node< T >(tag);
    temp -> setNext(root -> getNext());
    root -> setNext(temp);
    Node< Node< T >* > *aux = new Node< Node< T >* >(root -> getNext());
    father -> setSon(aux);
    if(father -> getSon()) 
        aux -> setNext(father -> getSon());

	nodesNumber++;
}

template <typename T>
void Tree< T > :: deleteLeaf(Node<T>* node) {	
	
}

/*
    EFECTO: modifica la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: modifyTag(Node< T >* node, T tag) {
	node -> setObject(tag);
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: getRoot() {
	return root;
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: father(Node< T > *node) {	
    Node< T > *temp = nullptr;
    if(node != root) {
        temp = root;
        Node< Node< T >* > *aux = temp -> getSon();
        while(aux -> getObject() != node) {
            if(!aux) {
                temp = temp -> getNext();
                aux = temp -> getSon();
            }
            else
                aux = aux -> getNext();
        }
    }
    return temp;
} 

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: leftmostSon(Node< T > *node) {
    Node< T > *temp = nullptr;
    if(node -> getSon())
        temp = node -> getSon() -> getObject();
    return temp;
}

template < typename T >
Node< T >* Tree< T > :: rightBrother(Node< T > *node) {
    return node -> getNext();
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

template < typename T >
int Tree< T > :: numSons(Node<T> *node) {
    int result = 0;
    if(node -> getSon() != nullptr) {
        Node< Node< T >* > *temp = node -> getSon();
        while(temp != nullptr) {
            ++result;
            temp = temp -> getNext();
        }
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
	return root == nullptr ? true : false;
}

/*
    EFECTO: devuelve la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
T Tree< T > :: tag(Node< T >* node) {
	return node -> getObject();
}

#endif //TREEB_H