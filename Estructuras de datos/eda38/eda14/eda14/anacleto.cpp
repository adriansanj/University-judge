
// JUAN CARLOS LLAMAS NÚÑEZ Y ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue_eda.h"
#include "deque_eda.h"
#include "stack_eda.h"


using namespace std;


bool es_vocal(char c) {
	c = tolower(c);
	return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
void volcar_pila(stack<char> & pila, queue<char> & X) {
	while (!pila.empty()) {
		X.push(pila.top());
		pila.pop();
	}
}
string decodifica(string const& mensaje) {
	
	string devolver = "";
	queue<char> X;
	queue<char> cola_inicio;
	stack<char> pila_fin; 
	stack<char> pila_consonantes;
	int N = 0;
	// primera fase, reordenar según posición
	for (char c : mensaje) {
		if (N % 2 == 0) {
			cola_inicio.push(c);
		}
		else {
			pila_fin.push(c);
		}
		N++;
	}
	// segunda fase, invertir consonantes entre vocales
	for (int i = 0; i < mensaje.length(); i++) {
		if (!cola_inicio.empty()) {
			if (es_vocal(cola_inicio.front())) {
				volcar_pila(pila_consonantes, X);
				X.push(cola_inicio.front());
			}
			else {
				pila_consonantes.push(cola_inicio.front());
			}
			cola_inicio.pop();
		}
		else {
			if (es_vocal(pila_fin.top())) {
				volcar_pila(pila_consonantes, X);
				X.push(pila_fin.top());
			}
			else {
				pila_consonantes.push(pila_fin.top());
			}
			pila_fin.pop();
		}
	}
	volcar_pila(pila_consonantes, X);
	for (int i = 0; i < mensaje.length(); i++) {
		devolver += X.front();
		X.pop();
	}
	return devolver;
}
bool resuelveCaso() {
	string mensaje;
	getline(cin, mensaje);
	if (!cin) {
		return false;
	}
	mensaje = decodifica(mensaje);
	
	cout << mensaje << '\n';
	
	return true;
}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}
