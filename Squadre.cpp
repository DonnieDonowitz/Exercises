#include <iostream>
#include <iomanip>
#include <string>

const int PUNTI_VITTORIA = 3;
const int PUNTI_PAREGGIO = 1;
const int PUNTI_SCONFITTA = 0;

class Squadra {
private:

	std::string nome;
	int vinte, pareggiate, perse;

public:

	Squadra(std::string n) : nome(n), vinte(0), pareggiate(0), perse(0) {}
	~Squadra() {}

	std::string getNome()
	{
		return nome;
	}
	void setNome(std::string n)
	{
		nome = n;
	}
	int getVinte()
	{
		return vinte;
	}
	void setVinte(int v)
	{
		vinte = v;
	}
	int getPareggiate()
	{
		return pareggiate;
	}
	void setPareggiate(int p)
	{
		pareggiate = p;
	}
	int getPerse()
	{
		return perse;
	}
	void setPerse(int p)
	{
		perse = p;
	}

	int punti()
	{
		return vinte * PUNTI_VITTORIA + pareggiate * PUNTI_PAREGGIO + perse * PUNTI_SCONFITTA;
	}
	void inizioAnno()
	{
		vinte = perse = pareggiate = 0;
	}
};

int main()
{
	Squadra inter("Inter");
	Squadra milan("Milan");
	char c;

	do {
		int v, p, s;
		std::cout << "Numero di vittorie, pareggi e sconfitte per la squadra " << inter.getNome() << ": ";
		std::cin >> v >> p >> s;

		inter.setVinte(v);
		inter.setPareggiate(p);
		inter.setPerse(s);

		std::cout << " \n Numero di vittorie, pareggi e sconfitte per la squadra " << milan.getNome() << ": ";
		std::cin >> v >> p >> s;

		milan.setVinte(v);
		milan.setPareggiate(p);
		milan.setPerse(s);

		std::cout << "\n Risultato finale: " << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << std::setw(15) << inter.getNome() << "\t" << inter.punti() << " punti " << std::endl;
		std::cout << std::setw(15) << milan.getNome() << "\t" << milan.punti() << " punti " << std::endl;

		if (inter.punti() != milan.punti())
		{
			std::cout << "Campionato vinto dalla squadra " << (inter.punti() > milan.punti() ? inter.getNome() : milan.getNome()) << std::endl;
		}
		else
		{
			std::cout << "Situazione di pari merito, e' necessario procedere allo spareggio!" << std::endl;
		}

		std::cout << std::endl << "Continuare con un nuovo campionato [S/N] ? ";
		std::cin >> c;
		
		inter.inizioAnno();
		milan.inizioAnno();
	} while (c == 'S' || c == 's');

	return 0;
}