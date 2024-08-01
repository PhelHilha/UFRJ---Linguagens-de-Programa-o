//Classe Aresta
#include <iostream>
#include <string>
#include "vertice.h"
using namespace std;
#ifndef ARESTA_H
#define ARESTA_H

class Aresta{
    public:
        Aresta(Vertice *,Vertice *,double = 10);
        Vertice *getOrigem();
        Vertice *getDestino();
        double getPeso();
    private:
        double peso;
        Vertice *origem;
        Vertice *destino;
        int caminho;



};
#endif