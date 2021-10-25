#ifndef TREEC_H
#define TREEC_H
#include "NodeTreeC.h"
template < class T >

class Tree {
    Node< T > *root;
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(T tag, T sonTag);
        void deleteLeaf(T tag);
        void modifyTag(T oldTag, T newTag);
        T getRoot();
        T father(T tag);
        T leftmostSon(T tag);
        T rightBrother(T tag);
        int numNodes();
        int numSons(T tag);
        bool empty();
        //Falta Etiqutea
};

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: create() {
    root = nullptr;
}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: destroy() {
    delete root;
}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: clear() {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: setRoot(T tag) {
    root = new Node< T >(tag);
}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: addSon(T tag, T sonTag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: deleteLeaf(T tag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: modifyTag(T oldTag, T newTag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
T Tree< T > :: getRoot() {
    return root -> getObject();
}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
T Tree< T > :: father(T tag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
T Tree< T > :: leftmostSon(T tag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
T Tree< T > :: rightBrother(T tag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
int Tree< T > :: numNodes() {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
int Tree< T > :: numSons(T tag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
bool Tree< T > :: empty() {

}

#endif
