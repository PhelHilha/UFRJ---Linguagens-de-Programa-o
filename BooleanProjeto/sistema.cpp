#include "sistema.h"

using namespace std;

Sistema::Sistema(int n):matriz(n){variaveis = n;}

void Sistema::SimpleBoolean(){
    cout<<"\n0 - Criar expressao bruta." << "\n1 - Imprimir expressao bruta existente."<<"\nDigite : ";
    int opt;
    cin >> opt;
    if (expressoes.empty()){
        cout<<"\nNenhuma expressao existente, crie uma para continuar.";
        opt = 0;}
    if(opt == 0){
        matriz.setMatriz();
        matriz.makeExpression();
        expressoes.push_back(matriz.getExpression());
    }
    if(opt == 1){
            cout<< expressoes[Select()];
    }
}

void Sistema::SimplificarPOS(){
    cout<<"\n0 - Inserir expressao." << "\n1 - Simplificar expressao existente."<<"\nDigite : ";
    int opt;
    cin >> opt;
    if (expressoes.empty()){
        cout<<"\nNenhuma expressao existente, crie uma para continuar.";
        opt = 0;}
    if(opt == 0){
        if(variaveis == 4){cout << "\nVariaveis : A - B - C - D";}
        if(variaveis == 3){cout << "\nVariaveis : A - B - C";}
        if(variaveis == 2){cout << "\nVariaveis : A - B";}

        cout << "\nDigite a expressao. exemplo (!A*B)+(C*D) :";
        string var;
        cin >> var;
        expressoes.push_back(var);
        matriz.setExpression(var);
        matriz.simplificar(0);
    }
    if(opt == 1){
            
            matriz.setExpression(expressoes[Select()]);
            matriz.simplificar(0);
    }
}

void Sistema::SimpleTable(){
        cout<<"\n0 - Criar tabela verdade." << "\n1 - Imprimir tabela verdade existente."<<"\nDigite : ";
    int opt;
    cin >> opt;
    if (expressoes.empty()){
        cout<<"\nNenhuma tabela existente, crie uma para continuar.";
        opt = 0;}
    if(opt == 0){
        matriz.setMatriz();
        matriz.truthtable();
        expressoes.push_back(matriz.getExpression());

    }
    if(opt == 1){
            matriz.setExpression(expressoes[Select()]);
            matriz.expressionTable();
    }
}

int Sistema::Select(){
    cout <<"\nEscolha uma expressao : "<<endl;
            for(unsigned i = 0; i < expressoes.size(); i++){
                cout << "\n" << i << " - Expressao";
            }
            cout<<"\nDigite : ";
            int m;
            cin>>m;
            return m;
}

void Sistema::BooleanToTable(){
    cout<<"\n0 - Criar tabela verdade." << "\n1 - Imprimir tabela verdade existente."<<"\nDigite : ";
    int opt;
    cin >> opt;
    if (expressoes.empty()){
        cout<<"\nNenhuma tabela existente, crie uma para continuar.";
        opt = 0;}
    if(opt == 0){
        if(variaveis == 4){cout << "\nVariaveis : A - B - C - D";}
        if(variaveis == 3){cout << "\nVariaveis : A - B - C";}
        if(variaveis == 2){cout << "\nVariaveis : A - B";}

        cout << "\nDigite a expressao. exemplo (!A*B)+(C*D) :";
        string var;
        cin >> var;
        expressoes.push_back(var);
        matriz.setExpression(var);
        matriz.expressionTable();
    }
    if(opt == 1){
            
            matriz.setExpression(expressoes[Select()]);
            matriz.expressionTable();
    }
}

void Sistema::SimplificarSOP(){
    cout<<"\n0 - Inserir expressao." << "\n1 - Simplificar expressao existente."<<"\nDigite : ";
    int opt;
    cin >> opt;
    if (expressoes.empty()){
        cout<<"\nNenhuma expressao existente, crie uma para continuar.";
        opt = 0;}
    if(opt == 0){
        if(variaveis == 4){cout << "\nVariaveis : A - B - C - D";}
        if(variaveis == 3){cout << "\nVariaveis : A - B - C";}
        if(variaveis == 2){cout << "\nVariaveis : A - B";}

        cout << "\nDigite a expressao. exemplo (!A*B)+(C*D) :";
        string var;
        cin >> var;
        expressoes.push_back(var);
        matriz.setExpression(var);
        matriz.simplificar(1);
    }
    if(opt == 1){
            
            matriz.setExpression(expressoes[Select()]);
            matriz.simplificar(1);
    }
}