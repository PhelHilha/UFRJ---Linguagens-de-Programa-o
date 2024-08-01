//Main Exercisio Avaliado 3

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "disciplina.h"
#include "historico.h"
#define OPTION true
using namespace std;

int main(){
    Historico historico;

    double *cra = historico.setPointer();
    fstream dados;
    string line, data, name;
    int period;
    double peso, nota;
    vector<Disciplina>discis;

    dados.open("dados.txt");

    if(dados.good()){
        Disciplina *disciplina;

        while(getline(dados,line)){
            stringstream Stream(line);

            while(getline(Stream,data, ' ')){
                name = data;
            getline(Stream,data, ' ');
                period = stoi(data);
            getline(Stream,data, ' ');
                peso = stod(data);
            getline(Stream,data);
                nota = stod(data);
            disciplina = new Disciplina(name,period,peso,nota);
            discis.push_back(*disciplina);
            }
        }
    }
    dados.close();
    while(OPTION){
        int option;
        cout<<"Options :"<<"\n0 = Fechar programa."<< "\n1 = Criar e adicionar disciplina ao historico." << "\n2 = Adicionar historico anterior ao atual."
        <<"\n3 = Imprimir historico completo."<<"\n4 = Buscar e imprimir disciplina especifica."<<"\n5 = Imprimir CRA do Aluno."
        <<"\n6 = Deletar disciplina do historico."<<"\n7 = Editar nota de disciplina."<<"\nDigite : "<<endl;
        cin>>option;

        if(option == 1){
            Disciplina *disciplina;
            disciplina = new Disciplina;
            cin>>*disciplina;
            historico += *disciplina;}
        
        if(option == 2){
            historico += discis;
        }

        if(option ==3){
            cout<<historico;
            cout<<"\nTotal de disciplinas : "<<historico.getMax()<<endl;;

        }

        if(option == 4){
            string search;
            cout<<"\nDigite o nome da disciplina buscada : ";
            cin>>search;
            historico(search);}

        if(option ==5){
            historico>>cra;
        }

        if(option ==6){
            string search;
            cout<<"\nDigite o nome da disciplina que deseja deletar : ";
            cin>>search;
            Disciplina *disciplina;
            disciplina = historico.setDisci(search);
            if(disciplina->getName() == search){
            historico -= *disciplina;}
            else cout<<"Disciplina nao encontrada.";
        }

        if(option ==7){
            string search;
            double novanota;
            cout<<"\nDigite o nome da disciplina buscada : ";
            cin>> search;
            cout<<"\nDigite a nova nota : ";
            cin>> novanota;
            historico(search, novanota);
        }

        if(option == 0){
            ofstream saida;
            saida.open("dados.txt");
            for(int i = 0; i< historico.getMax();i++){
                saida << historico.getName(i) << ' ' << historico.getPeriod(i) << ' ' << historico.getPeso(i)
                << ' ' << historico.getNota(i) << endl;
            }
            dados.close();

            break;}
    }
    return 0;
}