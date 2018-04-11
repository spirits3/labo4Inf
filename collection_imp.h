#include "collection.h"


template<typename T, typename CONTENEUR>
void Collection<T,CONTENEUR>::ajouter(T& valeur){
	push_back(valeur);
}
