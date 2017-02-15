#include <string>
#include <iostream>
using namespace std;

class Videojuego{
private:
	int noSerie;
	string nombre;
	float precio;
	string clasificacion;
	string plataforma;

public:
	Videojuego();
	Videojuego(int noSerie, string nombre, float precio, string clasificacion, string plataforma);

	int getNoSerie();
	string getNombre();
	float getPrecio();
	string getClasificacion();
	string getPlataforma();
	virtual Videojuego* clonar() = 0;
	virtual void Concepcion() = 0;
	virtual void Diseño() = 0;
	virtual void Planificacion() = 0;
	virtual void Produccion() = 0;
	virtual void Pruebas() = 0;
	bool operator < (const Videojuego &otro) const;


	template<class Tipo>
	static Videojuego* factoryMethod()
	{
		return new Tipo;
	}
};


template <class Tipo>
class ClonVideojuego :public Videojuego
{
public:
	virtual Videojuego* clonar()
	{
		return new Tipo(dynamic_cast<Tipo&>(*this));
	}
};
//////////////////////////////////////////////////////
class Estrategia : public ClonVideojuego<Estrategia>{
public:
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

class Aventura : public ClonVideojuego<Aventura>{
public:
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

class Aprendizaje : public ClonVideojuego<Aprendizaje>{
public:
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