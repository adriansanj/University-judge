//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;


bool resuelveCaso() {
	char tipo;
	cin >> tipo;
	if (!cin) {
		return false;
	}
	if (tipo == 'N') {
		int vacio = -1;
		bintree<int> arbol = leerArbol<int>(vacio);
		cout << arbol.minimo() << '\n';
	}
	else if (tipo == 'P') {
		string vacio = "#";
		bintree<string> arbol = leerArbol<string>(vacio);
		cout << arbol.minimo() << '\n';
	}
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}