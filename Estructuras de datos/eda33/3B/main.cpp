
// NOMBRES Y APELLIDOS (USUARIO DEL JUEZ)

#include <iostream>                              
#include <fstream>                              
#include <algorithm>
using namespace std;

// COMENTARIO SOBRE LA SOLUCIÓN Y SU COSTE JUSTIFICADO


bool resuelveCaso() {
   int N, M;
   cin >> N >> M;
   if (!cin)
      return false;

   
   
   
   return true;
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
