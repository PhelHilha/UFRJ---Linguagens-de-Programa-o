#!/usr/bin/make -f

TARGET = sistema

CXX = g++

RM = rm -f

ifeq ($(compiler), CLANG)
CXX = clang++
endif

LD = $(CXX)

CXXFLAGS = -Wall -std=c++11
LDFLAGS = -Wall

ifeq ($(dialect), C++14)
CXXFLAGS = -Wall -std=c++14
endif

ifeq ($(dialect), C++17)
CXXFLAGS = -Wall -std=c++17
endif

	OBJS = main.o sistema.o arvore.o atleta.o atletavar.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) *.o $(TARGET)
