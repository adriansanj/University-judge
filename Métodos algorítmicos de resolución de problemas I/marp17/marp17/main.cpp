// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "Digrafo.h"
#include <deque>
using namespace std;

void dfs(Digrafo const& d, vector<bool> & visitados, vector<bool> & apilados, deque<int> & solucion, int const& actual, bool & posible) {
	visitados[actual] = true;
	apilados[actual] = true;
	if (posible) {
		for (int w : d.ady(actual)) {
			if (!visitados[w]) {
				dfs(d, visitados, apilados, solucion, w, posible);
			}
			else if (apilados[w]) {
				posible = false;
			}
		}
		apilados[actual] = false;
		solucion.push_front(actual);
	}
}
bool resolver(Digrafo d, int v, deque<int> & solucion) {
	vector<bool> visitados(v,false);
	vector<bool> apilados(v);
	bool posible = true;
	for (int i = 0; i < v; i++) {
		if (!visitados[i] && posible) {
			dfs(d, visitados, apilados, solucion, i,posible);
		}
	}
	return posible;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int v, a, grupo, aux1, aux2;
	deque<int> resultado;
	cin >> v;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> a;
	Digrafo d = Digrafo(v);
	for (int i = 0; i < a; i++) {
		cin >> aux1 >> aux2;
		d.ponArista(aux1 - 1, aux2 - 1);
	}
	if (resolver(d, v, resultado)) {
		while(!resultado.empty()) {
			cout << resultado.front()+1 << ' ';
			resultado.pop_front();
		}
	}
	else {
		cout << "Imposible";
	}
	cout << '\n';
	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}