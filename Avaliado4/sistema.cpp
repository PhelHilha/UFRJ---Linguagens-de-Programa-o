#include "sistema.h"
#include "arvore.cpp"
void Sistema::insere(){
    string name;
    cout << endl << "Escreva o tipo do atleta :"<<endl;

    cout<< "1 - Atleta" << endl << "2 - AtletaVar" << endl;
    int idade, opcao;
    cout<< "Opcao : ";
    cin >> opcao;
    cout << endl << "Escreva o nome do atleta :";
    cin >> name;
    if(opcao == 1){
    Atleta *atleta;
    atleta = new Atleta(name);
    arvore + *atleta;
    }
    
    if(opcao == 2){
        cout << endl << "Escreva a idade do atleta : ";
        cin >> idade;
        Atleta *atleta;
        atleta = new AtletaVar(name,idade);
        arvore + *atleta;    
    }
}

void Sistema::busca(){
    try
    {
        cout << "Nome do Atleta a ser buscado : ";
        string name;
        cin >> name;
        MyException e = MyException();
        if (arvore(name) == NULL){throw e;}
        arvore(name)->imprime();
    }
    catch(MyException& e)
    {
        std::cerr << e.what() << '\n';
        busca();
    }
}

void Sistema::imprime(){
    cout << arvore;
}
