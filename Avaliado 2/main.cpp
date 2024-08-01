//Main exercisio avaliado 2
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "grafo.h"
#include "aresta.h"
#include "vertice.h"

using namespace std;

int main(int argc, char **argv){
    //Definir entradas
    Grafo grafo(8);
    Vertice RJ("RJ");
    Vertice SP("SP");
    Vertice MG("MG");
    Vertice AC("AC");
    Vertice AL("AL");
    Vertice AM("AM");
    Vertice BA("BA");
    Vertice ES("ES");
    vector<Vertice *> vertices;
    vertices.push_back(&RJ);
    vertices.push_back(&SP);
    vertices.push_back(&MG);
    vertices.push_back(&AC);
    vertices.push_back(&AL);
    vertices.push_back(&AM);
    vertices.push_back(&BA);
    vertices.push_back(&ES);
    
    grafo.inserirVertice(&RJ);
    grafo.inserirVertice(&SP);
    grafo.inserirVertice(&MG);
    grafo.inserirVertice(&AC);
    grafo.inserirVertice(&AL);
    grafo.inserirVertice(&AM);
    grafo.inserirVertice(&BA);
    grafo.inserirVertice(&ES);
    fstream arquivo;
    string linha,nome;
    double peso;
    vector <Aresta *> arestas;
    arquivo.open("dados.txt");
    if(arquivo.is_open()){
        Aresta *aresta = nullptr;
        Vertice* v1 =nullptr;
        Vertice* v2 =nullptr;
        while(getline(arquivo,linha)){
            stringstream conjunto(linha);
            while(getline(conjunto,nome, ' ')){
                for(auto v:vertices){if(nome == v->getVertice()){v1 = v;}}
                while(getline(conjunto,nome, ' ')){
                for(auto vv:vertices){if(nome == vv->getVertice()){v2 = vv;}}
                getline(conjunto, nome);
                peso = stod(nome);
                aresta = new Aresta(v1,v2,peso);
                arestas.push_back(aresta);

            }
        }
        }
    }
arquivo.close();
for (auto i: arestas){
    grafo.inserirAresta(i);
}
if(argc > 1){
    if (!strcmp(argv[1],"1")){

    for(int m = 0; m < grafo.getarestasNum() ;m++){
        cout<<grafo.getAresta(m)<<endl;}}

    else if (!strcmp(argv[1],"2")){
    grafo.printGrafo();}
    else if (!strcmp(argv[1],"3")){
        string origem;
        string destino;
        cout<<"Selecione uma origem: "<<endl;
        cin>>origem;
        cout<<"Selecione um destino: "<<endl;
        cin>>destino;
    int v1 =50;
    int v2 =50;
    for(auto v:vertices){if(origem == v->getVertice()){v1 = v->id;}}
    for(auto vv:vertices){if(destino == vv->getVertice()){v2 = vv->id;}}
    if(v1==50 or v2==50){cout<<"Origem ou Destino sao invalidos."<<endl;}
    else{
    grafo.dijkstra(v1,v2);}}
    else if (!strcmp(argv[1],"4")){
        grafo.Densidade();
    }
    else if (!strcmp(argv[1],"5")){
    grafo.centralidade();}
}
    return 0;
}
