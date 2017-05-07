//Víctor Rendón S. | A01022462
#include <iostream>
using namespace std;

class Child
{
public:
	int* p;
	Child()
	{
		p = new int;
	}
	~Child()
	{
		delete p;
		p = NULL;
	}

	CopyConstChild(const Child &x)
	{
		p = x.p;
	}
};
int main ()
{
	Child a;
	Child b = a;
	*(a.p) = 5;
	cout << *(b.p);
	cout << *a.p << " " << *b.p << endl;
	delete &a;
	delete &b;
}