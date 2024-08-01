//Main Avaliado 4
#include <iostream>
#include <string>
#include <vector>
#include "arvore.h"
#include "atleta.h"
#include "atletavar.h"
#include "sistema.h"

using namespace std;

int main(){

    Sistema sistema;
    bool ligado = true;
    cout << "Adicione um atleta para comecar"<< endl;
    sistema.insere();

    while(ligado == true){
        int opcao;
        cout << "\nSelecione uma opcao"<< endl;
        cout << "0 - Fechar programa." << "\n1 - Inserir Atleta." << "\n2 - Buscar Atleta." << "\n3 - Imprimir Arvore."<< "\nOpcao : "<<endl;
        cin >> opcao;
        if (opcao == 0){ligado = false;}
        if (opcao == 1){sistema.insere();}
        if (opcao == 2){sistema.busca();}
        if (opcao == 3){sistema.imprime();}
    }
    return 0;
}