#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;

//domeniul MIJLOC TRANSPORT

class Tren
{
private:
	string companieFeroviara;
	int nrVagoane;
	int nrBileteDisponibile;
	float* pretBilet;
	const float lungimeStandardVagon;
	static int vitezaMaximaStandard;

public:
	//constructor fara parametrii
	Tren() :lungimeStandardVagon(0)
	{
		this->companieFeroviara = 'na';
		this->nrVagoane = 0;
		this->nrBileteDisponibile = 0;
		this->pretBilet = NULL;
	}

	//constructor cu toti parametrii
	Tren(string comp, int nrVag, int nrBilete, float* pret, float lung) :lungimeStandardVagon(lung)
	{
		this->companieFeroviara = comp;
		this->nrVagoane = nrVag;
		this->nrBileteDisponibile = nrBilete;
		this->pretBilet = new float[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->pretBilet[i] = pret[i];
		}
	}

	//constructor cu o parte din parametrii
	Tren(string comp, int nrVag, float lung) :lungimeStandardVagon(lung)
	{
		this->companieFeroviara = comp;
		this->nrVagoane = nrVag;
		this->nrBileteDisponibile = 0;
		this->pretBilet = NULL;
	}

	//constructor de copiere
	Tren(const Tren& sursa) :lungimeStandardVagon(sursa.lungimeStandardVagon)
	{
		this->companieFeroviara = sursa.companieFeroviara;
		this->nrVagoane = sursa.nrVagoane;
		this->nrBileteDisponibile = sursa.nrBileteDisponibile;
		this->pretBilet = new float[sursa.nrBileteDisponibile];
		for (int i = 0; i < sursa.nrBileteDisponibile; i++)
		{
			this->pretBilet[i] = sursa.pretBilet[i];
		}
	}

	//operator =
	Tren& operator=(const Tren& sursa)
	{
		delete[]this->pretBilet;

		this->companieFeroviara = sursa.companieFeroviara;
		this->nrVagoane = sursa.nrVagoane;
		this->nrBileteDisponibile = sursa.nrBileteDisponibile;
		this->pretBilet = new float[sursa.nrBileteDisponibile];
		for (int i = 0; i < sursa.nrBileteDisponibile; i++)
		{
			this->pretBilet[i] = sursa.pretBilet[i];
		}

		return*this;
	}

	//geteri
	string getCompanieFeroviara()
	{
		return this->companieFeroviara;
	}

	int getNrVagoane()
	{
		return this->nrVagoane;
	}

	int getNrBileteDisponibile()
	{
		return this->nrBileteDisponibile;
	}

	float* getPretBilet()
	{
		return this->pretBilet;
	}

	//seteri
	void setCompanieFeroviara(string companie)
	{
		if (companie.length() > 2)
		{
			this->companieFeroviara = companie;
		}
	}

	void setNrVagoane(int nr)
	{
		if (nr > 2)
		{
			this->nrVagoane = nr;
		}
	}

	void setNrBileteDisponibile(int nrBil, float* pret)
	{
		if (nrBil > 0)
		{
			delete[]this->pretBilet;
			this->nrBileteDisponibile = nrBil;
			this->pretBilet = new float[nrBil];
			for (int i = 0; i < nrBil; i++)
			{
				this->pretBilet[i] = pret[i];
			}
		}
	}

	//functii statice de acces
	static int getVitezaStandard()
	{
		return vitezaMaximaStandard;
	}

	static void setVitezaStandard(int viteza)
	{
		if (viteza > 0)
		{
			vitezaMaximaStandard = viteza;
		}
	}

	//functii statice de calcul
	static bool suntBileteDisponibile(int nrBileteDisponibile)
	{
		return nrBileteDisponibile <= vitezaMaximaStandard;//presupun ca numarul max de bilete vandudte = cu vit max standard
	}

	//functie friend operator <<
	friend ostream& operator<<(ostream& out, const Tren& sursa)
	{
		string companieFeroviara;
		int nrVagoane;
		int nrBileteDisponibile;
		float* pretBilet;
		out << "Companie feroviara: " << sursa.companieFeroviara << endl;
		out << "Numarul de vagoane este: " << sursa.nrVagoane << endl;
		out << "Numar bilete disponibile este: " << sursa.nrBileteDisponibile << endl;
		out << "Pretul biletului este de: ";
		for (int i = 0; i < sursa.nrBileteDisponibile; i++)
		{
			out << sursa.pretBilet[i] << " ";
		}
		out << endl;

		return out;
	}

	//operator >>
	friend istream& operator>>(istream& in, Tren& sursa)
	{
		delete[]sursa.pretBilet;
		cout << "Numar bilete disponibile: ";
		in >> sursa.nrBileteDisponibile;

		sursa.pretBilet = new float[sursa.nrBileteDisponibile];
		for (int i = 0; i < sursa.nrBileteDisponibile; i++)
		{
			cout << "Pret: ";
			in >> sursa.pretBilet[i];
		}
		cout << "Compania feroviara de care apartine trenul este: ";
		in >> sursa.companieFeroviara;

		cout << "Numarul de vagoane este de: ";
		in >> sursa.nrVagoane;
		return in;
	}

	//operatorul cast pentru a calcula cate bilete au pretul peste 10 lei
	explicit operator int()
	{
		int contor = 0;
		for (int i = 0; i < this->nrBileteDisponibile; i++)
		{
			if (this->pretBilet[i] > 10)
			{
				contor++;
			}
		}
		return contor;
	}

	//operator ==
	bool operator ==(const Tren& sursa)
	{
		return (companieFeroviara == sursa.companieFeroviara) && (nrVagoane == sursa.nrVagoane);
	}

	//destructor
	~Tren()
	{
		delete[]this->pretBilet;
	}
};

//initializare functie statica
int Tren::vitezaMaximaStandard = 120;

void main()
{
	//Clasa Tren

	Tren t;

	//geteri
	cout << t.getCompanieFeroviara() << endl;
	cout << t.getNrVagoane() << endl;
	cout << t.getNrBileteDisponibile() << endl;
	for (int i = 0; i < t.getNrBileteDisponibile(); i++)
	{
		cout << t.getPretBilet()[i] << endl;

	}

	//seteri
	t.setCompanieFeroviara("RTG");
	t.setNrVagoane(30);
	t.setNrBileteDisponibile(2, new float[2] {12, 50});

	Tren t1("CFR", 100, 3, new float[3] {12, 23, 45}, 10);

	//geteri
	cout << t1.getCompanieFeroviara() << endl;
	cout << t1.getNrVagoane() << endl;
	cout << t1.getNrBileteDisponibile() << endl;
	for (int i = 0; i < t1.getNrBileteDisponibile(); i++)
	{
		cout << t1.getPretBilet()[i] << endl;

	}

	//seteri
	t1.setCompanieFeroviara("OIL");
	t1.setNrVagoane(50);
	t1.setNrBileteDisponibile(3, new float[3] {34, 90, 10});

	Tren t2("TGA", 10, 6);

	//geteri
	cout << t2.getCompanieFeroviara() << endl;
	cout << t2.getNrVagoane() << endl;
	cout << t2.getNrBileteDisponibile() << endl;
	for (int i = 0; i < t2.getNrBileteDisponibile(); i++)
	{
		cout << t2.getPretBilet()[i] << endl;

	}

	//seteri
	t2.setCompanieFeroviara("WPPW");
	t2.setNrVagoane(55);
	t2.setNrBileteDisponibile(4, new float[4] {12, 34, 11, 22});

	Tren t3(t1);

	//geteri
	cout << t3.getCompanieFeroviara() << endl;
	cout << t3.getNrVagoane() << endl;
	cout << t3.getNrBileteDisponibile() << endl;
	for (int i = 0; i < t3.getNrBileteDisponibile(); i++)
	{
		cout << t3.getPretBilet()[i] << endl;

	}

	//functii statice de acces
	int viteza = Tren::getVitezaStandard();
	cout << "Viteza maxima standard este: " << viteza << endl;
	Tren::setVitezaStandard(125);
	viteza = Tren::getVitezaStandard();
	cout << "Viteza maxima standard dupa setare: " << viteza << endl;

	//functii statice de calcul
	int nrBileteDiponibile = 50;
	if (Tren::suntBileteDisponibile(nrBileteDiponibile))
	{
		cout << "Sunt destule bilete" << endl;
	}
	else
	{
		cout << "Nu sunt destule bilete" << endl;
	}

	//apel operator =
	t = t1;

	//apel functie friend operator <<
	cout << t1 << t2;

	//apel operator cast
	cout << "Nr de bilete cu pretul peste 10 lei este: " << (int)t1;
	cout << endl;

	//apel operator >>
	cout << t1;
	cin >> t1;

	cout << endl;

	//apel operator ==
	if (t1 == t2)
	{
		cout << "T1 si T2 sunt egale" << endl;
	}
	else
	{
		cout << "T1 si T2 nu sunt egale" << endl;
	}

	//vector static
	Tren vectorStatic[100];
	int nr;
	cout << "Numarul de trenuri este: ";
	cin >> nr;
	for (int i = 0; i < nr; i++)
	{
		cin >> vectorStatic[i];
	}
	for (int i = 0; i < nr; i++)
	{
		cout<< vectorStatic[i];
	}
}