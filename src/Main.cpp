#include <iostream>
#include "Menus.h"

int main() {
	Menus< int > *menu = new Menus< int >();
	menu -> principalMenu();
	return 0;
}