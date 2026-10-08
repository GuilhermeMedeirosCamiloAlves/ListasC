#include "lista.h"
#include <stdio.h>
void inicialista(Lista *lista){
    int i;
    lista->inicio =-1;
    lista->dispo =0;
    for(i=0; i<Max-1; i++){
        lista->item[i].prox=i+1;
    }
     lista->item[i].prox=-1;
}
int cheia(Lista *lista){
    return(lista->dispo==-1);

}
int vazia(Lista *l){
return(l->inicio==-1);
}
int adicionaritem(int p, Lista *lista){
    int j=lista->dispo;
  
    if(cheia (lista))
        return 0;
    else{
        lista->dispo=lista->item[j].prox;
        lista->item[j].elemento.chave = p;
        lista->item[j].prox=lista->inicio;
        lista->inicio = j;
        return 1;
    }
}

void removeritemporindice(int p, Lista *lista){


    
}
void limparista(Lista *lista){
    inicialista(lista);
}
void mostrarista( Lista *lista){
    int i;
    if(vazia(lista)){
        printf("ta vazia\n");
    }
    else{
        for(i = lista->inicio; lista->item[i].prox != -1; i=lista->item[i].prox){
            printf("[%d]", lista->item[i].elemento.chave);
        }
        printf("[%d]", lista->item[i].elemento.chave);
    }
        
}
void trocaritemdeugar(int a, int b, Lista *lista){


    
}
int buscaritem(int p,Lista *lista){


    
}