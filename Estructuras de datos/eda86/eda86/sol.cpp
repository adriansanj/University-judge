//Adrián Sanjuán D29

#include <iostream>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
using namespace std;


void per(bintree<int> arbol, vector<int> & perfil,int nivel, int & niveles) {
	if (!arbol.empty()) {
		if (nivel > niveles) {
			perfil.push_back(arbol.root());
			niveles++;
		}
		per(arbol.left(), perfil, nivel + 1, niveles);
		per(arbol.right(), perfil, nivel + 1, niveles);
	}
	
}



void resuelveCaso() {
	int vacio = -1;
	int niveles = 0;
	vector<int> perfil;
	bintree<int> arbol = leerArbol<int>(vacio);
	per(arbol, perfil, 1, niveles);
	for (int num : perfil) {
		cout << num << ' ';
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