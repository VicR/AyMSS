#include<iostream>

using namespace std;

class Visitor;
class Number {
public:
	virtual void accept(Visitor*) = 0;
};

class Integer : public Number {
public:
	static int countInts;
	void accept(Visitor*);
};
int Integer::countInts = 0;

class Double : public Number {
public:
	static int countDouble;
	void accept(Visitor*);
};
int Double::countDouble = 0;

class Visitor {
public:
	virtual void visit(Integer*) = 0;
	virtual void visit(Double*) = 0;

	template <class T>
	static Visitor* getInst()
	{
		static T instance;
		return &instance;
	}
};

class CountVisitor : public Visitor {
public:
	void visit(Integer* i)
	{
		cout << Integer::countInts;
	}
	void visit(Double* i)
	{
		cout << Double::countDouble;
	}
};

class AddVisitor : public Visitor {
public:
	void visit(Integer*)
	{
		Integer::countInts++;
	}
	void visit(Double*)
	{
		Double::countDouble++;
	}
};

void Double::accept(Visitor* v)
{
	v->visit(this);
}

void Integer::accept(Visitor* v)
{
	v->visit(this);
}

int main()
{
	AddVisitor a;
	CountVisitor c;

	Number* n[] = { new Integer, new Double };

	for (int i = 0; i< 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			n[j]->accept(&a);
		}
	}

	n[0]->accept(&c);
	n[1]->accept(&c);
}