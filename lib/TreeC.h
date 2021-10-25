#ifndef TREEC_H
#define TREEC_H
#include "NodeTreeC.h"
template < class T >

class Tree {
    NodeTreeC< T > *root;
    public:
        void create();
        void destroy();
        void clear();
        bool search(T tag);
        NodeTreeC< T > search(T tag);
        void setRoot(T tag);
        void addSon(NodeTreeC< T > father, T sonTag);
        void deleteLeaf(NodeTreeC< T > node);
        void modifyTag(NodeTreeC< T > node, T newTag);
        T getRoot();
        T father(NodeTreeC< T > node);
        T leftmostSon(NodeTreeC< T > node);
        T rightBrother(NodeTreeC< T > node);
        T tag(NodeTreeC< T > node);
        int numNodes();
        int numSons(NodeTreeC< T > node);
        bool empty();
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
    root = new NodeTreeC< T >(tag);
}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: addSon(NodeTreeC< T > father, T sonTag) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: deleteLeaf(NodeTreeC< T > node) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: modifyTag(NodeTreeC< T > node, T newTag) {

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
T Tree< T > :: father(NodeTreeC< T > node) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
T Tree< T > :: leftmostSon(NodeTreeC< T > node) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
T Tree< T > :: rightBrother(NodeTreeC< T > node) {

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
int Tree< T > :: numSons(NodeTreeC< T > node) {

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
bool Tree< T > :: empty() {
    return root == nullptr ? true : false;
}

#endif
