#ifndef COLLECTION_H
#define COLLECTION_H

#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T, template <typename, typename> class Conteneur>
class Collection {
    
    friend std::ostream& operator<<(std::ostream&, const Collection&);

public:
    Collection();
    void ajouter(T&);
    void vider();
    size_t taille() const;
    T& get(size_t indice);
    Collection& parcourir(T);
    bool contient(T);

private:
    Conteneur<T, allocator<T> > cont;


};

#include "collection_imp.h"

#endif