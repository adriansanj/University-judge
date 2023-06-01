//Adrián Sanjuán DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
#include"autoescuela.h"

using namespace std;



bool resuelveCaso() {
	string ins, a,p;
	int n;
	autoescuela autoes;
	cin >> ins;
	if (!cin) {
		return false;
	}
	while (ins != "FIN") {

		if (ins == "alta") {
			
			cin >> a>>p;
			autoes.alta(a, p);

			

		}
		else if (ins == "es_alumno") {
			
			cin >> a >> p;

			cout << a << (autoes.es_alumno(a, p) ?" es alumno de " :" no es alumno de ") << p << '\n';
			
			
		}
		else if (ins == "puntuacion") {
			try {
				cin >> a;
				int p = autoes.puntuacion(a);
				cout << "Puntuacion de " << a << ": " << p << '\n';
			}
			catch (exception &e) {
				cout << "ERROR\n";
			}
		}
		else if (ins == "actualizar") {
			try {
				cin >> a >>n;
				autoes.actualizar(a, n);
			}
			catch (exception &e) {
				cout << "ERROR\n";
			}
		}
		else if (ins == "examen") {
		
				cin >> p >> n;
				list<string> l = autoes.examen(p, n);
				cout << "Alumnos de " << p << " a examen:" << '\n';
				for (auto al : l) {
					cout <<  al << '\n';
				}
			
			
		}
		else {
			try {
				cin >> a;
				autoes.aprobar(a);
			}
			catch (exception &e) {
				cout << "ERROR\n";
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

	while (resuelveCaso());
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}