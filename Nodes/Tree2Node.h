#ifndef TREE2NODE_H
#define TREE2NODE_H

template < class T >
class Node {
    List< T > *object;
    Node< T > *father;
    public:
        Node() { object = new List< T >(); father = nullptr; };
        Node< T > *getFather() { return father; };
        List< T > *getObject() { return object; };
        void setFather(Node< T > *f) { father = f; };
};

#endif // TREE2NODE_H