#ifndef LISTA_H
#define LISTA_H

#define MAX 100 

// Definição do tipo do elemento (exatamente igual ao Projeto 1)
typedef struct {
    int chave;
    char x[50];
} tipo_elem;

// Estrutura do Nó para a Lista Estática Encadeada
typedef struct {
    tipo_elem info;
    int prox; // Encadeamento feito por meio de índices
} No;

// Estrutura da Lista
typedef struct {
    No nos[MAX];
    int inicio; // Índice do primeiro elemento da lista
    int dispo;  // Índice do primeiro elemento disponível (livre)
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