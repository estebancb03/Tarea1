#include <iostream>
#include "Menus.h"

int main() {
	Menus< int > *menu = new Menus< int >();
	menu -> treeMenu();
	return 0;
}