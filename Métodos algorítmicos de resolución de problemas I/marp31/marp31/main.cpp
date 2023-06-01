// Grupo DG34 Adrián Sanjuán

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int resolver(vector<pair<long long int, long long int>> edif) {
	int cont = 1;
	long long int fin = edif[0].second;
	for (int i = 1; i < edif.size(); i++) {
		if (edif[i].first < fin) {
			if (edif[i].second < fin) {
				fin = edif[i].second;
			}
		}
		else {
			fin = edif[i].second;
			cont++;
		}
	}
	return cont;
}
	




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int n, aux, aux2;
	cin >> n;
	if (n == 0) // fin de la entrada
		return false;
	vector<pair<long long int, long long int>> edif;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		cin >> aux2;
		edif.push_back({aux ,aux2 });
	}
	sort(edif.begin(), edif.end());
	cout << resolver(edif) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}