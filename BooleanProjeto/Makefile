output : main.o boolean.o sistema.o
	g++ -I/opt/include/python3.10 -I/opt/include/python3.10 -Wsign-compare  -DNDEBUG -g -fwrapv -O3 -Wall main.o boolean.o sistema.o -L/opt/lib/python3.10/config-3.10-x86_64-linux-gnu -L/opt/lib -lpython3.10 -lpthread -ldl  -lutil -lm -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

boolean.o: boolean.cpp boolean.h
	g++ -std=c++11 -c boolean.cpp

sistema.o: sistema.cpp sistema.h
	g++ -std=c++11 -c sistema.cpp

clean:
	rm *.o
