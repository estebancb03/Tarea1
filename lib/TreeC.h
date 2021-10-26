#ifndef TREEC_H
#define TREEC_H
#include "NodeTreeC.h"
template < class T >

class Tree {
    int nodesNumber;
    NodeTreeC< T > *root;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(NodeTreeC< T > *father, T sonTag);
        void deleteLeaf(NodeTreeC< T > *node);
        void modifyTag(NodeTreeC< T > *node, T newTag);
        T tag(NodeTreeC< T > *node);
        NodeTreeC< T > *father(NodeTreeC< T > *node);
        NodeTreeC< T > *leftmostSon(NodeTreeC< T > *node);
        NodeTreeC< T > *rightBrother(NodeTreeC< T > *node);
        NodeTreeC< T > *getRoot();
        NodeTreeC< T > *search(T tag);
        int numNodes();
        int numSons(NodeTreeC< T > *node);
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
    delete root;
}

/*
    EFECTO: elimina todos los nodos del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: clear() {
    nodesNumber = 0;
}

/*
    EFECTO: pone el nod raíz del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: setRoot(T tag) {
    if(this -> empty())
        nodesNumber++;
    root = new NodeTreeC< T >(tag);
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(NodeTreeC< T > *father, T sonTag) {
    NodeTreeC< T > *temp = father -> getLeftmostSon();
    if(temp) {
        while(temp -> getRightBrother()) {
            temp = temp -> getRightBrother();
        }
        temp -> setRightBrother(new NodeTreeC< T >(sonTag));
    }
    else
        temp -> setLeftmostSon(new NodeTreeC< T >(sonTag));
    nodesNumber++;
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(NodeTreeC< T > *node) {
    nodesNumber--;
}

/*
    EFECTO: modifica la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: modifyTag(NodeTreeC< T > *node, T newTag) {
    node -> setObject(newTag);
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeC< T >* Tree< T > :: getRoot() {
    return root;
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeC< T >* Tree< T > :: father(NodeTreeC< T > *node) {

}

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeC< T >* Tree< T > :: leftmostSon(NodeTreeC< T > *node) {
    return node -> getLeftmostSon();
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeC< T >* Tree< T > :: rightBrother(NodeTreeC< T > *node) {
    return node -> getRightBrother();
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
int Tree< T > :: numSons(NodeTreeC< T > *node) {
    int result = 0;
    NodeTreeC< T > *temp = node -> getLeftmostSon();
    while(temp) {
        temp = temp -> getRightBrother();
        result++;
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
T Tree< T > :: tag(NodeTreeC< T > *node) {
   return node -> getObject();
}

/*
    EFECTO: devuelve un verdadero si el nodo existe, si no devuelve falso
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Tree< T > :: exist(T tag) {
    bool result = false;
    return result;
}

/*
    EFECTO: devuelve el nodo que contiene deteerminada etiqueta
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeC< T >* Tree< T > :: search(T tag) {
    
}

#endif