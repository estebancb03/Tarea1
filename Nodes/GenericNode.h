#ifndef GENERICNODE_H
#define GENERICNODE_H
template < class T >

class GenericNode {
    T object;
    GenericNode< T > *next;
    public:
        GenericNode(T o) { object = o; next = nullptr; };
        GenericNode< T > *getNext() { return next; };
        T getObject() { return object; };
        void setObject(T o) { object = o; };
        void setNext(GenericNode< T > *n) { next = n; };
};

#endif //GENERICNODE