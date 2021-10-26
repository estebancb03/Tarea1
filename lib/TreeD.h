#ifndef TREED_H
#define TREED_H
#include "NodeTreeD.h"
template < class T >

class Tree {
    int nodesNumber;
    NodeTreeD< T > *root;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(NodeTreeD< T > *father, T sonTag);
        void deleteLeaf(NodeTreeD< T > *node);
        void modifyTag(NodeTreeD< T > *node, T newTag);
        T tag(NodeTreeD< T > *node);
        NodeTreeD< T > *father(NodeTreeD< T > *node);
        NodeTreeD< T > *leftmostSon(NodeTreeD< T > *node);
        NodeTreeD< T > *rightBrother(NodeTreeD< T > *node);
        NodeTreeD< T > *getRoot();
        NodeTreeD< T > *search(NodeTreeD< T > *newRoot, T tag);
        NodeTreeD< T > *searchFather(NodeTreeD< T > *node, NodeTreeD< T > *actual, NodeTreeD< T > *actualFather);
        int numNodes();
        int numSons(NodeTreeD< T > *node);
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
    if(this -> empty())
        nodesNumber++;
    root = new NodeTreeD< T >(tag);
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(NodeTreeD< T > *father, T sonTag) {
    if(!father -> getLeftmostSon()) 
        father -> setLeftmostSon(new NodeTreeD< T >(sonTag));
    else{
        NodeTreeD< T > *temp = father -> getLeftmostSon();
        NodeTreeD< T > *aux = nullptr;
        while(temp -> getRightBrother()) 
            temp = temp -> getRightBrother();
        temp -> setRightBrother(new NodeTreeD< T >(sonTag));
        aux = temp -> getRightBrother();
        aux -> setLeftBrother(temp);
    }
    nodesNumber++;
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(NodeTreeD< T > *node) {
    if (node -> getRightBrother()) {
        NodeTreeD< T > *left = node -> getLeftBrother();
        if (left) {
          left -> setRightBrother(node -> getRightBrother());
          delete node;
        }
    } 
    else {
        if(node -> getLeftBrother()) {
            node -> getLeftBrother() -> setRightBrother(nullptr);
        }
        else {
            NodeTreeD< T > *father = searchFather(node, root, root);
            if(father) {
                father -> setLeftmostSon(nullptr);
                delete node;
            } 
            else 
                root = nullptr;
        }
      }
    nodesNumber--;
}

/*
    EFECTO: modifica la etiqueta de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: modifyTag(NodeTreeD< T > *node, T newTag) {
    node -> setObject(newTag);
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeD< T >* Tree< T > :: getRoot() {
    return root;
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeD< T >* Tree< T > :: father(NodeTreeD< T > *node) {
   return this -> searchFather(node, root, root);
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeD< T >* Tree< T > :: searchFather(NodeTreeD< T > *node, NodeTreeD< T > *actual, NodeTreeD< T > *actualFather) {
    NodeTreeD< T > *temp = nullptr;
      if(actual != node) {
          actualFather = actual;
        actual = actual -> getLeftmostSon();
        while(actual && !temp) {
          temp = searchFather(node, actual, actualFather);
          actual = actual -> getRightBrother();
        }
      }
      else
        temp = actualFather;
      return temp;
}

/*
    EFECTO: devuelve el hijo más izquierdo del padre si tiene, y si no devuelve nulo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeD< T >* Tree< T > :: leftmostSon(NodeTreeD< T > *node) {
    return node -> getLeftmostSon();
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeD< T >* Tree< T > :: rightBrother(NodeTreeD< T > *node) {
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
int Tree< T > :: numSons(NodeTreeD< T > *node) {
    int result = 0;
    NodeTreeD< T > *temp = node -> getLeftmostSon();
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
T Tree< T > :: tag(NodeTreeD< T > *node) {
   return node -> getObject();
}

/*
    EFECTO: devuelve un verdadero si el nodo existe, si no devuelve falso
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Tree< T > :: exist(T tag) {
    NodeTreeD< T > *temp = this -> search(root,tag);
    return temp != nullptr ? true : false;
}

/*
    EFECTO: devuelve el nodo que contiene deteerminada etiqueta
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeD< T >* Tree< T > :: search(NodeTreeD< T > *newRoot, T tag) {
    NodeTreeD< T > *temp = nullptr;
    if(newRoot == nullptr)
        return nullptr;
    while(newRoot) {
        if(newRoot -> getObject() == tag)
            return newRoot;
        if(newRoot -> getLeftmostSon()) {
            temp = search(newRoot -> getLeftmostSon(), tag);
            if(temp)
                return temp;
        }
        newRoot = newRoot -> getRightBrother();
    }
    return temp;
}

#endif