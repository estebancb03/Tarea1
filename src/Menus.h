#ifndef MENUS_H
#define MENUS_H
#include "../Tree/TreeA.h"
//#include "../Tree/TreeB.h"
//#include "../Tree/TreeC.h"
//#include "../Tree/TreeD.h"
//#include "../Tree/TreeE.h"
#include "../Stack/Stack.h"
#include "../Queue/Queue.h"
#include "../Tree/GenericTreeMethods.h"
using namespace std;

template <class T>
class Menus {
    public:
		void treeMenu();
        void principalMenu();
		void genericTreeMethodsMenu();
};

/*
	EFECTO: maneja el desplazamiento entre los otros menus
	REQUIERE: no tiene requerimientos
	MODIFICA: no hace modificaciones
*/
template < typename T >
void Menus< T > :: principalMenu() {
	bool enabled = true;
    int option = 0;
	while(enabled) {
		system("cls");
		cout << "M E N U  D E  O P C I O N E S" << endl << endl;
		cout << "1. Arbol n-ario" << endl;
		cout << "2. Metodos genericos (Etapa 3)" << endl;
		cout << "3. Salir" << endl << endl;
		cout << "Opcion: "; cin >> option;
		switch (option) {
			case 1: this -> treeMenu(); break;
			case 2: this -> genericTreeMethodsMenu(); break;
			case 3: enabled = false; break;
		}
	}
}

/*
	EFECTO: maneja el uso de los métodos genericos para arboles Tree
	REQUIERE: arbol creado
	MODIFICACIONES: varias modificaciones en el árbol de acuerdo a las opciones elegidas
*/
template < typename T >
void Menus< T > :: treeMenu() {
	bool enabled = true;
	int option = 0;
	Tree< T > *tree;
	GenericTreeMethods< T > *genericTreeMethods;
	while(enabled) {
		system("cls");
		cout << "M E N U  D E  O P C I O N E S  D E  A R B O L  N - A R I O" << endl << endl;
		cout << "1. Crear" << endl;
		cout << "2. Destruir" << endl;
		cout << "3. Vaciar" << endl;
		cout << "4. Vacio?" << endl;
		cout << "5. Poner raiz" << endl;
		cout << "6. Agregar hijo" << endl;
		cout << "7. Borrar hoja" << endl;
		cout << "8. Modificar etiqueta" << endl;
		cout << "9. Raiz?" << endl;
		cout << "10. Padre?" << endl;
		cout << "11. Hijo mas izquierdo?" << endl;
		cout << "12. Hermano derecho?" << endl;
		cout << "13. Etiqueta?" << endl;
		cout << "14. Numero de nodos?" << endl;
		cout << "15. Numero de hijos?" << endl;
		cout << "16. Visualizar" << endl;
		cout << "17. Salir" << endl << endl;
		cout << "Opcion: "; cin >> option;
		switch(option) {
			case 1: {
				system("cls");
				tree = new Tree< T >();
				tree -> create();
				genericTreeMethods = new GenericTreeMethods< T >(tree);
				cout << "Arbol creado correctamente" << endl << endl;
				system("pause");
			}	break;
			case 2: {
				system("cls");
				tree -> destroy();
				cout << "Arbol destruido correctamente" << endl << endl;
				system("pause");
			}	break;
			case 3: {
				system("cls");
				tree -> clear();
				cout << "Arbol vaciado corectamente" << endl << endl;
				system("pause");
			}	break;
			case 4: {
				system("cls");
				cout << "Estado del arbol: ";
				if(tree -> empty()) 
					cout << "vacio" << endl << endl;
				else
					cout << "no vacio" << endl << endl;
				system("pause");
			}	break;
			case 5: {
				system("cls");
				T tag;
				cout << "Etiqueta: "; cin >> tag;
				tree -> setRoot(tag);
				cout << "Nodo raiz establecido correctamente" << endl << endl;
				system("pause");
			}	break;
			case 6: {
				system("cls");
				T fatherTag;
				cout << "Nodo padre: "; cin >> fatherTag;
				if(tree -> exist(fatherTag)) {
					T sonTag;
					cout << "Nodo hijo: "; cin >> sonTag;
					tree -> addSon(tree -> search(tree -> getRoot(),fatherTag), sonTag);
					cout << "Hijo agregado correctamente" << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 7: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				if(tree -> exist(tag)) {
					tree -> deleteLeaf(tree -> search(tree -> getRoot(),tag));
					cout << "Hoja borrada correctamente" << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 8: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				if(tree -> exist(tag)) {
					T newTag;
					cout << "Nueva etiqueta: "; cin >> newTag;
					tree -> modifyTag(tree -> search(tree -> getRoot(), tag), newTag);
					cout << "Nodo modificado correctamente" << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 9: {
				system("cls");
				if(!tree -> empty() && tree -> getRoot())
					cout << "Raiz: " << tree -> tag(tree -> getRoot()) << endl << endl;
				else
					cout << "Raiz: nullptr" << endl << endl;
				system("pause");
			}	break;
			case 10: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				if(tree -> exist(tag)) {
					if(tree -> father(tree -> search(tree -> getRoot(),tag)) && tree -> father(tree -> search(tree -> getRoot(),tag)) != tree -> search(tree -> getRoot(),tag))
						cout << "Padre: " << tree -> tag(tree -> father(tree -> search(tree -> getRoot(),tag))) << endl << endl;
					else
						cout << "Padre: nullptr" << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 11: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				if(tree -> exist(tag)) {
					if(tree -> leftmostSon(tree -> search(tree -> getRoot(),tag)))
						cout << "Hijo mas izquierdo: " << tree -> tag(tree -> leftmostSon(tree -> search(tree -> getRoot(), tag))) << endl << endl;
					else
						cout << "Hijo mas izquierdo: nullptr" << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 12: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				if(tree -> exist(tag)) {
					if(tree -> rightBrother(tree -> search(tree -> getRoot(),tag)))
						cout << "Hermano derecho: " << tree -> tag(tree -> rightBrother(tree -> search(tree -> getRoot(), tag))) << endl << endl;
					else
						cout << "Hermano derecho: nullptr" << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 13: {
				system("cls");
				T tag;
				cout << "Etiqueta: "; cin >> tag;
				if(tree -> exist(tag)) {
					cout << "Resultado: " << tree -> tag(tree -> search(tree -> getRoot(),tag)) << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 14: {
				system("cls");
				cout << "Numero de nodos: " << tree -> numNodes() << endl << endl;
				system("pause");
			}	break;
			case 15: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				if(tree -> exist(tag)) {
					cout << "Numero de hijos: " << tree -> numSons(tree -> search(tree -> getRoot(),tag)) << endl << endl;
				}
				else {
					cout << "Error: el nodo no existe" << endl << endl;
				}
				system("pause");
			}	break;
			case 16: {
				system("cls");
				system("pause");
			}	break;
			case 17: {
				enabled = false;
			}	break;
		}
	}
}

/*
	EFECTO: maneja el uso de los métodos de la clase Tree
	REQUIERE: no tiene requerimientos
	MODIFICACIONES: varias modificaciones en el árbol de acuerdo a las opciones elegidas
*/
template < typename T >
void Menus< T > :: genericTreeMethodsMenu() {
	bool enabled = true;
	int option = 0;
	Tree< T > *tree;
	while(enabled) {
		system("cls");
		cout << "M E N U  D E  O P C I O N E S  D E  M E T O D O S  G E N E R I C O S " << endl << endl;
		cout << "1. Buscar hermano izquierdo" << endl;
		cout << "2. Etiquetas repetidas" << endl;
		cout << "3. Altura de un nodo" << endl;
		cout << "4. Profundidad de un nodo" << endl;
		cout << "5. Cantidad de niveles usando recorrido Pre-Orden" << endl;
		cout << "6. Cantidad de niveles usando recorrido por niveles" << endl;
		cout << "7. Listar etiquetas del iesimo nivel" << endl;
		cout << "8. Listar etiquetas en Pre-Orden usando recursividad del compilador" << endl;
		cout << "9. Listar etiquetas en Pre-Orden usando recursividad simulada con Pila" << endl;
		cout << "10. Listar etiquetas por niveles" << endl;
		cout << "11. Buscar una etiqueta" << endl;
		cout << "12. Salir" << endl << endl;
		cout << "Opcion: "; cin >> option;
		switch(option) {
			case 1: {
				system("cls");
				
				system("pause");
			}	break;
			case 2: {
				system("cls");
				
				system("pause");
			}	break;
			case 3: {
				system("cls");
				
				system("pause");
			}	break;
			case 4: {
				system("cls");
				
				system("pause");
			}	break;
			case 5: {
				system("cls");
				
				system("pause");
			}	break;
			case 6: {
				system("cls");
				
				system("pause");
			}	break;
			case 7: {
				system("cls");
				
				system("pause");
			}	break;
			case 8: {
				system("cls");
				
				system("pause");
			}	break;
			case 9: {
				system("cls");
				
				system("pause");
			}	break;
			case 10: {
				system("cls");
				
				system("pause");
			}	break;
			case 11: {
				system("cls");
				
				system("pause");
			}	break;
			case 12: enabled = false; break;
		}
	}
}

#endif //MENUS_H