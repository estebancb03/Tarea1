#ifndef TREEA_H
#define TREEA_H
#include "NodeTreeA.h"
template < class T >

class Tree {
    int size;
    int nodesNumber;
    NodeTreeA< T > *array;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(NodeTreeA< T > *father, T sonTag);
        void deleteLeaf(NodeTreeA< T > *node);
        void modifyTag(NodeTreeA< T > *node, T newTag);
        T tag(NodeTreeA< T > *node);
        NodeTreeA< T > *father(NodeTreeA< T > *node);
        NodeTreeA< T > *leftmostSon(NodeTreeA< T > *node);
        NodeTreeA< T > *rightBrother(NodeTreeA< T > *node);
        NodeTreeA< T > *getRoot();
        NodeTreeA< T > *search(T tag);
        int numNodes();
        int numSons(NodeTreeA< T > *node);
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
    array = new NodeTreeA< T >[size];
}

/*
    EFECTO: destruye el árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: destroy() {
    delete []array;
}

/*
    EFECTO: elimina todos los nodos del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: clear() {
    if(!this -> empty()) {
        for(int i = 0; i < numNodes; ++i) {
            delete array[i];
        }
        numNodes = 0;
    }
}

/*
    EFECTO: pone el nod raíz del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: setRoot(T tag) {
    array[0] = new NodeTreeA< T >(tag, 0, -1);
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(NodeTreeA< T > *father, T sonTag) {
    
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(NodeTreeA< T > *node) {
    
}

/*
    EFECTO: modifica la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: modifyTag(NodeTreeA< T > *node, T newTag) {
    
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA< T >* Tree< T > :: getRoot() {
    
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA< T >* Tree< T > :: father(NodeTreeA< T > *node) {

}

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA< T >* Tree< T > :: leftmostSon(NodeTreeA< T > *node) {
    
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA< T >* Tree< T > :: rightBrother(NodeTreeA< T > *node) {
    
}

/*
    EFECTO: devuelve el número de nodos que hay en el árbol
    REQUIERE: árbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Tree< T > :: numNodes() {
    
}

/*
    EFECTO: devuelve el número de hijos de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Tree< T > :: numSons(NodeTreeA< T > *node) {
    
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
T Tree< T > :: tag(NodeTreeA< T > *node) {
   
}

/*
    EFECTO: devuelve un verdadero si el nodo existe, si no devuelve falso
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Tree< T > :: exist(T tag) {
    
}

/*
    EFECTO: devuelve el nodo que contiene deteerminada etiqueta
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA< T >* Tree< T > :: search(T tag) {

}

#endif