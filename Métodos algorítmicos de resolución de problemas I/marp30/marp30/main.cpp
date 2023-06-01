// Grupo DG34 Adrián Sanjuán

#include <iostream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

int resolver(PriorityQueue<long long int> & alt, PriorityQueue<long long int> esq) {
	int cont = 0;
	while (!esq.empty()) {
		cont += abs(alt.top() - esq.top());
		alt.pop();
		esq.pop();
	}

	return cont;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, aux;
	cin >> n;
	if (n==0) // fin de la entrada
		return false;
	PriorityQueue<long long int> alt, esq;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		alt.push(aux);
	}
	for (int i = 0; i < n; i++) {
		cin >> aux;
		esq.push(aux);
	}
	cout << resolver(alt, esq) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}