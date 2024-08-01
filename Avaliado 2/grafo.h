//Classe Grafo
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include "aresta.h"
using namespace std;
#ifndef GRAFO_H
#define GRAFO_H

class Grafo{
    public:
        Grafo(int);
        ~Grafo();
        void inserirVertice(Vertice *);
        void inserirAresta(Aresta *);
        int getarestasNum();
        void printGrafo();
        void matrizAtt();
        string getAresta(int);
        void centralidade();
        void Densidade();
        void dijkstra(int,int);
        
    private:
        list<pair<int, int> > * adj;
        double **Matriz;
        int arestasNum;
        int verticesNum;
        vector <Aresta> arestas;
        vector <Vertice> vertices;
        void delMatriz();

};
#endif