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
#include"ipud.h"

using namespace std;



bool resuelveCaso() {
	setlocale(LC_ALL, "");
	string ins, a, s;
	int d;
	ipud ipud;
	cin >> ins;
	if (!cin) {
		return false;
	}
	while (ins != "FIN") {
		
		if (ins == "addSong") {
			try {
				cin >> s >> a >> d;
				ipud.addSong(s, a, d);
			}
			catch (exception & e) {
				cout << "ERROR " << e.what() << '\n';
			}


		}
		else if (ins == "addToPlaylist") {

			try {
				cin >> s;
				ipud.addToPlaylist(s);
			}
			catch (exception & e) {
				cout << "ERROR " << e.what() << '\n';
			}


		}
		else if (ins == "current") {
			try {
				ipud.current();
			}
			catch (exception & e) {
				cout << "ERROR " << e.what() << '\n';
			}

		}
		else if (ins == "play") {
			try {
				s = ipud.current();
				ipud.play();
				cout << "Sonando " << s << '\n';
			}
			catch (exception &e) {
				cout << "No hay canciones en la lista\n";
			}
		}
		else if (ins == "totalTime") {

			
			cout << "Tiempo total "<< ipud.totalTime() << '\n';


		}
		else if (ins == "recent") {

		
				cin >> d;
				
				list<string> l = ipud.recent(d);
				
				if (l.size() == 0) {
					cout << "No hay canciones recientes\n";
				}
				else {
					cout << "Las " << l.size() << " mas recientes\n";
					for (string c : l) {
						cout << "    " << c << '\n';
					}
				}
		
		}
		else {
			cin >> s;
			ipud.delete_song(s);
		}
		cin >> ins;
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