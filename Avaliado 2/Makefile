output: main.o grafo.o aresta.o vertice.o
	g++ main.o grafo.o aresta.o vertice.o -o programa

main.o: main.cpp
	g++ -c main.cpp

grafo.o: grafo.cpp grafo.h
	g++ -c grafo.cpp

vertice.o: vertice.cpp vertice.h
	g++ -c vertice.cpp

aresta.o: aresta.cpp aresta.h
	g++ -c aresta.cpp

clean:
	rm *.o output
