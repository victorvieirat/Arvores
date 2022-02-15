#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <string>
using namespace std;

// No da Arvore AVL
class No {
public:
  int valor;
  No *esquerda;
  No *direita;
  int altura;

  /**
   * Construtor padrao
   */
  No();

  /**
   * Construtor com valor em raiz
   */
  No(int n);
};

/**
 * @brief Retorna o maior de dois valores
 */
int maximo(int a, int b);

/**
 * @brief Retorna altura a arvore a partir da raiz N
 */
int altura(No *N);

/**
 * @brief Rotaciona a subarvore para direita
 */
No *rotacaoDireita(No *noB);

/**
 * @brief Rotaciona a subarvore para esquerda
 */
No *rotacaoEsquerda(No *noA);

/**
 * @brief Calcula o fator de balanceamento de N
 */
int pegarBalanceamento(No *N);

/**
 * @brief Insere elemento na AVL
 *
 * @param no  Raiz da AVL
 * @param valor Numero a ser inserido
 * @return No* Retorna raiz
 */
No *inserir(No *no, int valor);

/**
 * @brief Enconta o No com menor valor na Arvore
 * @paramNo z Raiz da AVL
 * @return No* Menor No
 */
No *pegarMenorValor(No *no);

/**
 * @brief Remove elemento da AVL
 * @param raiz Raiz da AVL
 * @param n Elemento a ser removido
 * @return No* Raiz da AVL apos remocao
 */
No *remover(No *raiz, int valor);

/**
 * @brief Encontra posicao do elemento
 *
 * @param raiz Raiz da AVL
 * @param n Numero a ser encontrado
 * @return int Nao Nulo se achou, -1 se nao achou
 */
int posicao(No *raiz, int n);

/**
 * @brief Funcao aux da funcao
 *
 * @param raiz Raiz da AVL
 * @param n Numero a ser encontrado
 * @param pos Contador para retornar posicao
 * @return int Nao Nulo se achou, -1 se nao achou
 */
int _posicao(No *raiz, int n, int &pos);

/**
 * @brief Funcao auxiliar da toString
 *
 * @param raiz raiz da AVL
 * @param lvlAtual Nivel atual
 * @param lvl Nivel que sera impresso
 * @param sequencia String com os valores por nivel
 */
void _toString(No *raiz, int lvlAtual, int lvl, std::string &sequencia);

/**
 * @brief Imprime por nivel a AVL
 *
 * @param raiz raiz da AVL
 * @return std::string valores organizados por nivel
 */
std::string toString(No *raiz);

/**
 * @brief Funcao para encontrar verificar se a posicao esta ocupada
 * e dar o valor que esta nessa posicao
 *
 * @param raiz Raiz da AVL
 * @param cont Contador da posicao
 * @param n Posicao a ser procurada
 * @param valor Valor encontrado
 * @return true Posicao ocupada
 * @return false Posicao nao ocupada
 */
bool percorrer(No *raiz, int &cont, int n, int &valor);

/**
 * @brief A partir de uma posicao, retorna o valor correspondente
 *
 * @param raiz Raiz da AVL
 * @param n Posicao a ser procurada
 * @return int Valor encontrado
 * @throw out_of_range Elemente nao existe
 */
int enesimoElemento(No *raiz, int n);

#endif