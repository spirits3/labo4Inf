/*
 -----------------------------------------------------------------------------------
 Laboratoire : 04
 Fichier     : collection_imp.h
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

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <iomanip>

template<typename T, template<typename, typename> class Conteneur>
std::ostream& operator << (std::ostream& os, const Collection<T, Conteneur>& collection) {
	

	os << fixed << setprecision(2) << "[";

	for(auto i = collection.cont.begin(); i != --collection.cont.end(); ++i) {
		os << *i << ", ";	
	}
	os << *--collection.cont.end()
	   << "]";
	return os;
}

template <typename T, template<typename, typename> class Conteneur>
Collection<T, Conteneur>::Collection(){
}

template <typename T, template<typename, typename> class Conteneur>
Collection<T, Conteneur>& Collection<T, Conteneur>::ajouter(const T& valeur){
	cont.push_back(T(valeur));
	return *this;
}

template <typename T, template<typename, typename> class Conteneur>
Collection<T, Conteneur>& Collection<T, Conteneur>::vider(){
    cont.clear();
    return *this;
}

template <typename T, template<typename, typename> class Conteneur>
size_t Collection<T, Conteneur>::taille() const {
    return cont.size();
}

template<typename T, template <typename, typename> class CONTENEUR>
T& Collection<T, CONTENEUR>::get(size_t indice){
    auto b = cont.begin();
    for(int i = 0; i < indice ; ++i, ++b);
    return *b;
}

template<typename T,template<typename, typename> class Conteneur>
template<typename F>
Collection<T, Conteneur>& Collection<T,Conteneur>::parcourir(const F& predicat) {
	std::for_each(cont.begin(), cont.end(), predicat);
	return *this;
}


template <typename T, template<typename,typename> class Conteneur>
bool Collection<T,Conteneur>::contient(T valeur) {
	for(auto i = cont.begin(); i != cont.end(); ++i) {
		if(*i == valeur) {
			return true;
		}
	}
	return false;
}