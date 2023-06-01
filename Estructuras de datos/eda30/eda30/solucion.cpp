//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>


using namespace std;



void resuelveCaso() {
	map<string, unsigned int> original = map<string, unsigned int>();
	map<string, unsigned int> resultado = map<string, unsigned int>();
	vector<string> anadir,borrar,cambio;
	string lineaaux, aux;
	
	int n;
	getline(cin, lineaaux);
	stringstream linea(lineaaux);


	while (linea>>aux) {
		
		linea >> n;
		original[aux] = n;


	}

	getline(cin, lineaaux);
	stringstream linea2(lineaaux);


	while (linea2 >> aux) {
		
		linea2 >> n;
		resultado[aux] = n;

	}

	
	for (auto pal: resultado) {
		if (original.count(pal.first) ==0) {
			anadir.push_back(pal.first);
		}
	}
	if (anadir.size() > 0) {
		cout << '+';
		for (string s : anadir) {
			cout << ' ' << s;
		}
		cout << "\n";
	}

	for (auto pal : original) {
		if (resultado.count(pal.first) == 0) {
			borrar.push_back(pal.first);
		}
	}
	if (borrar.size() > 0) {
		cout << '-';
		for (string s : borrar) {
			cout << ' ' << s;
		}
		cout << "\n";
	}

	
	for (auto pal : resultado) {
		if (original.count(pal.first)>0 && resultado[pal.first]!=original[pal.first]) {
			cambio.push_back(pal.first);
		}
	}
	
	if (cambio.size() > 0) {
		cout << '*';
		for (string s : cambio) {
			cout << ' ' << s;
		}
		cout << "\n";
	}
	if (cambio.size() == 0 && borrar.size() == 0 && anadir.size() == 0) {
		cout << "Sin cambios";
		cout << "\n";
	}
	cout << "---\n";
};

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
	cin.ignore(1);
	while (numCasos > 0) {
		resuelveCaso();
		numCasos--;
	}
		
		
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}