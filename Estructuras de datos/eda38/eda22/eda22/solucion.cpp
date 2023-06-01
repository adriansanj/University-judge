//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;

int diametro(bintree<char> arbol, int & camino) {
	int cleft=0, cright=0;
	if (arbol.empty()) {
		return 0;
	}
	else {
		int diamhijos = max(diametro(arbol.right(), cright), diametro(arbol.left(), cleft));
		
		if (arbol.root() == '*') {
			camino=max(cleft,cright)+1;
		}
		return max(cleft + 1 + cright, diamhijos);
	}

}


void resuelveCaso() {
	char vacio = '.';
	int c= 0;
	bintree<char> arbol = leerArbol<char>(vacio);
	cout << diametro(arbol,c) << '\n';

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