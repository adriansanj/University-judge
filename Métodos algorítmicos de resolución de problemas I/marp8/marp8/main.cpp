// DG 34 Adrián Sanjuán

#include <iostream>
#include "PriorityQueue.h"

using namespace std;
bool comp (int)
void resolver(PriorityQueue<int> q,int n) {
	int aux;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		if (aux == 0) {
			if (q.empty()) {
				cout << "ECSA ";
			}
			else {
				cout << q.top() << " ";
				q.pop();
			}
		}
		else {
			q.push(aux);
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	PriorityQueue<int> q;
	cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	resolver(q,n);
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}