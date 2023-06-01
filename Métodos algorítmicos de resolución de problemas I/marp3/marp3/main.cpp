// DG34 Adrián Sanjuán Espejo

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

long long int resolver(PriorityQueue<long long int> q) {
	long long int esfuerzo=0,suma;

	while (!q.empty()) {
		suma = q.top();
		q.pop();
		if (!q.empty()) {
			suma += q.top();
			q.pop();
			q.push(suma);
			esfuerzo += suma;
			suma = 0;
		}
	}
	return esfuerzo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int n,aux;
	PriorityQueue<long long int> q;
	cin >> n;
	if (n == 0) {
		return false;
	}
	for (long long int i = 0; i < n; i++) {
		cin >> aux;
		q.push(aux);
	}
	long long int sol = resolver(q);
	cout << sol << "\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}