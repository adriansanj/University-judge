//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

typedef struct {
	bool busqueda;
	int min, max;
}abb;
abb esDeBusqueda(bintree<int> const& arbol) {
	abb sol, soliz, soldr;

	if (arbol.empty()) {
		sol.busqueda = true;
		return sol;
	}
	else {
		soliz = esDeBusqueda(arbol.left());
		soldr = esDeBusqueda(arbol.right());
		if (!arbol.left().empty()) {
			sol.min = soliz.min;
		}
		else {
			sol.min = arbol.root();
		}

		if (!arbol.right().empty()) {

			sol.max = soldr.max;
		}else{

			sol.max = arbol.root();
		
		}
		

		sol.busqueda = soliz.busqueda&& soldr.busqueda && ((arbol.left().empty() || arbol.root() > soliz.max) && (arbol.right().empty() ||arbol.root() < soldr.min));
		return sol;
	}
}

void resuelveCaso() {
	int vacio = -1;
	bintree<int> arbol = leerArbol<int>(vacio);
	if (esDeBusqueda(arbol).busqueda) {
		cout << "SI";
	}
	else {
		cout << "NO";
	}
	cout << '\n';
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}