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
int resolver(Grafo g, int v) {
	vector<bool> visitados(v);
	bool resultado = true;
	int cont, maxcont = 0;
	for (int i = 0; i < v; i++) {
		if (!visitados[i]){
			cont = 0;
			rec(g, visitados, i, cont);
			maxcont = max(cont, maxcont);
		}
	}
	


	return maxcont;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int m, n, aux1, aux2;
	cin >> n;
	cin >> m;
	Grafo g = Grafo(n);
	for (int i = 0; i < m; i++) {
		cin >> aux1 >> aux2;
		g.ponArista(aux1-1, aux2-1);
	}
	
	cout << resolver(g, n) << '\n';

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}