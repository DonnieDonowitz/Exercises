#include <iostream>
#include <stdio.h>

int i, j, k;
double **m1, **m2, **m3;
int r1, c1, r2, c2, r3, c3 ;

int main()
{

	do {
		std::cout << "Inserisci numero di righe della prima matrice ";
		std::cin >> r1;
	} while (r1 < 1);
	do {
		std::cout << "Inserisci il numero di colonne della prima matrice ";
		std::cin >> c1;
	} while (c1 < 1);
	r2 = c1;
	do {
		std::cout << "Inserisci il numero di colonne della seconda matrice ";
		std::cin >> c2;
	} while (c2 < 1);

	m1 = new double *[r1];
	for (i = 0; i < r1; i++)
		m1[i] = new double[c1];
	m2 = new double *[r2];
	for (i = 0; i < r2; i++)
		m2[i] = new double[c2];
	m3 = new double *[r1];
	for (i = 0; i < r1; i++)
		m3[i] = new double[c2];



	std::cout << "Inserimento Prima Matrice " << std::endl;

	for (i = 0; i < r1; i++)
		for (j = 0; j < c1; j++) {
			std::cout << "Inserisci Elemento " << i << j << "  ";
			std::cin >> m1[i][j];
		}

	std::cout << "Inserimento Seconda Matrice " << std::endl;

	for (i = 0; i < r2; i++)
		for (j = 0; j < c2; j++) {
			std::cout << "Inserisci Elemento " << i << j << "  ";
			std::cin >> m2[i][j];
		}


	for (i = 0; i < r1; i++)
		for (j = 0; j < c2; j++) {
			m3[i][j] = 0;
			for (k = 0; k < c1; k++)
				m3[i][j] += m1[i][k] * m2[k][j];

		}

	std::cout << "Visualizzazione Matrice Prodotto " << std::endl;

	for (i = 0; i < r1; i++)
		for (j = 0; j < c2; j++)
			std::cout << "Elemento di Indice " << i << "," << j << " = " << m3[i][j] << std::endl;


	for (i = 0; i < r1; i++)
		delete m1[i];

	delete m1;

	for (i = 0; i < r2; i++)
		delete m2[i];

	delete m2;

	for (i = 0; i < r1; i++)
		delete m3[i];

	delete m3;

	return 0;
}
