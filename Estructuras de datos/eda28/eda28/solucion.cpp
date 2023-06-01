
//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "treemap_eda.h"
#include "ejercicios.h"

using namespace std;



bool resuelveCaso() {
	int n;
	string al, ev;
	char aux;
	cin >> n;
	if (n == 0) {
		return false;
	}
	ejercicios lista;
	for (int i = 0; i < n; i++) {
		cin.get(aux);
		getline(cin,al);
		cin >> ev;
		if (ev == "CORRECTO") {
			lista.anadir(al);
		}else{
			lista.restar(al);
		}
	}
	
	for (string al: lista.evaluados()) {
		cout << al << ", " << lista.cantidad(al) << '\n';
	}

	cout << "---\n" ;

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