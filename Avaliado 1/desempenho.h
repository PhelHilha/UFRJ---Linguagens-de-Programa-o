//Classes
//Possui a base de cada classe.
#include <iostream>
#include <vector>
#include <string>
#ifndef DESEMPENHO_H
#define DESEMPENHO_H
using namespace std;

//Classe que gerencia cada aluno
class Aluno{
    public:
        Aluno(int = 3);
        double notaRandom();
        void inserirMat();
        void inserirPort();
        void inserirFilo();
        void inserirAlmoso();
        void inserirComp();
        double getMedia();
        void mediaMovel();
        double getMat(int);
        double getPort(int);
        double getFilo(int);
        double getAlmoso(int);
        double getComp(int);        
    private:
        int periodos;
        vector <double> desempenho;
        vector <double> Mat;
        vector <double> Port;
        vector <double> Filo;
        vector <double> Almoso;
        vector <double> Comp;
};   

//Classe que gerencia os objetos relacionados as diciplinas
class Disciplina{
    public:
        Disciplina(int,int);
        //Definição da media de cada classe em seus periodos
        void insereAluno(Aluno obj);
        double mediaMovel(int = 3);
        double getMedia(int);
        void defMedMat();
        void defMedPort();
        void defMedFilo();
        void defMedAlmoso();
        void defMedComp();

    private:
        int periodos;
        int maxalunos;
        //Array que comporta a nota final nas devidas disciplinas de cada aluno.
        vector <Aluno> alunos;
        vector <double> media;
};
#endif
