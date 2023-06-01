//Adrián Sanjuán D29

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <string>
#include<vector>
#include <unordered_map>


using namespace std;


bool resuelveCaso() {
	unordered_map<int, int> numeros;
	vector<int> orden;
	int n, num;
	cin >> n;
	if (!cin) {
		return false;
	}
	for (int i = 0; i < n;i++ ) {
		cin >> num;
		if (!numeros.count(num)) {
			orden.push_back(num);
			numeros[num] = 1;
		}
		else {
			numeros[num]++;
		}
	}

	for (int numero : orden) {
		cout << numero << ' ' << numeros[numero] << '\n';
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