#ifndef TREE2NODE_H
#define TREE2NODE_H

template < class T >
class Node {
    T object;
    Node< T > *father;
    public:
        Node(T o) { object = o; next = nullptr; };
        Node< T > *getFather() { return father; };
        T getObject() { return object; };
        void setFather(Node< T > *f) { father = f; };
};

#endif // TREE2NODE_H