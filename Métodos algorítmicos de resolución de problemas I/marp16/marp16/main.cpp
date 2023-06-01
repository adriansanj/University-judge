// DG34 Adrián Sanjuán
// siguiendo solución del campus
#include <iostream>
#include <queue>

using namespace std;
int resolver(int origen, int fin) {
	queue<int> cola;
	vector<int> dist(10000, 999999999);
	vector<int> sig(3);
	cola.push(origen);
	dist[origen] = 0;
	while (!cola.empty()) {
		int o = cola.front();
		cola.pop();
		sig[0] = (o + 1) % 10000;
		sig[1] = (o * 2) % 10000;
		sig[2] = o / 3;
		for (int i = 0; i < 3; i++) {
			if (dist[sig[i]] == 999999999) {
				dist[sig[i]] = dist[o] + 1;
				if (sig[i] == fin) {
					return dist[sig[i]];
				}
				else {
					cola.push(sig[i]);
				}
			}
		}

	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int origen, fin;
	
	int distancia;
	cin >> origen;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> fin;
	if (origen != fin) {
		distancia = resolver(origen, fin);
	}
	else {
		distancia = 0;
	}
	
	

	cout << distancia <<'\n';
	return true;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

int main() {
	while (resuelveCaso());
	return 0;
}