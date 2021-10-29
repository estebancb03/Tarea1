#ifndef GENERICTREEMETHODS_H
#define GENERICTREEMETHODS_H
#include "../Stack/Stack.h"
#include "../Queue/Queue.h"
#include "../src/Menus.h"
using namespace std;

template < class T >
class Menus;
template < class T >
class GenericTreeMethods {
    Tree *tree;
    public:
        GenericTreeMethods();
        Node< T > *getLeftBrother();
        Node< T > *searchTag(T tag);
        bool repeatedTags();
        int nodeHeight(T tag);
        int nodeDepth(T tag);
        int preOrderTreeLevels();
        int byLevelsTreeLevels();
};

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
Node< T >* GenericTreeMethods< T > :: getLeftBrother() {

}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
Node< T >* GenericTreeMethods< T > :: searchTag(T tag) {

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

#endif //GENERICTREEMETHODS_H