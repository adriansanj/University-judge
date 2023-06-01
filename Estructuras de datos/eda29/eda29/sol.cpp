//Adrián Sanjuán DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>


using namespace std;


bool resuelveCaso() {
	int ini = 0, maslargo = 0, n,capitulo;
	unordered_map<int, int> capitulos; //<capitulo,día de emisión>

	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> capitulo;
		if (capitulos.count(capitulo) != 0 && capitulos[capitulo] >= ini) {
			if (i - ini > maslargo) {
				maslargo = i - ini;
			}
			ini = capitulos[capitulo] + 1;
		}
		
		capitulos[capitulo] = i;
	}
	
	if (n - ini > maslargo) {
		maslargo = n - ini;
	}

	cout << maslargo << "\n";

	return true;
}

int main() {
	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int numCasos;
	cin >> numCasos;
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