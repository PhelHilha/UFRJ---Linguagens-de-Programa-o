output: main.o desempenho.o
	g++ main.o desempenho.o -o programa

main.o: main.cpp
	g++ -c main.cpp

grafo.o: desempenho.cpp desempenho.h
	g++ -c grafo.cpp

clean:
	rm *.o output
