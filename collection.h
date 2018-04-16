/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection.h
 Auteur(s)   : Basile Botebol, Schaufelberger Florian, Nicodème Stalder
 Date        : 10.04.2018

 But         : Definition de la classe Collection avec :
			   - surcharge de l'opérateur <<
			   - ajouter   : permet d'ajouter un element de type Conteneur
			   - vider     : permet de vider le conteneur
			   - taille    : permet de connaitre la taille du conteneur
			   - get	   : permet de prendre l'élement a une position choisie dans
			                 le conteneur
			   - parcourir : permet de faire le même traitement à un element du 
			   				 conteneur
			   - contient  : permet de voir si le conteneur contient tel element

 Remarque(s) : Pas d'accesseur fait par rapport au conteneur

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef COLLECTION_H
#define COLLECTION_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T, template <typename, typename> class Conteneur>
class Collection;

template<typename T, template<typename, typename> class Conteneur>
std::ostream& operator << (std::ostream&, const Collection<T, Conteneur>&);

template<typename T, template <typename, typename> class Conteneur>
class Collection {
    
    friend std::ostream& operator << <>(std::ostream&, const Collection&);
public:
    Collection();
    Collection& ajouter(const T&);
    Collection& vider();
    size_t taille() const;
    T& get(size_t indice);

    template<typename F>
    Collection& parcourir(const F&);
    bool contient(T);

private:
    Conteneur<T, allocator<T>> cont;
};

#include "collection_imp.h"

#endif