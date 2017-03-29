//Víctor Rendón S. | A01022462
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Printer;
class Document{
protected:
	string docType;
	Document()
	{
		instance = this;
	}
	static Document* instance;

public:
	template <class T>
	static T* getInstance()
	{
		if (T::instance == NULL)
		{
			T();
			T* n = new T();
		}
		return T::instance;
	}
	string getDocType()
	{
		return docType;
	}
	void DocPrint(Printer* p);
};
Document* Document::instance = 0;

class SimpleDoc : public Document{
protected:
	friend class Document;
	SimpleDoc()
	{
		instance = this;
		docType = "Simple Document";
	}
	static SimpleDoc* instance;
};
SimpleDoc* SimpleDoc::instance = 0;

class FormatDoc : public Document{
protected:
	friend class Document;
		FormatDoc()
	{
		instance = this;
		docType = "Format Document";
	}
	static FormatDoc* instance;
};
FormatDoc* FormatDoc::instance = 0;

class ImageDoc : public Document{
protected:
	friend class Document;
		ImageDoc()
	{
		instance = this;
		docType = "Image Document";
	}
	static ImageDoc* instance;
};
ImageDoc* ImageDoc::instance = 0;

class PresCardDoc : public Document{
protected:
	friend class Document;
		PresCardDoc()
	{
		instance = this;
		docType = "Presentation Card Document";
	}
	static PresCardDoc* instance;
};
PresCardDoc* PresCardDoc::instance = 0;

//-------------------------------------------------------------

class Printer{
protected:
	string printerType;
	Printer()
	{
		instance = this;
	}
	static Printer* instance;

public:
	template <class T>
	static T* getInstance()
	{
		if (T::instance == NULL)
		{
			T();
			T* n = new T();
		}
		return T::instance;
	}
	void Print(Document* d)
	{
		cout << d->getDocType() << " was printed on " << printerType << endl;;
	}
};
Printer* Printer::instance = 0;

class LaserPrinter : public Printer{
protected:
	friend class Printer;
	LaserPrinter()
	{
		instance = this;
		printerType = "Laser Printer";
	}
	static LaserPrinter* instance;
};
LaserPrinter* LaserPrinter::instance = 0;

class InjectionPrinter : public Printer{
protected:
	friend class Printer;
	InjectionPrinter()
	{
		instance = this;
		printerType = "Injection Printer";
	}
	static InjectionPrinter* instance;
};
InjectionPrinter* InjectionPrinter::instance = 0;

class PDFPrinter : public Printer{
protected:
	friend class Printer;
	PDFPrinter()
	{
		instance = this;
		printerType = "PDF Printer";
	}
	static PDFPrinter* instance;
};
PDFPrinter* PDFPrinter::instance = 0;

class PostscriptPrinter : public Printer{
protected:
	friend class Printer;
	PostscriptPrinter()
	{
		instance = this;
		printerType = "Postscript Printer";
	}
	static PostscriptPrinter* instance;
};
PostscriptPrinter* PostscriptPrinter::instance = 0;

class PortablePrinter : public Printer{
protected:
	friend class Printer;
	PortablePrinter()
	{
		instance = this;
		printerType = "Portable Printer";
	}
	static PortablePrinter* instance;

};
PortablePrinter* PortablePrinter::instance = 0;

void Document::DocPrint(Printer* p)
{
	p->Print(this);
}

int main()
{
	vector<Document*> countDocs;
	countDocs.push_back(Document::getInstance<SimpleDoc>());
	countDocs.push_back(Document::getInstance<FormatDoc>());
	countDocs.push_back(Document::getInstance<ImageDoc>());
	countDocs.push_back(Document::getInstance<PresCardDoc>());

	vector<Printer*> countPrinters;
	countPrinters.push_back(Printer::getInstance<LaserPrinter>());
	countPrinters.push_back(Printer::getInstance<InjectionPrinter>());
	countPrinters.push_back(Printer::getInstance<PDFPrinter>());
	countPrinters.push_back(Printer::getInstance<PostscriptPrinter>());
	countPrinters.push_back(Printer::getInstance<PortablePrinter>());

	for (int i = 0; i < countDocs.size(); i++)
	{
		for (int j = 0; j < countPrinters.size(); j++)
		{
			countDocs.at(i)->DocPrint(countPrinters.at(j));
		}
	}
}