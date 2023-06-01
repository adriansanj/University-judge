//Adrián Sanjuán D29

#include <iostream>
#include <algorithm>
#include <fstream>
#include "set_eda.h"
using namespace std;


template <typename T>
class SetTree:public set<T> {
public:
	using Link = set<T>::Link;
	int count_interval(const T &lower, const T &upper) const {
		int n = 0;
		count(lower, upper, n, this->raiz);
		return n;
	}
protected:
	void count(const T &lower, const T &upper, int & n, Link raiz) {
		if (raiz != nullptr) {
			if ((menor(lower, raiz->elem) || lower == raiz->elem) && (menor(raiz->elem, upper) || upper== raiz->elem)) {
				n++;
				if (menor(raiz->elem, upper)) { count(lower, upper, n, raiz->dr); }
				if (menor(lower, raiz->elem)) { count(lower, upper, n, raiz->iz); }

				else if (menor(raiz->elem, lower)) {
					count(lower, upper, n, raiz->dr);
				}
			}
		}
	}
};



bool resuelveCaso() {
	int N, M, aux, aux2;
	SetTree<int> set;
	cin >> N;
	if (!cin) {
		return false;
	}
	for (int i = 0; i < N; i++) {
		cin >> aux;
		set.insert(aux);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> aux >> aux2;
		cout << set.count_interval(aux, aux2);

		
	}
	cout << "---\n";
	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while(resuelveCaso());
	


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}