#include "avl.h"

No::No() {
  valor = 0;
  esquerda = NULL;
  direita = NULL;
  altura = 1;
}

No::No(int n) {
  valor = n;
  esquerda = NULL;
  direita = NULL;
  altura = 1;
}

int altura(No *N) {
  if (N == NULL)
    return 0;
  return N->altura;
}

int max(int valorA, int valorB) { return (valorA > valorB) ? valorA : valorB; }

No *rotacaoDireita(No *noB) {
  No *noA = noB->esquerda;
  No *noTemp = noA->direita;

  noA->direita = noB;
  noB->esquerda = noTemp;

  noB->altura = max(altura(noB->esquerda), altura(noB->direita)) + 1;
  noA->altura = max(altura(noA->esquerda), altura(noA->direita)) + 1;

  return noA;
}

No *rotacaoEsquerda(No *noA) {
  No *noB = noA->direita;
  No *noTemp = noB->esquerda;

  noB->esquerda = noA;
  noA->direita = noTemp;

  noA->altura = max(altura(noA->esquerda), altura(noA->direita)) + 1;
  noB->altura = max(altura(noB->esquerda), altura(noB->direita)) + 1;

  return noB;
}

int pegarBalanceamento(No *N) {
  if (N == NULL)
    return 0;
  return altura(N->esquerda) - altura(N->direita);
}

No *inserir(No *no, int valor) {
  if (no == NULL)
    return new No(valor);

  if (valor < no->valor)
    no->esquerda = inserir(no->esquerda, valor);
  else if (valor > no->valor)
    no->direita = inserir(no->direita, valor);
  else
    return no;

  no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

  int balanco = pegarBalanceamento(no);

  // esquerda direita
  if (balanco > 1 && valor > no->esquerda->valor) {
    no->esquerda = rotacaoEsquerda(no->esquerda);
    return rotacaoDireita(no);
  }

  // esquerda esquerda
  if (balanco > 1 && valor < no->esquerda->valor)
    return rotacaoDireita(no);

  // direita esquerda
  if (balanco < -1 && valor < no->direita->valor) {
    no->direita = rotacaoDireita(no->direita);
    return rotacaoEsquerda(no);
  }
  // direita direita
  if (balanco < -1 && valor > no->direita->valor)
    return rotacaoEsquerda(no);

  return no;
}

No *pegarMenorValor(No *no) {
  No *menor = no;
  while (menor->esquerda != NULL)
    menor = menor->esquerda;
  return menor;
}

No *remover(No *raiz, int valor) {

  if (raiz == NULL)
    return raiz;

  if (valor < raiz->valor)
    raiz->esquerda = remover(raiz->esquerda, valor);

  else if (valor > raiz->valor)
    raiz->direita = remover(raiz->direita, valor);

  else {
    if ((raiz->esquerda == NULL) || (raiz->direita == NULL)) {
      No *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

      if (temp == NULL) {
        temp = raiz;
        raiz = NULL;
      } else
        *raiz = *temp;
      free(temp);
    } else {

      No *temp = pegarMenorValor(raiz->direita);
      raiz->valor = temp->valor;
      raiz->direita = remover(raiz->direita, temp->valor);
    }
  }

  if (raiz == NULL)
    return raiz;

  raiz->altura = 1 + max(altura(raiz->esquerda), altura(raiz->direita));

  int balanco = pegarBalanceamento(raiz);

  // esquerda esquerda
  if (balanco > 1 && pegarBalanceamento(raiz->esquerda) >= 0)
    return rotacaoDireita(raiz);

  // esquerda direita
  if (balanco > 1 && pegarBalanceamento(raiz->esquerda) < 0) {
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
  }

  // direita direita
  if (balanco < -1 && pegarBalanceamento(raiz->direita) <= 0)
    return rotacaoEsquerda(raiz);

  // direita esquerda
  if (balanco < -1 && pegarBalanceamento(raiz->direita) > 0) {
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
  }

  return raiz;
}

int posicao(No *raiz, int n) {
  int pos = 0;
  return _posicao(raiz, n, pos);
}

int _posicao(No *raiz, int n, int &pos) {
  int temp;
  if (raiz != NULL) {
    temp = _posicao(raiz->esquerda, n, pos);
    if (temp != -1)
      return temp;
    pos++;
    if (raiz->valor == n)
      return pos;
    temp = _posicao(raiz->direita, n, pos);
    if (temp != -1)
      return temp;
  }
  return -1;
}

std::string toString(No *raiz) {
  std::string sequencia;
  int alturaAVL = altura(raiz);
  for (int i = 0; i <= alturaAVL; i++) {
    _toString(raiz, 0, i, sequencia);
  }
  return sequencia;
}

void _toString(No *raiz, int lvlAtual, int lvl, std::string &sequencia) {
  if (raiz != NULL) {
    if (lvlAtual == lvl) {
      sequencia += std::to_string(raiz->valor) + " ";
      return;
    }

    _toString(raiz->esquerda, lvlAtual + 1, lvl, sequencia);
    _toString(raiz->direita, lvlAtual + 1, lvl, sequencia);
  }
}

bool percorrer(No *raiz, int &cont, int n, int &valor) {
  if (raiz != NULL) {
    if (percorrer(raiz->esquerda, cont, n, valor))
      return true;
    cont++;
    if (cont == n) {
      valor = raiz->valor;
      return true;
    }
    if (percorrer(raiz->direita, cont, n, valor))
      return true;
  }
  return false;
}

int enesimoElemento(No *raiz, int n) {
  int cont = 0;
  int resp = 0;

  if (!percorrer(raiz, cont, n, resp)) {
    throw std::out_of_range("ERRO: Índice fora do intervalo");
  }
  return resp;
}
