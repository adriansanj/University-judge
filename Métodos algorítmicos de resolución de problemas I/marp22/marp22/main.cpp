// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

bool ARM_Kruskal(GrafoValorado<int> const& g, int & coste) {
	vector<Arista<int>> _ARM;
	PriorityQueue<Arista<int>> cola(g.aristas());
	ConjuntosDisjuntos cjto(g.V());
	while (!cola.empty() && _ARM.size() != g.V()-1) {
		auto a = cola.top();
		cola.pop();
		int v = a.uno();
		int w = a.otro(v);
		
		if (!cjto.unidos(v, w)) {
			cjto.unir(v, w);
			_ARM.push_back(a);
			coste += a.valor();
		}
		
	}
	return cjto.num_cjtos() == 1;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int v, a, consultas, aux1, aux2, aux3, coste= 0;
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
	if (ARM_Kruskal(g, coste))
	{
		cout << coste <<"\n";
	}
	else {
		cout << "No hay puentes suficientes\n";
	}

	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}