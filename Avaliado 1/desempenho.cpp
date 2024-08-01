//Classes
//Definição das classes
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include "desempenho.h"
using namespace std;

//Classe que gerencia cada aluno
//ALUNO

Aluno::Aluno(int x){
    periodos = x;
    inserirMat();
    inserirPort();
    inserirFilo();
    inserirAlmoso();
    inserirComp();
}
double Aluno::notaRandom(){
   int randomNumber = rand()%(10+1);
	return randomNumber;

}
void Aluno::mediaMovel(){
    vector <string> melhor;
    vector <string> neutro;
    vector <string> pior;
//MAT
    double tempmat1;
    double tempmat2;
    for(int i = 1; i < 4; i++){
            tempmat1 += (Mat.at(periodos - i));
            }
    for(int i = 2; i < 5; i++){
            tempmat2 += Mat.at(periodos - i);
    }
        tempmat1 = tempmat1/tempmat2;
    if (tempmat1 > 1.05){melhor.push_back("Matematica");}
    if (tempmat1 <= 1.05 && tempmat1 >= 1){neutro.push_back("Matematica");}
    if (tempmat1 < 1){pior.push_back("Matematica");}
//Port
    double tempport1;
    double tempport2;
    for(int i = 1; i < 4; i++){
            tempport1 += (Port.at(periodos - i));
            }
    for(int i = 2; i < 5; i++){
            tempport2 += Port.at(periodos - i);
    }
        tempport1 = tempport1/tempport2;
    if (tempport1 > 1.05){melhor.push_back("Portugues");}
    if (tempport1 <= 1.05 && tempport1 >= 1){neutro.push_back("Portugues");}
    if (tempport1 < 1){pior.push_back("Portugues");}
//Filo
    double tempfilo1;
    double tempfilo2;
    for(int i = 1; i < 4; i++){
            tempfilo1 += (Filo.at(periodos - i));
            }
    for(int i = 2; i < 5; i++){
            tempfilo2 += Filo.at(periodos - i);
    }
        tempmat1 = tempfilo1/tempfilo2;
    if (tempfilo1 > 1.05){melhor.push_back("Filosofia");}
    if (tempfilo1 <= 1.05 && tempfilo1 >= 1){neutro.push_back("Filosofia");}
    if (tempfilo1 < 1){pior.push_back("Filosofia");}
//Almoso
    double tempalmoso1;
    double tempalmoso2;
    for(int i = 1; i < 4; i++){
            tempalmoso1 += (Almoso.at(periodos - i));
            }
    for(int i = 2; i < 5; i++){
            tempalmoso2 += Almoso.at(periodos - i);
    }
        tempmat1 = tempalmoso1/tempalmoso2;
    if (tempalmoso1 > 1.05){melhor.push_back("Almoso");}
    if (tempalmoso1 <= 1.05 && tempalmoso1 >= 1){neutro.push_back("Almoso");}
    if (tempalmoso1 < 1){pior.push_back("Almoso");}
//Comp
    double tempcomp1;
    double tempcomp2;
    for(int i = 1; i < 4; i++){
            tempcomp1 += (Comp.at(periodos - i));
            }
    for(int i = 2; i < 5; i++){
            tempcomp2 += Comp.at(periodos - i);
    }
        tempmat1 = tempcomp1/tempcomp2;
    if (tempcomp1 > 1.05){melhor.push_back("Comp");}
    if (tempcomp1 <= 1.05 && tempcomp1 >= 1){neutro.push_back("Comp");}
    if (tempcomp1 < 1){pior.push_back("Comp");}
//Tabela
    cout<<"Melhorou em:"<<endl;
    for (size_t i = 0;i < melhor.size();i++){cout<< melhor.at(i)<<endl;}
    cout<<"Neutro em:"<<endl;
    for (size_t i = 0;i < neutro.size();i++){cout<< neutro.at(i)<<endl;}
    cout<<"Piorou em"<<endl;
    for (size_t i = 0;i < pior.size();i++){cout<< pior.at(i)<<endl;}
}
double Aluno::getMedia(){
    return ((Mat.at(periodos - 1) + Port.at(periodos - 1) + Filo.at(periodos - 1) + Almoso.at(periodos - 1) + Comp.at(periodos - 1))/5);
}

void Aluno::inserirMat(){
    for(int i = 0; i < periodos; i++){
        Mat.push_back(notaRandom());
    }
}
void Aluno::inserirPort(){
    for(int i = 0; i < periodos; i++){
        Port.push_back(notaRandom());
    }
}
void Aluno::inserirFilo(){
    for(int i = 0; i < periodos; i++){
        Filo.push_back(notaRandom());
    }
}
void Aluno::inserirAlmoso(){
    for(int i = 0; i < periodos; i++){
        Almoso.push_back(notaRandom());
    }
}
void Aluno::inserirComp(){
    for(int i = 0; i < periodos; i++){
        Comp.push_back(notaRandom());
    }
}
double Aluno::getMat(int x){
    return Mat.at(x);
}
double Aluno::getPort(int x){
    return Port.at(x);
}
double Aluno::getFilo(int x){
    return Filo.at(x);
}
double Aluno::getAlmoso(int x){
    return Almoso.at(x);
}
double Aluno::getComp(int x){
    return Comp.at(x);
}


//---------------------------------------------------------------------------------------------------------------------------------//


//Classe que gerencia os objetos relacionados as diciplinas//
Disciplina::Disciplina(int x, int z){
    periodos = x;
    maxalunos = z;
}
double Disciplina::mediaMovel(int x){
    double tempmed = 0;
        if (x >= 0 && x <= 3){
           for(int i = 0; i < 3; i++){
                tempmed += media.at(3-i); 
        }
        }
        else{
            for(int i = 1; i < 4; i++){
                tempmed += media.at(x-i);
            }
        }
        tempmed = tempmed/3;
        tempmed = round(tempmed * 100) / 100;
        return tempmed;
    }
double Disciplina::getMedia(int x){
    return media[x-1];
}
void Disciplina::insereAluno(Aluno obj){
        alunos.push_back(obj);
    }
void Disciplina::defMedMat(){
    for(int i = 0;i < periodos; i++){
        int conte = 0;
        double mediatemp = 0;
        while (conte < maxalunos){
            for(int n = 0; n < maxalunos; n++){
        
                mediatemp += alunos[n].getMat(i);
                conte++;
                }
        }
        media.push_back(mediatemp / maxalunos);
    }
}
void Disciplina::defMedPort(){
    for(int i = 0;i < periodos; i++){
        int conte = 0;
        double mediatemp = 0;
        while (conte < maxalunos){
            for(int n = 0; n < maxalunos; n++){
        
                mediatemp += alunos[n].getPort(i);
                conte++;
                }
        }
        media.push_back(mediatemp / maxalunos);
    }
}
void Disciplina::defMedFilo(){
    for(int i = 0;i < periodos; i++){
        int conte = 0;
        double mediatemp = 0;
        while (conte < maxalunos){
            for(int n = 0; n < maxalunos; n++){
        
                mediatemp += alunos[n].getFilo(i);
                conte++;
                }
        }
        media.push_back(mediatemp / maxalunos);
    }
}
void Disciplina::defMedAlmoso(){
    for(int i = 0;i < periodos; i++){
        int conte = 0;
        double mediatemp = 0;
        while (conte < maxalunos){
            for(int n = 0; n < maxalunos; n++){
        
                mediatemp += alunos[n].getAlmoso(i);
                conte++;
                }
        }
        media.push_back(mediatemp / maxalunos);
    }
}
void Disciplina::defMedComp(){
    for(int i = 0;i < periodos; i++){
        int conte = 0;
        double mediatemp = 0;
        while (conte < maxalunos){
            for(int n = 0; n < maxalunos; n++){
        
                mediatemp += alunos[n].getComp(i);
                conte++;
                }
        }
        media.push_back(mediatemp / maxalunos);
    }
}
//Definição da media de cada classe em seus periodos
