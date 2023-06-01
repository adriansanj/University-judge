//Adrián Sanjuán D29

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;

bool sim(bintree<char> i, bintree<char> d) {
	bool son =  true,iz,dch;
	if (i.empty() && !d.empty() || d.empty() && !i.empty()) {
		return false;
	}
	else if (!i.empty() && !d.empty()) {
			/*if (!i.left().empty() && d.right().empty() || i.left().empty() && !d.right().empty() || !i.right().empty() && d.left().empty() || i.right().empty() && !d.left().empty()) {
				return false;
			}*/
			iz = sim(i.left(), d.right());
			dch = sim(d.left(), i.right());
			//return son && iz && dch;
			return iz && dch;
	}
	/*else {
		return true;
	}*/
	return true;
	


}



void resuelveCaso() {
	int vacio = '.';
	bintree<char> arbol = leerArbol<char>(vacio);
	if (arbol.empty()) {
		cout << "SI\n";
	}
	else {
		if (sim(arbol.left(),arbol.right())) {
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
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