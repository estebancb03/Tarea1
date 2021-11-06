#ifndef TREEB_H
#define TREEB_H
#include "../List/List.h"
#include "../Nodes/Tree2Node.h"

template < class T >
class Tree {
    Node< T > *root;
    int nodesNumber;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(GenericNode<T> *father, T sonTag);
        void deleteLeaf(GenericNode<T> *node);
        void modifyTag(GenericNode<T> *node, T newTag);
        T tag(GenericNode<T> *node);
        GenericNode<T> *father(GenericNode<T> *node);
        GenericNode<T> *leftmostSon(GenericNode<T> *node);
        GenericNode<T> *rightBrother(GenericNode<T> *node);
        GenericNode<T> *getRoot();
        GenericNode<T> *getList(T tag);
        int numNodes();
        int numSons(GenericNode<T> *node);
        bool empty();
};

/*
    EFECTO: crea la instancia del árbol
    REQUIERE: árbol sin crear o destruido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: create() {
    root = new Node< T >();
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
    if(root -> getObject() -> searchNodeByPosition(0) == nullptr) {
        root -> getObject() -> insert(tag);
        ++nodesNumber;
    }
    else
        root -> getObject() -> searchNodeByPosition(0) -> setObject(tag);
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(GenericNode<T> *father, T sonTag) {
    if(numNodes == 0) {
        
    }
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(GenericNode<T> *node) {
    
}

/*
    EFECTO: modifica la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: modifyTag(GenericNode<T> *node, T newTag) {
    
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
GenericNode<T>* Tree< T > :: getRoot() {
    return root -> getObject() -> searchNodeByPosition(0);
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
GenericNode<T>* Tree< T > :: father(GenericNode<T> *node) {
    
}

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
GenericNode<T>* Tree< T > :: leftmostSon(GenericNode<T> *node) {
    
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
GenericNode<T>* Tree< T > :: rightBrother(GenericNode<T> *node) {
    
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
int Tree< T > :: numSons(GenericNode<T> *node) {
    
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
T Tree< T > :: tag(GenericNode<T> *node) {
    node -> getObject();
}

#endif //TREEB_H