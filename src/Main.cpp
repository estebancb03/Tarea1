#include <iostream>
#include "Menus.h"
using namespace std;

int main() {
	Menus< int > *menu = new Menus< int >();
	menu -> principalMenu();
	return 0;
}