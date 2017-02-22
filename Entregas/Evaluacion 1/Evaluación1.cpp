//Víctor Rendón Suárez | A01022462
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "Videojuego.h"
#include "Inventario.h"
using namespace std;

Videojuego::Videojuego(){}
Videojuego::Videojuego(int noSerie, string nombre, float precio, string clasificacion, string plataforma);
{
	NoSerie = _noSerie;
	Nombre = _nombre;
	precio = _precio;
	clasificacion = _clasificacion;
	plataforma = _plataforma;
}
int Videojuego::getNoSerie(){ 
	return noSerie; 
}
string Videojuego::getNombre(){ 
	return nombre; 
}
float Videojuego::getPrecio(){ 
	return precio; 
}
string Videojuego::getClasificacion(){ 
	return clasificacion; 
}
string Videojuego::getPlataforma(){ 
	return plataforma; 
}


Videojuego* Videojuego::clonar(){}
void Videojuego::Concepcion(){}
void Videojuego::Diseño(){}
void Videojuego::Planificacion(){}
void Videojuego::Produccion(){}
void Videojuego::Pruebas(){}

bool Videojuego::operator < (const Videojuego &tmp) const
{
	if (precio < tmp.precio)
		return true;
	else
		return false;
}
///////////////////////////////////////////////////////////////

Inventario* Inventario::Instance = NULL;
unsigned Inventario::NewSN = 1;


Inventario::Inventario(){}
Inventario* Inventario::crear()
{
	if (Instance == NULL)
	{
		Instance = new Inventario;
	}
	return Instance;
}

void Inventario::agregarJuego(string _nombre, float precio, string clasificacion, string plataforma)
{
	string nombre;
	float precio;
	string clasificacion;
	string plataforma;

	cout << endl << "Nombre del juego: ";
	cin >> nombre;
	cout << endl << "Precio del juego: ";
	cin >> precio;
	cout << endl << "Clasificacion del juego (E,T,M,Ao):  ";
	cin >> clasificacion;
	cout << endl << "Plataforma del juego: ";
	cin >> plataforma;
	Inventario->agregarVideojuego(nombre, precio, clasificacion, plataforma);
	NewSN++;
	gameList.push_back(nombre, precio, clasificacion, plataforma);
}

void Inventario::eliminarJuego(int noSerie)
{
	for (unsigned i = 0; i<gameList.size(); i++)
	{
		if (noSerie == gameList[i].getNoSerie())
		{
			Eliminacion.push(gameList[i]);
			gameList.erase(gameList.begin() + i);
		}
	}
}

void Inventario::ordenar(bool menorAmayor)
{


}

Videojuego Inventario::buscar(int noSerie)
{
	for (unsigned i = 0; i<gameList.size(); i++)
	{
		if (noSerie == gameList[i].getNoSerie())
			return gameList[i];
	}
}

void Inventario::undo()
{

}

void Inventario::printAll()
{
	for (unsigned i = 0; i<gameList.size(); i++)
	{
		cout << gameList[i].getNoSerie() << " " << gameList[i].getNombre() << " " << gameList[i].getPrecio() << " " << gameList[i].getClasificacion() << " " << gameList[i].getPlataforma() << endl;
	}
	cout << endl;
}

unsigned Inventario::getAllItems()
{
	return gameList.size();
}
///////////////////////////////////////////////////////////////

int main()
{
	string op;
	cout << " || Chell A.S. || " << endl;
	cout << "Elija una opcion:" << endl;
	cout << "a) Agregar videojuego" << endl;
	cout << "b) Eliminar videojuego" << endl;
	cout << "c) Buscar videojuego" << endl;
	cout << "d) Ordenar inventario" << endl;
	cout << "e) Desplegar todo el invemtario" << endl;
	cout << "f) Ver tamaño de invetario" << endl;
	cout << "c) Re-hacer una opcion" << endl;
	cout << endl << "Seleccion: ";
	cin >> op;
	cout << endl;
	return 0;
}