#include <stdio.h>
#include "lista.h"


int obter_no(Lista *L) {
    int res = L->dispo;
    if (res != -1) {
        L->dispo = L->nos[res].prox;
    }
    return res;
}

// Devolve um índice à lista de posições disponíveis (reutilização)
void liberar_no(Lista *L, int indice) {
    L->nos[indice].prox = L->dispo;
    L->dispo = indice;
}


void iniciar(Lista *L) {
    // Encadeia todas as posições livres inicialmente
    for (int i = 0; i < MAX - 1; i++) {
        L->nos[i].prox = i + 1;
    }
    L->nos[MAX - 1].prox = -1; // Último nó disponível aponta para -1 (nulo)
    
    L->inicio = -1; // Lista lógica inicia vazia
    L->dispo = 0;   // Primeiro nó disponível é o índice 0
}

void destruir(Lista *L) {
    iniciar(L); // Ao reiniciar, todos os nós voltam para a lista de disponíveis
}

int vazia(Lista *L) {
    return L->inicio == -1;
}

int inserir_inicio(Lista *L, tipo_elem v) {
    int novo = obter_no(L);
    if (novo == -1) return 0; // Lista cheia
    
    L->nos[novo].info = v;
    L->nos[novo].prox = L->inicio;
    L->inicio = novo;
    return 1;
}

int inserir_final(Lista *L, tipo_elem v) {
    int novo = obter_no(L);
    if (novo == -1) return 0;
    
    L->nos[novo].info = v;
    L->nos[novo].prox = -1;
    
    if (vazia(L)) {
        L->inicio = novo;
    } else {
        int atual = L->inicio;
        while (L->nos[atual].prox != -1) {
            atual = L->nos[atual].prox;
        }
        L->nos[atual].prox = novo;
    }
    return 1;
}

int inserir_ord(Lista *L, tipo_elem v) {
    int novo = obter_no(L);
    if (novo == -1) return 0;
    
    L->nos[novo].info = v;
    
    // Inserir no início ou se a lista estiver vazia
    if (vazia(L) || L->nos[L->inicio].info.chave >= v.chave) {
        L->nos[novo].prox = L->inicio;
        L->inicio = novo;
        return 1;
    }
    
    // Percorrer para encontrar a posição correta
    int atual = L->inicio;
    int ant = -1;
    
    while (atual != -1 && L->nos[atual].info.chave < v.chave) {
        ant = atual;
        atual = L->nos[atual].prox;
    }
    
    L->nos[ant].prox = novo;
    L->nos[novo].prox = atual;
    
    return 1;
}

int remover_inicio(Lista *L) {
    if (vazia(L)) return 0;
    
    int apagado = L->inicio;
    L->inicio = L->nos[apagado].prox;
    liberar_no(L, apagado);
    return 1;
}

int remover_final(Lista *L) {
    if (vazia(L)) return 0;
    
    int atual = L->inicio;
    int ant = -1;
    
    while (L->nos[atual].prox != -1) {
        ant = atual;
        atual = L->nos[atual].prox;
    }
    
    if (ant == -1) { // Só havia um elemento
        L->inicio = -1;
    } else {
        L->nos[ant].prox = -1;
    }
    
    liberar_no(L, atual);
    return 1;
}

int remover(Lista *L, int chave) {
    if (vazia(L)) return 0;
    
    int atual = L->inicio;
    int ant = -1;
    
    while (atual != -1 && L->nos[atual].info.chave != chave) {
        ant = atual;
        atual = L->nos[atual].prox;
    }
    
    if (atual == -1) return 0; // Não encontrado
    
    if (ant == -1) {
        L->inicio = L->nos[atual].prox; // Era o primeiro
    } else {
        L->nos[ant].prox = L->nos[atual].prox;
    }
    
    liberar_no(L, atual);
    return 1;
}

void exibir(Lista *L) {
    int atual = L->inicio;
    while (atual != -1) {
        printf("[%d: %s] ", L->nos[atual].info.chave, L->nos[atual].info.x);
        atual = L->nos[atual].prox;
    }
}

int buscar(Lista *L, int chave, tipo_elem *v) {
    int atual = L->inicio;
    while (atual != -1) {
        if (L->nos[atual].info.chave == chave) {
            *v = L->nos[atual].info;
            return 1;
        }
        atual = L->nos[atual].prox;
    }
    return 0;
}

int tamanho(Lista *L) {
    int cont = 0;
    int atual = L->inicio;
    while (atual != -1) {
        cont++;
        atual = L->nos[atual].prox;
    }
    return cont;
}

int contar_maiores(Lista *L, int chave) {
    int cont = 0;
    int atual = L->inicio;
    while (atual != -1) {
        if (L->nos[atual].info.chave > chave) {
            cont++;
        }
        atual = L->nos[atual].prox;
    }
    return cont;
}

int tamanho_rec_aux(Lista *L, int atual) {
    if (atual == -1) return 0;
    return 1 + tamanho_rec_aux(L, L->nos[atual].prox);
}

int tamanho_rec(Lista *L) {
    return tamanho_rec_aux(L, L->inicio);
}


int buscar_rec_aux(Lista *L, int chave, tipo_elem *v, int atual) {
    if (atual == -1) return 0;
    if (L->nos[atual].info.chave == chave) {
        *v = L->nos[atual].info;
        return 1;
    }
    return buscar_rec_aux(L, chave, v, L->nos[atual].prox);
}

int buscar_rec(Lista *L, int chave, tipo_elem *v) {
    return buscar_rec_aux(L, chave, v, L->inicio);
}


void exibir_rec_aux(Lista *L, int atual) {
    if (atual == -1) return;
    printf("[%d: %s] ", L->nos[atual].info.chave, L->nos[atual].info.x);
    exibir_rec_aux(L, L->nos[atual].prox);
}

void exibir_rec(Lista *L) {
    exibir_rec_aux(L, L->inicio);
}


void exibir_inverso_rec_aux(Lista *L, int atual) {
    if (atual == -1) return;
    exibir_inverso_rec_aux(L, L->nos[atual].prox);
    printf("[%d: %s] ", L->nos[atual].info.chave, L->nos[atual].info.x);
}

void exibir_inverso_rec(Lista *L) {
    exibir_inverso_rec_aux(L, L->inicio);
}


int contar_maiores_rec_aux(Lista *L, int chave, int atual) {
    if (atual == -1) return 0;
    int eh_maior = (L->nos[atual].info.chave > chave) ? 1 : 0;
    return eh_maior + contar_maiores_rec_aux(L, chave, L->nos[atual].prox);
}

int contar_maiores_rec(Lista *L, int chave) {
    return contar_maiores_rec_aux(L, chave, L->inicio);
}