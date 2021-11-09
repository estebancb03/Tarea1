#ifndef TREEA_H
#define TREEA_H
#include <vector>
#include "../Nodes/Tree1Node.h"
using namespace std;

template < class T >
class Tree {
    int size;
    int nodesNumber;
    vector< Node< T >* > tree;
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
        int numNodes();
        int numSons(Node< T > *node);
        bool empty();
        bool exist(T tag);
        void print();
};

template < typename T >
void Tree< T > :: create(){
    this -> size = 10;
    this -> nodesNumber = 0;
    this -> tree.reserve(this -> size);
}


template < typename T >
void Tree< T > :: destroy(){
    delete this; 
}


template < typename T >
void Tree< T > :: clear(){
    this -> destroy();
    this -> create();
    nodesNumber = 0;
}


template < typename T >
bool Tree< T > :: empty(){
    return nodesNumber == 0 ? true : false;;
}


template < typename T >
Node< T >* Tree< T > :: getRoot(){
    return this -> tree[0];
}


template < typename T >
void Tree< T > :: setRoot(T tag){
    Node< T > *root = new Node< T >();
    root -> setObject(tag);
    root -> setFatherPosition(-1);
    root -> setPosition(nodesNumber);
    this -> tree.push_back(root);
    nodesNumber++;
}


template < typename T >
Node<T>* Tree< T > :: father(Node< T > *node){
    return this -> tree[node -> getFatherPosition()];
}



template < typename T >
void Tree< T > :: addSon(Node< T > *node, T tag){
    Node< T > *son = new Node<T>();
    son -> setObject(tag);
    son -> setFatherPosition(node -> getPosition());
    son -> setPosition(nodesNumber);
    this -> tree.push_back(son);
    nodesNumber++;
}


template < typename T >
int Tree< T > :: numNodes(){
    return nodesNumber;
}


template < typename T >
T Tree< T > :: tag(Node< T > *node){
    return this -> tree[node -> getPosition()] -> getObject();
}


template < typename T >
void Tree< T > :: modifyTag(Node< T > *node, T tag) {
    this -> tree[node -> getPosition()] -> setObject(tag);
}


template < typename T >
Node<T>* Tree< T > :: leftmostSon(Node< T > *node){
    int father = node -> getPosition();
    for (int i = 0; i < nodesNumber; ++i) {
        if (this -> tree[i] -> getFatherPosition() == father) {
            return this -> tree[i];
        }
    }
    return nullptr;
}


template < typename T >
Node<T>* Tree< T > :: rightBrother(Node< T > *node){
    int father = node -> getFatherPosition();
    for (int i = node -> getPosition() + 1; i < this -> tree.size(); ++i) {
        if (this -> tree[i] -> getFatherPosition() == father) {
            return this -> tree[i];
        }
    }
    return nullptr;
}


template < typename T >
int Tree<T>::numSons(Node<T>* node){
    int father = node -> getPosition();
    int numSons = 0;
    for (int i = 0; i < this -> tree.size(); ++i) {
        if (this -> tree[i] -> getFatherPosition() == father) {
            ++numSons;
        }
    }
    return numSons;
}


template < typename T >
void Tree< T > :: deleteLeaf(Node< T > *node){
    if(node -> getPosition() != 0 && node -> getPosition() < nodesNumber - 1) {
        for(int i = node -> getPosition(); i < nodesNumber - 1; ++i) 
            tree[i] = tree[i + 1];
    }
    else 
        delete tree[node -> getPosition()];
    --nodesNumber;
}

#endif