/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : Produit.h
 Auteur(s)   : Basile Botebol, Schaufelberger Florian, Nicodème Stalder
 Date        : 10.04.2018

 But         : Déclaration de la classe Produit qui contient : 
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
#ifndef PRODUIT_H
#define PRODUIT_H

#include <ostream>
#include <string>

class Produit {
    friend std::ostream& operator<<(std::ostream& lhs, const Produit rhs);
    friend Produit operator+(Produit lhs, const double& rhs);
    friend Produit operator-(Produit lhs, const double& rhs);
    friend Produit operator*(Produit lhs, const double& rhs);
    friend Produit operator/(Produit lhs, const double& rhs);
    friend bool operator==(const Produit& lhs, const Produit& rhs);
    friend bool operator!=(const Produit& lhs, const Produit& rhs);

public:

    Produit(unsigned int no, const std::string nom, double prix);
    Produit& operator+=(double rhs);
    Produit& operator-=(double rhs);
    Produit& operator*=(double rhs);
    Produit& operator/=(double rhs);

    unsigned int getNo() const;
    const std::string& getNom() const;
    double getPrix() const;
    
    void setNo(unsigned int no);
    void setNom(const std::string& nom);
    void setPrix(double prix);

private:

    unsigned int no;
    std::string nom;
    double prix;
};


#endif /* PRODUIT_H */

