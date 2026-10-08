#ifndef LISTA_H
#define LISTA_H

// Definição do tipo do elemento (exatamente igual aos Projetos 1 e 2)
typedef struct {
    int chave;
    char x[50];
} tipo_elem;

// Estrutura do Nó com alocação dinâmica
typedef struct no {
    tipo_elem info;
    struct no *prox;
} No;

// Estrutura da Lista
typedef struct {
    No *head; // Ponteiro para o primeiro elemento da lista
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