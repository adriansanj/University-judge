// DG 34 Adrián Sanjuán

#include <iostream>
#include "PriorityQueue.h"

using namespace std;

typedef struct {
	int num;
	int partituras;
}tInstrumento; //Se pueden dar dos instrumentos iguales pero da igual porque nos interesa el máximo número de instrumentos en un atril (y o el tipo de estos)

int maxnum(int part, int num) {
	if (num%part != 0) {
		return num / part + 1;
	}
	else {
		return num / part;
	}
}

struct comp {
	bool operator()(const tInstrumento &a, const tInstrumento &b) {
		if (a.partituras == 0) { return true; }
		else if (a.partituras == 0 && b.partituras == 0 && a.num > b.num) {
			return true;
		}
		else if (a.partituras != 0 && b.partituras != 0 && maxnum(a.partituras, a.num) > maxnum(b.partituras, b.num)) {
			return true;
		}
		else {
			return false;
		}
	}
};
int resolver(PriorityQueue<tInstrumento,comp> q,int p) {
	tInstrumento instrumento;
	for (int i = 0; i < p; i++) {
		instrumento = q.top();
		q.pop();
		instrumento.partituras++;
		q.push(instrumento);
	}
	return maxnum(q.top().partituras, q.top().num);
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n,p,sum=0;
	tInstrumento aux;
	PriorityQueue<tInstrumento,comp> q;
	cin >> p;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> aux.num;
		sum += aux.num;
		aux.partituras = 0;
		q.push(aux);
	}
	if (p > sum) {
		cout << 1 << "\n";
	}
	else {
		cout << resolver(q, p) << "\n";
	}
	
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}