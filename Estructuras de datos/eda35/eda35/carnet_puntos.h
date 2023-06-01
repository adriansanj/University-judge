#pragma once

#ifndef CARNET_PUNTOS
#define CARNET_PUNTOS

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <math.h>

using namespace std;

class carnet_puntos {
private:
	
	unordered_map<string,pair<int,list<string>::iterator>> lista;

	vector<list<string>> listapuntos;

	list<string>::iterator insertar_por_puntos(string dni, int pts) {
		auto& lista = listapuntos[pts];
		return lista.insert(lista.begin(), dni);
	}

public:
	
	carnet_puntos() : listapuntos(16) {}

	void nuevo(string DNI) {
		if (lista.count(DNI) > 0) {
			throw domain_error("Conductor duplicado");
		}
		else {
			lista.insert({ DNI,{15,insertar_por_puntos(DNI,15)} });
		}
	}

	void quitar(string dni, int puntos) {
		if (lista.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			if (puntos > 0 && lista[dni].first > 0) {
				listapuntos[lista[dni].first].erase(lista[dni].second);
				int p = max(lista[dni].first - puntos, 0);
				lista[dni] = { p,insertar_por_puntos(dni,p) };
			}
		}
	}

	void recuperar(string dni, int puntos) {
		if (lista.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			if (puntos > 0 && lista.at(dni).first < 15) {
				listapuntos[lista[dni].first].erase(lista[dni].second);
				int p = min(lista[dni].first + puntos, 15);
				lista[dni] = { p,insertar_por_puntos(dni,p) };
			}
		}
	}

	int consultar(string dni) {
		if (lista.count(dni) == 0) {
			throw domain_error("Conductor inexistente");
		}
		else {
			return lista[dni].first;
		}
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos >15) {
			throw domain_error("Puntos no validos");
		}
		else {
			return listapuntos[puntos].size();
		}
	}

	list<string> const& lista_por_puntos(int puntos) {
		if (puntos < 0 || puntos >15) {
			throw domain_error("Puntos no validos");
		}
		else {
			return listapuntos[puntos];
		}
	}
};

			
	





#endif // CARNET_PUNTOS