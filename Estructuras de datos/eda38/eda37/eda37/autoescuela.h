#pragma once

#ifndef AUTOESCUELA
#define AUTOESCUELA

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

class autoescuela {
private:
	unordered_map<string, set<string>> profesores;
	unordered_map<string,pair<int,string>> alumnos;
public:

	autoescuela() {};

	void alta(string A, string P) {
		if (alumnos.count(A)) {
			if (profesores[P].count(A) == 0) {
				profesores[P].insert(A);
				profesores[alumnos[A].second].erase(A);
				alumnos[A].second = P;
			}
		}
		else {
			profesores[P].insert(A);
			alumnos[A] = { 0,P };
		}
	}

	bool es_alumno(string A, string P) {
		if (alumnos.count(A)) {
			return alumnos[A].second == P;
		}
		return false;
	}

	int puntuacion(string A) {
		if (alumnos.count(A)) {
			return alumnos[A].first;
		}
		else {
			throw domain_error("El alumno A no esta matriculado");
		}
	}


	void actualizar(string A, int N) {
		if (alumnos.count(A)) {
			alumnos[A].first+=N;
		}
		else {
			throw domain_error("El alumno A no esta matriculado");
		}
	}

	list<string> examen(string P, int N) {
		list<string> e;
		for (auto a : profesores[P]) {
			if (alumnos.at(a).first >= N) {
				e.push_back(a);
			}
		}
		return e;
	}

	void aprobar(string A) {
		if (alumnos.count(A)) {
			profesores[alumnos[A].second].erase(A);
			alumnos.erase(A);
		}
		else {
			throw domain_error("El alumno A no esta matriculado");

		}
	}
};








#endif // AUTOESCUELA