#pragma once

#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <string>
#include <vector>
#include <math.h>

typedef struct {
	int coeficiente;
	int exponente;
}tMonomio;

class polinomio {
private:
	std::vector<tMonomio> pares;
public:
	// constructora
	polinomio(std::vector<int> n = {}) {
		tMonomio m;
		for (int i = 0; i < n.size(); i+=2) {
			m.coeficiente = n[i];
			m.exponente = n[i + 1];
			pares.push_back(m);
		}
	}

	int evaluar(int valor) {
		int resultado=0;
		for (int i = 0; i < pares.size(); i++) {
			resultado += pow(valor, pares[i].exponente)*pares[i].coeficiente;
		}
		return resultado;
	}
	// observadoras


	// operador de comparación
	/*bool operator<(pelicula const& p) const {
		if (horaFinal == p.horaFinal) {
			return (nombre < p.nombre);
		}
		else {
			return (horaFinal < p.horaFinal);
		}
	}
	void read(std::istream & input = std::cin) {
		horas hi, d; std::string nombre;
		input >> hi >> d;
		getline(input, nombre);
		*this = pelicula(hi, d, nombre);
	}
	void print(std::ostream& o = std::cout) const {
		o << horaFinal << " " << nombre;
	}*/


};
/*inline std::ostream & operator<<(std::ostream & salida, pelicula const& p) {
	p.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, pelicula & p) {
	p.read(entrada);
	return entrada;
}*/

#endif

