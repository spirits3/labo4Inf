#include <cstdlib>
#include <list>
#include <vector>
#include "collection.h"
#include "produit.h"

using namespace std;

int main() {
	Collection<int, vector> cVectorInt;
	
	for (int i = 1; i <= 3; ++i)
		cVectorInt.ajouter(i);

	cout << "Collection<int, vector> cVectorInt :" << endl
		 << "1. contenu: " << cVectorInt << endl
		 << "2. taille: " << cVectorInt.taille() << endl
		 << "3. 1er element : " << cVectorInt.get(0) << endl;

	cVectorInt.vider();

	cout << "4. contenu: " << cVectorInt << endl << endl;

	Collection<Produit, list> cListProduit;

	// un produit se caractérise par un no, un libellé, un prix
	cListProduit.ajouter({1, "Produit 1", 1.5});
	cListProduit.ajouter({2, "Produit 2", 5});

	cout << "Collection<Produit, list> cListProduit :" << endl
		 << "1. contenu: " << cListProduit << endl
		 << "2. taille: " << cListProduit.taille() << endl
		 << "3. 1er element : " << cListProduit.get(0) << endl;

	cListProduit.vider();

	cout << "4. contenu: " << cListProduit << endl << endl;

	return EXIT_SUCCES;
}