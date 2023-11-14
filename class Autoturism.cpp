#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;

//domeniul MIJLOC TRANSPORT

class Autoturism
{
private:
	char* marca;
	int anFabricatie;
	string culoare;
	const int numarRoti;
	static int numarTotalAutoturisme;

public:
	//constructor fara parametrii
	Autoturism() :numarRoti(4)
	{
		this->marca = new char[strlen("na") + 1];
		strcpy(this->marca, "na");
		this->anFabricatie = 0;
		this->culoare = 'na';
	}

	//constructor cu toti parametrii
	Autoturism(const char* marca, int anFab, string cul, int nrRoti) :numarRoti(nrRoti)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		this->anFabricatie = anFab;
		this->culoare = cul;
	}

	//constructor cu o parte din parametrii
	Autoturism(int anFab, string cul, int nrRoti) :numarRoti(nrRoti)
	{
		this->marca = new char[strlen("na") + 1];
		strcpy(this->marca, "na");
		this->anFabricatie = anFab;
		this->culoare = cul;
	}

	//constructor de copiere
	Autoturism(const Autoturism& sursa) :numarRoti(sursa.numarRoti)
	{
		this->marca = new char[strlen(sursa.marca) + 1];
		strcpy(this->marca, sursa.marca);
		this->anFabricatie = sursa.anFabricatie;
		this->culoare = sursa.culoare;
	}

	//operator =
	Autoturism &operator=(const Autoturism &sursa)
	{
		delete[]this->marca;
		
		this->marca = new char[strlen(sursa.marca) + 1];
		strcpy(this->marca, sursa.marca);
		this->anFabricatie = sursa.anFabricatie;
		this->culoare = sursa.culoare;
	
		return*this;
	}
	

	//geteri
	char* getMarca()
	{
		return this->marca;
	}

	int getanFabricatie()
	{
		return this->anFabricatie;
	}

	string getCuloare()
	{
		return this->culoare;
	}

	//seteri
	void setMarca(const char* marca)
	{
		if (strlen(marca) > 2)
		{
			delete[]this->marca;
			this->marca = new char[strlen(marca) + 1];
			strcpy(this->marca, marca);
		}
	}

	void setanFabricatie(int anFab)
	{
		if (anFab != 0)
		{
			this->anFabricatie = anFab;
		}
	}

	void setCuloare(string cul)
	{
		if (cul.length() > 2)
		{
			this->culoare = cul;
		}
	}

	//functii statice de acces
	static int getNumarTotalAutoturisme()
	{
		return numarTotalAutoturisme;
	}

	static void setNumarTotalAutoturisme(int nr)
	{
		if (nr > 0)
		{
			numarTotalAutoturisme = nr;
		}
	}

	//functii statice de calcul
	static bool esteVechi(int anFabricatie)
	{
		return 2023 - anFabricatie > 25;
	}

	//functie friend operator <<
	friend ostream& operator<<(ostream& out, const Autoturism& sursa)
	{
		out << "Marca este: " << sursa.marca << endl;
		out << "Anul fabricatiei este: " << sursa.anFabricatie << endl;
		out << "Culoarea este: " << sursa.culoare << endl;

		return out;
	}

	//operatorul pentru comparatie ==
	bool operator==(const Autoturism& sursa)
	{
		return string(marca) == string(sursa.marca) && anFabricatie == sursa.anFabricatie && culoare == sursa.culoare;
	}
	
	//operator <
	bool operator<(const Autoturism& sursa)
	{
		if (this->anFabricatie < sursa.anFabricatie)
		{
			return 1;//true
		}
		else
		{
			return 0;//false
		}
	}

	//operator >>
	friend istream& operator>>(istream& in, Autoturism& sursa)
	{
		if (sursa.marca != NULL)
		{
			delete[]sursa.marca;
		}

		cout << "Marca este: ";
		char aux[100];
		in >> aux;
		sursa.marca = new char[strlen(aux) + 1];
		strcpy(sursa.marca, aux);
		
		cout << endl;

		cout << "Anul fabricatiei este: ";
		in >> sursa.anFabricatie;

		cout << endl;

		cout << "Culoarea autoturism este: ";
		in >> sursa.culoare;

		cout << endl;

		return in;
	}

	//destructor
	~Autoturism()
	{
		delete[]this->marca;
	}

	friend void afisare(Autoturism sursa);
};

//initializare atribut static
int Autoturism::numarTotalAutoturisme = 0;

//functii globale pentru afisarea in consola a anumitor atribute
void afisare(Autoturism sursa)
{
	cout << "Marca: " << sursa.marca << endl;
	cout << "An fabricatie: " << sursa.anFabricatie << endl;
}

void main()
{
	//Clasa autoturism

	Autoturism a;

	//geteri
	cout << a.getMarca() << endl;
	cout << a.getanFabricatie() << endl;
	cout << a.getCuloare() << endl;

	//seteri
	a.setMarca("Dacia");
	a.setanFabricatie(2001);
	a.setCuloare("roz");

	Autoturism a1("Honda", 2010, "rosie", 4);

	//geteri
	cout << a1.getMarca() << endl;
	cout << a1.getanFabricatie() << endl;
	cout << a1.getCuloare() << endl;

	//seteri
	a1.setMarca("Volvo");
	a1.setanFabricatie(2008);
	a1.setCuloare("alb");

	Autoturism a2(2008, "albastra", 4);

	//geteri
	cout << a2.getMarca() << endl;
	cout << a2.getanFabricatie() << endl;
	cout << a2.getCuloare() << endl;

	//seteri
	a2.setMarca("Lambo");
	a2.setanFabricatie(2004);
	a2.setCuloare("verde");

	//apel constructor de copiere
	Autoturism a3(a1);

	//geteri
	cout << a3.getMarca() << endl;
	cout << a3.getanFabricatie() << endl;
	cout << a3.getCuloare() << endl;

	//seteri
	a3.setMarca("Bentley");
	a3.setanFabricatie(2012);
	a3.setCuloare("gri");

	//functii statice de acces
	int total = Autoturism::getNumarTotalAutoturisme();
	cout << "Numar total autoturisme: " << total << endl;
	Autoturism::setNumarTotalAutoturisme(10);
	total = Autoturism::getNumarTotalAutoturisme();
	cout << "Numar total autoturisme dupa setarea unui numar: " << total << endl;

	//functii statice de calcul
	if (Autoturism::esteVechi(1990))
	{
		cout << "Autoturismul din 1990 este vechi" << endl;
	}
	else
	{
		cout << "Autoturismul din 1990 nu este vechi" << endl;
	}

	//functii globale pentru afisarea in consola a anumitor atribute
	afisare(a1);
	afisare(a2);

	//apel operator =
	a = a1;

	//apel functie friend operator <<
	cout << a1 << a2;

	//apel operatorul pentru comparatie ==
	if (a1 == a2)
	{
		cout << "Autoturismele sunt identice" << endl;
	}
	else
	{
		cout << "Autoturismele sunt diferite" << endl;
	}
	
	//apel operator <
	if (a1 < a2)
	
		{
			cout << "A1 este mai vechi decat a2" << endl;
		}
	else
	{
		cout << "A1 este mai nou decat A2" << endl;
	}

	//apel operator >>
	cout << a1;
	cin >> a1;

	//vector dinamic
	Autoturism* vectorDinamic;
	int nrAutoturisme;
	cout << "Numarul de autoturisme este: ";
	cin >> nrAutoturisme;
	vectorDinamic = new Autoturism[nrAutoturisme];
	for (int i = 0; i < nrAutoturisme; i++)
	{
		cin >> vectorDinamic[i];
	}
	for (int i = 0; i < nrAutoturisme; i++)
	{
		cout << vectorDinamic[i];
	}
	delete[]vectorDinamic;
	//matrice statica de 4 pe 4
Autoturism matrice[4][4];
for (int i = 0; i < 4; i++)
{
	for (int j = 0; j < 4; j++)
	{
		cin >> matrice[i][j];
	}
}
for (int i = 0; i < 4; i++)
{
	for (int j = 0; j < 4; j++)
	{
		cout<< matrice[i][j];
	}
}
}
