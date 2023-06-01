// Adrián Sanjuán DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "stack_eda.h"
using namespace std;

#include "fecha.h"

typedef struct {
	fecha f;
	int victimas;
}accidente;

bool resuelveCaso() {
	int N;
	accidente aux;
	stack<accidente> pila;
	cin >> N;
	
	if (!cin) {
		return false;
	}

	for (int i = 0; i < N; i++) {
		cin >> aux.f >> aux.victimas;
		while (!pila.empty() && pila.top().victimas <= aux.victimas){
			pila.pop();
		}
		if (pila.empty()) {
			cout << "NO HAY\n";
		}
		else {
			cout << pila.top().f << "\n";
		}
		pila.push(aux);
	}
	cout << "---\n";
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
