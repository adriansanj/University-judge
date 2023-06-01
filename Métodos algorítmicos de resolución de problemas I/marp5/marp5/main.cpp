// DG34 Adrián Sanjuán Espejo

#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	string nombre;
	long long int gravedad;
	int llegada;
}tPaciente;

bool operator <(const tPaciente &a, const tPaciente &b) {
	return (a.gravedad > b.gravedad || (a.gravedad == b.gravedad && a.llegada < b.llegada));
}
void resolver(PriorityQueue<tPaciente> q, int n) {
	char c;
	tPaciente paciente;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'I') {
			cin >> paciente.nombre;
			cin >> paciente.gravedad;
			paciente.llegada = i; //No importa que cuando empiezen a salir pacientes el turno/llegada se desvirtue, 
								//simplemente sirve para poder hacer una comparación y ver quién ha llegado antes
			q.push(paciente);
		}
		else {
			cout << q.top().nombre << "\n";
			q.pop();
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	PriorityQueue<tPaciente> q;
	cin >> n;
	if (n == 0) {
		return false;
	}

	resolver(q, n);
	cout << "---\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}