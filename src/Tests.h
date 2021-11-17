#ifndef TESTS_H
#define TESTS_H
#include <chrono>
#include <iostream>
#include "../Tree/TreeA.h"
//#include "../Tree/TreeB.h"
//#include "../Tree/TreeC.h"
//#include "../Tree/TreeD.h"
//#include "../Tree/TreeE.h"
#include "../Tree/GenericTreeMethods.h"
//using namespace std;

template <class T>
class Tests {
    Tree< T > *tree;
	GenericTreeMethods< T > *genericTreeMethods;
    public:
        void test();
};

template < typename T >
void Tests< T > :: test() {

    tree = new Tree< T >();
	tree -> create();
	genericTreeMethods = new GenericTreeMethods< T >(tree);
    tree -> setRoot(0);
    for(int i = 1; i < 20000; i++) {
        tree -> addSon(tree -> getRoot(), i);
    }

    auto start = std :: chrono :: system_clock :: now();
    genericTreeMethods -> printAllLevels();

    auto end = std :: chrono :: system_clock :: now();
    std :: chrono :: duration<float, std :: milli> duration = end - start;
    std :: cout << endl << "Tiempo: " << duration.count() << " milisegundos" << endl;
}

#endif //TESTS_H