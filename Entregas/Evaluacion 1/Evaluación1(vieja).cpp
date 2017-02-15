//Víctor Rendón Suárez | A01022462
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Videojuego
{
private:
	int noSerie;
	string Nombre;
	int fechaCreacion;
	string clasificacion;
	int plataforma;

public:
	virtual Videojuego* clonar() = 0;
	virtual void Concepcion() = 0;
	virtual void Diseño () = 0;
	virtual void Planificacion() = 0;
	virtual void Produccion() = 0;
	virtual void Pruebas() = 0;
};
template <class SubClase>
class ClonVideojuego : public Videojuego
{
public:
	virtual Videojuego* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

template <class SubClase>
SubClase* factoryMethod(string nombre)
{
	SubClase* fm = new SubClase(nombre);
	fm->subClase::Concepcion;
	fm->subClase::Diseño;
	fm->subClase::Planificacion;
	fm->subClase::Produccion;
	fm->subClase::Pruebas;
	return fm;
}

class Estrategia : public ClonVideojuego<Estrategia>
{
public:
	Estrategia(string nombre)
	{
		name = nombre;
	}
	virtual void Concepcion()
	{
		cout << "Juego de estrategia en concepcion" << endl;
	}
	virtual void Diseño()
	{
		cout << "Juego de estrategia en diseño" << endl;
	}
	virtual void Planificacion()
	{
		cout << "Juego de estrategia en planificacion" << endl;
	}
	virtual void Produccion()
	{
		cout << "Juego de estrategia en produccion" << endl;
	}
	virtual void Pruebas()
	{
		cout << "Juego de estrategia en pruebas" << endl;
	}
};

class Aventura : public ClonVideojuego<Aventura>
{
public:
	Aventura(string nombre)
	{
		name = nombre;
	}
	virtual void Concepcion()
	{
		cout << "Juego de aventura en concepcion" << endl;
	}
	virtual void Diseño()
	{
		cout << "Juego de aventura en diseño" << endl;
	}
	virtual void Planificacion()
	{
		cout << "Juego de aventura en planificacion" << endl;
	}
	virtual void Produccion()
	{
		cout << "Juego de aventura en produccion" << endl;
	}
	virtual void Pruebas()
	{
		cout << "Juego de aventura en pruebas" << endl;
	}
};

class Aprendizaje : public ClonVideojuego<Aprendizaje>
{
private:

public:
	Aprendizaje(string nombre)
{
	name = nombre;
}
	virtual void Concepcion()
	{
		cout << "Juego de aprendizaje en concepcion" << endl;
	}
	virtual void Diseño()
	{
		cout << "Juego de aprendizaje en diseño" << endl;
	}
	virtual void Planificacion()
	{
		cout << "Juego de aprendizaje en planificacion" << endl;
	}
	virtual void Produccion()
	{
		cout << "Juego de aprendizaje en produccion" << endl;
	}
	virtual void Pruebas()
	{
		cout << "Juego de aprendizaje en pruebas" << endl;
	}
};

///////////////////////////////////////////////////////////////

class Inventario{
private:
	int totalItems;
	Inventario()
	{
		Instance = this;
	}
	static Inventario* Instance;

public:
	static Inventario* crear()
	{
		if (Instance == NULL)
		{
			Inventario();
			return Instance;
		}
		return Instance;
	}

	void agregarJuego();
	void eliminarJuego();
	void undo();
	void ordenar();
	void buscar();
	void printAll();
};

void agregarJuego(){

}
void eliminarJuego(){
	stack<string> undo;
	undo.push();
}
void undo(){
	cout << undo.top() << endl;
	undo.pop;
	cout << undo.top() << endl;
	undo.pop;
	cout << undo.top() << endl;
	undo.pop;
}
void ordenar(){

}
void buscar(){

}
void printAll(){

}

///////////////////////////////////////////////////////////////

int main()
{
	cout << " || Chell A.S. || " << endl;
	cout << "Elija una opcion:" << endl;
	cout << "a) Crear inventario" << endl;
	cout << "b) Crear videojuego" << endl;
	return 0;
}