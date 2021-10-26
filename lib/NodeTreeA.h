#ifndef NODETREEA_H
#define NODETREEA_H
template < class T >

class NodeTreeA {
    T object;
    int position;
    int fatherPosition;
    public:
        NodeTreeC(T o, int p, int fp) { object = o; position = p; fatherPosition = fp; };
        T getObject() { return object; };
        T getposition() { return position; };
        T getFatherPosition() { return fatherPosition; };
        void setObject(T o) { object = o; };
        void setPosition(T p) { position = p; };
        void setFatherPosition(T fp) { fatherPosition = fp; };
};

#endif 