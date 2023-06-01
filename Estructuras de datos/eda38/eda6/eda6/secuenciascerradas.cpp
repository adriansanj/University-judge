// JUAN CARLOS LLAMAS NÚÑEZ Y ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

#include "stack_eda.h"


using namespace std;
bool correcto(const string mensaje) {
	stack<char> pila;
	for (char c : mensaje) {
		if (c == '{' || c == '(' || c == '[') {
			pila.push(c);
		}
		else {
			switch (c)
			{
			case '}':
				if (!pila.empty() && pila.top() == '{') {
					pila.pop();
				}
				else {
					return false;
				}
				break;
			case ')':
				if (!pila.empty() && pila.top() == '(') {
					pila.pop();
				}
				else {
					return false;
				}
				break;
			case ']':
				if (!pila.empty() && pila.top() == '[') {
					pila.pop();
				}
				else {
					return false;
				}
				break;
			}
		}
	}
	if (!pila.empty()) {
		return false;
	}
	return true;
}
bool resuelveCaso() {
	
	string mensaje;
	getline(cin, mensaje);
	if (!cin) {
		return false;
	}
	if (correcto(mensaje)) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	
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
