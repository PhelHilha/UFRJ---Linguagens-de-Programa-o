//Classe Atleta
#include <iostream>
#include <string>
#include <vector>
#include "atleta.h"

#ifndef ATLETAVAR_H
#define ATLETAVAR_H

using namespace std;

class AtletaVar: public Atleta{
    friend class Sistema;
    friend ostream &operator<< (ostream &, AtletaVar &);

    public:
        AtletaVar (string , int);
        bool operator==(const AtletaVar&) const;
        bool operator<(const AtletaVar&) const;
        string getName() const;
        virtual void imprime();
    protected:
        int idade;


};
#endif