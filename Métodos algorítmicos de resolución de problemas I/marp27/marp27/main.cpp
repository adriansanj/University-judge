// Grupo DG34 Adrián Sanjuán

#include <iostream>
#include <vector>
using namespace std;

int resolver(vector<long long int> datos, int l) {
	int cont = 1;
	int ref = datos[0];
	if (datos.size() > 1) {
		for (int i = 1; i < datos.size(); i++) {
			if (datos[i] - ref > l) {
				ref = datos[i];
				cont++;
			}
		}
	}
	return cont;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, l;
	cin >> n;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> l;
	vector<long long int> datos(n);
	for (int i = 0; i < n; i++) {
		cin >> datos[i];
	}
	cout << resolver(datos, l) << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}