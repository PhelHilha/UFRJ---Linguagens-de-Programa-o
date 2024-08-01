//Classe Disciplina
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

class Disciplina{
    friend class Historico;

    friend istream &operator>>(istream &, Disciplina &);
    friend ostream &operator<<(ostream & ,const Disciplina &);
    public:
        Disciplina(string = "Default", int = 2023, double = 3, double = 7.0);
        const void imprimir() const;
        string getName();
        bool operator<(const Disciplina &) const;
        bool operator==(const Disciplina &) const;

        struct disciplinaType
        {
            string disciplinaName;  
            int periodoconclusao;
            double creditos;
            double notaFinal;
        };
        
    protected:
    disciplinaType disciplina;
};

#endif