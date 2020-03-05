//Feito por Guilherme Freitas Da Silva
//Trabalho da materia estrutura de dados 1, ministrada pelo professor Roney Pignaton
#ifndef SKIPLIST.H
#define SKIPLIST.H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEVEL 5// quantidade maxima de hierarquia, lembrando que a hierarquia mais profunda e = 0

/* Esse programa implementa uma SkipList que torna uma busca mais eficiente em uma lista dinamicamente ligada e ordenada.
Possui um conjunto de sub-listas encadeadas hierárquicas.
A lista com hierarquia = 0 refere-se a lista completa, ja as listas superiores sao copias dessa lista porem fragmentada.
Os comandos e valores sao passados por um aquivo .txt de leitura e o resultado eh escrito em um outro arquivo .txt.
*/

typedef struct no{ //Estrutua utilizada para Cabeca de lista e tambem para o No que compoem cada elemento.
int i;
struct no **prox; //vetor de ponteiros.
}no;

void createList(no **List);//cria Estrutua utilizada para Cabeca de lista.

no *createNo(int i , int level);//cria No que compoem cada elemento. i=valor da chave, level == nivel mais alto de hierarquia do elemento.

int isEmptyList(no *List);// verifica se List == NULL e se todos os campos de ponteiro da cabeca estao apontados para NULL

int searchList(int i, no *List , no **searchVet , int imprimir , FILE *fileW);//procura pelo elemento que carrega a chave com valor == i na Lista List, atualisando o valor do vetor searchVet, e imprimindo os valores desse vetor caso imprimir == 1 no arquivo fileW

int InsertNo(no **List, int novo, int level, no **searchVet);//cria e insere um elemento com chave == novo e nivel de hierarquia == level, na lista List, somente se a lista ainda nao possuir um elemento com este valor

int removeNo(no **List, int kay, no **searchVet);//caso encontre o elemento com chave == kay, remove da lista List

void printListLevel(no *List, int level, FILE *fileW); // imprime todos elementos do nivel de hierarquia == level,  da lista List no arquivo fileW

void all(no *List ,FILE *fileW); // imprime todos os elementos de todos os niveis de hierarquia existentes na lista List no arquivo fileW
#endif //SKIPLIST.H

