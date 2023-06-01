// DG34 Adrián Sanjuán
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "Digrafo.h"

using namespace std;

bool resolver(Digrafo d, int v, int&s) {
	/*vector<bool> candidato(v,false);
	vector<int> entrantes(v,0);*/
	bool resp = false;
	/*for (int i = 0; i < v; i++) {
		if (d.ady(i).empty()) {
			candidato[i] = true;
		}
		else {
			for (int w : d.ady(i)) {
				entrantes[w]++;
			}
		}
		
	}
	int i = 0;
	while (!resp && i < v) {
		if (candidato[i] && entrantes[i] == v - 1) {
			resp = true;
			s = i;
		}
		i++;
	}*/
	int i = 0;
	while (!resp && i < v) {
		if (d.ady(i).size() == 0 && d.inverso().ady(i).size() == v - 1) {
			resp = true;
			s = i;
		}
		i++;
	}
	
	return resp;

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int v, a, s, aux1, aux2;
	vector<int> resultado;
	cin >> v;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> a;
	Digrafo d = Digrafo(v);
	for (int i = 0; i < a; i++) {
		cin >> aux1 >> aux2;
		d.ponArista(aux1, aux2);
	}
	if (resolver(d, v, s)) {
		cout << "SI " << s << '\n';
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