#ifndef TREEE_H
#define TREEE_H
#include "NodeTreeE.h"
template < class T >

class Tree {
    int nodesNumber;
    NodeTreeE< T > *root;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(NodeTreeE< T > *father, T sonTag);
        void deleteLeaf(NodeTreeE< T > *node);
        void modifyTag(NodeTreeE< T > *node, T newTag);
        T tag(NodeTreeE< T > *node);
        NodeTreeE< T > *father(NodeTreeE< T > *node);
        NodeTreeE< T > *leftmostSon(NodeTreeE< T > *node);
        NodeTreeE< T > *rightBrother(NodeTreeE< T > *node);
        NodeTreeE< T > *getRoot();
        NodeTreeE< T > *search(NodeTreeE< T > *newRoot, T tag);
        NodeTreeE< T > *searchLeftBrother(NodeTreeE< T > *node, NodeTreeE< T > *actual);
        NodeTreeE< T > *searchFather(NodeTreeE< T > *node, NodeTreeE< T > *actual, NodeTreeE< T > *actualFather);
        int numNodes();
        int numSons(NodeTreeE< T > *node);
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
    root = new NodeTreeE< T >(tag);
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(NodeTreeE< T > *father, T sonTag) {
    if(!father -> getLeftmostSon()) {
        father -> setLeftmostSon(new NodeTreeE< T >(sonTag));
        father -> getLeftmostSon() -> setRightBrotherOrFather(father);
    }
    else{
        NodeTreeE< T > *temp = father -> getLeftmostSon();
        while(temp -> getRightBrotherOrFather() != father) 
            temp = temp -> getRightBrotherOrFather();
        temp -> setRightBrotherOrFather(new NodeTreeE< T >(sonTag));
        temp -> getRightBrotherOrFather() -> setRightBrotherOrFather(father);
    }
    nodesNumber++;
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(NodeTreeE< T > *node) {
    if (node -> getRightBrotherOrFather()) {
        NodeTreeE< T > *left = this -> searchLeftBrother(node, root);
        if (left) {
          left -> setRightBrotherOrFather(node -> getRightBrotherOrFather());
          delete node;
        }
    } 
    else {
        if(searchLeftBrother(node, root)) {
            searchLeftBrother(node, root) -> setRightBrotherOrFather(father(searchLeftBrother(node, root)));
        }
        else {
            NodeTreeE< T > *father = searchFather(node, root, root);
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
void Tree< T > :: modifyTag(NodeTreeE< T > *node, T newTag) {
    node -> setObject(newTag);
}

/*
    EFECTO: devuelve el nodo raíz del árbol
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeE< T >* Tree< T > :: getRoot() {
    return root;
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeE< T >* Tree< T > :: father(NodeTreeE< T > *node) {
   return this -> searchFather(node, root, root);
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeE< T >* Tree< T > :: searchFather(NodeTreeE< T > *node, NodeTreeE< T > *actual, NodeTreeE< T > *actualFather) {
    NodeTreeE< T > *temp = nullptr;
      if(actual != node) {
          actualFather = actual;
        actual = actual -> getLeftmostSon();
        while(actual && !temp) {
          temp = searchFather(node, actual, actualFather);
          actual = actual -> getRightBrotherOrFather();
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
NodeTreeE< T >* Tree< T > :: leftmostSon(NodeTreeE< T > *node) {
    return node -> getLeftmostSon();
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeE< T >* Tree< T > :: rightBrother(NodeTreeE< T > *node) {
    return node -> getRightBrotherOrFather();
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
int Tree< T > :: numSons(NodeTreeE< T > *node) {
    int result = 0;
    NodeTreeE< T > *temp = node -> getLeftmostSon();
    while(temp) {
        temp = temp -> getRightBrotherOrFather();
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
T Tree< T > :: tag(NodeTreeE< T > *node) {
   return node -> getObject();
}

/*
    EFECTO: devuelve un verdadero si el nodo existe, si no devuelve falso
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Tree< T > :: exist(T tag) {
    NodeTreeE< T > *temp = this -> search(root,tag);
    return temp != nullptr ? true : false;
}

/*
    EFECTO: devuelve el nodo que contiene deteerminada etiqueta
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeE< T >* Tree< T > :: search(NodeTreeE< T > *newRoot, T tag) {
    NodeTreeE< T > *temp = nullptr;
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
        newRoot = newRoot -> getRightBrotherOrFather();
    }
    return temp;
}

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
NodeTreeE< T >* Tree< T > :: searchLeftBrother(NodeTreeE< T > *node, NodeTreeE< T > *actual) {
    NodeTreeE< T > *temp = nullptr;
    if (actual -> getRightBrotherOrFather() == node)
        temp = actual; 
    else {
        actual = actual -> getLeftmostSon();
        while (actual && !temp) {
            temp = searchLeftBrother(node, actual);
            actual = actual -> getRightBrotherOrFather();
        }
    }
    return temp;
}

#endif