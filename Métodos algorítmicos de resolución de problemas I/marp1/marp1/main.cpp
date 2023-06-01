// DG 34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>

#include "bintree_eda.h" 

using namespace std;
typedef struct {
	bool avl;
	int min, max;
}AVL;
AVL esAVL(bintree<int> arbol, int& altura) {
	AVL i, d, r;
	int ai, ad;
	if (arbol.empty()) {
		altura = 0;
		r.avl = true;
		return r;
	}
	else {
		i = esAVL(arbol.left(),ai);
		d = esAVL(arbol.right(), ad);
		altura = max(ai, ad)+1;
		if (!arbol.left().empty()) {
			r.min = i.min;
		}
		else {
			r.min = arbol.root();
		}

		if (!arbol.right().empty()) {

			r.max = d.max;
		}
		else {

			r.max = arbol.root();

		}
		r.avl = (i.avl && d.avl && (abs(ai - ad) <= 1) && ((arbol.left().empty() || arbol.root() > i.max) && (arbol.right().empty() || arbol.root() < d.min)));
		return r;
		
	}
}


void resuelveCaso() {
	int vacio = -1;
	int altura = 0;
	bintree<int> arbol = leerArbol<int>(vacio);
	AVL sol = esAVL(arbol,altura);
	if (sol.avl) {
		cout << "SI\n";
	}
	else
	{
		cout << "NO\n";
	}
	
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}