#ifndef TREEA_H
#define TREEA_H
#include <vector>
#include "../Nodes/Tree1Node.h"
using namespace std;

template < class T >
class Tree {
    int size;
    int nodesNumber;
    vector< Node< T >* > tree;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(Node< T > *father, T sonTag);
        void deleteLeaf(Node< T > *node);
        void modifyTag(Node< T > *node, T newTag);
        T tag(Node< T > *node);
        Node< T > *father(Node< T > *node);
        Node< T > *leftmostSon(Node< T > *node);
        Node< T > *rightBrother(Node< T > *node);
        Node< T > *getRoot();
        int numNodes();
        int numSons(Node< T > *node);
        bool empty();
        bool exist(T tag);
        void print();
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
    tree.reserve(this -> size);
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
    this -> destroy();
    this -> create();
    nodesNumber = 0;
}

/*
    EFECTO: pone el nod raíz del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: setRoot(T tag) {
    Node< T > *root = new Node< T >();
    root -> setObject(tag);
    root -> setFatherPosition(-1);
    root -> setPosition(nodesNumber);
    tree.push_back(root);
    nodesNumber++;
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(Node< T > *node, T tag) {
    Node< T > *son = new Node<T>();
    son -> setObject(tag);
    son -> setFatherPosition(node -> getPosition());
    son -> setPosition(nodesNumber);
    tree.push_back(son);
    nodesNumber++;
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(Node< T > *node) {
    if(node -> getPosition() != 0 && node -> getPosition() < nodesNumber - 1) {
        for(int i = node -> getPosition(); i < nodesNumber - 1; ++i) 
            tree[i] = tree[i + 1];
    }
    else 
        delete tree[node -> getPosition()];
    --nodesNumber;
}

/*
    EFECTO: modifica la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: modifyTag(Node< T > *node, T tag) {
    tree[node -> getPosition()] -> setObject(tag);
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: getRoot() {
    return tree[0];
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: father(Node< T > *node) {
    return tree[node -> getFatherPosition()];
}

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node<T>* Tree< T > :: leftmostSon(Node< T > *node) {
    int father = node -> getPosition();
    for (int i = 0; i < nodesNumber; ++i) {
        if (tree[i] -> getFatherPosition() == father) 
            return this -> tree[i];
    }
    return nullptr;
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: rightBrother(Node< T > *node) {
    int father = node -> getFatherPosition();
    for (int i = node -> getPosition() + 1; i < tree.size(); ++i) {
        if (tree[i] -> getFatherPosition() == father) 
            return this -> tree[i];
    }
    return nullptr;
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
int Tree< T > :: numSons(Node< T >* node) {
    int father = node -> getPosition();
    int numSons = 0;
    for (int i = 0; i < tree.size(); ++i) {
        if (tree[i] -> getFatherPosition() == father) 
            ++numSons;
    }
    return numSons;
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
T Tree< T > :: tag(Node< T > *node) {
    return this -> tree[node -> getPosition()] -> getObject();
}

#endif

//TREEA_H