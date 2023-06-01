//ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue_eda.h"



using namespace std;

class MezclarQueue : public queue<int> {
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


	void mezclar(MezclarQueue&lista2) {
		Nodo* act1 = this->prim;
		Nodo* act2 = lista2.prim;
		Nodo* act = act1;
		if (!this->empty() && !lista2.empty()) {
			if (act2->elem < act1->elem) {
				this->prim = act2;
				act = act2;
				act2 = act2->sig;
			}
			else {
				act1 = act1->sig;
			}
			while (act1 != nullptr  && act2 != nullptr) {
				if (act1->elem < act2->elem) {
					act->sig = act1;
					act1 = act1->sig;
				}
				else {
					act->sig = act2;
					act2 = act2->sig;
				}
				act = act->sig;
			}
			if (act1 == nullptr) {
				act->sig = act2;
				this->ult = lista2.ult;
			}
			else {
				act->sig = act1;
			}

			this->nelems += lista2.nelems;
		}
		else if (this->empty()) {
			this->prim = lista2.prim;
		}
		lista2.prim = nullptr;
		lista2.nelems = 0;
		
		
	}
};
void resuelveCaso() {
	MezclarQueue lista1, lista2;
	int aux;
	cin >> aux;

	while(aux!=0) {
		lista1.push(aux);
		std::cin >> aux;

	}
	cin >> aux;
	while(aux!=0) {
		lista2.push(aux);
		std::cin >> aux;

	}
	lista1.mezclar(lista2);
	lista1.print();
	lista2.print();

	cout << "\n";

}


int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;

	while (numCasos > 0) {
		resuelveCaso();
		numCasos--;
	}

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}