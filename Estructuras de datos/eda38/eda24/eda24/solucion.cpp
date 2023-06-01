//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "bintree_eda.h"
using namespace std;

bintree<int> reconstruir(vector<int> & preord, vector<int> & inord, int inipre, int finpre, int iniino, int finino) {
	bintree<int> arbol;
	bintree<int> d;
	bintree<int> i;
	
	if (finpre < inipre) {
		return arbol;
	}
	int r = preord[inipre];
	

	int c = iniino;
	while (inord[c] != r) {
		c++;
	}
	int tam = c - iniino;
	i = reconstruir(preord, inord, inipre + 1, inipre + tam, iniino,c-1);
	d = reconstruir(preord, inord, inipre +tam+ 1, finpre, c+1, finino);

	arbol = bintree<int>(i, r, d);
	return arbol;
}

bool resuelveCaso() {
	vector<int> preord;
	vector<int> inord;
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
	//leer segundo vector
	cin >> num;
	inord.push_back(num);
	cin.get(aux);
	while (aux != '\n') {
		cin >> num;
		inord.push_back(num);
		cin.get(aux);
	}
	num = 0;
	arbol = reconstruir(preord,inord,0,preord.size()-1,0,inord.size()-1);
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
	
	while(resuelveCaso());
	

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}