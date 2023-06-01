#pragma once

#ifndef IPUD
#define IPUD

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iostream>
#include <set>

#include <list>
#include <math.h>

using namespace std; 

class ipud {
private:
	struct info {
		string autor;
		int duracion;
		list<string>::iterator itPlayList;
		list<string>::iterator itReproducido;
	};

	unordered_map<string, info> canciones;

	list<string> playList;

	list<string> reproducido;

	int durTotal;
public:

	ipud() : durTotal(0) {};

	void addSong(string s, string a, int d) {
		auto its = canciones.find(s);
		if (its == canciones.end()) {
			canciones[s] = { a,d,playList.end(),reproducido.end() };
		}
		else {
			
			throw domain_error("addSong");
		}
	}

	void addToPlaylist(string s) {
		auto its = canciones.find(s);
		if (its == canciones.end()) {
			throw domain_error("addToPlaylist");
		}
		else {
			if (its->second.itPlayList == playList.end()) {
				its->second.itPlayList = playList.insert(playList.end(), s);
				durTotal += its->second.duracion;
			}
		}
	}

	string current() {
		if (playList.empty()) {
			throw domain_error("current");
		}
		return playList.front();
	}

	void play() {
		if (!playList.empty()) {
			string cancion = playList.front();
			canciones[cancion].itPlayList = playList.end();
			durTotal -= canciones[cancion].duracion;
			playList.pop_front();
			if (canciones[cancion].itReproducido != reproducido.end()) {
				reproducido.erase(canciones[cancion].itReproducido);
			}
			canciones[cancion].itReproducido = reproducido.insert(reproducido.begin(), cancion);
		}
	}

	int totalTime() {
		
		return durTotal;
		
	}

	list<string> recent(int N) {
		list<string> recientes;
		if (N > reproducido.size()) {
			return reproducido;
		}
		else {
			for (string const& c : reproducido) {
				recientes.push_back(c);
				if (recientes.size() == N) {
					break;
				}
			}
			return recientes;
		}
	}

	void delete_song(string s) {
		auto its = canciones.find(s);
		if (its != canciones.end()) {
			if (its->second.itPlayList != playList.end()) {
				playList.erase(its->second.itPlayList);
				durTotal -= its->second.duracion;
			}
			if (its->second.itReproducido != reproducido.end()) {
				reproducido.erase(its->second.itReproducido);
			}
			canciones.erase(its);
		}
	}
};








#endif // IPUD