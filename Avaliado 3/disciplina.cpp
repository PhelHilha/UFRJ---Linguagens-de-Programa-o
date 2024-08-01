//Definição Disciplina
#include "disciplina.h"
#include "historico.h"
using namespace std;

istream &operator>>(istream & input, Disciplina & dados){
    cout<< "Nome da disciplina:"<<endl;
    input >> dados.disciplina.disciplinaName;
    cout<<"\nPeriodo de conclusao:"<<endl;
    input>> dados.disciplina.periodoconclusao;
    cout<<"\nCreditos:"<<endl;
    input>> dados.disciplina.creditos;
    cout<<"\nNota Final:"<<endl;
    input>> dados.disciplina.notaFinal;
    return input;
}

ostream &operator<<(ostream & output, const Disciplina &disci){
    output<<"\n"<<"Nome : "<<disci.disciplina.disciplinaName<<"\n"<<"Creditos : "<<disci.disciplina.creditos<<
    "\n"<<"Nota Final : "<<disci.disciplina.notaFinal<<"\n"<<"Periodo conclusao : "<<disci.disciplina.periodoconclusao<<endl;
    return output;
}

bool Disciplina::operator==(const Disciplina &right) const{
    return (right.disciplina.disciplinaName == this->disciplina.disciplinaName);
}

Disciplina::Disciplina(string s, int p, double pp, double n){
    disciplina.disciplinaName = s;
    disciplina.periodoconclusao = p;
    disciplina.creditos = pp;
    disciplina.notaFinal = n;}

string Disciplina::getName(){return disciplina.disciplinaName;}

bool Disciplina::operator<(const Disciplina & right) const{
    if (right.disciplina.periodoconclusao > this->disciplina.periodoconclusao)
    {
    return true;
    }
    else if(right.disciplina.periodoconclusao == this->disciplina.periodoconclusao){
        return right.disciplina.disciplinaName.length() > this->disciplina.disciplinaName.length(); 
    }
    else return false;
    }

const void Disciplina::imprimir() const{
    cout<<"\n"<<disciplina.disciplinaName<<"\n"<<disciplina.creditos<<"\n"<<disciplina.notaFinal<<"\n"<<disciplina.periodoconclusao<<endl;
    }
