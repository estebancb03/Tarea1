#ifndef TREEC_H
#define TREEC_H
#include "../Nodes/Tree3Node.h"

template < class T >
class Tree {
    int nodesNumber;
    Node< T > *root;
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
        Node< T > *searchLeftBrother(Node< T > *node, Node< T > *actual);
        Node< T > *searchFather(Node< T > *node, Node< T > *actual, Node< T > *actualFather);
        int numNodes();
        int numSons(Node< T > *node);
        bool empty();
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
    EFECTO: pone el nodo raíz del árbol
    REQUIERE: árbol creado
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: setRoot(T tag) {
    if(this -> empty())
        nodesNumber++;
    root = new Node< T >(tag);
}

/*
    EFECTO: agrega al nodo un hijo con esa etiqueta
    REQUIERE: árbol creado y nodo válido
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: addSon(Node< T > *father, T sonTag) {
    Node< T > *aux = new Node< T >(sonTag);
    if(!father -> getLeftmostSon()) 
        father -> setLeftmostSon(aux);
    else{
        Node< T > *temp = father -> getLeftmostSon();
        father -> setLeftmostSon(aux);
        aux -> setRightBrother(temp);
    }
    nodesNumber++;
}

/*
    EFECTO: elimima el nodo
    REQUIERE: árbol creado, nodo sin hijos y válido 
    MODIFICA: árbol
*/
template < typename T >
void Tree< T > :: deleteLeaf(Node< T > *node) {
    if (node -> getRightBrother()) {
        Node< T > *left = this -> searchLeftBrother(node, root);
        if (left) {
          left -> setRightBrother(node -> getRightBrother());
          delete node;
        }
    } 
    else {
        if(searchLeftBrother(node, root)) {
            searchLeftBrother(node, root) -> setRightBrother(nullptr);
        }
        else {
            Node< T > *father = searchFather(node, root, root);
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
    return root;
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: father(Node< T > *node) {
   return this -> searchFather(node, root, root);
}

/*
    EFECTO: devuelve el nodo padre de un nodo
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: searchFather(Node< T > *node, Node< T > *actual, Node< T > *actualFather) {
    Node< T > *temp = nullptr;
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
Node< T >* Tree< T > :: leftmostSon(Node< T > *node) {
    return node -> getLeftmostSon();
}

/*
    EFECTO: devuelve el hermano derecho si tiene, y si no existe devuelve nulo.
    REQUIERE: árbol creado y nodo válido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: rightBrother(Node< T > *node) {
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
int Tree< T > :: numSons(Node< T > *node) {
    int result = 0;
    Node< T > *temp = node -> getLeftmostSon();
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
T Tree< T > :: tag(Node< T > *node) {
   return node -> getObject();
}

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* Tree< T > :: searchLeftBrother(Node< T > *node, Node< T > *actual) {
    Node< T > *temp = nullptr;
    if (actual -> getRightBrother() == node)
        temp = actual; 
    else {
        actual = actual -> getLeftmostSon();
        while (actual && !temp) {
            temp = searchLeftBrother(node, actual);
            actual = actual -> getRightBrother();
        }
    }
    return temp;
}

#endif //TREEC_H