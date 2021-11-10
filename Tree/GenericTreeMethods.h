#ifndef GENERICTREEMETHODS_H
#define GENERICTREEMETHODS_H
#include "../src/Menus.h"
#include "../Queue/Queue.h"
#include "../Stack/Stack.h"
using namespace std;

template < class T >
class GenericTreeMethods {
    Tree< T > *tree;
    public:
        GenericTreeMethods(Tree< T > *t) { tree = t; };
        Node< T > *getLeftBrother(Node< T > *node); 
        Node< T > *searchTag(Node< T > *node, T tag); 
        bool repeatedTags(); 
        int nodeHeight(Node< T > *node);
        int nodeHeight(Node< T > *node, int height, Stack< int > *stack);
        int nodeDepth(Node< T > *node);
        int preOrderTreeLevels(Node< T > *node, int levels);
        int byLevelsTreeLevels();
        void printALevel(int level);
        void printInPreOrder(Node< T > *node); 
        void printInPreOrderUsingStack();
        void printAllLevels();
        //Metodos auxiliares
        void fillQueue(Node< T > *node, Queue< Node< T >* > *queue);
        int objectQuantityInQueue(Queue< Node< T >* > *queue, T object);
};

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* GenericTreeMethods< T > :: getLeftBrother(Node< T > *node) {
    Node< T > *temp = nullptr;
    Node< T > *father = tree -> father(node);
    if(tree -> leftmostSon(father) != node) {
        Node< T > *aux = tree -> leftmostSon(father);
        bool enabled = true;
        while(enabled && aux) {
            if(tree -> rightBrother(aux) == node) {
                temp = aux;
                enabled = false;
            }
            else
                aux = tree -> rightBrother(aux);
        }
    } 
    return temp;
}

/*
    EFECTO: devuelve el nodo hermano izquierdo
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
Node< T >* GenericTreeMethods< T > :: searchTag(Node< T >* node, T tag) {
    Node< T > *temp = nullptr;
    if(node == nullptr)
        return nullptr;
    while(node) {
        if(node -> getObject() == tag)
            return node;
        if(tree -> leftmostSon(node)) {
            temp = searchTag(tree -> leftmostSon(node), tag);
            if(temp)
                return temp;
        }
        node = tree -> rightBrother(node);
    }
    return temp;
}

/*
    EFECTO: devuelve un true si hay etiquetas repetidas y un false si no
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
bool GenericTreeMethods< T > :: repeatedTags() {
    bool result = false;
    Queue< Node< T >* > *queue = new Queue< Node< T >* >(tree -> numNodes());
    queue -> create();
    this -> fillQueue(tree -> getRoot(), queue);
    while(!queue -> empty() && !result) {
        Node< T > *node = queue -> top();
        if(this -> objectQuantityInQueue(queue, node -> getObject()) > 1) 
            result = true;
        else
            queue -> pop();
    }
    queue -> destroy();
    return result;
}

/*
    EFECTO: devuelve la altura de un nodo haciendo
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
int GenericTreeMethods< T > :: nodeHeight(Node< T > *node) {
    Stack< int > *stack = new Stack< int >();
    stack -> create();
    int height = nodeHeight(node, 0, stack);
    stack -> destroy();
    return height;
}

template < typename T >
int GenericTreeMethods< T > :: nodeHeight(Node< T > *node, int height, Stack< int > *stack) {
    int newHeight = 0;
    Node< T > *temp = tree -> leftmostSon(node);
    while (temp) {
        if(!stack -> exist(this -> nodeDepth(node)))
            ++height;
        stack -> push(this -> nodeDepth(node));
        newHeight = nodeHeight(temp, height, stack);
        if (height < newHeight) 
            height = newHeight;
        temp = tree -> rightBrother(temp);
    }
    return height;
}

/*
    EFECTO: averigua la profundiad de un nodo determinado
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
int GenericTreeMethods< T > :: nodeDepth(Node< T > *node) {
    int depth = 0;
    if(node != tree -> getRoot()) {
        ++depth;
        Node< T > *temp = tree -> father(node);
        while(temp != tree -> getRoot()) {
            temp = tree -> father(temp);
            ++depth;
        }
    }
    return depth;
}

/*
    EFECTO: devuelve la cantidad de niveles del arbol haciendo un recorrido en pre-orden
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
int GenericTreeMethods< T > :: preOrderTreeLevels(Node< T > *node, int levels) {
    bool nextLevel = true;
    node = tree -> leftmostSon(node);
    while(node) {
        if (nextLevel) 
            ++levels;
        levels = preOrderTreeLevels(node, levels);
        node = tree -> rightBrother(node);
        nextLevel = false;
    }
  return levels;
}

/*
    EFECTO: devuelve la cantidad de niveles haciendo recorrdio por niveles
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
int GenericTreeMethods< T > :: byLevelsTreeLevels() {
    int levels = 0;
    Node< T > *temp = nullptr, *temp2 = nullptr;
    Queue< Node< T >* > *queue = new Queue< Node< T >* >(tree -> numNodes());
    Queue< Node< T >* > *queue2 = new Queue< Node< T >* >(tree -> numNodes());
    queue -> create();
    queue2 -> create();
    queue -> add(tree -> getRoot());
    queue2 -> add(tree -> getRoot());
    while(!queue -> empty()) {
        temp = queue -> pop();
        temp2 = tree -> leftmostSon(temp);
        while(temp2) {
            queue -> add(temp2);
            queue2 -> add(temp2);
            temp2 = tree -> rightBrother(temp2);
        }
    }
    while(!queue2 -> empty()) {
        temp = queue2 -> pop();
        if(levels < nodeDepth(temp))
            levels = nodeDepth(temp);
    }
    ++levels;
    queue -> destroy();
    queue2 -> destroy();
    return levels;
} 

/*
    EFECTO: imprime los nodos de un determinado nivel
    REQUIERE: arbol creado y nodo valido
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: printALevel(int level) {
    Node< T > *root = tree -> getRoot();
    Queue< Node< T >* > *queue = new Queue< Node< T >* >(tree -> numNodes());
    queue -> create();
    this -> fillQueue(root, queue);
    while(!queue -> empty()) {
        Node< T > *temp = queue -> pop();
        if(this -> nodeDepth(temp) == level - 1)
            cout << temp -> getObject() << ", ";
    } 
}

/*
    EFECTO: imprime los elementos del arbol en preorden
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: printInPreOrder(Node< T > *node) {
    cout << node -> getObject() << ", ";
    Node< T > *actual = tree -> leftmostSon(node);
    while(actual) {
        this -> printInPreOrder(actual);
        actual = tree -> rightBrother(actual);
    }
}

/*
    EFECTO: imprime los elementos del arbol en preorden usando una pila auxiliar
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: printInPreOrderUsingStack() {
    Stack< Node< T >* > *stack = new Stack< Node< T >* >();
    Node< T > *node = tree -> getRoot();
    while (node) {
        cout << node -> getObject() << ", ";
        if (tree -> rightBrother(node)) 
            stack -> push(tree -> rightBrother(node));
        node = tree -> leftmostSon(node);
        if(!node)
            node = stack -> pop();
    }
} 

/*
    EFECTO: imprime los nodos del arbol en orden por niveles
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: printAllLevels() {
    Node< T > *temp = nullptr, *temp2 = nullptr;
    Queue< Node< T >* > *queue = new Queue< Node< T >* >(tree -> numNodes());
    queue -> create();
    queue -> add(tree -> getRoot());
    while(!queue -> empty()){
        temp = queue -> pop();
        cout << temp -> getObject() << ", ";
        temp2 = tree -> leftmostSon(temp);
        while(temp2){
            queue -> add(temp2);
            temp2 = tree -> rightBrother(temp2);
        }
    }
    queue -> destroy();
}

/*
    EFECTO: llena una cola con los elementos del arbol en pre-orden
    REQUIERE: arbol creado
    MODIFICA: no hace modificaciones
*/
template < typename T >
void GenericTreeMethods< T > :: fillQueue(Node< T > *node, Queue< Node< T >* > *queue) {
    queue -> add(node);
    Node< T > *actual = tree -> leftmostSon(node);
    while(actual) {
        this -> fillQueue(actual, queue);
        actual = tree -> rightBrother(actual);
    }
} 

/*
    EFECTO: retorna la cantidad de veces que un objeto esta en la cola
    REQUIERE: cola creada
    MODIFICA: no hace modificaciones
*/
template < typename T >
int GenericTreeMethods< T > :: objectQuantityInQueue(Queue< Node< T >* > *queue, T object) {
    int result = 0;
    Node< T >* *array = queue -> getArray();
    for(int i = 0; i < queue -> getSize(); ++i) {
        Node< T > *node = array[i];
        if(object == node -> getObject())
            ++result;
    }
    return result;
}

#endif //GENERICTREEMETHODS_H