#include <iostream>
#include "../lib/Menus.h"

int main() {
	Menus< int > *menu = new Menus< int >();
	menu -> principalMenu();
	return 0;
}