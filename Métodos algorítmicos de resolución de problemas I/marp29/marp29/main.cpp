// Grupo DG34 Adrián Sanjuán

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int resolver(vector<pair<long long int, long long int>> horas) {
	int cont = 1;
	long long int fin = horas[0].first;
	for (int i = 1; i < horas.size() ; i++) {
		if (horas[i].second -10 >= fin) {
			cont++;
			fin = horas[i].first;
		}
	}
			


	return cont;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int n, aux, aux_h=0;
	char c;
	cin >> n;
	if (n==0) // fin de la entrada
		return false;
	vector<pair<long long int,long long int>> horas;
	for (int i = 0; i < n; i++) {
		cin >> aux;
		aux_h = aux * 60;
		cin.get(c);
		cin >> aux;
		aux_h += aux;
		cin >> aux;
		horas.push_back({ aux_h + aux ,aux_h});
	}
	sort(horas.begin(), horas.end());
	cout << resolver(horas) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}