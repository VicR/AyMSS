#include <iostream>
#include <vector>
using namespace std;

class Subject {
	vector <class Observer *> subjList;
	string name;
	string phrase;
public:
	virtual void attach(Observer* obs) = 0;
	virtual void comment(string phrase) = 0;
	string getName() 
	{
		return name;
	}
	void notify();
};

void Subject::notify() 
{
	for (int i = 0; i < subjList.size(); i++)
		subjList[i]->update();
}

class PenaNieto : public Subject{
public:
	string name = "Enrique Pena Nieto";
};

class DonaldTrump : public Subject{
public:
	string name = "Donald Trump";
};

class Observer{
	Subject *name;
	string phrase;
public:
	Observer(Subject *nam, string phr) 
	{
		name = nam;
		phrase = phr;
		name->attach(this);
	}
	virtual void update() = 0;
protected:
	Subject *getSubject() 
	{
		return name;
	}
	string getPhrase() 
	{
		return phrase;
	}
};		

class RefObserver : public Observer{
public:
	void publicar();
	void update();
};
void RefObserver::publicar()
{
	cout << "Reforma reporta: " << endl;
	cout << subj.getName() << "dijo que " << subj->getPhrase() << endl;
}

class TelObserver : public Observer{
public:
	void publicar();
	void update();
};

class NBCObserver : public Observer{
public:
	void publicar();
	void update();
};

int main() {
	Subject subj;

}