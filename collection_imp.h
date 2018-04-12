
template <typename T, template<typename, typename> class CONTENEUR>
Collection<T, CONTENEUR>::Collection(){
}

template <typename T, template<typename, typename> class CONTENEUR>
void Collection<T, CONTENEUR>::ajouter(T& valeur){
	cont.push_back(T(valeur));
}

template <typename T, template<typename, typename> class CONTENEUR>
void Collection<T, CONTENEUR>::vider(){
    cont.empty();
}

template <typename T, template<typename, typename> class CONTENEUR>
size_t Collection<T, CONTENEUR>::taille() const {
    return cont.size();
}

template <typename T, template<typename, typename> class CONTENEUR>
T& Collection<T, CONTENEUR>::get(size_t indice){
    return cont.at(indice);
}