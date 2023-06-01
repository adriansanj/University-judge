// DG34 Adrián Sanjuán Espejo

#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	int id;
	long long int sig_turno;
}tCaja;

bool operator <(const tCaja &a, const tCaja &b) {
	return (a.sig_turno < b.sig_turno || (a.sig_turno == b.sig_turno && a.id < b.id));
}
int resolver(PriorityQueue<tCaja> q,int c) {
	long long int cliente;
	tCaja aux;
	for (int i= 0; i<c; i++) {
		cin >> cliente;
		aux = q.top();
		q.pop();
		aux.sig_turno += cliente;
		q.push(aux);
	}
	return q.top().id+1;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n,c,caja_res;
	tCaja caja;
	PriorityQueue<tCaja> q;
	cin >> n >> c;
	if (n == 0 && c==0) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		caja.id = i;
		caja.sig_turno = 0;
		q.push(caja);
	}
	caja_res = resolver(q, c);
	cout << caja_res << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}