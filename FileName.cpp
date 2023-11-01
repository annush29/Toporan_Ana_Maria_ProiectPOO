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


class Motocicleta
{
private:
	char* numeProprietar;
	float pret;
	string modelMotocicleta;
	int capacitateCilindrica;
	const string tipVehicul;
	static bool cascaObligatorie;

public:

	//constructor fara parametrii
	Motocicleta() :tipVehicul("na")
	{
		this->numeProprietar = new char[strlen("na") + 1];
		strcpy(this->numeProprietar, "na");
		this->pret = 300;//l am initializat cu suma aceasta ca sa nu imi dea rezultatul functiei globale cu minus
		this->modelMotocicleta = 'na';
		this->capacitateCilindrica = 0;
	}

	//constructor cu toti parametrii
	Motocicleta(const char* nume, float pret, string model, int capacitate, string tip) :tipVehicul(tip)
	{
		this->numeProprietar = new char[strlen(nume) + 1];
		strcpy(this->numeProprietar, nume);
		this->pret = pret;
		this->modelMotocicleta = model;
		this->capacitateCilindrica = capacitate;
	}

	//constructor cu o parte din parametrii
	Motocicleta(const char* nume, float pret, int capacitate, string tip) :tipVehicul(tip)
	{
		this->numeProprietar = new char[strlen(nume) + 1];
		strcpy(this->numeProprietar, nume);
		this->pret = pret;
		this->capacitateCilindrica = capacitate;
	}

	//constructor de copiere
	Motocicleta(const Motocicleta& sursa) :tipVehicul(sursa.tipVehicul)
	{
		this->numeProprietar = new char[strlen(sursa.numeProprietar) + 1];
		strcpy(this->numeProprietar, sursa.numeProprietar);
		this->pret = sursa.pret;
		this->modelMotocicleta = sursa.modelMotocicleta;
		this->capacitateCilindrica = sursa.capacitateCilindrica;
	}

	//geteri
	char* getNumeProprietar()
	{
		return this->numeProprietar;
	}

	float getPret()
	{
		return this->pret;
	}

	string getModelMotocicleta()
	{
		return this->modelMotocicleta;
	}

	int getCapacitateCilindrica()
	{
		return this->capacitateCilindrica;
	}

	//seteri
	void setNumeProprietar(const char* nume)
	{
		if (strlen(nume) > 2)
		{
			delete[]this->numeProprietar;
			this->numeProprietar = new char[strlen(nume) + 1];
			strcpy(this->numeProprietar, nume);
		}
	}

	void setPret(float pret)
	{
		if (pret != 0)
		{
			this->pret = pret;
		}
	}

	void setModelMotocicleta(string model)
	{
		if (model.length() > 2)
		{
			this->modelMotocicleta = model;
		}
	}

	void setCapacitateCilindrica(int capacitate)
	{
		if (capacitate != 0)
		{
			this->capacitateCilindrica = capacitate;
		}
	}

	//functii statice de acces
	static bool getCascaObligatorie()
	{
		return cascaObligatorie;
	}

	//functii statice de calcul
	static bool necesitaCasca(int capacitateCilindrica)
	{
		return capacitateCilindrica > 50;
	}

	//destructor
	~Motocicleta()
	{
		delete[]this->numeProprietar;
	}

	friend void reducerePret(Motocicleta sursa, float sumaRed);
};

//initializare atribut static
bool Motocicleta::cascaObligatorie = true;

//functii globale pentru reducere a pretului unei motociclete
void reducerePret(Motocicleta  sursa, float sumaRed)
{
	sursa.pret -= sumaRed;
	cout << "Pretul nou al motocicletei este " << sursa.pret << endl;
}

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
		this->pretBilet= NULL;
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

	//Clasa Motocicleta

	Motocicleta m;

	//geteri
	cout << m.getNumeProprietar() << endl;
	cout << m.getPret() << endl;
	cout << m.getModelMotocicleta() << endl;
	cout << m.getCapacitateCilindrica() << endl;

	//seteri
	m.setNumeProprietar("Andrei");
	m.setPret(700);
	m.setModelMotocicleta("Yahama");
	m.setCapacitateCilindrica(200);

	Motocicleta m1("Radu", 4000, "nou", 200, "uzat");

	//geteri
	cout << m1.getNumeProprietar() << endl;
	cout << m1.getPret() << endl;
	cout << m1.getModelMotocicleta() << endl;
	cout << m1.getCapacitateCilindrica() << endl;

	//seteri
	m1.setNumeProprietar("Ion");
	m1.setPret(2500);
	m1.setModelMotocicleta("Jiu");
	m1.setCapacitateCilindrica(100);

	Motocicleta m2("Maria", 6000, 400, "nou");

	//geteri
	cout << m2.getNumeProprietar() << endl;
	cout << m2.getPret() << endl;
	cout << m2.getModelMotocicleta();
	cout << m2.getCapacitateCilindrica() << endl;

	//seteri
	m2.setNumeProprietar("Popescu");
	m2.setPret(3000);
	m2.setModelMotocicleta("Suzuki");
	m2.setCapacitateCilindrica(150);

	Motocicleta m3(m1);
	
	//geteri
	cout << m3.getNumeProprietar() << endl;
	cout << m3.getPret() << endl;
	cout << m3.getModelMotocicleta() << endl;
	cout << m3.getCapacitateCilindrica() << endl;

	//functii statice de acces
	int valoare = Motocicleta::getCascaObligatorie();
	cout << "Valoarea pentru casca obligatorie este: " << valoare <<endl;

	//functii statice de calcul
	if (Motocicleta::necesitaCasca(200))
	{
		cout << "Pentru o motocicleta de 200, casca este obligatorie" << endl;
	}
	else
	{
		cout << "Pentru o motocicleta de 200, casca nu este obligatorie" << endl;
	}

	//functii globale pentru reducere a pretului unei motociclete
	Motocicleta sursa;
	reducerePret(sursa, 150);

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
}