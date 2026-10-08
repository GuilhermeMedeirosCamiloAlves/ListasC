#include<stdio.h>
#include "racionais.h"

racional Define(int n, int d){
    racional r;
    r.num=n;
    r.Den=d;
    return r;
}
racional Soma(racional R2, racional R1){
    racional r;
    r.num = (R1.num*R2.Den+R1.Den*R2.num);
    r.Den = R1.Den*R2.Den;
    return r;
}
racional Multiplica(racional R1, racional R2){
    racional r;
    r.num = R1.num+R2.num;
    r.Den = R1.Den+R2.Den;
    return r;
}
int TestaIgualdade(racional R1, racional R2){
    if(R1.Den == R2.Den && R1.num == R2.num){
            printf("é igual");
            return 1;
    }

    else return 0;
}
