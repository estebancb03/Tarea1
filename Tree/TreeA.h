#ifndef TREEA_H
#define TREEA_H
#include "../Nodes/Tree1Node.h"
using namespace std;

template < class T >
class Tree {
    int size = 10;
    int nodesNumber;
    Node< T >* tree[10];
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
    //tree = new Node< T >*[size];
}

/*
    EFECTO: destruye el árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: destroy() {
    //delete[] tree;
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
    Node< T > *root = new Node< T >(tag, 0, -1);
    tree[0] = root;
    nodesNumber++;
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(Node< T > *father, T sonTag) {
    Node< T > *temp = new Node< T >(sonTag, nodesNumber, father -> getPosition());
    tree[nodesNumber] = temp;
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
void Tree< T > :: modifyTag(Node< T > *node, T newTag) {
    node -> setObject(newTag);
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: getRoot() {
    Node< T > *root = tree[0];
    return root;
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: father(Node< T > *node) {
    int position = node -> getFatherPosition();
    Node< T > *temp = tree[position];
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
    int i = node -> getPosition();
    while(i < size) {
        Node< T > *aux = tree[i];
        if(node -> getPosition() == aux -> getFatherPosition()) {
            i = size; 
            temp = aux;
        }
        else
            ++i;
    }
    return temp;
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: rightBrother(Node< T > *node) {
    Node< T > *temp = nullptr;
    int i = node -> getPosition();
    while(i <= size - 1) {
        Node< T > *aux = tree[i + 1];
        if(node -> getFatherPosition() == aux -> getFatherPosition()) {
            i = size;
            temp = aux;
        }
        else
            ++i;
    }
    return temp;
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
int Tree< T > :: numSons(Node< T > *node) {
    int position = node -> getPosition();
    int result = 0;
    for(int i = position + 1; i < nodesNumber; ++i) {
        if(tree[i] -> getFatherPosition() == position)
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
T Tree< T > :: tag(Node< T > *node) {
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

template < typename T >
void Tree< T > :: print() {
    for(int i = 0; i < size; ++i) {
        Node< T > *temp = tree[i];
        if(temp) {
            cout << "[" << i << "]: " << temp -> getObject() << endl;
        }
        else {
            cout << "[" << i << "]: nullptr" << endl;
        }
    }
}

#endif

//TREEA_H