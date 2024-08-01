#include "boolean.h"

using namespace std;

Boolean::Boolean(int n){
    maxVariaveis = n;
    colunas = pow(2,n);
    MatrizBool = (bool **)malloc(colunas * sizeof(bool *));
    for(int x = 0; x < colunas; x++){
        MatrizBool[x] = (bool *)malloc(n*sizeof(bool));
        
    }
     MatrizVar = (string**)malloc(colunas * sizeof(string*));
  for (int i = 0; i < 16; i++) {
    MatrizVar[i] = (string*)malloc(n * sizeof(string));
  
  }
  MatrizResult = (bool *)malloc(colunas * sizeof(bool));
    if(n==4){truth4();}
    if(n==3){truth3();}
    if(n==2){truth2();}
}


void Boolean::makeExpression(){
    if(var.empty() == true){
      setMatriz();
    }
    cout<<endl<<"A expressao booleana : "<< var<< endl;
}

void Boolean::truth4(){
    int i = 0;
  for (int x1 = 0; x1 <= 1; x1++) {
    for (int y1 = 0; y1 <= 1; y1++) {
      for (int z1 = 0; z1 <= 1; z1++) {
        for (int w1 = 0; w1 <= 1; w1++) {
          string A,B,C,D;
          if(x1==1){MatrizVar[i][0] = "A";} else MatrizVar[i][0] ="!A";
          if(y1==1){MatrizVar[i][1] = "B";} else MatrizVar[i][1]="!B";
          if(z1==1){MatrizVar[i][2] = "C";} else MatrizVar[i][2]="!C";
          if(w1==1){MatrizVar[i][3] = "D";} else MatrizVar[i][3]="!D";
          MatrizBool[i][0] = x1;
          MatrizBool[i][1] = y1;
          MatrizBool[i][2] = z1;
          MatrizBool[i][3] = w1;
          i++;
        }
      }
    }
  }
}
void Boolean::truthtable(){
  if(var.empty() == true){setMatriz();}
  if(maxVariaveis==4){
  cout<< endl << left << setw (3) << "A" <<setw(3)<< "B" <<setw(3)<< "C" <<setw(3)<< "D"<< setw(3) << "|" << setw(3) << "Y";}

  if(maxVariaveis==3){
  cout<< endl << left << setw (3) << "A" <<setw(3)<< "B" <<setw(3)<< "C" << setw(3) << "|" << setw(3) << "Y";}

  if(maxVariaveis==2){
  cout<< endl << left << setw (3) << "A" <<setw(3)<< "B" << setw(3) << "|" << setw(3) << "Y";}
  for(int a = 0; a < colunas;a++){
        cout<<"\n";
        
        for(int b = 0; b < maxVariaveis;b++){
            cout<< left << setw (3) << MatrizBool[a][b];
        }
        if (MatrizResult[a] == 1)cout << setw(3) << "|"<< setw(3) << "True";
        else
        cout << setw(3) << "|"<< setw(3) << "False";
  }
}
void Boolean::setMatriz(){
    int cont = 0;
    var.clear();
    for(int k = 0; k < colunas; k++){MatrizResult[k] = false;}
    for(int a = 0; a < colunas;a++){
        cout<<"\n";
        for(int b = 0; b < maxVariaveis;b++){
            cout<< left << setw (3) << MatrizBool[a][b];
        }
        cout<<" = ";
        int result;
        cin>> result;
        if(result > 1){cout<<"\nValor errado!"; break;}
        if(result == 1)MatrizResult[a] = true;  
        if(result < 1) MatrizResult[a] = false; 
        
    }
    for(int x = 0; x < colunas; x++){
    if(MatrizResult[x] == true){
          var+= "("; 
          for(int i = 0; i<maxVariaveis;i++){
            if (i==maxVariaveis-1){
              var+=MatrizVar[x][i] + ")";} 
              else var+=MatrizVar[x][i] + "*";}
            if(x == colunas)cont++;
             else var+=" + ";
             cont++;} 
             }
    if(cont > 0) var.erase(var.length() - 2);
    if(cont == colunas){var = '1';} else if(cont == 0){var = '0';}
  }

void Boolean::simplificar(int op){
    char *arr = convert(var);
    Py_Initialize();
        PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
    if(conter == 0){
      conter++; 
    name = PyUnicode_FromString((char*)"man");
    load_module = PyImport_Import(name);}

    if(op == 0){
    func = PyObject_GetAttrString(load_module,(char*)"somer");
    args = PyTuple_Pack(1, PyUnicode_FromString((char*)arr));
    callfunc = PyObject_CallObject(func,args);
    string funout = _PyUnicode_AsString(callfunc);
    cout<< "\nExpressao simplificada : "  << funout << endl;}

    if(op == 1){
    func = PyObject_GetAttrString(load_module,(char*)"sop");
    args = PyTuple_Pack(1, PyUnicode_FromString((char*)arr));
    callfunc = PyObject_CallObject(func,args);
    string funout = _PyUnicode_AsString(callfunc); 
    cout<< "\nExpressao simplificada : "  << funout << endl;
    }
}

char *Boolean::convert(string expression){
  const int lenght = expression.length();
  char *arr = (char *)malloc(lenght + 1 * sizeof(char));
  
  string change = expression;
  replace(change.begin(), change.end(), '!', '~');
  replace(change.begin(), change.end(), '*', '&');
  replace(change.begin(), change.end(), '+', '|');
  strcpy(arr, change.c_str());
  
  return arr;
}

void Boolean::expressionTable(){
  char *arr = convert(var);
  Py_Initialize();
        PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\".\")");
    if(conter == 0){
      conter++; 
    name = PyUnicode_FromString((char*)"man");
    load_module = PyImport_Import(name);}

    func = PyObject_GetAttrString(load_module,(char*)"truth");
    args = PyTuple_Pack(2, PyUnicode_FromString((char*)arr),PyFloat_FromDouble(maxVariaveis));
    callfunc = PyObject_CallObject(func,args);
}

void Boolean::truth3(){
    int i = 0;
  for (int x1 = 0; x1 <= 1; x1++) {
    for (int y1 = 0; y1 <= 1; y1++) {
      for (int z1 = 0; z1 <= 1; z1++) {
          string A,B,C;
          if(x1==1){MatrizVar[i][0] = "A";} else MatrizVar[i][0] ="!A";
          if(y1==1){MatrizVar[i][1] = "B";} else MatrizVar[i][1]="!B";
          if(z1==1){MatrizVar[i][2] = "C";} else MatrizVar[i][2]="!C";
          MatrizBool[i][0] = x1;
          MatrizBool[i][1] = y1;
          MatrizBool[i][2] = z1;
          i++;
        }
      }
    }
  }

void Boolean::truth2(){
    int i = 0;
  for (int x1 = 0; x1 <= 1; x1++) {
    for (int y1 = 0; y1 <= 1; y1++) {
          string A,B;
          if(x1==1){MatrizVar[i][0] = "A";} else MatrizVar[i][0] ="!A";
          if(y1==1){MatrizVar[i][1] = "B";} else MatrizVar[i][1]="!B";
          MatrizBool[i][0] = x1;
          MatrizBool[i][1] = y1;
          i++;
        }
      }
    }

void Boolean::setExpression(string x){
  var = x;
}

string Boolean::getExpression(){
  return var;
}

Boolean::~Boolean(){
  Py_DECREF(func);
  Py_DECREF(name);
  Py_DECREF(load_module);
  Py_DECREF(callfunc);
  Py_DECREF(args);
  Py_Finalize();

  delete[] MatrizResult;
  free(MatrizBool);
}
