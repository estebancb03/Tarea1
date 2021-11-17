/*
	C01795 - Esteban Castañeda Blanco
	C03913 - Esteban Iglesias Vargas
	C04285 - Daniel Lizano Morales
*/
#include <iostream>
#include "Menus.h"
#include "Tests.h"

int main() {
	//Menus< string > *menu = new Menus< string >();
	//menu -> treeMenu();
	Tests< int > *test = new Tests< int >();
	test -> test();
	return 0;
}