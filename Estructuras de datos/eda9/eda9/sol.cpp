//ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue_eda.h"



using namespace std;

class InvertirQueue : public queue<int> {
	using Nodo = queue<int>::Nodo;
public:
	// imprime la lista enlazada
	void print(std::ostream& o = std::cout) const {
		Nodo* ptr = this->prim;
		while (ptr != nullptr) {
			o << ptr->elem << " ";
			ptr = ptr->sig;
		}

	}

	// introduce los elementos de other (una lista enlazada)
	// en la lista representada por this alternativamente al principio y al final

	// Coste: o(n) donde n es el tamaño de la lista other (la lista que se pasa como parámetro y se recorre)


	void invertir() {
		if (!this->empty()) {
			Nodo* nuevosig = nullptr;
			Nodo* act = this->prim;
			Nodo* siguiente = this->prim->sig;
			while (siguiente != nullptr) {
				act->sig = nuevosig;
				nuevosig = act;
				act = siguiente;
				siguiente = siguiente->sig;
			}
			act->sig = nuevosig;
			this->ult = this->prim;
			this->prim = act;

		}
	}
};
bool resuelveCaso() {
	InvertirQueue lista;
	int aux;
	std::cin >> aux;
	if (!std::cin) {
		return false;
	}
	while (aux != 0) {
		lista.push(aux);
		std::cin >> aux;
	}

	lista.invertir();
	lista.print();

	cout << "\n";


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