//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;

bintree<int> reconstruir(vector<int> & preord) {
	bintree<int> arbol,i,d;
	
	if (preord.size()==0) {
		arbol = bintree<int>();
		return arbol;
	}
	int r = preord[0];
	vector<int> dr;
	vector<int>izq;
	if (preord.size() > 1) {
		for (int i = 1; i < preord.size(); i++) {
			if (preord[i] < r) {
				izq.push_back(preord[i]);
			}
			else {
				dr.push_back(preord[i]);
			}
		}

		i = reconstruir(izq);
		d = reconstruir(dr);
		arbol = bintree<int>(i, r, d);
		return arbol;
	}
	else {
		arbol = bintree<int>(r);

	}
	return arbol;
}

bool resuelveCaso() {
	vector<int> preord;
	bintree<int> arbol;
	int num;
	char aux;
	//leer primer vector
	cin >> num;
	if (!cin) {
		return false;
	}
	preord.push_back(num);
	cin.get(aux);
	while (aux != '\n') {
		cin >> num;
		preord.push_back(num);
		cin.get(aux);
	}
	
	arbol = reconstruir(preord);
	for (int el : arbol.postorder()) {
		cout << el << ' ';
	}
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