//Adrián Sanjuán D29

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <string>
#include<vector>
#include <unordered_map>


using namespace std;
typedef struct {
	int tiempo;
	string veredicto;
} tProblema;

typedef struct {
	int tiempo;
	int problemas;
} tResultados;

bool mayor(pair<string, tResultados>&a, pair<string, tResultados>&b) {
	return (a.second.problemas > b.second.problemas || (a.second.problemas == b.second.problemas && a.second.tiempo < b.second.tiempo) || (a.second.problemas == b.second.problemas && a.second.tiempo == b.second.tiempo && a.first < b.first));
}

void resuelveCaso() {
	string grupo,problema,veredicto;
	int tiempo, suma = 0;
	unordered_map<string, unordered_map<string, tProblema>> grupos;
	vector<pair<string, tResultados>> resultados;
	cin >> grupo;
	while (grupo != "FIN") {
		cin >> problema >> tiempo >> veredicto;
		if (veredicto != "AC") {
			suma = 20;
		}
		else {
			suma = tiempo;
		}

		if (!grupos.count(grupo) || (grupos.count(grupo) && !grupos[grupo].count(problema))) {
			grupos[grupo][problema] = { 0,veredicto };
		}
		else {
			if (grupos[grupo][problema].veredicto == "AC") {
				suma = 0;
			}
			else {
				grupos[grupo][problema].veredicto = veredicto;
			}
		}
		grupos[grupo][problema].tiempo += suma;
		
		
		cin >> grupo;
	}

	for (auto team : grupos) {
		suma = 0;
		tiempo = 0;
		for (auto problema : team.second) {
			if (problema.second.veredicto == "AC") {
				suma++;
				tiempo += problema.second.tiempo;
			}
		}
		resultados.push_back({ team.first,{tiempo,suma} });
	}
	sort(resultados.begin(), resultados.end(), &mayor);

	for (auto team : resultados) {
		cout << team.first << ' ' << team.second.problemas << ' ' << team.second.tiempo << '\n';
	}
	cout << "---\n";
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
		--numCasos;
	};



	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}