//Classe Historico
#include <iostream>
#include <string>
#include <vector>
#include "disciplina.h"

using namespace std;

#ifndef HISTORICO_H
#define HISTORICO_H

class Historico{
    friend class Disciplina;
    friend ostream &operator<<(ostream & ,const Historico &);
    public:
        Historico();
        void ordenarVetor();
        const Historico &operator+=(const Disciplina &) ;
        const Historico &operator+=(const vector<Disciplina> &);
        const Historico &operator-=(const Disciplina &);
        const Historico &operator()(string);
        const Historico &operator()(string, double);
        const Historico &operator>>(double*);

        string getName(int);
        int getPeriod(int);
        double getPeso(int);
        double getNota(int);
        double* setPointer();
        Disciplina* setDisci(string);
        int getMax();
    protected:
    vector<Disciplina>disciplinas;
    int maxDisciplinas = 0;
    double cra;

};

#endif