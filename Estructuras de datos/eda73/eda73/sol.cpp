//ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue_eda.h"
#include "horas.h"



using namespace std;
template <class T>
class EliminarQueue : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
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

	void eliminar() {
		if (this->size() > 1) {
			Nodo* previo = this->prim;
			Nodo* siguiente = previo->sig;
			while (siguiente != nullptr) {
				while ( siguiente != nullptr&&siguiente->elem < previo->elem ) {
					previo->sig = siguiente->sig;
					delete(siguiente);
					siguiente = previo->sig;
				}
				if (siguiente != nullptr) {
					previo = siguiente;
					siguiente = previo->sig;
				}
			}
			this->ult = previo;
			
		}
	}
};
bool resuelveCaso() {
	EliminarQueue<horas> lista;
	horas h;
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}

	for (int i = 0; i < n; i++) {
		std::cin >> h;
		lista.push(h);
	}

	lista.eliminar();
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