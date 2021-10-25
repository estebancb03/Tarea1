#ifndef TREED_H
#define TREED_H
#include "Node.h"
template < class T >

class Tree {
    public:
        void create();
        void destroy();
        void clear();
        void setRoot(T tag);
        void addSon(T tag, T sonTag );
        void deleteLeaf(T tag);
        void modifyTag(T oldTag, T newTag);
        T root();
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

}

/*
    EFECTO: 
    REQUIERE: 
    MODIFICA: 
*/
template < typename T >
void Tree< T > :: destroy() {

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
T Tree< T > :: root() {

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