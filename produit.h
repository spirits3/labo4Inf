/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : produit.h
 Auteur(s)   : Basile Botebol, Schaufelberger Florian, Nicodème Stalder
 Date        : 10.04.2018

 But         : Declaration de la classe Produit qui contient : 
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

#ifndef PRODUIT_H
#define PRODUIT_H

#include <ostream>
#include <string>

class Produit {
    friend std::ostream& operator<<(std::ostream& lhs, const Produit rhs);
    friend bool operator==(const Produit& lhs, const Produit& rhs);

public:

    Produit(unsigned int no, const std::string nom, double prix);
    
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

