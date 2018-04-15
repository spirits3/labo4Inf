/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Produit.cpp
 Auteur(s)   : Basile Botebol, Schaufelberger Florian, Nicodème Stalder
 Date        : 10.04.2018

 But         : Implémentation de la classe Produit qui contient : 
 * - un champs privé no de type unsigned int, le numero du produit
 * - un champs privé nom, de type string, le nom du produit
 * - un champs privé prix de type double, le prix du produit
 * - un constructeur (publique) à trois paramètres qui initialise dans cet ordre 
 le no, le nom et le prix 
 * - les surcharges d'opérateur (publiques) -=, +=, *= et /= avec un double
 qui modifie le prix du produit 
 * - les fonctions amies de surcharge d'opérateur +, -, * et / avec un double qui 
 modifient également seulement le prix
 * - les fonction amies de surcharge d'opérateur == et =!, qui comparent strictement
 champs à champs les deux objets.

 Remarque(s) : certaines surcharges d'opérateu sont peut être superflues, mais 
 néanmoins implémentées, en prévision de la suite

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include <ostream>
#include <string>

#include "produit.h"

using namespace std;

ostream& operator<<(ostream& lhs, Produit rhs) {
    return lhs << '(' << rhs.no << ", \"" << rhs.nom << "\", " << rhs.prix << ')';
}

Produit operator+(Produit lhs, const double& rhs) {
    return lhs += rhs;
}

Produit operator-(Produit lhs, const double& rhs) {
    return lhs -= rhs;
}

Produit operator*(Produit lhs, const double& rhs) {
    return lhs *= rhs;
}

Produit operator/(Produit lhs, const double& rhs) {
    return lhs /= rhs;
}

bool operator==(const Produit& lhs, const Produit& rhs) {
    return (lhs.no == rhs.no && lhs.nom == rhs.nom && rhs.prix == lhs.prix);
}

bool operator!=(const Produit& lhs, const Produit& rhs) {
    return !(lhs == rhs);
}

Produit::Produit(unsigned int no, const std::string nom, double prix) : no(no), nom(nom), prix(prix) {
}

Produit& Produit::operator+=(double rhs) {
    prix += rhs;
    return *this;
}

Produit& Produit::operator-=(double rhs) {
    prix -= rhs;
    return *this;
}

Produit& Produit::operator*=(double rhs) {
    prix *= rhs;
    return *this;
}

Produit& Produit::operator/=(double rhs) {
    prix /= rhs;
    return *this;
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
