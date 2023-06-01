// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "Grafo.h"
#include <algorithm>

using namespace std;

void rec(Grafo const& g, vector<bool> & visitados, int const& actual, int &cont) {
	cont++;
	visitados[actual] = true;
	for (int w : g.ady(actual)) {
		if (!visitados[w]) {
			rec(g, visitados, w, cont);
		}
	}
}
/*int resolver(Grafo g, int v, int & num) {
	vector<bool> visitados(v);
	bool resultado = true;
	int cont, maxcont = 0;
	for (int i = 0; i < v; i++) {
		if (!visitados[i]) {
			cont = 0;
			rec(g, visitados, i, cont);

			maxcont = max(cont, maxcont);
		}
	}
	return maxcont;
}*/
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int f, c, aux1, aux2;
	
	char ch;
	cin >> f;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> c;
	bool matriz[1000][1000];
	Grafo g = Grafo(f*c);
	cin.get(ch);
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			cin.get(ch);
			if (ch == '#') {
				matriz[i][j] = true;
			}
			else {
				matriz[i][j] = false;
			}
		}
		cin.get(ch);
	}
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (matriz[i][j]) {
				if (j != c - 1) {
					if (matriz[i][j + 1]) {
						g.ponArista(c*i + j, c*i + j + 1);
					}
				}
				if (i!= f-1) {
					if (matriz[i+1][j]) {
						g.ponArista(c*i + j, c*(i + 1) + j);
					}
				}

			}
		}
	}

	vector<bool> visitados(f*c);
	bool resultado = true;
	int cont, maxcont = 0;
	int maxgrande, num = 0;
	for (int i = 0; i < f*c; i++) {
		if (!visitados[i] && matriz[i/c][i%c]) {
			num++;
			cont = 0;
			rec(g, visitados, i, cont);
			maxcont = max(cont, maxcont);
		}
	}
	cout << num << ' ' << maxcont << '\n';

	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}