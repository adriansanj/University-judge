//Adrián Sanjuán DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>


using namespace std;

bool mayor(const pair<string, int> &a, const pair<string, int> &b) {
	return (a.second > b.second || (a.second == b.second && a.first < b.first));
}

bool resuelveCaso() {
	unordered_map<string, set<string>> deportes;
	unordered_map<string, string> estudiantes;
	string deporte, alumno;
	vector<pair<string, int>> fin;
	cin >> deporte;
	if (!cin) {
		return false;
	}
	while (deporte != "_FIN_") {
		deportes[deporte];
		cin >> alumno;
		char c = alumno[0];
		while (c >= 'a' && c <= 'z') {
			if (!deportes[deporte].count(alumno)) {
				deportes[deporte].insert(alumno);
			}
			if (estudiantes.count(alumno) && estudiantes[alumno] != deporte) {
				deportes[estudiantes[alumno]].erase(alumno);
				deportes[deporte].erase(alumno);
			}
			else {
				estudiantes[alumno] = deporte;
			}
			cin >> alumno;
			c = alumno[0];
			
		}
		deporte = alumno;
	}

	for (auto d : deportes) {
		fin.push_back({ d.first, d.second.size() });
	}

	sort(fin.begin(), fin.end(), &mayor);

	for (auto pr : fin) {
		cout << pr.first << ' ' << pr.second << '\n';
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