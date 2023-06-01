// Grupo DG34 Adrián Sanjuán

#include <iostream>
#include <vector>
#include<deque>
using namespace std;


int resolver(deque<int> pilas, int v) {
	int cont_c = 0;
	int i = 0, suma_v = 0;
	for(int i = 0; i< pilas.size(); i++) {
		suma_v += pilas[i];
		if (suma_v > v) {
			cont_c++;
			suma_v = 0;
		}
	}
	return cont_c;
}





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	long long int n, v,aux;
	cin >> n;
	cin >> v;
	deque<int> pilas;
	for (int i = 0; i < n; i++) {
		cin >>  aux;
		pilas.push_back(aux);
	}
	cout << resolver(pilas, v) << '\n';
	
	return true;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}