#ifndef LISTA_H
#define LISTA_H

#define MAX 100 // Capacidade máxima da lista estática

// Definição do tipo do elemento conforme utilizado no main.c
typedef struct {
    int chave;
    char x[50];
} tipo_elem;

// Definição da estrutura da Lista Estática Sequencial
typedef struct {
    tipo_elem dados[MAX];
    int n; // Quantidade atual de elementos
} Lista;

// Operações Básicas do TAD
void iniciar(Lista *L);
void destruir(Lista *L);
int vazia(Lista *L);
int inserir_inicio(Lista *L, tipo_elem v);
int inserir_final(Lista *L, tipo_elem v);
int inserir_ord(Lista *L, tipo_elem v);
int remover(Lista *L, int chave);
int remover_inicio(Lista *L);
int remover_final(Lista *L);
void exibir(Lista *L);
int buscar(Lista *L, int chave, tipo_elem *v);

// Novas Operações (Iterativas e Recursivas)
int tamanho(Lista *L);
int tamanho_rec(Lista *L);
int buscar_rec(Lista *L, int chave, tipo_elem *v);
void exibir_rec(Lista *L);
void exibir_inverso_rec(Lista *L);
int contar_maiores(Lista *L, int chave);
int contar_maiores_rec(Lista *L, int chave);

#endif