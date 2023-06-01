// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "Grafo.h"

using namespace std;

void rec(Grafo const& g, vector<bool> & visitados, int const& actual, int & cont) {
	visitados[actual] = true;
	cont++;
	for (int w : g.ady(actual)) {
		if (!visitados[w]) {
			rec(g, visitados, w, cont);
		}
	}
}

vector<int> resolver(Grafo g, int v) {
	vector<bool> visitados(v);
	vector<int> alcance(v);
	for (int i = 0; i < alcance.size(); i++) {
		alcance[i] = 0;
	}
	int cont;
	for (int i = 0; i<alcance.size();i++){
		if (alcance[i] == 0) {
			for (int j = 0; j < visitados.size(); j++) {
				visitados[j] = false;
			}
			cont = 0;
			rec(g, visitados, i,cont);
			for (int l = 0; l < alcance.size(); l++) {
				if (visitados[l]) { alcance[l] = cont; }
			}
			
		}
	}
	return alcance;
	
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, m, grupo, aux1, aux2;
	vector<int> resultado;
	cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> m;
	Grafo g = Grafo(n);
	for (int i = 0; i < m; i++) {
		cin >> grupo;
		if (grupo > 0) {
			cin >> aux1;
		}
		for (int j = 0; j < grupo-1; j++) {
			cin >> aux2;
			g.ponArista(aux1-1, aux2-1);
		}
	}
	resultado = resolver(g, n);
	for (int n : resultado) {
		cout << n << ' ';
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