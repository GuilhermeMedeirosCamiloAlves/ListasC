#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// --- Funções Auxiliares para Recursividade ---

void aux_exibir_rec(Lista *L, int i) {
    if (i < L->n) {
        printf("Posicao [%d] -> Chave: %d | Descricao: %s\n", i, L->dados[i].chave, L->dados[i].x);
        aux_exibir_rec(L, i + 1);
    }
}

void aux_exibir_inv_rec(Lista *L, int i) {
    if (i < L->n) {
        aux_exibir_inv_rec(L, i + 1);
        printf("Posicao [%d] -> Chave: %d | Descricao: %s\n", i, L->dados[i].chave, L->dados[i].x);
    }
}

int aux_busca_rec(Lista *L, int chave, tipo_elem *v, int i) {
    if (i >= L->n) {
        return 0; // Não encontrou
    }
    if (L->dados[i].chave == chave) {
        *v = L->dados[i];
        return 1;
    }
    return aux_busca_rec(L, chave, v, i + 1);
}

int aux_tamanho_rec(Lista *L, int i) {
    if (i >= L->n) {
        return 0;
    }
    return 1 + aux_tamanho_rec(L, i + 1);
}

int aux_contar_maiores_rec(Lista *L, int chave, int i) {
    if (i >= L->n) {
        return 0;
    }
    int eh_maior = (L->dados[i].chave > chave) ? 1 : 0;
    return eh_maior + aux_contar_maiores_rec(L, chave, i + 1);
}

// --- Funções Principais do TAD ---

void iniciar (Lista *L) {
    L->n = 0;
}

void destruir (Lista *L) {
    L->n = 0;
}

int vazia (Lista *L) {
    return (L->n == 0);
}

int inserir_inicio (Lista *L, tipo_elem v) {
    if (L->n == MAX) {
        return 0;
    }
    for (int i = L->n; i > 0; i--) {
        L->dados[i] = L->dados[i - 1]; 
    }
    L->dados[0] = v;
    L->n++;
    return 1;
}

int inserir_final (Lista *L, tipo_elem v) {
    if (L->n == MAX) {
        return 0;
    }
    L->dados[L->n] = v;
    L->n++;
    return 1;
}

int inserir_ord (Lista *L, tipo_elem v) {
    if (L->n == MAX) {
        return 0;
    }
    int pos = 0;
    while (pos < L->n && L->dados[pos].chave < v.chave) {
        pos++;
    }
    for (int i = L->n; i > pos; i--) {
        L->dados[i] = L->dados[i - 1];
    }
    L->dados[pos] = v;
    L->n++;
    return 1; // Sucesso
}

int remover (Lista *L, int chave) {
    int pos = -1;
    for (int i = 0; i < L->n; i++) {
        if (L->dados[i].chave == chave) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        return 0; // Não encontrou
    }
    for (int i = pos; i < L->n - 1; i++) {
        L->dados[i] = L->dados[i + 1];
    }
    L->n--;
    return 1;
}

int remover_inicio (Lista *L) {
    if (L->n == 0) return 0;
    for (int i = 0; i < L->n - 1; i++) {
        L->dados[i] = L->dados[i + 1];
    }
    L->n--;
    return 1;
}

int remover_final (Lista *L) {
    if (L->n == 0) return 0;
    L->n--; 
    return 1;
}

void exibir (Lista *L) {
    if (L->n == 0) return;
    printf("\n--- Conteudo da Lista ---\n");
    for (int i = 0; i < L->n; i++) {
        printf("Posicao [%d] -> Chave: %d | Descricao: %s\n", i, L->dados[i].chave, L->dados[i].x);
    }
}

void exibir_rec (Lista *L) {
    if (L->n == 0) return;
    printf("\n--- Exibicao Recursiva ---\n");
    aux_exibir_rec(L, 0);
}

void exibir_inverso_rec (Lista *L) {
    if (L->n == 0) return;
    printf("\n--- Exibicao Inversa Recursiva ---\n");
    aux_exibir_inv_rec(L, 0); 
}

int buscar (Lista *L, int chave, tipo_elem *v) {
    for (int i = 0; i < L->n; i++) {
        if (L->dados[i].chave == chave) {
            *v = L->dados[i];
            return 1;
        }
    }
    return 0;
}

int buscar_rec (Lista *L, int chave, tipo_elem *v) {
    return aux_busca_rec(L, chave, v, 0);
}

int tamanho (Lista *L) {
    return L->n;
}

int tamanho_rec (Lista *L) {
    return aux_tamanho_rec(L, 0);
}

int contar_maiores (Lista *L, int chave) {
    int contador = 0;
    for (int i = 0; i < L->n; i++) {
        if (L->dados[i].chave > chave) {
            contador++;
        }
    }   
    return contador;
}

int contar_maiores_rec (Lista *L, int chave) {
    return aux_contar_maiores_rec(L, chave, 0);
}