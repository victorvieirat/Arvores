
#   implementação de Árvore AVL
Projeto desenvolvido na matéria Estrutura de Dados Básicas II na curso de Tecnologia da Informação/UFRN, ministrada pela docente Silvia M. D. M. Maia.
## Autores
> *Paulo V. F. Andrade*

> *Rita C. C.  Cruz*

> *Victor V Targino*

## Execução
```bash
g++ src/main.cpp src/avl.cpp -o AVL
./ABB <arquivo da arvore> <arquivo de comandos>
```
## Funcionamento
A partir de um arquivo com inteiro separados por espaço uma [Árvore AVL](https://pt.wikipedia.org/wiki/%C3%81rvore_AVL) é criada. O segundo argumento é o caminho para um arquivo, cada linha do arquivo deve ser um comando. Os comandos suportados são:


| INSIRA N  | Insere um Número na AVL, caso já exista nada acontece.        |
|-----------|---------------------------------------------------------------|
|  REMOVA N | Remove um Número na AVL, caso não exista nada acontece.       |
| ENESIMO N | Imprime o N-esimo (contando a partir de 1) na ordem simétrica. |
| POSICAO N | Imprime a posição por ordem simétrica do elemento N.                          |
| IMPRIMA   | Imprime uma sequencia do valores organizado por nível.         |

## Exemplo de arquivo
_arvore.txt_
```
10 9 20 8 7 30 40
```
_comandos.txt_
```
ENESIMO 7
POSICAO 40
IMPRIMA
REMOVA 10
INSIRA 24
IMPRIMA
```
