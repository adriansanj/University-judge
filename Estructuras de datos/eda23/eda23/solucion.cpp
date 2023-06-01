//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;

int rescates(bintree<int> arbol, int& maxi) {
	int r1,r2;
	int max1=0, max2=0;
	if (arbol.empty()) {
		return 0;
	}
	else {
		r1 = rescates(arbol.left(), max1);
		r2 = rescates(arbol.right(), max2);
		maxi = max(max1, max2);
		if (arbol.root() != 0) {
			maxi += arbol.root();
			if ((r1 + r2) == 0) {
				return 1;
			}
		}
		return r1 + r2;
	}
}


void resuelveCaso() {
	int vacio = -1, maxi = 0;
	bintree<int> arbol = leerArbol<int>(vacio);
	cout << rescates(arbol, maxi);
	cout << ' '<<maxi << '\n';

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