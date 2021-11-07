#ifndef MENUS_H
#define MENUS_H
//#include "../Tree/TreeA.h"
//#include "../Tree/TreeB.h"
//#include "../Tree/TreeC.h"
//#include "../Tree/TreeD.h"
#include "../Tree/TreeE.h"
#include "../Tree/GenericTreeMethods.h"
using namespace std;

template <class T>
class Menus {
	Tree< T > *tree;
	GenericTreeMethods< T > *genericTreeMethods;
    public:
		void treeMenu();
};

/*
	EFECTO: maneja el uso de los métodos genericos para arboles Tree
	REQUIERE: arbol creado
	MODIFICACIONES: varias modificaciones en el árbol de acuerdo a las opciones elegidas
*/
template < typename T >
void Menus< T > :: treeMenu() {
	bool enabled = true;
	int option = 0;
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
		cout << "15. Numero de hijos?" << endl << endl;

		cout << "O P C I O N E S  E T A P A  # 3 " << endl << endl;
		cout << "16. Buscar hermano izquierdo" << endl;
		cout << "17. Etiquetas repetidas" << endl;
		cout << "18. Altura de un nodo" << endl;
		cout << "19. Profundidad de un nodo" << endl;
		cout << "20. Cantidad de niveles usando recorrido Pre-Orden" << endl;
		cout << "21. Cantidad de niveles usando recorrido por niveles" << endl;
		cout << "22. Listar etiquetas del iesimo nivel" << endl;
		cout << "23. Listar etiquetas en Pre-Orden usando recursividad del compilador" << endl;
		cout << "24. Listar etiquetas en Pre-Orden usando recursividad simulada con Pila" << endl;
		cout << "25. Listar etiquetas por niveles" << endl;
		cout << "26. Buscar una etiqueta" << endl;
		cout << "27. Salir" << endl << endl;
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
				Node< T > *root = tree -> getRoot();
				Node< T > *father = genericTreeMethods -> searchTag(root, fatherTag);
				if(father) {
					T sonTag;
					cout << "Nodo hijo: "; cin >> sonTag;
					tree -> addSon(father, sonTag);
					cout << "Hijo agregado correctamente" << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 7: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *toDelete = genericTreeMethods -> searchTag(root, tag);
				if(toDelete) {
					tree -> deleteLeaf(toDelete);
					cout << "Hoja borrada correctamente" << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 8: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *toModify = genericTreeMethods -> searchTag(root, tag);
				if(toModify) {
					T newTag;
					cout << "Nueva etiqueta: "; cin >> newTag;
					tree -> modifyTag(toModify, newTag);
					cout << "Nodo modificado correctamente" << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 9: {
				system("cls");
				Node< T > *root = tree -> getRoot();
				if(!tree -> empty() && root)
					cout << "Raiz: " << tree -> tag(root) << endl << endl;
				else
					cout << "Raiz: nullptr" << endl << endl;
				system("pause");
			}	break;
			case 10: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *son = genericTreeMethods -> searchTag(root, tag);
				if(son) {
					Node< T > *father = tree -> father(son);
					if(father && father != son)
						cout << "Padre: " << tree -> tag(father) << endl << endl;
					else
						cout << "Padre: nullptr" << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 11: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *father = genericTreeMethods -> searchTag(root, tag);
				if(father) {
					Node< T > *leftmostSon = tree -> leftmostSon(father);
					if(leftmostSon)
						cout << "Hijo mas izquierdo: " << tree -> tag(leftmostSon) << endl << endl;
					else
						cout << "Hijo mas izquierdo: nullptr" << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 12: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *actual = genericTreeMethods -> searchTag(root, tag);
				if(actual) {
					Node< T > *rightBrother = tree -> rightBrother(actual);
					if(rightBrother)
						cout << "Hermano derecho: " << tree -> tag(rightBrother) << endl << endl;
					else
						cout << "Hermano derecho: nullptr" << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 13: {
				system("cls");
				T tag;
				cout << "Etiqueta: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *actual = genericTreeMethods -> searchTag(root, tag);
				if(actual) 
					cout << "Resultado: " << tree -> tag(actual) << endl << endl;
				else 
					cout << "Error: el nodo no existe" << endl << endl;
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
				Node< T > *root = tree -> getRoot();
				Node< T > *actual = genericTreeMethods -> searchTag(root, tag);
				if(actual) 
					cout << "Numero de hijos: " << tree -> numSons(actual) << endl << endl;
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 16: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *node = genericTreeMethods -> searchTag(root, tag);
				if(node) {
					Node< T > *leftBrother = genericTreeMethods -> getLeftBrother(node); 
					if(leftBrother)
						cout << "Hermano izquierdo: " << tree -> tag(leftBrother) << endl << endl;
					else
						cout << "Hermano izquierdo: nullptr" << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 17: {
				system("cls");
				cout << "Hay etiquetas repetidas?: ";
				if(!tree -> empty()) {
					bool result = genericTreeMethods -> repeatedTags();
					if(result)
						cout << "Si" << endl << endl;
					else
						cout << "No" << endl << endl;
				}
				else 
					cout << "No" << endl << endl;
				system("pause");
			}	break;
			case 19: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *node = genericTreeMethods -> searchTag(root, tag);
				if(node) {
					int nodeDepth = genericTreeMethods -> nodeDepth(node);
					cout << "Profundidad: " << nodeDepth << endl << endl;
				}
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 23: {
				system("cls");
				if(!tree -> empty())  {
					cout << "Arbol: ";
					Node< T > *root = tree -> getRoot();
					genericTreeMethods -> printInPreOrder(root);
					cout << endl << endl;
				} 
				else
					cout << "Error: el arbol esta vacio" << endl << endl;
				system("pause");
			}	break;
			case 25: {
				system("cls");
				if(!tree -> empty())  {
					cout << "Arbol: ";
					Node< T > *root = tree -> getRoot();
					genericTreeMethods -> printAllLevels();
					cout << endl << endl;
				} 
				else
					cout << "Error: el arbol esta vacio" << endl << endl;
				system("pause");
			}	break;
			case 26: {
				system("cls");
				T tag;
				cout << "Nodo: "; cin >> tag;
				Node< T > *root = tree -> getRoot();
				Node< T > *result = genericTreeMethods -> searchTag(root, tag); 
				if(result) 
					cout << "Etiqueta: " << tree -> tag(result) << endl << endl;
				else 
					cout << "Error: el nodo no existe" << endl << endl;
				system("pause");
			}	break;
			case 27: {
				enabled = false;
			}	break;
		}
	}
}

#endif //MENUS_H