#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#ifndef SISTEMA_H
#define SISTEMA_H

using namespace std;

class Sistema{
    public:
        Sistema(int);

        void SimpleBoolean();

        void SimplificarPOS();

        void SimpleTable();

        void BooleanToTable();

        void SimplificarSOP();
    private:
        int Select();
        int variaveis;
        Boolean matriz;
        bool existe = false;
        vector <string> expressoes;
};
#endif