//ADRIÁN SANJUÁN ESPEJO

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "list_eda.h"
#include "personas.h"



using namespace std;


bool resuelveCaso() {
	list<persona> lista;
	int n, edadmin, edadmax, e;
	char aux;
	cin >> n >> edadmin >> edadmax;
	if (n == 0 && edadmin == 0 && edadmax == 0) {
		return false;
	}
	string name;
	persona p;

	for (int i = 0; i < n; i++) {
		cin >> e;
		cin.get(aux);
		getline(cin, name);
		p = persona(name, e);
		lista.push_back(p);
	}
	lista.remove_if([edadmin, edadmax](persona p) {
		return (edadmin > p.getEdad() || edadmax < p.getEdad());
	});
	for (persona p : lista) {
		cout << p.getNombre() << '\n';
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