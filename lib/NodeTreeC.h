#ifndef NODETREEC_H
#define NODETREEC_H
template < class T >

class Node {
    T object;
    Node< T > *leftmostSon;
    Node< T > *rightBrother;
    public:
        Node(T o) { object = o; leftmostSon = nullptr; rightBrother = nullptr };
        Node< T > *getLeftmostSon() { return leftmostSon; };
        Node< T > *getRightBrother() { return rightBrother; };
        T getObject() { return object; };
        void setLeftmostSon(Node< T > *ls) { leftmostSon = ls; };
        void setRightBrother(Node< T > *rb) { rightBrother = rb; };
};

#endif 