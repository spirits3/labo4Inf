#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>

template<typename T, typename CONTENEUR>
class Collection {
	friend std::ostream& operator << (std::ostream&, const Collection&);
public:
	Collection();
	Collection ajouter(T&);
	void vider();
	T taille();
	T get(T);
	CONTENEUR parcourir(T);
	bool contient(T);
};

#endif