output: main.o disciplina.o historico.o
	g++ -std=c++11 main.o disciplina.o historico.o -o programa

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

disciplina.o: disciplina.cpp disciplina.h
	g++ -std=c++11 -c disciplina.cpp

historico.o: historico.cpp historico.h
	g++ -std=c++11 -c historico.cpp

clean:
	rm *.o


