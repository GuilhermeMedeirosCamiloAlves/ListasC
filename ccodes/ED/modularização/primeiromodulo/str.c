#include<stdio.h>
#include "str.h"
#include <stdlib.h>

int comprimento(char *s){
    int cont =0;
    for(int i=0; s[i]!= '\0';cont++, i++ );
    return cont;
}
void concatena(char *destino, char *origem){
  
}
void copia(char *destino, char *origem){
    while(*origem)
    *(destino++) = *(origem++);
}