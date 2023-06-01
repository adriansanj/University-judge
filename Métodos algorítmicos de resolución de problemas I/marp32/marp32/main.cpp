// Grupo DG34 Adrián Sanjuán

#include <iostream>
#include <vector>
#include<algorithm>
#include"PriorityQueue.h"
using namespace std;


bool resolver(PriorityQueue<pair<long long int, long long int>> inv, int &cont, int ini, int fin) {
	cont =0;
	bool posible = true, cubierto = false;
	pair<long long int, long long int> candidato = { ini,ini};
	pair<long long int, long long int> anterior = { ini,ini};
	bool encontrado = false;
	while (!inv.empty() && !encontrado) {
		auto actual = inv.top();
		inv.pop();
		if (actual.first <= anterior.first && actual.second >= candidato.second) {
			candidato = actual;
		}
		if (candidato != anterior && inv.top().first > anterior.first) {
			anterior = candidato;
			encontrado = true;
			cont++;
		}
	}
	while (!inv.empty() && posible && !cubierto && encontrado) {
		auto actual = inv.top();
		inv.pop();
		if (actual.first == candidato.first) {
			candidato = actual;
		}
		else {
			if (actual.first <= candidato.second && actual.second >= candidato) {
				anterior = candidato;
					cont++;
					if (actual.first <= anterior.second) {
						if (actual.second > anterior.second) {
							candidato = actual;
								if (inv.empty()) {
									anterior = candidato;
										cont++;
								}
						}
					}}
			else {
				posible = false;
			}
		}
		if (anterior.second >= fin) {
			cubierto = true;
		}
	}

	if (!encontrado || anterior.second< fin) {
		posible = false;
	}
	return posible;
}





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int n, aux, aux2;
	int ini, fin;
	int cont = 0;
	cin >> ini;
	cin >> fin;
	cin >> n;
	if (n == 0 && fin == 0 && ini == 0) // fin de la entrada
		return false;
	PriorityQueue<pair<long long int, long long int>, std::less<pair<long long int, long long int>>> inv;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		cin >> aux2;
		inv.push({ aux ,aux2 });
	}
	if (resolver(inv, cont, ini, fin )) {
		cout << cont << '\n';
	}
	else {
		cout << "Imposible\n";
	}
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}