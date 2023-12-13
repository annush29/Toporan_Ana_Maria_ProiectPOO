#include<iostream>
#include<string>
#include <fstream>
#pragma warning (disable:4996)
using namespace std;

//domeniul MIJLOC TRANSPORT


class MijlocTransport
{
public:
	virtual void informatieTransport() = 0;
};


class Autoturism :public MijlocTransport
{
private:
	char* marca;
	int anFabricatie;
	string culoare;
	const int numarRoti;
	static int numarTotalAutoturisme;

public:
	virtual void informatieTransport() 
	{
		cout << "Transportul se face cu autoturismul." << endl;
	}

	//afisare in fisier binar
	void generareFisierBinar(ofstream& fout)
	{
		fout.write((char*)&this->anFabricatie, sizeof(int));

		int lungimeSir = strlen(this->marca) + 1;
		fout.write((char*)&lungimeSir, sizeof(int));
		fout.write(this->marca, lungimeSir);

		int   lungimeSir2 = this->culoare.length() + 1;
		fout.write((char*)&lungimeSir2, sizeof(int));
		fout.write(this->culoare.c_str(), lungimeSir2);

	}

	//citire din fisier binar 
	void citireFisierBinar(ifstream& fin)
	{
		fin.read((char*)&this->anFabricatie, sizeof(int));

		char buffer[200];
		int lungimeSir;
		fin.read((char*)&lungimeSir, sizeof(int));
		fin.read(buffer, lungimeSir);

		delete[] this->marca;
		this->marca = new char[lungimeSir];
		strcpy(this->marca, buffer);

		char buufer2[200];
		int   lungimeSir2;
		fin.read((char*)&lungimeSir2, sizeof(int));
		fin.read(buufer2, lungimeSir2);
		this->culoare = buufer2;
	}

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
	Autoturism& operator=(const Autoturism& sursa)
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


class Taxi :public Autoturism
{
private:
	char* sofer;
	float pretPerKilometru;

public:
	void informatieTransport() 
	{
		cout << "Transportul se face cu taxiul." << endl;
	}

	//constructor fara parametrii
	Taxi()
	{
		this->sofer = new char[strlen("na") + 1];
		strcpy(this->sofer, "na");
		this->pretPerKilometru = 1.5;
	}

	//constructor cu toti parametrii
	Taxi(const char* marca, int anFab, string cul, int nrRoti, const char* so, float pretK) :Autoturism(marca, anFab, cul, nrRoti)
	{
		this->sofer = new char[strlen(so) + 1];
		strcpy(this->sofer, so);
		this->pretPerKilometru = pretK;
	}

	//constructor de copiere
	Taxi(const Taxi& sursa) :Autoturism(sursa)
	{
		this->sofer = new char[strlen(sursa.sofer) + 1];
		strcpy(this->sofer, sursa.sofer);
		this->pretPerKilometru = sursa.pretPerKilometru;
	}

	//operator =
	Taxi& operator=(const Taxi& sursa)
	{
		Autoturism::operator=(sursa);

		delete[] this->sofer;
		this->sofer = new char[strlen(sursa.sofer) + 1];
		strcpy(this->sofer, sursa.sofer);
		this->pretPerKilometru = sursa.pretPerKilometru;
		return *this;
	}

	//geteri
	char* getSofer() 
	{
		return this->sofer;
	}

	float getPretKm() 
	{
		return this->pretPerKilometru;
	}

	//seteri
	void setSofer(const char* soferNou)
	{
		if (strlen(soferNou) > 2) 
		{
			delete[] this->sofer;
			this->sofer = new char[strlen(soferNou) + 1];
			strcpy(this->sofer, soferNou);
		}
	}

	void setPretKm(float p)
	{
		if (p > 0) 
		{
			this->pretPerKilometru = p;
		}
	}

	//destructor
	~Taxi() {
		delete[] this->sofer;
	}
};


class TransportPe2Roti
{
protected:
	bool permis = 1;

public:
	virtual int getPermis() = 0;
};


class Bicicleta : public TransportPe2Roti
{
public:
	int  getPermis() 
	{
		return this->permis;
	}

	Bicicleta() 
	{
		this->permis = 0;
	}
};


class Motocicleta :public TransportPe2Roti
{
private:
	char* numeProprietar;
	float pret;
	string modelMotocicleta;
	int capacitateCilindrica;
	const string tipVehicul;
	static bool cascaObligatorie;

public:
	int  getPermis() 
	{
		return this->permis;
	}

	//afisare in fisier binar
	void generareFisierBinar(ofstream& fout)
	{
		fout.write((char*)&this->pret, sizeof(float));
		fout.write((char*)&this->capacitateCilindrica, sizeof(int));

		int lungimeSir = strlen(this->numeProprietar) + 1;
		fout.write((char*)&lungimeSir, sizeof(int));
		fout.write(this->numeProprietar, lungimeSir);


		int   lungimeSir2 = this->modelMotocicleta.length() + 1;
		fout.write((char*)&lungimeSir2, sizeof(int));
		fout.write(this->modelMotocicleta.c_str(), lungimeSir2);
	}

	//citire din fisier binar 
	void citireFisierBinar(ifstream& fin)
	{
		fin.read((char*)&this->pret, sizeof(float));
		fin.read((char*)&this->capacitateCilindrica, sizeof(int));

		char buffer[200];
		int lungimeSir;
		fin.read((char*)&lungimeSir, sizeof(int));
		fin.read(buffer, lungimeSir);

		delete[] this->numeProprietar;
		this->numeProprietar = new char[lungimeSir];
		strcpy(this->numeProprietar, buffer);

		char buufer2[200];
		int lungimeSir2;
		fin.read((char*)&lungimeSir2, sizeof(int));
		fin.read(buufer2, lungimeSir2);
		this->modelMotocicleta = buufer2;
	}

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
		out << "Capacitate cilindrica: " << sursa.capacitateCilindrica << endl;
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

	friend void reducerePret(Motocicleta& sursa, float sumaRed);
};

//initializare atribut static
bool Motocicleta::cascaObligatorie = true;

//functii globale pentru reducere a pretului unei motociclete
void reducerePret(Motocicleta& sursa, float sumaRed)
{
	sursa.pret -= sumaRed;
	//cout << "Pretul nou al motocicletei este " << sursa.pret << endl;
}


class MotocicletaCurse :public Motocicleta
{
private:
	int nrCurse;
	float* timpi;//timpul scos pe fiecare cursa

public:
	//constructor fara parametrii
	MotocicletaCurse() {
		this->nrCurse = 0;
		this->timpi = NULL;
	}

	//constructor cu toti parametrii
	MotocicletaCurse(const char* nume, float pret, string model, int capacitate, string tip, int nr, float* ti) :Motocicleta(nume, pret, model, capacitate, tip)
	{
		this->nrCurse = nr;
		this->timpi = new float[nr];
		for (int i = 0; i < nr; i++) 
		{
			this->timpi[i] = ti[i];
		}
	}

	//constructor de copiere
	MotocicletaCurse(const MotocicletaCurse& sursa) :Motocicleta(sursa)
	{
		this->nrCurse = sursa.nrCurse;
		this->timpi = new float[sursa.nrCurse];
		for (int i = 0; i < sursa.nrCurse; i++) 
		{
			this->timpi[i] = sursa.timpi[i];
		}
	}

	//operator =
	MotocicletaCurse& operator= (const MotocicletaCurse& sursa)
	{
		Motocicleta::operator=(sursa);
		delete[] this->timpi;
		this->nrCurse = sursa.nrCurse;
		this->timpi = new float[sursa.nrCurse];
		for (int i = 0; i < sursa.nrCurse; i++) 
		{
			this->timpi[i] = sursa.timpi[i];
		}
		return *this;
	}

	//geteri
	int getNrCurse() 
	{
		return this->nrCurse;
	}

	float* getTimpi() 
	{
		return this->timpi;
	}

	//seteri
	void setTimpi(int nr, float* ti) 
	{
		if (nr > 0) {
			delete[] this->timpi;
			this->nrCurse = nr;
			this->timpi = new float[nr];
			for (int i = 0; i < nr; i++) 
			{
				this->timpi[i] = ti[i];
			}
		}
	}

	//destructor
	~MotocicletaCurse() 
	{
		delete[] this->timpi;
	}
};


class Tren :public MijlocTransport
{
private:
	string companieFeroviara;
	int nrVagoane;
	int nrBileteDisponibile;
	float* pretBilet;
	const float lungimeStandardVagon;
	static int vitezaMaximaStandard;

public:
	void informatieTransport() 
	{
		cout << "Transportul se face cu trenul." << endl;
	}

	friend ofstream& operator<<(ofstream& out, const Tren& sursa)
	{
		out << sursa.companieFeroviara << endl;
		out << sursa.nrVagoane << endl;
		out << sursa.nrBileteDisponibile << endl;
		for (int i = 0; i < sursa.nrBileteDisponibile; i++)
		{
			out << sursa.pretBilet[i] << endl;
		}

		return out;
	}

	//operator >>
	friend ifstream& operator>>(ifstream& in, Tren& sursa)
	{
		in >> sursa.companieFeroviara;
		in >> sursa.nrVagoane;
		in >> sursa.nrBileteDisponibile;

		delete[]sursa.pretBilet;

		sursa.pretBilet = new float[sursa.nrBileteDisponibile];
		for (int i = 0; i < sursa.nrBileteDisponibile; i++)
		{

			in >> sursa.pretBilet[i];
		}

		return in;
	}

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


class Gara
{
private:
	string locatie;
	int nrPeroane;
	int nrTrenuri;
	Tren* trenuri;

public:

	friend ostream& operator<<(ostream& out, const Gara& sursa)
	{
		out << "Locatie " << sursa.locatie << endl;
		out << "Nr peroane " << sursa.nrPeroane << endl;
		out << "Nr trenuri " << sursa.nrTrenuri << endl;
		for (int i = 0; i < sursa.nrTrenuri; i++)
		{
			out << sursa.trenuri[i] << endl;
		}

		return out;
	}

	friend ofstream& operator<<(ofstream& out, const Gara& sursa)
	{
		out << sursa.locatie << endl;
		out << sursa.nrPeroane << endl;
		out << sursa.nrTrenuri << endl;
		for (int i = 0; i < sursa.nrTrenuri; i++)
		{
			out << sursa.trenuri[i] << endl;
		}

		return out;
	}

	//operator >>
	friend ifstream& operator>>(ifstream& in, Gara& sursa)
	{
		in >> sursa.locatie;
		in >> sursa.nrPeroane;
		in >> sursa.nrTrenuri;

		delete[]sursa.trenuri;

		sursa.trenuri = new Tren[sursa.nrTrenuri];
		for (int i = 0; i < sursa.nrTrenuri; i++)
		{

			in >> sursa.trenuri[i];
		}

		return in;
	}

	//constructor fara parametrii
	Gara()
	{
		this->locatie = "na";
		this->nrPeroane = 0;
		this->nrTrenuri = 0;
		this->trenuri = NULL;
	}

	//constrcutor cu toti parametrii
	Gara(string locatieData, int nrPeroaneDate, int nrTrenuriDate, Tren* trenuriDate)
	{
		if (locatieData.length() > 2)
		{
			this->locatie = locatieData;
		}
		else
		{
			this->locatie = "na";
		}

		if (nrPeroaneDate > 0 && nrPeroaneDate >= nrTrenuriDate && trenuriDate != NULL)
		{
			this->nrPeroane = nrPeroaneDate;
			this->nrTrenuri = nrTrenuriDate;
			this->trenuri = new Tren[nrTrenuriDate];
			for (int i = 0; i < nrTrenuriDate; i++)
			{
				this->trenuri[i] = trenuriDate[i];
			}
		}
		else
		{
			this->trenuri = NULL;
			this->nrPeroane = 0;
			this->nrTrenuri = 0;
		}
	}

	//constructor de copiere
	Gara(const Gara& sursa)
	{
		this->locatie = sursa.locatie;
		this->nrPeroane = sursa.nrPeroane;
		this->nrTrenuri = sursa.nrTrenuri;
		this->trenuri = new Tren[sursa.nrTrenuri];
		for (int i = 0; i < sursa.nrTrenuri; i++)
		{
			this->trenuri[i] = sursa.trenuri[i];
		}
	}

	//operator =
	Gara& operator= (const Gara& sursa)
	{
		delete[] this->trenuri;

		this->locatie = sursa.locatie;
		this->nrPeroane = sursa.nrPeroane;
		this->nrTrenuri = sursa.nrTrenuri;
		this->trenuri = new Tren[sursa.nrTrenuri];
		for (int i = 0; i < sursa.nrTrenuri; i++)
		{
			this->trenuri[i] = sursa.trenuri[i];
		}
		return *this;
	}

	//geteri
	string getLocatie()
	{
		return this->locatie;
	}

	int getNrPeroane()
	{
		return this->nrPeroane;
	}

	int getNrTrenuri()
	{
		return this->nrTrenuri;
	}

	Tren* getTrenuri()
	{
		return this->trenuri;
	}

	//seteri
	void setLocatie(string l)
	{
		if (l.length() > 2)
		{
			this->locatie = l;
		}
	}

	void setNrPeroane(int nr)
	{
		if (nr > this->nrTrenuri)
		{
			this->nrPeroane = nr;
		}
	}

	void setNrTrenuri(int nr, Tren* trenuriDate)
	{
		if (nr > 0 && nr <= this->nrPeroane && trenuriDate != NULL)
		{
			delete[] this->trenuri;
			this->nrTrenuri = nr;
			this->trenuri = new Tren[nr];
			for (int i = 0; i < nr; i++)
			{
				this->trenuri[i] = trenuriDate[i];
			}
		}
	}

	void adaugaTren(Tren nou)
	{
		if (this->nrTrenuri + 1 <= this->nrPeroane)
		{
			Tren* vn;
			vn = new Tren[this->nrTrenuri + 1];
			for (int i = 0; i < this->nrTrenuri; i++)
			{
				vn[i] = this->trenuri[i];
			}
			vn[this->nrTrenuri] = nou;
			delete[] this->trenuri;
			this->trenuri = vn;
			this->nrTrenuri++;
		}
	}

	//operator += pentru a adauga un nou tren in gara
	Gara& operator+= (Tren nou)
	{
		this->adaugaTren(nou);
		return *this;
	}

	//operator +
	Gara operator+ (Tren nou)
	{
		Gara c = *this;
		c.adaugaTren(nou);

		return c;
	}

	// ++ pre incrementare
	Gara& operator++()
	{
		this->nrPeroane += 1;
		return *this;
	}

	//post incrementare
	Gara operator++(int)
	{
		Gara c = *this;
		this->nrPeroane += 1;
		return c;
	}

	//operator == daca 2 gari sunt la fel atunci comparam locatia 
	bool operator == (Gara sursa)
	{
		if (strcmpi(this->locatie.c_str(), sursa.locatie.c_str()) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//destructor
	~Gara() 
	{
		delete[] this->trenuri;
	}
};


class AplicatieTransport 
{
private:
	int nrMijloaceTransport;
	MijlocTransport** mijloace;

public:
	//constructor fara parametrii
	AplicatieTransport() 
	{
		nrMijloaceTransport = 0;
		mijloace = NULL;
	}

	//constructor cu toti parametrii
	AplicatieTransport(int nr, MijlocTransport** mj)
	{
		nrMijloaceTransport = nr;
		mijloace = new MijlocTransport * [nr];
		for (int i = 0; i < nr; i++) 
		{
			this->mijloace[i] = mj[i];
		}
	}

	//constructor de copiere
	AplicatieTransport(const AplicatieTransport& sursa)
	{
		nrMijloaceTransport = sursa.nrMijloaceTransport;
		mijloace = new MijlocTransport * [nrMijloaceTransport];
		for (int i = 0; i < nrMijloaceTransport; i++) 
		{
			this->mijloace[i] = sursa.mijloace[i];
		}
	}

	//operator =
	AplicatieTransport& operator=(const AplicatieTransport& sursa)
	{
		delete[] this->mijloace;
		nrMijloaceTransport = sursa.nrMijloaceTransport;
		mijloace = new MijlocTransport * [nrMijloaceTransport];
		for (int i = 0; i < nrMijloaceTransport; i++) 
		{
			this->mijloace[i] = sursa.mijloace[i];
		}
		return *this;
	}

	void afisareTransporturi()
	{
		for (int i = 0; i < this->nrMijloaceTransport; i++) 
		{
			this->mijloace[i]->informatieTransport();
		}
	}

	//destructor
	~AplicatieTransport()
	{
		delete[] this->mijloace;
	}
};


void main()
{
	//Clasa autoturism

	Autoturism a;

	//seteri
	a.setMarca("Dacia");
	a.setanFabricatie(2001);
	a.setCuloare("roz");

	Autoturism a1("Honda", 2010, "rosie", 4);

	//seteri
	a1.setMarca("Volvo");
	a1.setanFabricatie(2008);
	a1.setCuloare("alb");

	//geteri
	// cout << a1.getMarca() << endl;
	//cout << a1.getanFabricatie() << endl;
	//cout << a1.getCuloare() << endl;

	Autoturism a2(2008, "albastra", 4);

	//seteri
	a2.setMarca("Lambo");
	a2.setanFabricatie(2004);
	a2.setCuloare("verde");

	//apel constructor de copiere
	Autoturism a3(a1);

	//seteri
	a3.setMarca("Bentley");
	a3.setanFabricatie(2012);
	a3.setCuloare("gri");

	//functii statice de acces
	int total = Autoturism::getNumarTotalAutoturisme();
	//cout << "Numar total autoturisme: " << total << endl;
	Autoturism::setNumarTotalAutoturisme(10);
	total = Autoturism::getNumarTotalAutoturisme();
	//cout << "Numar total autoturisme dupa setarea unui numar: " << total << endl;

	//functii statice de calcul
	if (Autoturism::esteVechi(1990))
	{
		//cout << "Autoturismul din 1990 este vechi" << endl;
	}
	else
	{
		//cout << "Autoturismul din 1990 nu este vechi" << endl;
	}

	//functii globale pentru afisarea in consola a anumitor atribute
	//afisare(a1);
	//afisare(a2);

	//apel operator =
	a = a1;

	//apel functie friend operator <<
	//cout << a1 << a2;

	//apel operatorul pentru comparatie ==
	if (a1 == a2)
	{
		//cout << "Autoturismele sunt identice" << endl;
	}
	else
	{
		//cout << "Autoturismele sunt diferite" << endl;
	}

	//apel operator <
	if (a1 < a2)

	{
		//cout << "A1 este mai vechi decat a2" << endl;
	}
	else
	{
		//cout << "A1 este mai nou decat A2" << endl;
	}

	//apel operator >> si << 

	//cout << a1;
	//cin >> a1;

	//vector dinamic

	//Autoturism* vectorDinamic;
	//int nrAutoturisme ;
	//cout << "Numarul de autoturisme este: ";
	//cin >> nrAutoturisme;
	//vectorDinamic = new Autoturism[nrAutoturisme];
	//for (int i = 0; i < nrAutoturisme; i++)
	//{
	//	cin >> vectorDinamic[i];
	//}
	//for (int i = 0; i < nrAutoturisme; i++)
	//{
	//	cout << vectorDinamic[i];
	//}
	//delete[]vectorDinamic;


	//matrice statica de 4 pe 4

	//Autoturism matrice[4][4];
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cin >> matrice[i][j];
	//	}
	//}
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cout << matrice[i][j];
	//	}
	//}


	//Clasa Motocicleta

	Motocicleta m;

	//seteri
	m.setNumeProprietar("Andrei");
	m.setPret(700);
	m.setModelMotocicleta("Yahama");
	m.setCapacitateCilindrica(200);

	Motocicleta m1("Radu", 4000, "nou", 200, "uzat");

	//seteri
	m1.setNumeProprietar("Ion");
	m1.setPret(2500);
	m1.setModelMotocicleta("Jiu");
	m1.setCapacitateCilindrica(100);

	//geteri
	//cout << m1.getNumeProprietar() << endl;
	//cout << m1.getPret() << endl;
	//cout << m1.getModelMotocicleta() << endl;
	//cout << m1.getCapacitateCilindrica() << endl;

	Motocicleta m2("Maria", 6000, 400, "nou");

	//seteri
	m2.setNumeProprietar("Popescu");
	m2.setPret(3000);
	m2.setModelMotocicleta("Suzuki");
	m2.setCapacitateCilindrica(150);

	Motocicleta m3(m1);

	//functii statice de acces
	int valoare = Motocicleta::getCascaObligatorie();
	//cout << "Valoarea pentru casca obligatorie este: " << valoare << endl;

	//functii statice de calcul
	if (Motocicleta::necesitaCasca(200))
	{
		//	cout << "Pentru o motocicleta de 200, casca este obligatorie" << endl;
	}
	else
	{
		//	cout << "Pentru o motocicleta de 200, casca nu este obligatorie" << endl;
	}

	//functii globale pentru reducere a pretului unei motociclete
	Motocicleta sursa;
	reducerePret(sursa, 150);

	//apel operator =
	m = m1;

	//apel functie friend operator <<
	//cout << m1 << m2;

	//apel operator >>
	//cout << m1;
	//cin >> m1;

	//apel operator ==
	if (m1 == m2)
	{
		//	cout << "Motocicletele sunt identice!" << endl;
	}
	else
	{
		//cout << "Motocicletele sunt diferite!" << endl;
	}

	//apel operator <
	if (m1 == m2)
	{
		//cout << "M1 este mai scumpa decat M2!" << endl;
	}//
	else
	{
		//cout << "M1 este mai ieftina decat M2!" << endl;
	}

	//vector static

	//Motocicleta vectorStatic[100];
	//int nr;
	//cout << "Numarul de motociclete este: ";
	//cin >> nr;
	//for (int i = 0; i < nr; i++)
	//{
	//	cin >> vectorStatic[i];
	//}
	//for (int i = 0; i < nr; i++)
	//{
	//	cout << vectorStatic[i];
	//}


	//Clasa Tren

	Tren t;

	//seteri
	t.setCompanieFeroviara("RTG");
	t.setNrVagoane(30);
	t.setNrBileteDisponibile(2, new float[2] {12, 50});

	Tren t1("CFR", 100, 3, new float[3] {12, 23, 45}, 10);

	//geteri
	//cout << t1.getCompanieFeroviara() << endl;
	//cout << t1.getNrVagoane() << endl;
	//cout << t1.getNrBileteDisponibile() << endl;
	for (int i = 0; i < t1.getNrBileteDisponibile(); i++)
	{
		//cout << t1.getPretBilet()[i] << endl;
	}

	//seteri
	t1.setCompanieFeroviara("OIL");
	t1.setNrVagoane(50);
	t1.setNrBileteDisponibile(3, new float[3] {34, 90, 10});

	Tren t2("TGA", 10, 6);

	//seteri
	t2.setCompanieFeroviara("WPPW");
	t2.setNrVagoane(55);
	t2.setNrBileteDisponibile(4, new float[4] {12, 34, 11, 22});

	Tren t3(t1);

	//functii statice de acces
	int viteza = Tren::getVitezaStandard();
	//cout << "Viteza maxima standard este: " << viteza << endl;
	Tren::setVitezaStandard(125);
	viteza = Tren::getVitezaStandard();
	//cout << "Viteza maxima standard dupa setare: " << viteza << endl;

	//functii statice de calcul
	int nrBileteDiponibile = 50;
	if (Tren::suntBileteDisponibile(nrBileteDiponibile))
	{
		//	cout << "Sunt destule bilete" << endl;
	}
	else
	{
		//cout << "Nu sunt destule bilete" << endl;
	}

	//apel operator =
	t = t1;

	//apel functie friend operator <<
	//cout << t1 << t2;

	//apel operator cast
	//cout << "Nr de bilete cu pretul peste 10 lei este: " << (int)t1;
	//cout << endl;

	//apel operator >>
	//cout << t1;
	//cin >> t1;

	//cout << endl;

	//apel operator ==
	if (t1 == t2)
	{
		//cout << "T1 si T2 sunt egale" << endl;
	}
	else
	{
		// cout << "T1 si T2 nu sunt egale" << endl;
	}

	//vector static

	//Tren vectorStaticStatic[100];
	// int nr1;
	//cout << "Numarul de trenuri este: ";
	//cin >> nr1;
	//for (int i = 0; i < nr1; i++)
	//{
	//	cin >> vectorStaticStatic[i];
	//}
	//for (int i = 0; i < nr1; i++)
	//{
	//	cout << vectorStaticStatic[i];
	//}


	// Clasa Gara

	Tren trenvector[2]{ t1, t2 };

	Gara g;

	Gara g1("Bucuresti", 3, 2, trenvector);

	Gara g2(g1);

	g = g1;

	//seteri
	g1.setLocatie("Buzau");
	g1.setNrPeroane(5);
	g1.setNrTrenuri(2, trenvector);

	//geteri
	//cout << g1.getLocatie() << endl;
	//cout << g1.getNrPeroane() << endl;
	//cout << g1.getNrTrenuri() << endl;

	for (int i = 0; i < g1.getNrTrenuri(); i++)
	{
		// cout << g1.getTrenuri()[i] << endl;
	}


	// FAZA 6 

	// cout << a1;

	ofstream fout;
	fout.open("fisierbinarAutotursim.bin", ofstream::binary);
	if (fout.is_open())
	{
		a1.generareFisierBinar(fout);
		fout.close();
	}

	Autoturism adf;//adf=autoturism de verificat 

	ifstream fin;
	fin.open("fisierbinarAutotursim.bin", ifstream::binary);
	if (fin.is_open())
	{
		adf.citireFisierBinar(fin);
		fin.close();
	}

	// cout << adf;

	//  cout << m1;

	ofstream fout1;
	fout1.open("fisierbinarMoto.bin", ofstream::binary);
	if (fout1.is_open())
	{
		m1.generareFisierBinar(fout1);
		fout1.close();
	}

	Motocicleta mdf;//mdf=motocicleta de verificat 

	ifstream fin1;
	fin1.open("fisierbinarMoto.bin", ifstream::binary);
	if (fin1.is_open())
	{
		mdf.citireFisierBinar(fin1);
		fin1.close();
	}

	//  cout << mdf;

	//fisiere text 

	//  cout << g1;

	ofstream fout2;
	fout2.open("fisierbinarGara.txt", ofstream::out);
	if (fout2.is_open())
	{
		fout2 << g1;
		fout2.close();
	}

	Gara gdf;//gdf=gara de verificat 

	ifstream fin2;
	fin2.open("fisierbinarGara.txt", ifstream::in);
	if (fin2.is_open())
	{
		fin2 >> gdf;
		fin2.close();
	}

	//cout << gdf;

	//FAZA 7 

	Taxi tx;
	Taxi tx1("Honda", 2010, "rosie", 4, "Marius", 2.3);
	Taxi tx2(tx1);
	tx = tx1;
	tx.setSofer("Ionut");
	tx.setPretKm(2.4);
	//cout << tx.getSofer() << ", " << tx.getPretKm() << endl;

	MotocicletaCurse mc;
	MotocicletaCurse mc1("Maria", 6000, "Turbo sistem", 400, "nou", 3, new float[3]{10, 232, 43 });
	MotocicletaCurse mc2(mc1);
	mc = mc1;
	mc1.setTimpi(3, new float[3]{10, 11, 12});
	//cout << mc.getNrCurse() << endl;
	for (int i = 0; i < mc.getNrCurse(); i++) 
	{
		//cout << mc.getTimpi()[i] << endl;
	}

	//UPCASTING-construim o motocicleta pe baza unei motocilete de curse
	Motocicleta mot((Motocicleta)mc1); 

	//FAZA 8 
	//late binding
	MijlocTransport* mjt[10] = { &t1, &t2, &t3, &tx1, &tx, &tx2, &a, &a1, &a2, &a3 };
	for (int i = 0; i < 10; i++) 
	{
		mjt[i]->informatieTransport();
	}

	Bicicleta bici;
	TransportPe2Roti* tp2[3] = { &mc1, &m1, &bici };
	for (int i = 0; i < 3; i++) {
		cout << tp2[i]->getPermis() << endl;
	}

	AplicatieTransport ap;
	AplicatieTransport ap1(10, mjt);
	AplicatieTransport ap2(ap1);
	ap = ap1;
	ap1.afisareTransporturi();
}

