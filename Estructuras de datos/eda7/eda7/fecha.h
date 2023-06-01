#pragma once

//  ADRIÁN SANJUÁN ESPEJO

#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <iomanip>
#include <stdexcept>  // invalid_argument

class fecha {
private:
	int D; 
	int M; 
	int A;  
	/*bool check(int h, int m, int s) {
		return 1 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60;
	}*/
public:
	// constructora
	fecha(int d = 1, int m = 1, int a = 1900) {
		D = d;
		M = m;
		A = a;
		
	
	}

	// observadoras
	int dia() const { return D; }
	int mes() const { return M; }
	int anno() const { return A; }

	// operador de comparación
	/*bool operator<(fecha const& f) const {
		return(anno < f.anno || (anno == f.anno && mes < f.mes) || (anno == f.anno && mes == f.mes && dia < f.dia));
	}*/

	void read(std::istream & input = std::cin) {
		int d, m, a; char c;
		input >> d >> c >> m >> c >> a;
		*this = fecha(d,m,a);
	}
	void print(std::ostream& o = std::cout) const {
		o << std::setfill('0') << std::setw(2) << D << '/'
			<< std::setfill('0') << std::setw(2) << M << '/'
			<< std::setfill('0') << std::setw(2) << A;
	}
};

inline std::ostream & operator<<(std::ostream & salida, fecha const& h) {
	h.print(salida);
	return salida;
}

inline std::istream & operator>>(std::istream & entrada, fecha & h) {
	h.read(entrada);
	return entrada;
}

#endif
