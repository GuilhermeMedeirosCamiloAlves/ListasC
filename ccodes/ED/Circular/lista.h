#include<stdio.h>
#define MAX 10
typedef int tipoelem;
typedef struct{
    tipoelem a[MAX];
    int inicio, fim;
}Fila;
void iniciar(Fila *f);
int Vazia(Fila *f);
int Cheia(Fila *f);
void exibir(Fila *f);
tipoelem primeiro(Fila *f);
int tamanho(Fila *f);
int enfileirar(Fila *f);
int desenfileirar(Fila *f);
int destruir(Fila *f);