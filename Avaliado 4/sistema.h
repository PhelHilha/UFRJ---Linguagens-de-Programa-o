//Sistema Classe
#include <iostream>
#include <string>
#include <vector>
#include "arvore.h"
#include "atleta.h"
#include "exceptionsistema.h"
#include "atletavar.h"
#ifndef SISTEMA_H
#define SISTEMA_H

using namespace std;

class Sistema{
    friend class Atleta;

    public:

    void insere ();

    void busca();

    void imprime();

    private:

    Arvore <Atleta> arvore;
};
#endif