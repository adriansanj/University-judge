//Adrián Sanjuán DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
#include"carnet_puntos.h"

using namespace std;



bool resuelveCaso() {
	string ins,dni;
	int pts;
	carnet_puntos lista;
	cin >> ins;
	if (!cin) {
		return false;
	}
	while (ins != "FIN") {

		if (ins == "nuevo") {
			try {
				cin >> dni;
				lista.nuevo(dni);
			}
			catch (exception &e) {
				cout << "ERROR: "<< e.what() << '\n';
			}

		}
		else if (ins == "quitar") {
			try {
				cin >> dni;
				cin >> pts;
				lista.quitar(dni, pts);
			}
			catch (exception &e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (ins == "recuperar") {
			try {
				cin >> dni;
				cin >> pts;
				lista.recuperar(dni, pts);
			}
			catch (exception &e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (ins == "consultar") {
			try {
				cin >> dni;
				int i = lista.consultar(dni);
				cout << "Puntos de " << dni << ": " << i << '\n';
			}
			catch (exception &e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else if (ins == "cuantos_con_puntos") {
			try {
				cin >> pts;
				int i = lista.cuantos_con_puntos(pts);
				cout << "Con " << pts << " puntos hay " << i << '\n';
			}
			catch (exception& e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		else {
			try {
				cin >> pts;
				list<string> l = lista.lista_por_puntos(pts);
				cout << "Tienen " << pts << " puntos:";
				for (auto p : l) {
					cout << ' ' << p ;
				}
				cout << '\n';
			}
			catch (exception &e) {
				cout << "ERROR: " << e.what() << '\n';
			}
		}
		cin >> ins;
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