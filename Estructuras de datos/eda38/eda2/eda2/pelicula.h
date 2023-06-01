#pragma once

#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument
#include <string>
#include"horas.h"

class pelicula {
private:
	std::string nombre;
    horas horaInicial; 
    horas horaFinal;
public:
    // constructora
   pelicula(horas hi = horas(0,0,0), horas duracion = horas(0, 0, 0), std::string n = "") {
	   try {
		   horaInicial = hi;
		   horaFinal = hi + duracion;
		   nombre = n;
	   }
	   catch (std::domain_error & e) {
		   throw std::domain_error("datos invalidos");
	   }
    }

    // observadoras


    // operador de comparación
    bool operator<(pelicula const& p) const {
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
	}
	
	
};
inline std::ostream & operator<<(std::ostream & salida, pelicula const& p) {
	p.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, pelicula & p) {
	p.read(entrada);
	return entrada;
}

#endif
