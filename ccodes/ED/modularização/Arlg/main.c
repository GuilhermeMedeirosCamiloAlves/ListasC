#include<stdio.h>
#include"lista.h"

int main(){
    
    Lista lista;
    
    inicialista(&lista);
    mostrarista(&lista);
    adicionaritem(8, &lista);
    adicionaritem(6, &lista);
    adicionaritem(5, &lista);
    adicionaritem(4, &lista);
    adicionaritem(1111, &lista);

    mostrarista(&lista);
    /*mostrarista(&lista);
    
    int p=1;
    adicionaritem(p, ll);
    mostrarista(ll);
    return 0;
    */
}