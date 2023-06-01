// DG34 Adrián Sanjuán Espejo

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	long long int id;
	long long int intervalo;
	long long int sig_turno;
}tUsuario;

bool operator <(const tUsuario &a, const tUsuario &b) { 
	return (a.sig_turno < b.sig_turno || (a.sig_turno == b.sig_turno && a.id < b.id));
}
void resolver(PriorityQueue<tUsuario> q, int k) {
	tUsuario aux;
	for (int i = 0; i<k; i++) {
		aux = q.top();
		cout << aux.id << "\n";
		q.pop();
		aux.sig_turno += aux.intervalo;
		q.push(aux);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n,k;
	long long int aux, aux_int;
	tUsuario aux_usuario;
	PriorityQueue<tUsuario> q;
	cin >> n;
	if (n == 0) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		cin >> aux_usuario.id;
		cin >> aux_usuario.intervalo;
		aux_usuario.sig_turno = aux_usuario.intervalo;
		q.push(aux_usuario);
	}
	cin >> k;
	resolver(q, k);
	cout << "---\n";
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}