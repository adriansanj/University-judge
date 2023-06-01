
//ADRIÁN SANJUÁN ESPEJO DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "deque_eda.h"



using namespace std;
typedef struct {
	int n;
	int indicie;
}tNum;

bool resuelveCaso() {

	string devolver = "";
	deque<tNum> candidatos;

	int k, n;
	tNum aux;
	bool candidato;
	cin >> n >> k;
	if (n == 0 && k == 0) {
		return false;
	}
	
	
	for (int i = 0; i < n; i++) {
		cin >> aux.n;
		aux.indicie = i;
		
		while (!candidatos.empty() && candidatos.back().n < aux.n) {
			candidatos.pop_back();
		}
		candidatos.push_back(aux);
		while (!(candidatos.front().indicie > i - k)) {
			candidatos.pop_front();
		}
		if (i >= k-1) {
			cout << candidatos.front().n << ' ';
		}
		
	}
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