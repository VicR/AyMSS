//Víctor Rendón Suárez | A01022462
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Asteroid;
class Planet;

class Spacecraft{
protected:
	string SCraftType;
	Spacecraft()
	{
		instance = this;
	}
	static Spacecraft* instance;

public:
	template <class T>
	static T* getInstance()
	{
		if (T::instance == NULL)
		{
			T* n = new T();
		}
		return T::instance;
	}
	string getSCraftType()
	{
		return SCraftType;
	}
	void SCxAsteroid(Asteroid* p);
	void SCxPlanet(Planet* p);
	virtual Spacecraft* clonar() = 0;
};
Spacecraft* Spacecraft::instance = 0;

template <class SubClase>
class ClonSpacecraft : public Spacecraft
{
public:
	virtual Spacecraft* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class PlanetExShip : public ClonSpacecraft<PlanetExShip>{
protected:
	friend class Spacecraft;
	PlanetExShip()
	{
		instance = this;
		SCraftType = "Exploration Ship (Spacecraft)";
	}
	static PlanetExShip* instance;
};
PlanetExShip* PlanetExShip::instance = 0;

class ColonizationShip : public ClonSpacecraft<ColonizationShip>{
protected:
	friend class Spacecraft;
	ColonizationShip()
	{
		instance = this;
		SCraftType = "Colonization Ship (Spacecraft)";
	}
	static ColonizationShip* instance;
};
ColonizationShip* ColonizationShip::instance = 0;

class PlanetOvShip : public ClonSpacecraft<PlanetOvShip>{
protected:
	friend class Spacecraft;
	PlanetOvShip()
	{
		instance = this;
		SCraftType = "Observation Ship (Spacecraft)";
	}
	static PlanetOvShip* instance;
};
PlanetOvShip* PlanetOvShip::instance = 0;


class Asteroid{
protected:
	string AsteroidType;
	Asteroid()
	{
		instance = this;
	}
	static Asteroid* instance;

public:
	template <class T>
	static T* getInstance()
	{
		if (T::instance == NULL)
		{
			T* n = new T();
		}
		return T::instance;
	}
	string getAsteroidType()
	{
		return AsteroidType;
	}
	void PlanetxAsteroid(Planet* p);
	void AsteroidCollision(Spacecraft* d)
	{
		cout << d->getSCraftType() << " collided with " << AsteroidType << endl;;
	}
};
Asteroid* Asteroid::instance = 0;

template <class SubClase>
class ClonAsteroid : public Asteroid
{
public:
	virtual Asteroid* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class StonyMet : public ClonAsteroid<StonyMet>{
protected:
	friend class Asteroid;
	StonyMet()
	{
		instance = this;
		AsteroidType = "Stony Meteorite (Asteroid)";
	}
	static StonyMet* instance;
};
StonyMet* StonyMet::instance = 0;

class IronMet : public ClonAsteroid<IronMet>{
protected:
	friend class Asteroid;
	IronMet()
	{
		instance = this;
		AsteroidType = "Iron Meteorite (Asteroid)";
	}
	static IronMet* instance;
};
IronMet* IronMet::instance = 0;

void Spacecraft::SCxAsteroid(Asteroid* p)
{
	p->AsteroidCollision(this);
}


class Planet{
protected:
	string PlanetType;
	Planet()
	{
		instance = this;
	}
	static Planet* instance;

public:
	template <class T>
	static T* getInstance()
	{
		if (T::instance == NULL)
		{
			T* n = new T();
		}
		return T::instance;
	}
	string getPlanetType()
	{
		return PlanetType;
	}
	void PlanetCollision(Spacecraft* d)
	{
		cout << d->getSCraftType() << " collided with " << PlanetType << endl;;
	}
	void AstroPlanetCollision(Asteroid* a)
	{
		cout << a->getAsteroidType() << " collided with " << PlanetType << endl;;
	}
};
Planet* Planet::instance = 0;

template <class SubClase>
class ClonPlanet : public Planet
{
public:
	virtual Planet* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class DesertPlanet : public ClonPlanet<DesertPlanet>{
protected:
	friend class Planet;
	DesertPlanet()
	{
		instance = this;
		PlanetType = "Desert Planet";
	}
	static DesertPlanet* instance;
};
DesertPlanet* DesertPlanet::instance = 0;

class EarthAnalog : public ClonPlanet<EarthAnalog>{
protected:
	friend class Planet;
	EarthAnalog()
	{
		instance = this;
		PlanetType = "Earth Analog Planet";
	}
	static EarthAnalog* instance;
};
EarthAnalog* EarthAnalog::instance = 0;

void Spacecraft::SCxPlanet(Planet* p)
{
	p->PlanetCollision(this);
}
void Asteroid::PlanetxAsteroid(Planet* p)
{
	p->AstroPlanetCollision(this);
}

int main()
{
	vector<Spacecraft*> countSCrafts;
	countSCrafts.push_back(Spacecraft::getInstance<PlanetExShip>());
	countSCrafts.push_back(Spacecraft::getInstance<ColonizationShip>());
	countSCrafts.push_back(Spacecraft::getInstance<PlanetOvShip>());


	vector<Asteroid*> countAsteroids;
	countAsteroids.push_back(Asteroid::getInstance<StonyMet>());
	countAsteroids.push_back(Asteroid::getInstance<IronMet>());

	vector<Planet*> countPlanets;
	countPlanets.push_back(Planet::getInstance<DesertPlanet>());
	countPlanets.push_back(Planet::getInstance<EarthAnalog>());

	for (int i = 0; i < countSCrafts.size(); i++)
	{
		for (int j = 0; j < countAsteroids.size(); j++)
		{
			countSCrafts.at(i)->SCxAsteroid(countAsteroids.at(j));
		}
	}

	for (int i = 0; i < countSCrafts.size(); i++)
	{
		for (int j = 0; j < countPlanets.size(); j++)
		{
			countSCrafts.at(i)->SCxPlanet(countPlanets.at(j));
		}
	}

	for (int i = 0; i < countAsteroids.size(); i++)
	{
		for (int j = 0; j < countPlanets.size(); j++)
		{
			countAsteroids.at(i)->PlanetxAsteroid(countPlanets.at(j));
		}
	}
}