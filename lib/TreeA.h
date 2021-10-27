#ifndef TREEA_H
#define TREEA_H
#include <vector>

class NodeTreeA {
    public:
        int object;
        int position;
        int fatherPosition;
};

template < class T >

class Tree {
    int size;
    int nodesNumber;
    vector< NodeTreeA* > tree;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(NodeTreeA *father, T sonTag);
        void deleteLeaf(NodeTreeA *node);
        void modifyTag(NodeTreeA *node, T newTag);
        T tag(NodeTreeA *node);
        NodeTreeA *father(NodeTreeA *node);
        NodeTreeA *leftmostSon(NodeTreeA *node);
        NodeTreeA *rightBrother(NodeTreeA *node);
        NodeTreeA *getRoot();
        NodeTreeA *search(NodeTreeA *newRoot, T tag);
        int numNodes();
        int numSons(NodeTreeA *node);
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
    NodeTreeA* root = new NodeTreeA();
    root -> object = tag;
    root -> position = 0;
    root -> fatherPosition = 0;
    tree.push_back(root);
    nodesNumber++;
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(NodeTreeA *father, T sonTag) {
    NodeTreeA *temp = new NodeTreeA();
    temp -> object = sonTag;
    temp -> position = nodesNumber;
    temp -> fatherPosition = father -> position;
    tree[nodesNumber] = temp;
    nodesNumber++;
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(NodeTreeA *node) {
    for(int i = node -> position + 1; i  < nodesNumber ; i++){
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
void Tree< T > :: modifyTag(NodeTreeA *node, T newTag) {
    node -> object = newTag;
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA* Tree< T > :: getRoot() {
    return this -> tree[0];
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA* Tree< T > :: father(NodeTreeA *node) {
    return tree[node -> fatherPosition];
}

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeA* Tree< T > :: leftmostSon(NodeTreeA *node) {
    int i = node -> position + 1;
    bool enabled = true;
    while(enabled) {
        if(i > size) 
            enabled = false;
        else {
            if(tree[i] -> fatherPosition == node -> position)
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
NodeTreeA* Tree< T > :: rightBrother(NodeTreeA *node) {
    int i = node -> position + 1;
    bool enabled = true;
    while(enabled) {
        if(i > size) 
            enabled = false;
        else {
            if(tree[i] -> fatherPosition == node -> fatherPosition)
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
int Tree< T > :: numSons(NodeTreeA *node) {
    int position = node -> position;
    int result = 0;
    for(int i = position + 1; i < nodesNumber; ++i) {
        if(tree[i] -> fatherPosition == position)
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
T Tree< T > :: tag(NodeTreeA *node) {
   return tree[node -> position] -> object;
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
            if(tree[i] -> object == tag) {
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
NodeTreeA* Tree< T > :: search(NodeTreeA *newRoot, T tag) {
    NodeTreeA *temp = nullptr;
    bool enabled = true;
    int i = 0;
    while(enabled) {
        temp = tree[i];
        if(i >= size) 
            enabled = false;
        else {
            if(temp -> object == tag) {
                enabled = false;
            }
            ++i;
        }
    }
    return temp;
}

#endif