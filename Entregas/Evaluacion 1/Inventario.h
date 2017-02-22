#include <vector>
#include <algorithm>
#include <stack>
#include "Videojuego.h"

class Inventario{
private:
	Inventario();
	static Inventario* Instance;
	vector<Videojuego> gameList;
	stack<Videojuego> Eliminacion;
	int noItems;
	unsigned NewSN;

public:
	static Inventario* crear();
	void agregarJuego(string _Nombre, float precio, string clasificacion, string plataforma);
	void eliminarJuego(int noSerie);
	void ordenar(bool menorAmayor);
	void buscar(int noSerie);
	void undo();
	void printAll();
	unsigned getAllItems();
};