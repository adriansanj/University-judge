//Adrián Sanjuán D29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>


using namespace std;


bool resuelveCaso() {
	int l;
	cin >> l;
	if (l == 0) {
		return false;
	}
	map<string, vector<int>> ref;
	string linea,palabra,palabra2="";
	int cont = 0;
	for (int i = 0; i < l; i++) {
		char c = ' ';
		while (c != '\n' && c != '\r') {
			cin >> palabra;
			for (char p : palabra) {
				palabra2 += tolower(p);
				cont++;
			}
			if (cont>2 && (ref[palabra2].size()==0||ref[palabra2][ref[palabra2].size()-1] != i + 1)) {
				ref[palabra2].push_back(i + 1);
			}
			palabra2 = "";
			cont = 0;
			cin.get(c);
		}
	}

	for (auto pr : ref) {
		cout << pr.first;
		for (int i = 0; i < ref[pr.first].size(); i++) {
			cout << ' ' << ref[pr.first][i];
		}
		cout << '\n';
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