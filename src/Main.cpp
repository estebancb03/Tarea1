#include <iostream>
#include "Menus.h"

int main() {
	Menus< string > *menu = new Menus< string >();
	menu -> treeMenu();
	return 0;
}