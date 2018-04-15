#include <vector>
#include <list>
#include <algorithm>

template<typename T, template<typename, typename> class Conteneur>
std::ostream& operator << (std::ostream& os, const Collection<T, Conteneur>& collection) {
	os << "[";

	for(auto i = collection.cont.begin(); i != collection.cont.end(); ++i) {
		os << *i;
			os << ",";	
	}

	os << "]";
	return os;
}

template <typename T, template<typename, typename> class Conteneur>
Collection<T, Conteneur>::Collection(){
}

template <typename T, template<typename, typename> class Conteneur>
void Collection<T, Conteneur>::ajouter(T valeur){
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