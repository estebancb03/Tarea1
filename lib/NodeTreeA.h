#ifndef NODETREEA_H
#define NODETREEA_H
template < class T >

class NodeTreeA {
    T object;
    int position;
    int fatherPosition;
    public:
        NodeTreeA(T o) { object = o; position = 0; fatherPosition = 0; };
        T getObject() { return object; };
        int getposition() { return position; };
        int getFatherPosition() { return fatherPosition; };
        void setObject(int o) { object = o; };
        void setPosition(int p) { position = p; };
        void setFatherPosition(int fp) { fatherPosition = fp; };
};

#endif 