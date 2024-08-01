#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "boolean.h"
#include "sistema.h"

using namespace std;

int main(int argc, char*argv[])
{
    
    cout<<"Defina o numero de variaveis (2 a 4) : ";
    int n;
    cin >> n;
    Sistema sistema(n);
    bool ligado = true;
        int opcao;
        while(ligado == true){
        cout << "\nSelecione uma opcao"<< endl;
        cout << "0 - Fechar programa." << "\n1 - Simple Boolan." << "\n2 - Simplificar POS FORM." <<
         "\n3 - SimpleTable."<< "\n4 -Boolean To Table."<< "\n5 - Simplificar SOP FORM." << "\nOpcao : "<<endl;
        cin >> opcao;
        if (opcao == 0){ligado = false;}
        if (opcao == 1){sistema.SimpleBoolean();}
        if (opcao == 2){sistema.SimplificarPOS();}
        if (opcao == 3){sistema.SimpleTable();}
        if (opcao == 4){sistema.BooleanToTable();}
        if (opcao == 5){sistema.SimplificarSOP();}
        }
    return 0;
}