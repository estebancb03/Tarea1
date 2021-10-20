#include <iostream>
#include "Menus.h"
using namespace std;

int main() {
	Menus<string> *menu = new Menus<string>();
	menu -> principalMenu();
	return 0;
}