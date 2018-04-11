#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class Produit {

public:
	Produit(int numero, std::string libbele, double prix);

private:
	int numero;
	std::string libbele;
	double prix;
};

#endif