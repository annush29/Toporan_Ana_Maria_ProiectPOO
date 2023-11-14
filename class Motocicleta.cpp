#include<iostream>
#include<string>
#pragma warning (disable:4996)
using namespace std;

//domeniul MIJLOC TRANSPORT


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

	//operator =
	Motocicleta& operator=(const Motocicleta& sursa)
	{
		delete[]this->numeProprietar;

		this->numeProprietar = new char[strlen(sursa.numeProprietar) + 1];
		strcpy(this->numeProprietar, sursa.numeProprietar);
		this->pret = sursa.pret;
		this->modelMotocicleta = sursa.modelMotocicleta;
		this->capacitateCilindrica = sursa.capacitateCilindrica;
	
		return*this;
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

	//functie friend operator <<
	friend ostream& operator<<(ostream& out, const Motocicleta& sursa)
	{
		out << "Nume proprietar: " << sursa.numeProprietar << endl;
		out << "Pretul este: " << sursa.pret << endl;
		out << "Model motocicleta: " << sursa.modelMotocicleta << endl;
		out << "Capacitate cilindrica: " << sursa.capacitateCilindrica <<endl;
		return out;
	}

	//operator >>
	friend istream& operator>>(istream& in, Motocicleta& sursa)
	{
		if (sursa.numeProprietar != NULL)
		{
			delete[]sursa.numeProprietar;
		}

		cout << "Numele proprietarului este: ";
		char aux[100];
		in >> aux;
		sursa.numeProprietar = new char[strlen(aux) + 1];
		strcpy(sursa.numeProprietar, aux);

		cout << endl;

		cout << "Pretul este: ";
		in >> sursa.pret;

		cout << endl;

		cout << "Modelul motocicletei este: ";
		in >> sursa.modelMotocicleta;

		cout << endl;

		cout << "Are capacitatea cilindrica de: ";
		in >> sursa.capacitateCilindrica;

		return in;
	}

	//operator ==
	bool operator ==(const Motocicleta& sursa)
	{
		return string(modelMotocicleta) == string(sursa.modelMotocicleta) && pret == sursa.pret && capacitateCilindrica == sursa.capacitateCilindrica;
	}

	//operator <
	bool operator<(const Motocicleta& sursa)
	{
		if (this->pret < sursa.pret)
		{
			return 1;
		}
		else
		{
			return 0;
		}
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


void main()
{

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
	cout << "Valoarea pentru casca obligatorie este: " << valoare << endl;

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

	//apel operator =
	m = m1;

	//apel functie friend operator <<
	cout << m1 << m2;

	//apel operator >>
	cout << m1;
	cin >> m1;

	//apel operator ==
	if (m1 == m2)
	{
		cout << "Motocicletele sunt identice!" << endl;
	}
	else
	{
		cout << "Motocicletele sunt diferite!" << endl;
	}

	//apel operator <
	if (m1 == m2)
	{
		cout << "M1 este mai scumpa decat M2!" << endl;
	}
	else
	{
		cout << "M1 este mai ieftina decat M2!" << endl;
	}

	//vector static
	Motocicleta vectorStatic[100];
	int nr;
	cout << "Numarul de motociclete este: ";
	cin >> nr;
	for (int i = 0; i < nr; i++)
	{
		cin >> vectorStatic[i];
	}
	for (int i = 0; i < nr; i++)
	{
		cout << vectorStatic[i];
	}
}