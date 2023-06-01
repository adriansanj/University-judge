//ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue_eda.h"



using namespace std;

class IntercambiarQueue : public queue<int> {
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


	void intercambiar() {
		if (this->size()>1) {
			Nodo* previo = this->prim;
			Nodo* siguiente = previo->sig;
			Nodo* aux = nullptr;
			bool entrado=false;
			this->prim = siguiente;
			for (int i = 0; i < this->size() / 2-1; i++) {
				entrado = true;
				if (i != 0) {
					aux->sig = siguiente;
				}
				previo->sig = siguiente->sig;
				siguiente->sig = previo;
				aux = previo;
				previo = previo->sig;
				siguiente = previo->sig;
			}
			if (entrado) {
				aux->sig = siguiente;
			}
			previo->sig = siguiente->sig;
			siguiente->sig = previo;
			if (this->size() % 2 == 0) {
				this->ult = previo;
			}
		}
	}
};
bool resuelveCaso() {
	IntercambiarQueue lista;
	int n,aux;
	cin >> n;
	if (n == 0) {
		return false;
	}
	
	for (int i = 0; i < n; i++) {
		std::cin >> aux;
		lista.push(aux);
	}

	lista.intercambiar();
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