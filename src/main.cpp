#include "avl.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  int num_aux;
  std::ifstream arquivoArvore;
  arquivoArvore.open(argv[1]);
  No *raiz = NULL;

  while(arquivoArvore >> num_aux) raiz = inserir(raiz, num_aux);
  
  arquivoArvore.close();
	
	std::ifstream arquivoComandos;
  std::string linha, comando;
  arquivoComandos.open(argv[2]);

  while (std::getline(arquivoComandos, linha)) {
    std::stringstream lineStream(linha);
    lineStream >> comando;
    if (comando == "ENESIMO") {
      lineStream >> num_aux;
      try{
          std::cout << enesimoElemento(raiz,num_aux) << std::endl;
      }
      catch(const std::exception& e)
      {
          std::cerr << e.what() << '\n';
      }
    } else if (comando == "POSICAO") {
      lineStream >> num_aux;
      std::cout << posicao(raiz,num_aux) <<std::endl;
    } else if (comando == "REMOVA") {
      lineStream >> num_aux;
      raiz = remover(raiz,num_aux);
    } else if (comando == "INSIRA") {
      lineStream >> num_aux;
      raiz =inserir(raiz, num_aux);
    } else if (comando == "IMPRIMA") {
      std::cout << toString(raiz) << std::endl;
    }
  }

  arquivoComandos.close();
  
	return 0;
}