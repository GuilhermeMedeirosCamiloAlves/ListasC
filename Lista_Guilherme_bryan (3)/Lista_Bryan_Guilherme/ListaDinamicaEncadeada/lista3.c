#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void iniciar(Lista *L) {
    L->head = NULL;
}

void destruir(Lista *L) {
    No *atual = L->head;
    No *prox_no;
    
    while (atual != NULL) {
        prox_no = atual->prox;
        free(atual);
        atual = prox_no;
    }
    L->head = NULL;
}

int vazia(Lista *L) {
    return L->head == NULL;
}

int inserir_inicio(Lista *L, tipo_elem v) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) return 0; // Falha na alocação
    
    novo->info = v;
    novo->prox = L->head;
    L->head = novo;
    
    return 1;
}

int inserir_final(Lista *L, tipo_elem v) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) return 0;
    
    novo->info = v;
    novo->prox = NULL;
    
    if (vazia(L)) {
        L->head = novo;
    } else {
        No *atual = L->head;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    
    return 1;
}

int inserir_ord(Lista *L, tipo_elem v) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) return 0;
    
    novo->info = v;
    
    if (vazia(L) || L->head->info.chave >= v.chave) {
        novo->prox = L->head;
        L->head = novo;
        return 1;
    }
    
    No *atual = L->head;
    No *ant = NULL;
    
    while (atual != NULL && atual->info.chave < v.chave) {
        ant = atual;
        atual = atual->prox;
    }
    
    ant->prox = novo;
    novo->prox = atual;
    
    return 1;
}

int remover_inicio(Lista *L) {
    if (vazia(L)) return 0;
    
    No *apagado = L->head;
    L->head = apagado->prox;
    free(apagado);
    
    return 1;
}

int remover_final(Lista *L) {
    if (vazia(L)) return 0;
    
    No *atual = L->head;
    No *ant = NULL;
    
    while (atual->prox != NULL) {
        ant = atual;
        atual = atual->prox;
    }
    
    if (ant == NULL) { // Só havia um elemento
        L->head = NULL;
    } else {
        ant->prox = NULL;
    }
    
    free(atual);
    return 1;
}

int remover(Lista *L, int chave) {
    if (vazia(L)) return 0;
    
    No *atual = L->head;
    No *ant = NULL;
    
    while (atual != NULL && atual->info.chave != chave) {
        ant = atual;
        atual = atual->prox;
    }
    
    if (atual == NULL) return 0; // Chave não encontrada
    
    if (ant == NULL) {
        L->head = atual->prox; // Remover o primeiro
    } else {
        ant->prox = atual->prox;
    }
    
    free(atual);
    return 1;
}

void exibir(Lista *L) {
    No *atual = L->head;
    while (atual != NULL) {
        printf("[%d: %s] ", atual->info.chave, atual->info.x);
        atual = atual->prox;
    }
}

int buscar(Lista *L, int chave, tipo_elem *v) {
    No *atual = L->head;
    while (atual != NULL) {
        if (atual->info.chave == chave) {
            *v = atual->info;
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int tamanho(Lista *L) {
    int cont = 0;
    No *atual = L->head;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

int contar_maiores(Lista *L, int chave) {
    int cont = 0;
    No *atual = L->head;
    while (atual != NULL) {
        if (atual->info.chave > chave) {
            cont++;
        }
        atual = atual->prox;
    }
    return cont;
}
//recursivas

int tamanho_rec_aux(No *atual) {
    if (atual == NULL) return 0;
    return 1 + tamanho_rec_aux(atual->prox);
}

int tamanho_rec(Lista *L) {
    return tamanho_rec_aux(L->head);
}


int buscar_rec_aux(No *atual, int chave, tipo_elem *v) {
    if (atual == NULL) return 0;
    if (atual->info.chave == chave) {
        *v = atual->info;
        return 1;
    }
    return buscar_rec_aux(atual->prox, chave, v);
}

int buscar_rec(Lista *L, int chave, tipo_elem *v) {
    return buscar_rec_aux(L->head, chave, v);
}


void exibir_rec_aux(No *atual) {
    if (atual == NULL) return;
    printf("[%d: %s] ", atual->info.chave, atual->info.x);
    exibir_rec_aux(atual->prox);
}

void exibir_rec(Lista *L) {
    exibir_rec_aux(L->head);
}


void exibir_inverso_rec_aux(No *atual) {
    if (atual == NULL) return;
    exibir_inverso_rec_aux(atual->prox);
    printf("[%d: %s] ", atual->info.chave, atual->info.x);
}

void exibir_inverso_rec(Lista *L) {
    exibir_inverso_rec_aux(L->head);
}


int contar_maiores_rec_aux(No *atual, int chave) {
    if (atual == NULL) return 0;
    int eh_maior = (atual->info.chave > chave) ? 1 : 0;
    return eh_maior + contar_maiores_rec_aux(atual->prox, chave);
}

int contar_maiores_rec(Lista *L, int chave) {
    return contar_maiores_rec_aux(L->head, chave);
}