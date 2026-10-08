#include"lista.h"
#include<stdio.h>
void inicialista(Lista *lista){
    lista->tamanho=0;
}

void adicionaritem(int p, Lista *lista){
        lista->e[lista->tamanho].element = p;
        lista->tamanho++;
}
void removeritemporindice(int p, Lista *lista){
    
}

void limparista(int p, Lista *lista){
    
}

void mostrarista(Lista *lista){
    for(int i=0; i<=lista->tamanho;i++){
        printf("[%d]", lista->e[i].element);
    }
}

void trocaritemdeugar(int a, int b, Lista *lista){
    
}

int buscaritem(int p,Lista *lista){


    
}