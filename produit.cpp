/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.cpp
 Auteur(s)   : Basile Botebol, Schaufelberger Florian, Nicodème Stalder
 Date        : 10.04.2018

 But         : Implémentation de la classe Produit qui contient : 
               - un champs privé no de type unsigned int, le numero du produit
               - un champs privé nom, de type string, le nom du produit
               - un champs privé prix de type double, le prix du produit
               - un constructeur (publique) à trois paramètres qui initialise dans 
                 cet ordre le no, le nom et le prix 
               - la fonction amie de surcharge d'opérateur ==, qui 
                 compare strictement champs à champs les deux objets.
               - la fonctinon de surcharge d'ecriture sur un flux.
               - les accesseurs aux differents champs

 Remarque(s) : 

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <iomanip>

#include "produit.h"

std::ostream& operator<<(std::ostream& lhs, Produit rhs) {
    return lhs << std::fixed << std::setprecision(2) << '(' << rhs.no << ", \"" << rhs.nom << "\", " << rhs.prix << ')';
}

bool operator==(const Produit& lhs, const Produit& rhs) {
    return (lhs.no == rhs.no && lhs.nom == rhs.nom && rhs.prix == lhs.prix);
}

Produit::Produit(unsigned int no, const std::string nom, double prix) : no(no), nom(nom), prix(prix) {
}

unsigned int Produit::getNo() const{
    return no;
}

const std::string& Produit::getNom() const{
    return nom;
}

double Produit::getPrix() const {
    return prix;
}

void Produit::setNo(unsigned int no) {
    this->no = no;
}

void Produit::setNom(const std::string& nom) {
    this->nom = nom;
}
 
void Produit::setPrix(double prix) {
    this->prix = prix;
}