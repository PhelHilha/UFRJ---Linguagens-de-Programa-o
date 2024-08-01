//Definição Classe Grafo
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <list>
#include <queue>
#include "grafo.h"
#define INFINITO 10000000

using namespace std;

Grafo::Grafo(int a):arestasNum(0),verticesNum(a){adj = new list<pair<int, int> >[a];}

void Grafo::inserirVertice(Vertice *obj){
    vertices.push_back(*obj);
}

void Grafo::inserirAresta(Aresta *obj){
    arestas.push_back(*obj);
    arestasNum++;
    Matriz = (double **)malloc(vertices.size()*sizeof(double *));
    for(size_t i = 0; i < vertices.size(); i++){
        Matriz[i] = (double *)malloc(vertices.size()*sizeof(double));
    }
    for (size_t n = 0; n < vertices.size(); n++){
        for (size_t j = 0; j < vertices.size(); j++){
            Matriz[n][j] = 0;
        }
    }
    adj[obj->getOrigem()->id].push_back(make_pair(obj->getDestino()->id, obj->getPeso()));
    adj[obj->getDestino()->id].push_back(make_pair(obj->getOrigem()->id, obj->getPeso()));

        

    
}
string Grafo::getAresta(int x){
    return arestas.at(x).getOrigem()->getVertice()+ " - "+ arestas.at(x).getDestino()->getVertice();
}
int Grafo::getarestasNum(){return arestasNum;}

void Grafo::printGrafo(){
    matrizAtt();
    cout << "\n";
for (size_t i = 0; i < vertices.size(); i++) {
cout << left << setw (3) << vertices.at(i).getVertice();
}
    for(size_t a = 0; a < vertices.size();a++){
        cout<<"\n";
        for(size_t b = 0; b < vertices.size();b++){
            cout<< left << setw (3) << Matriz[a][b];
        }
    }
}
void Grafo::matrizAtt(){
    for(size_t a = 0; a < vertices.size();a++){
        for(size_t b = 0;b< vertices.size();b++){
            for(size_t x = 0; x < arestas.size();x++){
                if((vertices[a].getVertice()==arestas[x].getOrigem()->getVertice() && vertices[b].getVertice()==arestas[x].getDestino()->getVertice())||
                (vertices[b].getVertice()==arestas[x].getOrigem()->getVertice() && vertices[a].getVertice()==arestas[x].getDestino()->getVertice())){
                    Matriz[a][b] = arestas[x].getPeso();
                }
            }

        }
    }
}
Grafo::~Grafo() {
    delMatriz();}

void Grafo::delMatriz(){
        for (size_t i = 0; i < vertices.size() - 1; i++) {
            free (Matriz[i]);
        }
}
void Grafo::Densidade(){
    double n = verticesNum;
    double x = (n*(n-1))/2;
    n = n/x;
    cout << "A Densidade do Grafo : " << n<<endl;
}
void Grafo::dijkstra(int orig, int dest)
	{
		// vetor de distâncias
		int dist[verticesNum];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[verticesNum];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < verticesNum; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;
        vector<string>caminho;
		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}


    



       
		}
        if(dist[dest] == INFINITO){cout<<"Nao existe caminho entre os dois."<<endl;}
		// retorna a distância mínima até o destino
		cout<<"O caminho de "<<vertices[orig].getVertice()<<" ate "<<vertices[dest].getVertice()<<
        " mede : "<<dist[dest]<<endl;
	}
    void Grafo::centralidade(){
        vector <string> vertices_string;   

   for (Aresta indice: arestas) {
      vertices_string.push_back(indice.getOrigem()->getVertice());
      vertices_string.push_back(indice.getDestino()->getVertice());
   }

   auto last_int = vertices_string.front();
   auto frequente = vertices_string.front();
   int max_freq = 0, current_freq = 0;

   for (const auto &i : vertices_string) {
      if (i == last_int)
         ++current_freq;
      else {
         if (current_freq > max_freq) {
               max_freq = current_freq;
               frequente = last_int;
         }
         
         last_int = i;
         current_freq = 1;
      }
    }

    if (current_freq > max_freq) {
        max_freq = current_freq;
        frequente = last_int;
    }

    cout<<"O vertice de maior centralidade : "<<frequente<<endl;
}