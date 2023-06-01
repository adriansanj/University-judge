// DG 34 Adrián Sanjuán

#include <iostream>
#include "PriorityQueue.h"

using namespace std;
typedef struct {
	long long int inicio;
	long long int fin;
	bool periodica;
	long long int repe;
}tTarea;
bool operator <(const tTarea &a, const tTarea &b) {
	return (a.inicio < b.inicio || (a.inicio == b.inicio && a.fin < b.fin));
}
bool resolver(PriorityQueue<tTarea> q,int t) {
	bool conflicto = false;
	tTarea aux;
	long long int t_conf=-1;
	while (!conflicto && !q.empty()) {
		aux = q.top();
		q.pop();
		if (aux.inicio < t_conf) {
			conflicto = true;
		}
		t_conf = aux.fin;
		if (aux.periodica) {
			aux.inicio+=aux.repe;
			aux.fin += aux.repe;
			if (aux.inicio < t) {
				q.push(aux);
			}
		}
		
	}
	return conflicto;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int t;
	int repe, n, m;
	tTarea aux;
	PriorityQueue<tTarea> q;
	cin >> n >> m >> t;
	if (!std::cin) // fin de la entrada
		return false;
	for (int i = 0; i < n; i++) {
		cin >> aux.inicio;
		cin >> aux.fin;
		aux.periodica = false;
		aux.repe = 0;
		if (aux.inicio < t) {
			q.push(aux);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> aux.inicio;
		cin >> aux.fin;
		cin >> aux.repe;
		aux.periodica = true;
		if (aux.inicio < t) {
			q.push(aux);
		}

	}

	if (resolver(q,t)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}