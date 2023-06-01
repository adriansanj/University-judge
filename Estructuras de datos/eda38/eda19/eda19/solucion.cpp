//Adrián Sanjuán

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


void resuelveCaso() {
	char vacio = '.';
	bintree<char> arbol = leerArbol<char>(vacio);
	/*if (arbol.empty()) {
		cout << "0 0 0\n";
	}
	else {*/
		cout << arbol.numNodos() << ' ' << arbol.numHojas() << ' ' << arbol.altura() << '\n';
	//}
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