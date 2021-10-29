#ifndef TREE1NODE_H
#define TREE1NODE_H

template < class T >
class Node {
    public:
        T object;
        int position;
        int fatherPosition;
        Node(T o, int p, int fp) { object = o; position = p; fatherPosition = fp; };
        T getObject() { return object; };
        int getPosition() { return position; };
        int getFatherPosition() { return fatherPosition; };
        void setObject(T o) { object = o; };
        void setPosition(int p) { position = p; };
        void setFatherPosition(int fp) { fatherPosition = fp; };
};

#endif // TREE1NODE_H