#include "atleta.h"

using namespace std;

ostream &operator<<(ostream & output, Atleta &indiv){
    output<<"\n"<< "Nome do Atleta : " << indiv.nome<< endl;
    return output;
}

Atleta::Atleta(string n):nome(n){}

void Atleta::imprime(){
    cout << "\n"<< "Nome do Atleta : " << nome << endl;
}

bool Atleta::operator==(const Atleta &right) const{
    return (right.nome == this->nome);
}
bool Atleta::operator<(const Atleta &right) const{
    return (right.nome > this->nome);
}

string Atleta::getName() const {
    return nome;}