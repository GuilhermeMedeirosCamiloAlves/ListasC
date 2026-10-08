#include<stdio.h>
#include "racionais.h"
int main(){
    racional rr;
    rr.Den=1;
    rr.num=55;
    racional rr2;
    rr2.Den=1;
    rr2.num=3;
    TestaIgualdade(rr, rr2);
    Soma(rr, rr2);
    return 0;
}