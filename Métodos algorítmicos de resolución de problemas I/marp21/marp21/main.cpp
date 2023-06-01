// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "GrafoValorado.h"
#include <queue>

using namespace std;

bool bfs(GrafoValorado<int> const& g, vector<bool> & visitados, int const& actual, int const& fin, int const& ancho) {
	queue<int> cola;
	cola.push(actual);
	bool encontrado = false;
	while (!cola.empty()) {
		int v = cola.front();
		cola.pop();
		visitados[v] = true;
		if (v == fin) {
			encontrado = true;
		}
		if (!encontrado) {
			for (auto arista : g.ady(v)) {
				if (!(arista.valor() < ancho)) {
					int w = arista.otro(v);
					if (!visitados[w]) {
						cola.push(w);
					}
				}
			}
		}
	}
	return encontrado;
}

int resolver(GrafoValorado<int> g, int origen, int fin, int ancho) {
	vector<bool> visitados(g.V());
	bool encontrado;
	if (!(origen == fin)) {
		encontrado = bfs(g, visitados, origen, fin, ancho);
	}
	else {
		encontrado = true;
	}
	return encontrado;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int v,a, consultas, aux1, aux2,aux3, origen, fin, ancho;
	vector<int> resultado;
	cin >> v;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> a;
	GrafoValorado<int> g = GrafoValorado<int>(v);
	for (int i = 0; i < a; i++) {
		cin >> aux1 >> aux2 >> aux3;
		g.ponArista({ aux1 - 1, aux2 - 1, aux3 });
	}
	cin >> consultas;
	for (int i = 0; i < consultas; i++) {
		cin >> origen >> fin >> ancho;
		if (resolver(g, origen - 1, fin - 1, ancho))
		{
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}