/*
-----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : main.cpp
 Auteur(s)   : Basile Botebol, Schaufelberger Florian, Nicodème Stalder
 Date        : 10.04.2018

 But         : main testant que notre fonction generique marche comme on
 			   le souhaite
 			   test sur les méthode de collection.h de contient et parcourir.

 Remarque(s) : Pas de catch d'exception ni de tests sur les données rentrees par 
 			   l'utilisateur

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

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

	cout << "Collection<int, vector> cVectorInt :" 		<< endl
		 << "1. contenu: " 		<< cVectorInt 			<< endl
		 << "2. taille: " 		<< cVectorInt.taille() 	<< endl
		 << "3. 1er element : " << cVectorInt.get(0) 	<< endl;

	cVectorInt.vider();

	cout << "4. contenu: " << cVectorInt << endl << endl;

	Collection<Produit, list> cListProduit;

	// un produit se caractérise par un no, un libellé, un prix
	cListProduit.ajouter({1, "Produit 1", 1.5});
	cListProduit.ajouter({2, "Produit 2", 5});

	cout << "Collection<Produit, list> cListProduit :" 		<< endl
		 << "1. contenu: " 		<< cListProduit 			<< endl
		 << "2. taille: " 		<< cListProduit.taille()	<< endl
		 << "3. 1er element : " << cListProduit.get(0) 		<< endl;

	cListProduit.vider();

	cout << "4. contenu: " << cListProduit << endl << endl;

	//test de methodes membre contient() et parcourir()

	cListProduit.ajouter({1, "Produit 1", 1.5});
	cListProduit.ajouter({2, "Produit 2", 5});

	Produit test  = {1, "Produit 1", 1.5};
	Produit test2 = {1, "Produit 1", 1.8};

	cout << boolalpha << "Est ce que notre liste contient l'élement {1, \"Produit 1\", 1,50: "
		 << cListProduit.contient(test) << endl;

	cout << boolalpha << "Est ce que notre cListProduit contient l'élement {1, \"Produit 1\", 1,80}: "
		 << cListProduit.contient(test2) << endl << endl;

	cout << "Avant la majoration de 10% des prix de cListProduit: " << endl
		 << cListProduit << endl;
	cout <<	"Après la majoration des prix de 10% de cListProduit : " << endl
		 << cListProduit.parcourir([] (Produit& p) { p.setPrix(p.getPrix() * 1.1); });

	return EXIT_SUCCESS;
}