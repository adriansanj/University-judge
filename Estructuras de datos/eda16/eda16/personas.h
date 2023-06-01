#pragma once

#ifndef PERSONAS_H
#define PERSONAS_H

#include <iostream>
#include <iomanip>
#include<string>
#include <stdexcept>  // invalid_argument

class persona {
private:
	std::string nombre; 
	int edad;
	
public:
	// constructora
	persona(std::string p = "", int e = 0) {
		nombre = p;
		edad = e;
	}

	// observadoras
	std::string getNombre() const { return nombre; }
	int getEdad() const { return edad; }
	



};
#endif
