//Classe Vertice
#include <iostream>
#include <string>
using namespace std;
#ifndef VERTICE_H
#define VERTICE_H

class Vertice{
    public:
        Vertice(string);
        string getVertice();
        static int conter;
        const int id;
    private:
        string vert;
};
#endif