#include "atletavar.h"

using namespace std;

ostream &operator<<(ostream & output, AtletaVar &indiv){
    output<<"\n"<< "Nome do Atleta : " << indiv.nome<< " - Idade do atleta : "<< indiv.idade<< endl;
    return output;
}

AtletaVar::AtletaVar(string n, int x):Atleta(n), idade(x){}

void AtletaVar::imprime(){
    Atleta::imprime();
    cout << "Idade do Atleta : " << idade << endl;
}

bool AtletaVar::operator==(const AtletaVar &right) const{
    return (right.nome == this->nome);
}
bool AtletaVar::operator<(const AtletaVar &right) const{
    return (right.nome > this->nome);
}

string AtletaVar::getName() const {
    return nome;}