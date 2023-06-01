// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "Grafo.h"
#include <queue>

using namespace std;

int bfs(Grafo const& g, vector<bool> & visitados, int const& actual, int const& tll) {
	queue<int> cola;
	int cont = 1;
	vector<int> distancia(g.V(), -1);
	cola.push(actual);
	distancia[actual] = 0;
	while (!cola.empty()) {
		int v = cola.front();
	
		cola.pop();
		for (int w : g.ady(v)) {
			if (distancia[w] == -1) {
				distancia[w] = distancia[v] + 1;
				if (distancia[w] <= tll) {
					cont++;
					if (distancia[w] < tll) {
						cola.push(w);
					}
				}
				
				
			}
		}
	}
	return cont;
}

int resolver(Grafo g, int v, int origen, int tll) {
	vector<bool> visitados(v);
	int result = 0;
	if (v > 0) {
		result = v- bfs(g,visitados,origen,tll);
	}
	return result;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, c,consultas, aux1, aux2, origen, tll;
	vector<int> resultado;
	cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> c;
	Grafo g = Grafo(n);
	for (int i = 0; i < c; i++) {
		cin >> aux1 >> aux2;
		g.ponArista(aux1 - 1, aux2 - 1);
	}
	cin >> consultas;
	for (int i = 0; i < consultas; i++) {
		cin >> origen >> tll;
		cout << resolver(g, n, origen-1,tll) << '\n';
	}
	cout << "---\n";
	
	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}