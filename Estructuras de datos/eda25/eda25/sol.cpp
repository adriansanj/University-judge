//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;

void resuelveCaso(vector<bool> const& primos) {
	bintree<int> arbol = leerArbol(-1);
	
	bool encontrado = false;
	int multsiete, prof;
	if (!arbol.empty() && !primos[arbol.root()]) {

		queue<bintree<int>> q;
		int nivelactual = 1, nodosact = 1, nodossig = 0;
		q.push(arbol);
		while (!encontrado && !q.empty()) {
			bintree<int> a = q.front();
			q.pop();
			nodosact--;
			if (a.root() % 7 == 0) {
				encontrado = true;
				multsiete = a.root();
				prof = nivelactual;
			}
			else {
				bintree<int> iz = a.left();
				if (!iz.empty() && !primos[iz.root()]) {
					q.push(iz);
					nodossig++;
				}

				bintree<int> dr = a.right();
				if (!dr.empty() && !primos[dr.root()]) {
					q.push(dr);
					nodossig++;
				}
				if (nodosact == 0) {
					nivelactual++;
					nodosact = nodossig;
					nodossig = 0;
				}
			}
		}
	}
	if (encontrado) {
		cout << multsiete << ' ' << prof;
	}
	else {
		cout << "NO HAY";
	}
	cout << '\n';
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	vector<bool> primos(5000);
	int aux = 2;
	bool primo = true;
	
	for (int i = 2; i < 5000; i++) {
		while (aux <= i / 2 && primo) {
			if (i%aux == 0) {
				primo = false;
			}
			aux++;
		}
		if (primo) {
			primos[i] = true;
		}
		primo = true;
		aux = 2;
	}

	int numCasos;
	cin >> numCasos;
	while (numCasos > 0) {
		resuelveCaso(primos);
		numCasos--;
	};

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}