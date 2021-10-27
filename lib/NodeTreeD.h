#ifndef NODETREED_H
#define NODETREED_H
template < class T >

class NodeTreeD {
    T object;
    NodeTreeD< T > *leftmostSon;
    NodeTreeD< T > *leftBrother;
    NodeTreeD< T > *rightBrother;
    NodeTreeD< T > *father;
    public:
        NodeTreeD(T o) { object = o; leftmostSon = nullptr; leftBrother = nullptr; rightBrother = nullptr; father = nullptr; };
        NodeTreeD< T > *getLeftmostSon() { return leftmostSon; };
        NodeTreeD< T > *getLeftBrother() { return leftBrother; };
        NodeTreeD< T > *getRightBrother() { return rightBrother; };
        NodeTreeD< T > *getFather() { return father; };
        T getObject() { return object; };
        void setObject(T o) { object = o; };
        void setLeftmostSon(NodeTreeD< T > *ls) { leftmostSon = ls; };
        void setLeftBrother(NodeTreeD< T > *lb) { leftBrother = lb; };
        void setRightBrother(NodeTreeD< T > *rb) { rightBrother = rb; };
        void setFather(NodeTreeD< T > *f) { father = f; };
};

#endif 