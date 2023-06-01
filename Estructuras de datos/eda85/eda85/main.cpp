//Adrián Sanjuán D29

#include <iostream>
#include <algorithm>
#include <fstream>
#include "set_eda.h"
using namespace std;


bool resuelveCaso() {
	int N, M, aux;
	pair<bool, int> p;
	set<int> set;
	cin >> N;
	if (N == 0){
		return false;
	}
	for(int i = 0; i< N; i++){
		cin >> aux;
		set.insert(aux);
	}
	cin >> M;
	for(int i = 0; i< M; i++){
		cin >> aux;
		p = set.lower_bound(aux);
		if (p.first) {
			cout << p.second<< '\n';
		}
		else {
			cout << "NO HAY\n";
		}
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
	while (resuelveCaso());


	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}