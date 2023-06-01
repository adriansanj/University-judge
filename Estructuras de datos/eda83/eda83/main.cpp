//Adrián Sanjuán D29

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


int subcompleto(bintree<char> arbol, int & m) {
	int altura = 0;
	if (!arbol.empty()) {
		if (arbol.left().empty() || arbol.right().empty()) {
			altura = 1;
			subcompleto(arbol.left(),m);
			subcompleto(arbol.right(),m);

		}
		else {
			altura = min(subcompleto(arbol.right(), m), subcompleto(arbol.left(), m)) + 1;
		}
		
		
	}
	m = max(altura, m);
	return altura;

}



void resuelveCaso() {
	char vacio = '.';
	int max = 0;
	bintree<char> arbol = leerArbol<char>(vacio);
	subcompleto(arbol,max);
	cout << max << '\n';
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