#pragma once

#ifndef VENTA_LIBROS
#define VENTA_LIBROS

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
using libro = string;


class venta_libros {
private:
	struct infoLibro {
		int ejemplares;
		int vendidos;
		list<string>::iterator itVentas;
	};
	unordered_map<string, infoLibro> libros;
	map<int, list<string>,std::greater<int>> ventas;

	list<string>::iterator insertar_por_ventas(libro l, int v) {
		ventas.insert({ v,{} });
		auto& listaventas = ventas[v];
		return listaventas.insert(listaventas.begin(), l);
	}
public:
	venta_libros() {
	}

	void nuevoLibro(int  n, libro x) {
		auto itl = libros.find(x);
		if (itl == libros.end()) {
			libros.insert({ x,{n,0,} });
		} else{
			if (n > 0) {
				itl->second.ejemplares += n;
			}
		}
	}

	void comprar(libro x) {
		auto itl = libros.find(x);
		if (itl == libros.end()) {
			throw invalid_argument("Libro no existente");
		}
		else {
			infoLibro & info = itl->second;
			if (info.ejemplares ==0) {
				throw out_of_range("No hay ejemplares");
			}
			else {
				if (info.vendidos> 0 && info.itVentas != ventas.at(info.vendidos).end()) {
					if (ventas[info.vendidos].size() == 1) {
						ventas.erase(info.vendidos);
					}
					else {
						ventas[info.vendidos].erase(info.itVentas);
					}
				}
				info.vendidos++;
				info.ejemplares--;
				info.itVentas = insertar_por_ventas(x, info.vendidos);
			}
		}

	}

	bool estaLibro(libro x) {
		auto itl = libros.find(x);
		return itl != libros.end();
	}

	void elimLibro(libro x) {
		auto itl = libros.find(x);
		if (itl != libros.end()) {
			infoLibro & info = itl->second;
			if (info.vendidos > 0) {
				if (ventas[info.vendidos].size() == 1) {
					ventas.erase(info.vendidos);
				}
				else {
					ventas[info.vendidos].erase(info.itVentas);
				}
			}
			libros.erase(itl);
		}
	}

	int numEjemplares(libro x) {
		auto itl = libros.find(x);
		if (itl == libros.end()) {
			throw invalid_argument("Libro no existente");
		}
		else {
			return itl->second.ejemplares;
		}
	}

	list<libro> const top10(){
		int i = 0;
		list<libro> lista;
		for (auto & l : ventas) {
			for (libro & lib : l.second) {
				lista.push_back(lib);
				i++;
				if (i == 10) {
					break;
				}
			}
			if (i == 10) {
				break;
			}
		}
		return lista;
	}
};








#endif // VENTA_LIBROS