#include <stdio.h>
#include <string.h>
#include "lista.h"

int main () {
    int op;
    Lista L;
    tipo_elem v;
    int chave;

    iniciar(&L);

    do {
        printf("\n1 - Vazia\n");
        printf("2 - Inserir no inicio\n");
        printf("3 - Inserir no final\n");
        printf("4 - Inserir ordenadamente\n");
        printf("5 - Remover do inicio\n");
        printf("6 - Remover do final\n");
        printf("7 - Remover por chave\n");
        printf("8 - Buscar elemento\n");
        printf("9 - Exibir lista\n");
        printf("10 - Exibir lista (rec)\n");
        printf("11 - Exibir lista em ordem inversa (rec)\n");
        printf("12 - Informar tamanho\n");
        printf("13 - Informar tamanho (rec)\n");
        printf("14 - Buscar (rec)\n");
        printf("15 - Contar chaves maiores que X\n");
        printf("16 - Contar chaves maiores que X (rec)\n");
        printf("17 - Destruir lista\n");
        printf("0 - Sair\n");
        printf("> ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                if (vazia(&L))
                    printf("\nLista esta atualmente vazia!\n");
                else
                    printf("\nLista nao esta vazia!\n");
                break;

            case 2:
                printf("\nDigite a chave: ");
                scanf("%d", &v.chave);
                printf("Digite o texto (x): ");
                scanf(" %[^\n]", v.x); 
                
                if (inserir_inicio(&L, v))
                    printf("\nElemento inserido no inicio!\n");
                else
                    printf("Nao foi possivel inserir.\n");
                break;

            case 3:
                printf("\nDigite a chave: ");
                scanf("%d", &v.chave);
                printf("Digite o texto (x): ");
                scanf(" %[^\n]", v.x);
                
                if (inserir_final(&L, v))
                    printf("\nElemento inserido no final!\n");
                else
                    printf("Nao foi possivel inserir.\n");
                break;

            case 4:
                printf("\nDigite a chave: ");
                scanf("%d", &v.chave);
                printf("Digite o texto (x): ");
                scanf(" %[^\n]", v.x);

                if (inserir_ord(&L, v))
                    printf("\nElemento inserido de forma ordenada!\n");
                else
                    printf("Nao foi possivel inserir.\n");
                break;

            case 5:
                if (remover_inicio(&L))
                    printf("\nElemento do inicio removido com sucesso!\n");
                else
                    printf("Falha ao remover.\n");
                break;

            case 6:
                if (remover_final(&L))
                    printf("\nElemento do final removido com sucesso!\n");
                else
                    printf("Falha ao remover.\n");
                break;

            case 7:
                printf("\nChave do elemento que deseja remover: ");
                scanf("%d", &chave);
                if (remover(&L, chave))
                    printf("\nElemento removido com sucesso!\n");
                else
                    printf("\nChave nao encontrada.\n");
                break;

            case 8:
                printf("\nChave que deseja buscar: ");
                scanf("%d", &chave);
                if (buscar(&L, chave, &v))
                    printf("\nEncontrado: Chave %d | Texto: %s\n", v.chave, v.x);
                else
                    printf("\nChave nao encontrada na lista.\n");
                break;

            case 9:
                printf("\n");
                exibir(&L);
                printf("\n");
                break;
                
            case 10:
                printf("\n");
                exibir_rec(&L);
                printf("\n");
                break;
                
            case 11:
                printf("\n");
                exibir_inverso_rec(&L);
                printf("\n");
                break;
            
            case 12:
                printf("\nTamanho: %d elemento(s)\n", tamanho(&L));
                break;
            
            case 13:
                printf("\nTamanho: %d elemento(s)\n", tamanho_rec(&L));
                break;
            
            case 14:
                printf("\nChave que deseja buscar: ");
                scanf("%d", &chave);
                if (buscar_rec(&L, chave, &v))
                    printf("\nEncontrado: Chave %d | Texto: %s\n", v.chave, v.x);
                else
                    printf("\nChave nao encontrada na lista.\n");
                break;
            
            case 15:
                printf("\nChave de referencia: ");
                scanf("%d", &chave);
                printf("\nExistem %d chaves maiores que %d\n", contar_maiores(&L, chave), chave);
                break;
            
            case 16:
                printf("\nChave de referencia: ");
                scanf("%d", &chave);
                printf("\nExistem %d chaves maiores que %d\n", contar_maiores_rec(&L, chave), chave);
                break;
            
            case 17:
                destruir(&L);
                printf("\nLista destruida!\n");
                break;
            
            case 0:
                destruir(&L);
                printf("\nEncerrando o programa...\n");
                break;
            
            default:
                printf("\nValor invalido! Tente novamente.\n");
                break;
        }
    } while (op != 0);
    
    return 0;
}