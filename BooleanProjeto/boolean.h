#define PY_SSIZE_T_CLEAN
#include <python3.10/Python.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstring>
#include <algorithm>
#ifndef BOOLEAN_H
#define BOOLEAN_H
using namespace std;

class Boolean{
    friend class Sistema;
    public:
        Boolean(int = 2);
        ~Boolean();

        void setExpression(string);
        
        void makeExpression();

        void simplificar(int);

        void truthtable();

        void expressionTable();

        string getExpression();

    protected:
    
        PyObject *name, *load_module, *func, *callfunc, *args;
        bool **MatrizBool;
        string** MatrizVar;
        bool *MatrizResult;
        int maxVariaveis;
        int colunas;
        string var;
        char* convert(string);
        void truth2();
        void truth3();
        void truth4();
        void setMatriz();
        int conter = 0;

};
#endif