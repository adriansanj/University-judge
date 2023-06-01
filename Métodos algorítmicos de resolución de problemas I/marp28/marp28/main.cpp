// Grupo DG34 Adrián Sanjuán

#include <iostream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

int resolver(PriorityQueue<long long int, greater<int>> ata, PriorityQueue<long long int, greater<int>> def) {
	int cont = 0;
	while (!ata.empty()) {
		if (ata.top() <= def.top()) {
			cont++;
			ata.pop();
			def.pop();
		}
		else {
			ata.pop();
		}
		
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
	if (!std::cin) // fin de la entrada
		return false;
	PriorityQueue<long long int, greater<int>> ata, def;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		ata.push(aux);
	}
	for (int i = 0; i < n; i++) {
		cin >> aux;
		def.push(aux);
	}
	cout << resolver(ata,def) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}