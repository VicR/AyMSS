#include <iostream>
using namespace std;
/*
class Hora {
	private:
		Hora();

	public:
		time_t hora;
};

int main()
{
	Hora hora1;
	time(&hora);
	cout << "Hora: " << ctt;
}*/

class Hora {
	private:
		Hora()
		{
			instance = this;
		}
		static Hora* instance;

	public:
		void getTime()
		{
			cout << instance << endl;
		};

		static Hora* getInstance()
		{
			if (instance != 0)
				return instance;
			else
				Hora();
			return instance;
			//////////////////
			//static Hora instance;
			//return &instance;
		}
};

Hora* Hora::instance = 0;

int main()
{
	Hora* h = Hora::getInstance();
	h->getTime();
	Hora* hh = Hora::getInstance();
	hh->getTime();
	delete h;
}