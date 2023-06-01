// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "DigrafoValorado.h"
#include "PriorityQueue.h"
#include "IndexPQ.h"


using namespace std;

bool Dijkstra(DigrafoValorado<int> const& d, int & coste) {
	IndexPQ<int> cola(d.V());
	vector<int> distancia(d.V(), 1000000);
	vector<bool> arbol_cam_min(d.V(), false);
	cola.push(0, 0);
	distancia[0] = coste;
	while (!cola.empty() && !arbol_cam_min[d.V()-1]) {
		int v = cola.top().elem;
		cola.pop();
		arbol_cam_min[v] = true;
		for (auto a : d.ady(v)) {
			int w = a.hasta();
			if (distancia[w] > distancia[v] + a.valor()) {
				distancia[w] = distancia[v] + a.valor();
				cola.update(w, distancia[w]);
			}
		}

	}
	coste = distancia[d.V() - 1];
	return arbol_cam_min[d.V() - 1];
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int v, a, aux1, aux2, aux3, coste = 0;
	
	cin >> v;
	if (v==0) // fin de la entrada
		return false;

	vector<int> t_carga(v);
	for (int i = 0; i < v; i++) {
		cin >> t_carga[i];
	}
	cin >> a;
	DigrafoValorado<int> d = DigrafoValorado<int>(v);
	for (int i = 0; i < a; i++) {
		cin >> aux1 >> aux2 >> aux3;
		d.ponArista({ aux1 - 1, aux2 - 1, aux3+t_carga[aux2-1]});
	}
	coste += t_carga[0];
	if (Dijkstra(d, coste))
	{
		cout << coste << "\n";
	}
	else {
		cout << "IMPOSIBLE\n";
	}

	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}