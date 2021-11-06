#ifndef TREE2NODE_H
#define TREE2NODE_H

template < class T >
class Node {
    T object;
	Node< Node< T >* > *son;
	Node *next;
    public:
        Node() {};
        Node(T o) { object = o; next = nullptr; son = nullptr; };
        Node(T o, Node* n) { object = o; next = n; son = nullptr; };
        T getObject() { return object; };
        Node* getNext() { return next; };
        Node< Node< T >* > *getSon() { return son; };
        void setObject(T o) { object = o; };
        void setNext(Node *n) { next = n; };
        void setSon(Node< Node< T >* > *s) { son = s; };

};

#endif // TREE2NODE_H