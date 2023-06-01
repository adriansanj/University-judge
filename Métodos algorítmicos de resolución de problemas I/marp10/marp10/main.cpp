// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "Grafo.h"

using namespace std;

bool rec(Grafo const& g, vector<bool> & visitados, int const& actual, int const& anterior, int & cont){
	for (int w : g.ady(actual)) {
		if (visitados[w] && (w != anterior)){
			return false;
		}
		else if (!visitados[w]){
			visitados[w]=true;
			cont++;
			if (!rec(g, visitados, w, actual, cont)) {
				return false;
			}
		}
	}
	return true;
}
bool resolver(Grafo g, int v) {
	vector<bool> visitados(v);
	bool resultado = true;
	visitados[0] = true;
	int cont = 1;
	resultado = rec(g, visitados, 0, 0, cont);
	resultado = resultado && (cont == v);
	

	return resultado;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int a, v, aux1,aux2;
	cin >> v;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> a;
	Grafo g = Grafo(v);
	for (int i = 0; i < a; i++) {
		cin >> aux1 >> aux2;
		g.ponArista(aux1, aux2);
	}
	if (resolver(g,v)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}