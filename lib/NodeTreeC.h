#ifndef NODETREEC_H
#define NODETREEC_H
template < class T >

class NodeTreeC {
    T object;
    NodeTreeC< T > *leftmostSon;
    NodeTreeC< T > *rightBrother;
    public:
        NodeTreeC(T o) { object = o; leftmostSon = nullptr; rightBrother = nullptr; };
        NodeTreeC< T > *getLeftmostSon() { return leftmostSon; };
        NodeTreeC< T > *getRightBrother() { return rightBrother; };
        T getObject() { return object; };
        void setLeftmostSon(NodeTreeC< T > *ls) { leftmostSon = ls; };
        void setRightBrother(NodeTreeC< T > *rb) { rightBrother = rb; };
};

#endif 