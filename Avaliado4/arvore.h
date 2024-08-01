//Classe Arvore
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "atleta.h"
#include "atletavar.h"
#ifndef ARVORE_H
#define ARVORE_H

using namespace std;


template <class T>
class Arvore{
    template <class M>
    friend ostream &operator<<(ostream & out, Arvore<T> & in);
    public:
        const Arvore &operator+( T &);
        T* operator()(string);
        string getAtletaName(int) const;
        int getNumAtleta() const;
        T *getAtleta(int)const;

    protected:
        void insereAtleta(T &) ;
        vector <T *> vArvore;
        void Ordenar();
        int atletas;
};
#endif