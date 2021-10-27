#ifndef NODETREEE_H
#define NODETREEE_H
template < class T >

class NodeTreeE {
    T object;
    NodeTreeE< T > *leftmostSon;
    NodeTreeE< T > *rightBrotherOrFather;
    public:
        NodeTreeE(T o) { object = o; leftmostSon = nullptr; rightBrotherOrFather = nullptr; };
        NodeTreeE< T > *getLeftmostSon() { return leftmostSon; };
        NodeTreeE< T > *getRightBrotherOrFather() { return rightBrotherOrFather; };
        T getObject() { return object; };
        void setObject(T o) { object = o; };
        void setLeftmostSon(NodeTreeE< T > *ls) { leftmostSon = ls; };
        void setRightBrotherOrFather(NodeTreeE< T > *rbf) { rightBrotherOrFather = rbf; };
};

#endif 