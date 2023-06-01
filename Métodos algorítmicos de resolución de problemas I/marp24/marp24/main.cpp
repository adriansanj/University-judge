// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "GrafoValorado.h"
#include "IndexPQ.h"


using namespace std;

int Dijkstra(GrafoValorado<int> const& g) {
	IndexPQ<int> cola(g.V());
	vector<int> distancia(g.V(), -1);
	vector<int> cam_min_hasta(g.V() - 1, 0);
	vector<Arista<int>> ultima(g.V());
	int cont = 0;
	cola.push(0, 0);
	distancia[0] = 0;
	while (!cola.empty()) {
		int v = cola.top().elem;
		cola.pop();
		for (auto a : g.ady(v)) {
			int w = a.otro(v);
			int dist = distancia[v] + a.valor();
			if (distancia[w]!=-1 && distancia[w] > dist) {
				cam_min_hasta[w] = 0;
			}
			else if (distancia[w] == dist) {
				cam_min_hasta[w]++;
			}

			if (distancia[w]==-1 || (distancia[w]!=-1 && distancia[w] > dist)) {
				distancia[w] = distancia[v] + a.valor();
				cola.update(w, distancia[w]);
			}
		}

	}
	return cont;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int v, a, aux1, aux2, aux3;
	cin >> v;
	if (!cin) // fin de la entrada
		return false;
	cin >> a;
	GrafoValorado<int> g = GrafoValorado<int>(v);
	for (int i = 0; i < a; i++) {
		cin >> aux1 >> aux2 >> aux3;
		g.ponArista({ aux1 - 1, aux2 - 1, aux3});
	}
	cout << Dijkstra(g) << '\n';

	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}