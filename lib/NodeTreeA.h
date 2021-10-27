#ifndef NODETREEA_H
#define NODETREEA_H
template < class T >

class NodeTreeA {
    T object;
    int position;
    int fatherPosition;
    public:
        NodeTreeA(T o, int p, int fp) { object = o; position = p; fatherPosition = fp; };
        T getObject() { return object; };
        int getposition() { return position; };
        int getFatherPosition() { return fatherPosition; };
        void setObject(int o) { object = o; };
        void setPosition(int p) { position = p; };
        void setFatherPosition(int fp) { fatherPosition = fp; };
};

#endif 