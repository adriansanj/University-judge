//ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "queue_eda.h"



using namespace std;

class SaltosQueue : public queue<int> {
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


	void saltar(int saltos) {
		Nodo* borrar = this->prim;
		Nodo* anterior = this->ult;
		int aux = 0;
		while (this->nelems > 1) {
			for (int i = 0; i < saltos; i++) {
				if (borrar == this->ult) {
					borrar = this->prim;
				}
				else {
					borrar = borrar->sig;
				}
				if (anterior == this->ult) {
					anterior = this->prim;
				}
				else {
					anterior = anterior->sig;
				}
			}
			
			if (borrar == this->ult) {
				borrar = this->prim;
				anterior->sig = nullptr;
				this->ult = anterior;
			}
			else if(borrar == this->prim) {
				borrar = borrar->sig;
				this->prim = borrar;
			}
			else {
				anterior->sig = borrar->sig;
				borrar->sig = nullptr;
				borrar = anterior->sig;
			}
			
			--this->nelems;
		}

	}
};
bool resuelveCaso() {
	SaltosQueue q;
	int salto, n;
	cin >> n >> salto;
	if (salto==0 &&n==0) {
		return false;
	}

	for (int i = 0; i < n; i++) {
		q.push(i+1);
	}
	q.saltar(salto);
	q.print();
	
	cout << '\n';


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