//Definição Historico
#include "historico.h"
using namespace std;

//Função cout para imprimir
ostream &operator<<(ostream & output, const Historico &hist){
    for(unsigned i = 0;i<hist.disciplinas.size();i++){cout << hist.disciplinas[i];}
    return output;
}
//Construtor da Classe
Historico::Historico(){}

//Função para inserir disciplina individual
const Historico &Historico::operator+=(const Disciplina &right){
    for(unsigned i = 0; i < disciplinas.size(); i++){
        if(disciplinas[i]==right){return *this;}
    }
    disciplinas.push_back(right);
    maxDisciplinas++;
    ordenarVetor();
    return *this;
}

//Função para inserir vetor de disciplinas
const Historico &Historico::operator+=(const vector<Disciplina> &right){
    bool cont;
    for(unsigned i = 0; i < right.size(); i++){
        cont = false;
        for(unsigned e = 0; e < disciplinas.size(); e++){
        if(disciplinas[e]==right[i]){cont = true;}}
    if(cont = true){
    disciplinas.push_back(right[i]);
    maxDisciplinas++;}}
    ordenarVetor();
    return *this;
}

//Função para ordenar vetor de disciplinas
void Historico::ordenarVetor(){
    vector<Disciplina> queue(disciplinas);
    vector<Disciplina> temp;
    unsigned cont = 0;
    while (temp.size()<disciplinas.size()){
    for(unsigned a = 0; a < queue.size(); a++){
    for(unsigned i = 0; i < queue.size();i++){
        if(a==i){continue;}
        if (queue[i]<queue[a]){cont++;}

    }
    if(cont == queue.size()-1){
        temp.push_back(queue[a]);
        queue.erase(queue.begin()+a);}
    cont = 0;}
    }
    disciplinas = temp;
}

//Função para remover disciplina
const Historico &Historico::operator-=(const Disciplina &right){
    for(unsigned i =0; i < disciplinas.size();i++){
        if(disciplinas[i]==right){disciplinas.erase(disciplinas.begin()+i); maxDisciplinas--; return this[i];}
    }
    return this[-1];
}

//Função para remover disciplina

const Historico &Historico::operator()(string word){
    for(unsigned i = 0; i < disciplinas.size(); i++){
        if(disciplinas[i].getName() == word){cout << disciplinas[i]; return this[i];}
    }
    return this[-1];
}

const Historico &Historico::operator()(string word, double newnota){
    for(unsigned i = 0; i < disciplinas.size(); i++){
        if(disciplinas[i].getName() == word){disciplinas[i].disciplina.notaFinal = newnota; return this[i];}
    }
    return this[-1];
}

const Historico &Historico::operator>>(double *c) {
    double notafinal;
    double pond;
    if(c = &cra){
        for (unsigned i=0;i<disciplinas.size();i++){
            double nota = disciplinas[i].disciplina.notaFinal;
            double peso = disciplinas[i].disciplina.creditos;
            pond += peso;
            notafinal += (nota * peso);
        }
    
    notafinal = (notafinal / pond);
    cout << "CRA do aluno : " <<  setprecision(2) << notafinal <<  endl;
    return *this;}
    else cout<<"comando invalido."; return *this;
}

double*Historico::setPointer(){
    return &cra;
}

Disciplina *Historico::setDisci(string name){
    Disciplina* temp;
    for(unsigned i = 0; i< disciplinas.size(); i++){
        if(disciplinas[i].getName()==name){temp = &disciplinas[i]; return temp;}
    }
    temp = &disciplinas[0];
    return temp;
}

string Historico::getName(int i){return disciplinas[i].getName();}
int Historico::getPeriod(int i){return disciplinas[i].disciplina.periodoconclusao;}
double Historico::getPeso(int i){return disciplinas[i].disciplina.creditos;}
double Historico::getNota(int i){return disciplinas[i].disciplina.notaFinal;}

int Historico::getMax(){return maxDisciplinas;}