//Adrián Sanjuán DG29

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
#include <wchar.h>
#include <locale.h>
#include"venta_libros.h"

using namespace std;



bool resuelveCaso() {
	string ins, l;
	char aux;
	int n,numins;
	venta_libros tienda;
	cin >> numins;
	if (!cin) {
		return false;
	}
	for (int j = 0; j < numins; j++) {
		cin >> ins;
		if (ins == "nuevoLibro") {
			
				cin >> n;
				cin.get(aux);
				getline(cin, l);
				tienda.nuevoLibro(n,l);
			
			


		}
		else if (ins == "comprar") {

			try {
				cin.get(aux);
				getline(cin, l);
				tienda.comprar(l);
			}
			catch (exception & e) {
				std::cout << e.what() << '\n';
			}


		}
		else if (ins == "estaLibro") {
			cin.get(aux);
			getline(cin, l);
			std::cout << (tienda.estaLibro(l) ? "El libro " + l + " esta en el sistema\n" : "No existe el libro " + l + " en el sistema\n");

		}
		else if (ins == "elimLibro") {
			cin.get(aux);
			getline(cin, l);
			tienda.elimLibro(l);
		}
		else if (ins == "numEjemplares") {

			try {
				cin.get(aux);
				getline(cin, l);
				int i = tienda.numEjemplares(l);
				std::cout << "Existen " << i << " ejemplares del libro " << l << '\n';
			}
			catch (exception & e) {
				std::cout << "No existe el libro " << l << " en el sistema\n";
			}


		}
		else if (ins == "top10") {



			list<string> l = tienda.top10();

			/*if (l.size() == 0) {
				cout << "No hay canciones recientes\n";
			}*/
			//else {
			std::cout << "TOP10\n";
				for (string c : l) {
					std::cout << "    " << c << '\n';
				}
			//}

		}
	
	}
	std::cout << "---\n";

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