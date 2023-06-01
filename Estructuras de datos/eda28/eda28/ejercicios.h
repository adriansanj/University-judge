#pragma once

#ifndef ejercicios_h
#define ejercicios_h

#include <iostream>
#include <stdexcept>
#include <string>
#include<vector>
#include <utility>
#include "treemap_eda.h"

using alumno = std::string;

class ejercicios {
private:
	map<alumno, int> tabla;
public:
	ejercicios() {}
	void anadir(alumno const& a) { // O(log A)
		++tabla[a];
	}

	void restar(alumno const& a) {
		--tabla[a];
		
	}
	int cantidad(alumno const& a) const { // O(log A)
		auto it = tabla.find(a);
		if (it == tabla.end())
			return 0;
		else
			return it->valor;
	}
	std::vector<alumno> evaluados() const { // O(A)
		std::vector<alumno> resultado;
		for (auto const& par : tabla) {
			if (par.valor != 0)
				resultado.push_back(par.clave);
		}
		return resultado;
	}



};


#endif