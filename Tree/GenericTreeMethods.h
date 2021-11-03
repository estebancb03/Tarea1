#ifndef GENERICTREEMETHODS_H
#define GENERICTREEMETHODS_H
#include "../src/Menus.h"
using namespace std;

template < class T >
class Menus;

template < class T >
class GenericTreeMethods {
    Tree< T > *tree;
    public:
        GenericTreeMethods(Tree< T > *t) { tree = t; };
        Node< T > *getLeftBrother(Node< T > *actual, Node< T > *node);
        Node< T > *searchTag(Node< T >* node, T tag);
        bool repeatedTags();
        int nodeHeight(T tag);
        int nodeDepth(T tag);
        int preOrderTreeLevels();
        int byLevelsTreeLevels();
        void printALevel(int level);
        void printInPreOrder();
        void printInPreOrderUsingStack();
        void printAllLevels();
};

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* GenericTreeMethods< T > :: getLeftBrother(Node< T > *node, Node< T > *actual) {
    Node< T > *temp = nullptr;
    if (tree -> rightBrother(actual) == node)
        temp = actual; 
    else {
        actual = tree -> leftmostSon(actual);
        while (actual && !temp) {
            temp = getLeftBrother(node, actual);
            actual = tree -> rightBrother(actual);
        }
    }
    return temp;
}

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado
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
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
bool GenericTreeMethods< T > :: repeatedTags() {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
int GenericTreeMethods< T > :: nodeHeight(T tag) {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
int GenericTreeMethods< T > :: nodeDepth(T tag) {

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
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void GenericTreeMethods< T > :: printALevel(int level) {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void GenericTreeMethods< T > :: printInPreOrder() {

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

}

#endif //GENERICTREEMETHODS_H