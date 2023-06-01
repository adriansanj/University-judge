//ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue_eda.h"



using namespace std;

class InsertarQueue : public queue<int> {
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


	void insertar(InsertarQueue&other, int pos) {
		Nodo* act = nullptr;
		Nodo* auxoriginal = this->prim;

		for (int i = 0; i < pos; i++) {
			act = auxoriginal;
			auxoriginal = auxoriginal->sig;
		}

		if (act == nullptr) {
			this->prim = other.prim;
			other.ult->sig = auxoriginal;
		}
		else if (act==this->ult){
			this->ult = other.ult;
			act->sig = other.prim;
		}
		else {
			act->sig = other.prim;
			other.ult->sig = auxoriginal;
		}
		this->nelems += other.nelems;
		other.nelems = 0;
		other.prim = nullptr;
		
	}
};
bool resuelveCaso() {
	InsertarQueue lista1,lista2;
	int pos, n1, n2;
	int aux;
	cin >> n1;
	if (!std::cin) {
		return false;
	}
	
	for(int i = 0; i<n1;i++) {
		std::cin >> aux;
		lista1.push(aux);
		
	}
	cin >> n2 >> pos;
	for (int i = 0; i < n2; i++) {
		std::cin >> aux;
		lista2.push(aux);
		
	}
	lista1.insertar(lista2,pos);
	lista1.print();
	lista2.print();

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