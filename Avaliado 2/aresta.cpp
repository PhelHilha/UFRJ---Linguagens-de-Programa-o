//Definições classe Aresta
#include <iostream>
#include <string>
#include "aresta.h"
using namespace std;


Aresta::Aresta(Vertice *a,Vertice *b,double x):peso(x),origem(a),destino(b){
;
}
Vertice *Aresta::getOrigem(){return origem;}
Vertice *Aresta::getDestino(){return destino;}
double Aresta::getPeso(){return peso;}
