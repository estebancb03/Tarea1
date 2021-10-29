#ifndef TREE4NODE_H
#define TREE4NODE_H

template < class T >
class Node {
    T object;
    Node< T > *leftmostSon;
    Node< T > *leftBrother;
    Node< T > *rightBrother;
    Node< T > *father;
    public:
        Node(T o) { object = o; leftmostSon = nullptr; leftBrother = nullptr; rightBrother = nullptr; father = nullptr; };
        Node< T > *getLeftmostSon() { return leftmostSon; };
        Node< T > *getLeftBrother() { return leftBrother; };
        Node< T > *getRightBrother() { return rightBrother; };
        Node< T > *getFather() { return father; };
        T getObject() { return object; };
        void setObject(T o) { object = o; };
        void setLeftmostSon(Node< T > *ls) { leftmostSon = ls; };
        void setLeftBrother(Node< T > *lb) { leftBrother = lb; };
        void setRightBrother(Node< T > *rb) { rightBrother = rb; };
        void setFather(Node< T > *f) { father = f; };
};

#endif // TREE4NODE_H