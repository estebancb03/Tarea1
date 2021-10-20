#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
template < class T >

class Queue {
    int first;
    int last;
    int size = 10;
    T array[10];
    public:
        void create();
        void destroy(); //Falta por hacer
        void clear(); //Falta por hacer
        void print(); //Falta por hacer
        bool add(T element);
        bool empty();
        bool full();
        int quantity();
        T pop();
        T top();
};

/*
    EFECTO: crea e inicializa la cola circular
    REQUIERE: cola no creada o destruida
    MODIFICA: cola
*/
template < typename T >
void Queue< T > :: create() {
    first = -1;
    last = -1; 
    this -> add("h");
    this -> add("o");
    this -> add("l");
    this -> add("a");
    this -> add("_");
    this -> add("m");
    this -> add("u");
    this -> add("n");
    this -> add("d");
    this -> add("o");
}

/*
    EFECTO: elimina la estructura de datos
    REQUIERE: cola creada
    MODIFICA: cola
*/
template < typename T >
void Queue< T > :: destroy() {
    //delete array;
}

/*
    EFECTO:
    REQUIERE:
    MODIFICA:
*/
template < typename T >
void Queue< T > :: clear() {

}

/*
    EFECTO: introduce un elemento al final de la cola
    REQUIERE: cola creada
    MODIFICA: cola
*/
template < typename T >
bool Queue< T > :: add(T element) {
    if(!this -> full()) {
        if(this -> empty()) {
            first = 0;
        }
        if(last == size - 1) {
            last = 0;
        }
        else {
            last++;
        }
        array[last] = element;
        return true;
    }
    else 
        return false;
}

/*
    EFECTO: devuelve un verdadero si la cola está vacía y un falso si no
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Queue< T > :: empty() {
    return last == -1 ? true : false;
}

/*
    EFECTO: devuelve la cantidad de elementos precentes en la cola
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
int Queue< T > :: quantity() {
    int result = 0;
    if(!this -> empty()) {
        if(first <= last)
            result = last - first + 1;
        else
            result = size - first + last + 1;
    }
    return result;
}

/*
    EFECTO: devuelve un verdadero si la cola está llena y un falso si no
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool Queue< T > :: full() {
    return this -> quantity() == size ? true : false;
}

/*
    EFECTO: devuelve el primer elemento y a la vez lo elimina de la cola
    REQUIERE: cola creada
    MODIFICA: cola
*/
template < typename T >
T Queue< T > :: pop() {
    if(!this -> empty()) {
        T temp = array[first];
        if(this -> quantity() == 1) {
            this -> create();
        }
        else {
            array[first] = "";
            if(first == size - 1)
                first = 0;
            else
                ++first;
        }
        return temp;
    }
}

/*
    EFECTO: devuelve el primer elemento de la cola
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
T Queue< T > :: top() {
        return array[first];
}

/*
    EFECTO: imprime los elementos de la cola
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
void Queue< T > :: print() {
    cout << "Cola: ";
    for(int i = first; i < size; ++i) {
        cout << "#" << i << ": " << array[i];
        if(i < size - 1)
            cout << " -> ";
    }
    if(first != 0) {
        for(int i = 0; i < first; ++i) {
            cout << " #" << i << ": " << array[i];
            cout << " -> ";
        }
    }
}

#endif