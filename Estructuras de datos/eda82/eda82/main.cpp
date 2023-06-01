//Adrián Sanjuán D29

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

int navegables(bintree<int> arbol, int &nav,int nivel) {
	int caudal=0;
	if (arbol.empty()) {
		return 0;
	}
	else if (arbol.right().empty() && arbol.left().empty()) {
		return 1;
	}
	else {
		caudal = navegables(arbol.left(), nav,nivel+1)+ navegables(arbol.right(), nav,nivel+1) - arbol.root();
		if (caudal < 0) {
			caudal = 0;
		}
		if (nivel > 1 && caudal >= 3) {
			nav++;
		}
	}
	return caudal;


}



void resuelveCaso() {
	int vacio = -1;
	int nav = 0;
	bintree<int> arbol = leerArbol<int>(vacio);
	navegables(arbol, nav,1);
	cout << nav << '\n';
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