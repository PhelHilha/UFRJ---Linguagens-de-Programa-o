//Classe Arvore

#include "arvore.h"


using namespace std;

template<class T> 
std::ostream &operator<<(std::ostream &out, Arvore<T> &in){
    for(int i = 0 ; i < in.getNumAtleta(); i++){
        in.getAtleta(i)->imprime();
    }
    
    return out;

}


template<class T> 
const Arvore<T> &Arvore<T>::operator+(T &right) {
    for(unsigned i = 0; i < vArvore.size(); i++){
        if(*vArvore[i]==right){return *this;}
    }
    insereAtleta(right);
    Ordenar();
    atletas++;
    return *this;
}



template<class T>
void Arvore<T>::Ordenar(){
     for (unsigned i = 0; i < vArvore.size() - 1; i++) {
    for (unsigned j = 0; j < vArvore.size() - i - 1; j++) {
      if (vArvore[j]->getName() > vArvore[j + 1]->getName()) {
        swap(vArvore[j], vArvore[j + 1]);
      }
    }
    }    
}

template<class T> 
string Arvore<T>::getAtletaName(int a) const{
    return vArvore[a]->getName();
}
template<class T>
int Arvore<T>::getNumAtleta() const{
    return atletas;
}

template<class T> 
T* Arvore<T>::operator()(string i){
    for(unsigned x = 0; x < vArvore.size();x++){
        if(vArvore[x]->getName() == i){
            return vArvore[x];
        }
    }
    return NULL;
}

template <class T>
T *Arvore<T>::getAtleta(int i)const {
    return vArvore[i];
}

template<class T> 
void Arvore<T>::insereAtleta(T &a) {
    vArvore.push_back(&a);
}

