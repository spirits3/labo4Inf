#include <vector>
#include <list>

template <typename T, template<typename, typename> class Conteneur>
Collection<T, Conteneur>::Collection(){
}

template <typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(T& valeur){
	cont.push_back(T(valeur));
}

template <typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::vider(){
    cont.empty();
}

template <typename T, template<typename, typename> class Conteneur>
size_t Collection<T, Conteneur>::taille() const {
    return cont.size();
}

template <typename T, template<typename, typename> class Conteneur>
T& Collection<T, Conteneur>::get(size_t indice){
    return cont.at(indice);
}

template<typename T, template<typename, typename> class Conteneur>
void Collection<T,Conteneur>::parcourir(T predicat) {
	for(auto i = cont.begin(); i != cont.end(); ++i) {
		predicat(*i);
	}
}

template <typename T, template<typename,typename> class Conteneur>
bool Collection<T,Conteneur>::contient(T valeur) {
	for(auto i = cont.begin(); i != cont.end(); ++i) {
		if(cont[i] == valeur) {
			return true;
		}
	}
	return false;
}