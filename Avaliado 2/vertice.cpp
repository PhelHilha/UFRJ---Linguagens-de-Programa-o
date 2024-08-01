//Definições classe Vertice
#include <iostream>
#include <string>
#include "vertice.h"
using namespace std;
Vertice::Vertice(string a):id(conter),vert(a){conter++;}
string Vertice::getVertice(){return vert;}
int Vertice::conter=0;