//Exception Classe
#include <iostream>
#include <string>
#ifndef EXCEPTIONSISTEMA_H
#define EXCEPTIONSISTEMA_H

using namespace std;

class MyException : public exception {
 public:
  MyException() {
  }

  const char* what() const noexcept override {
    return "Atleta nao encontrao, tente novamente";
  }

 private:
};
#endif