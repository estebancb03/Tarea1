#ifndef GENERICTREEMETHODS_H
#define GENERICTREEMETHODS_H
#include "../src/Menus.h"
#include "../Queue/Queue.h"
#include "../Stack/Stack.h"
using namespace std;

template < class T >
class GenericTreeMethods {
    Tree< T > *tree;
    public:
        GenericTreeMethods(Tree< T > *t) { tree = t; };
        Node< T > *getLeftBrother(Node< T > *node); 
        Node< T > *searchTag(Node< T > *node, T tag); 
        bool repeatedTags(); 
        int nodeHeight(Node< T > *node);
        int nodeDepth(Node< T > *node);
        int preOrderTreeLevels();
        int byLevelsTreeLevels();
        void printALevel(int level);
        void printInPreOrder(Node< T > *node); 
        void printInPreOrderUsingStack();
        void printAllLevels();
        void fillQueue(Node< T > *node, Queue< T > *queue);
};

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* GenericTreeMethods< T > :: getLeftBrother(Node< T > *node) {
    Node< T > *temp = nullptr;
    Node< T > *father = tree -> father(node);
    if(tree -> leftmostSon(father) != node) {
        Node< T > *aux = tree -> leftmostSon(father);
        bool enabled = true;
        while(enabled && aux) {
            if(tree -> rightBrother(aux) == node) {
                temp = aux;
                enabled = false;
            }
            else
                aux = tree -> rightBrother(aux);
        }
    } 
    return temp;
}

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* GenericTreeMethods< T > :: searchTag(Node< T >* node, T tag) {
    Node< T > *temp = nullptr;
    if(node == nullptr)
        return nullptr;
    while(node) {
        if(node -> getObject() == tag)
            return node;
        if(tree -> leftmostSon(node)) {
            temp = searchTag(tree -> leftmostSon(node), tag);
            if(temp)
                return temp;
        }
        node = tree -> rightBrother(node);
    }
    return temp;
}

/*
    EFECTO: devuelve un true si hay etiquetas repetidas y un false si no
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool GenericTreeMethods< T > :: repeatedTags() {
    int counter = 0;
    bool result = false;
    Queue< T > *queue = new Queue< T >(tree -> numNodes());
    queue -> create();
    this -> fillQueue(tree -> getRoot(), queue);
    while(!queue -> empty() && !result) {
        T object = queue -> top();
        if(queue -> objectQuantity(object) > 1) 
            result = true;
        else
            queue -> pop();
    }
    queue -> destroy();
    return result;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
int GenericTreeMethods< T > :: nodeHeight(Node< T > *node) {

}

/*
    EFECTO: averigua la profundiad de un nodo determinado
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
int GenericTreeMethods< T > :: nodeDepth(Node< T > *node) {
    int depth = 0;
    if(node != tree -> getRoot()) {
        ++depth;
        Node< T > *temp = tree -> father(node);
        while(temp != tree -> getRoot()) {
            temp = tree -> father(temp);
            ++depth;
        }
    }
    return depth;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
int GenericTreeMethods< T > :: preOrderTreeLevels() {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
int GenericTreeMethods< T > :: byLevelsTreeLevels() {
    
}

/*
    EFECTO: imprime los nodos de un determinado nivel
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: printALevel(int level) {
    Node< T > *root = tree -> getRoot();
    Queue< T > *queue = new Queue< T >(tree -> numNodes());
    queue -> create();
    this -> fillQueue(root, queue);
    while(!queue -> empty()) {
        Node< T > *temp = this -> searchTag(root, queue -> pop());
        if(this -> nodeDepth(temp)  == level - 1)
            cout << temp -> getObject() << ", ";
    } 
}

/*
    EFECTO: imprime los elementos del arbol en preorden
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: printInPreOrder(Node< T > *node) {
    cout << node -> getObject() << ", ";
    Node< T > *actual = tree -> leftmostSon(node);
    while(actual) {
        this -> printInPreOrder(actual);
        actual = tree -> rightBrother(actual);
    }
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void GenericTreeMethods< T > :: printInPreOrderUsingStack() {

} 

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void GenericTreeMethods< T > :: printAllLevels() {
    Node< T > *temp = tree -> getRoot();
    Node< T > *temp2 = nullptr;
    Queue< Node< T >* > *queue = new Queue< Node< T >* >(tree -> numNodes());
    queue -> create();
}

/*
    EFECTO: llena una cola con los elementos del arbol en pre-orden
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: fillQueue(Node< T > *node, Queue< T > *queue) {
    queue -> add(node -> getObject());
    Node< T > *actual = tree -> leftmostSon(node);
    while(actual) {
        this -> fillQueue(actual, queue);
        actual = tree -> rightBrother(actual);
    }
}

#endif //GENERICTREEMETHODS_H