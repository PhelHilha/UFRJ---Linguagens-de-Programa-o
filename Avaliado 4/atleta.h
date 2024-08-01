//Classe Atleta
#include <iostream>
#include <string>
#include <vector>

#ifndef ATLETA_H
#define ATLETA_H

using namespace std;

class Atleta{
    friend class Sistema;
    friend ostream &operator<< (ostream &, Atleta &);

    public:
        Atleta (string);
        bool operator==(const Atleta&) const;
        bool operator<(const Atleta&) const;
        string getName() const;
        virtual void imprime();
    protected:
        string nome;


};
#endif