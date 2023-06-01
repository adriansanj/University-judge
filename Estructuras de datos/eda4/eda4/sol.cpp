// Adrián Sanjuán DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#include "polinomio.h"

bool resuelveCaso() {
	int c, e;
	vector<int> p;
	polinomio poli;
	cin >> c >> e;
	if (!cin) {
		return false;
	}
	while (c != 0 || e != 0) {
		p.push_back(c);
		p.push_back(e);
		cin >> c >> e;
	}
	poli = polinomio(p);

	int n, valor;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> valor;
		cout << poli.evaluar(valor)<< ' ';
	}
	cout << '\n';
	return true;
}
int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
