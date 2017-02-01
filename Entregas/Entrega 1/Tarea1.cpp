//Víctor Rendón Suárez | A01022462
#include <iostream>
#include <string>
using namespace std;

class Personaje
{
public:
	virtual void correr() = 0;
	virtual Personaje* clonar() = 0;
};
template <class SubClase>
class ClonPersonaje : public Personaje
{
public:
	virtual Personaje* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

template <class SubClase>
SubClase* factoryMethod()
{
	return SubClase::crear();
}

class Principe : public ClonPersonaje<Principe>
{
private:
	Principe()
	{
		Instance = this;
	}
	static Principe* Instance;
public:
	static Principe* crear()
	{
		if (Instance == NULL)
		{
			Principe();
			return Instance;
		}
		return Instance;
	}
	void seleccionarArma();
	void atacar();
	void correr()
	{
		cout << "El principe corre rápido" << endl;
	}
};
Principe* Principe::Instance = 0;

class Princesa : public ClonPersonaje<Princesa>
{
private:
	Princesa()
	{
		Instance = this;
	}
	static Princesa* Instance;
public:
	static Princesa* crear()
	{
		if (Instance == NULL)
		{
			Princesa();
			return Instance;
		}
		return Instance;
	}
	void gritar();
	void correr()
	{
		cout << "La princesa corre medio lento" << endl;
	}
};
Princesa* Princesa::Instance = 0;

class Villano : public ClonPersonaje<Villano>
{
private:
	Villano()
	{
		Instance = this;
	}
	static Villano* Instance;
public:
	static Villano* crear()
	{
		if (Instance == NULL)
		{
			Villano();
			return Instance;
		}
		return Instance;
	}
	void atacar();
	void atraparPricnesa();
	void correr()
	{
		cout << "El villano no necesita correr" << endl;
	}
};
Villano* Villano::Instance = 0;

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
private:
	VillanoVolador()
	{
		Instance = this;
	}
	static VillanoVolador* Instance;
public:
	static VillanoVolador* crear()
	{
		if (Instance == NULL)
		{
			VillanoVolador();
			return Instance;
		}
		return Instance;
	}
	void correr()
	{
		cout << "También puede volar" << endl;
	}
};
VillanoVolador* VillanoVolador::Instance = 0;

int main()
{
	Villano* v = factoryMethod<Villano>();
	v->correr();
	Princesa* p = factoryMethod<Princesa>();
	p->correr();
	Principe* pri = factoryMethod<Principe>();
	pri->correr();

	return 1;
}