#include "lista.h"
void iniciar(Fila *f){
    f->inicio = f->fim =0;
}
int Vazia(Fila *f){
    return(f->fim == f->inicio);
}
int Cheia(Fila *f){
    return((f->fim +1)%MAX== f->inicio);
}
void exibir(Fila *f){
    int i;
    if(Vazia(f)!= 1){
        printf("ta vazio meu chapa");
    }
    else{    
        while(i!= (f-> fim +1)%MAX){
            printf("%d", f->a[i]);
            i=(i+1)%MAX;
        }
    }
}
tipoelem primeiro(Fila *f){
    return(f->a[f->(inicio+1)%MAX]);
}
int tamanho(Fila *f){
    if(f->inicio >= f->fim)
        return(f->fim - f->inicio);

    return(MAX-f->inicio + f->fim);
}
int enfileirar (Fila *f, tipoelem v){
    if(cheia(f))
        return 0;
    f->fim = fim(f->fim+1)%MAX;
    f->a[f->fim]= v;
    return 1;

}
int desenfileirar(Fila *f){
    if(Vazia(f))
        return 0;
    f->inicio = (f->inicio+1)%MAX;
    
}
int destruir(Fila *f){
    f->fim = f->inicio = 0;
}
