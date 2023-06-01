//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

bool genealogico(bintree<int> arbol, int nivel, int & gen) {
	bool izq, dch, act = true;
	
	if (arbol.empty()) {
		return true;
	}
	if (nivel > gen) {
		gen = nivel;
	}
	
	izq = genealogico(arbol.left(),nivel+1, gen);
	dch = genealogico(arbol.right(),nivel+1 ,gen);

	if (!arbol.left().empty()) {
		act = arbol.left().root() + 18 <= arbol.root();
		if (!arbol.right().empty()) {
			act = act && arbol.left().root() - 2 >= arbol.right().root();
		}
	}
	else {
		if (!arbol.right().empty()) {
			return false;
		}
	}
	return izq && dch && act;
	
}



void resuelveCaso() {
	int vacio = -1;
	int gen=0;
	bool es;
	bintree<int> arbol = leerArbol<int>(vacio);
	if (genealogico(arbol, 1, gen)) {
		cout << "SI " << gen << '\n';
	}
	else {
		cout << "NO\n";
	}
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