#ifndef TREEB_H
#define TREEB_H
#include <iostream>
#include "../Nodes/Tree2Node.h"
using namespace std; 

template < class T >
class Tree {
    Node< T > *root;
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

/*
    EFECTO: destruye el árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: destroy() {
	if (!this -> empty()){
		Node< Node< T >* > *sonsAux = root -> getSon();
		Node< Node< T >* > *deletSon = sonsAux;
		Node< T > *fathersAux = root;
		Node< T > *deleteFather = root;
		while (fathersAux) {
			if (!sonsAux) {
                fathersAux = fathersAux -> getNext();
				delete deleteFather;
				deleteFather = fathersAux;
				if (fathersAux)
					sonsAux = fathersAux -> getSon();
			}
			else {
				sonsAux = sonsAux -> getNext();
				delete deletSon;
				deletSon = sonsAux;
			}
		}
	}
	delete this;
}

/*
    EFECTO: elimina todos los nodos del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
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
void Tree< T > :: addSon(Node< T > *node, T tag) {
    Node< T > *temp = new Node< T >(tag);
    temp -> setNext(root -> getNext());
    root -> setNext(temp);
    Node< Node< T >* > *aux = new Node< Node< T >* >(root -> getNext());
	if (node -> getSon())
        aux -> setNext(node -> getSon()); 
    node -> setSon(aux);
	nodesNumber++;
}

template <typename T>
void Tree< T > :: deleteLeaf(Node<T>* nodo) {	
	
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
    bool enabled = false;
	if(node != root) {
		temp = root;
		Node< Node< T >* > *aux = temp -> getSon();
		while (!enabled) {
			if (aux) {
				if (aux -> getObject() == node) 
					enabled = true;
				aux = aux -> getNext();
			} 
            else {
				temp = temp -> getNext();
				aux = temp -> getSon();
			}
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

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: rightBrother(Node< T > *node) {
    Node< T > *fathersAux = root;
    Node< Node< T >* > *sonsAux = root -> getSon(); 
	bool enabled = false;
	while (!enabled) {
		if (!sonsAux) {
            fathersAux = fathersAux -> getNext();
			sonsAux = fathersAux -> getSon();
		} 
        else {
			if (sonsAux -> getObject() == node) 
				enabled = true;
			sonsAux = sonsAux -> getNext();
		}
	}
	return !sonsAux ? nullptr : sonsAux -> getObject();
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
    if(node -> getSon()) {
        Node< Node< T >* > *temp = node -> getSon();
        while(temp) {
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