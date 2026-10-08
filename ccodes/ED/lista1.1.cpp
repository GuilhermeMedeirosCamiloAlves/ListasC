#include<stdio.h>
#include<string.h>
/* int main(){
    int x;
    printf("\n digite um numero para saber se é par ou impar\n");
    scanf("%d", &x);
    if(2%x != 0){
        printf("%d é par \n", x);
    }
    else printf("%d é impar", x);
}
int main(){
    float x, y, z, media;
    printf("Coloque 3 notas para descobrir a media \n");
    scanf("%f %f %f", &x,&y,&z);
    media = (x+y+z)/3;
    printf("A media foi %f", media);

}

int main(){
    int x;
    scanf("%d", &x);
    for(int i=0;i<10;i++){
        printf("%d * %d = %d \n",x,i,x*i);
    }

}

int main(){
    int x, i=2, y=1;
    scanf("%d", &x);
    while(i<=x){
        y=i*y;
        i++;
        printf("%d \n", y);
    }
}

int main(){
    int x;
    scanf("%d", &x);
    for(int i =0; i<x; i+=2){
        printf("%d", i);
    }
}
int main(){
    int x, i=2;
    bool divisivel = false;
    scanf("%d", &x);
    while(i<x){
        if(x%i==0){divisivel = true;}
        i++;
    }
    if(divisivel == false){
        printf("primo");
    }
    else printf("nao primo");
}

int main(){
    char palavra[20], c1, c2;
    bool epalindromo = true;
    scanf("%s", palavra);
    int sz = strlen(palavra);
    for(int i =0; i<sz; i++){
        sz--;
        c1=palavra[i];
        c2=palavra[sz];
        if(c1!=c2){printf("%c e %c não são iguais \n", c1, c2);epalindromo = false;}}
if(epalindromo == false){printf("portanto não é um palindromo");}
else{printf("e um palindromo");}
}
int main(){
    int  j ,sum1;
    int vet[10];
    for(int i=0; i<10; i++){
        scanf("%d", &j);
        vet[i]=j;
        if(vet[i]%2==0)
        sum1+=vet[i];
    }
    printf("a soma dos pares deste vetor é %d", sum1);
}

int main(){
    int tamanho = 3;
    int matriz[tamanho][tamanho];
    int i = 0, j;
    int soma = 0;
    float media;
    printf("Digite os elementos da matriz 3x3:\n");
    while (i < 3) {
        j = 0;
        while (j < 3) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            soma += matriz[i][j];
            j++;
        }
        i++;
    }
    media = (float)soma / (tamanho*tamanho);
    printf("\nA media aritmetica dos elementos e: %.2f\n", media);
    return 0;
}
int main() {
    int tamanhoDaMatriz;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);
    int matrizA[tamanhoDaMatriz][tamanhoDaMatriz];
    int matrizB[tamanhoDaMatriz][tamanhoDaMatriz];
    int soma[tamanhoDaMatriz][tamanhoDaMatriz];
    int i = 0, j;
    printf("\nDigite os elementos da primeira matriz:\n");
    while (i < tamanhoDaMatriz) {
        j = 0;
        while (j < tamanhoDaMatriz) {
            printf("Matriz A[%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
            j++;
        }
        i++;
    }
    i = 0;
    printf("\nDigite os elementos da segunda matriz:\n");
    while (i < tamanhoDaMatriz) {
        j = 0;
        while (j < tamanhoDaMatriz) {
            printf("Matriz B[%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
            j++;
        }
        i++;
    }
    i = 0;

    while (i < tamanhoDaMatriz) {
        j = 0;
        while (j < tamanhoDaMatriz) {
            soma[i][j] = matrizA[i][j] + matrizB[i][j];
            j++;
        }
        i++;
    }
    printf("\nMatriz resultante:\n");
    i = 0;
    while (i < tamanhoDaMatriz) {
        j = 0;
        while (j < tamanhoDaMatriz) {
            printf("%d ", soma[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}

int main() {
    char texto[100];
    int i = 0;
    int encontrou = 0;
    printf("Digite uma string: ");
    fgets(texto, 100, stdin);
    while (texto[i] != '\0') {
        if (texto[i] == 'c' && texto[i + 1] == 'a' &&  texto[i + 2] == 's' && texto[i + 3] == 'a') {

            encontrou = 1;
        }
        i++;
    }
    if (encontrou == 1) {
        printf("A string contem a substring \"casa\".\n");
    } else {
        printf("A string nao contem a substring \"casa\".\n");
    }
    return 0;
}
    int main() {
    char texto[100];
    int vogais = 0;
    int i;
    printf("Digite uma string: ");
    fgets(texto, 100, stdin);
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == 'a' || texto[i] == 'e' ||
            texto[i] == 'i' || texto[i] == 'o' ||
            texto[i] == 'u') {

            vogais++;
        }
    }
    printf("Numero de vogais: %d\n", vogais);
    return 0;
}
    int main() {
    int tamanhoDaMatriz;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);
    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];
    int i = 0, j;
    int maior;
    while (i < tamanhoDaMatriz) {
        j = 0;
        while (j < tamanhoDaMatriz) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            j++;
            }
        i++;
    }
    maior = matriz[0][0];
    i = 0;
    while (i < tamanhoDaMatriz) {
        j = 0;
        while (j < tamanhoDaMatriz) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            j++;
        }
        i++;
    }
    printf("\nMaior numero da matriz: %d\n", maior);
    return 0;
}

int main() {
    int tamanhoDoVetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoDoVetor);
    int vetor[tamanhoDoVetor];
    int menor;
    for (int i = 0; i < tamanhoDoVetor; i++) {
        printf("Digite o elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }
    menor = vetor[0];
    for (int i = 1; i < tamanhoDoVetor; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    printf("\nMenor numero do vetor: %d\n", menor);
    return 0;
}

int main() {
    char texto[100];
    printf("Digite uma string: ");
    fgets(texto, 100, stdin);
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == 'a') {
            texto[i] = 'b';
        }
    }
    printf("Nova string: %s", texto);
    return 0;
}

int main() {
    int tamanhoDaMatriz;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);
    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];
    int soma = 0;
    int i = 0, j;
    while (i < tamanhoDaMatriz) {
        j = 0;
        while (j < tamanhoDaMatriz) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            j++;
        }
        i++;
    }
    i = 0;
    while (i < tamanhoDaMatriz) {
        soma += matriz[i][i];
        i++;
    }
    printf("\nSoma da diagonal principal: %d\n", soma);
    return 0;
}
    int main() {
    char texto[100];
    int i = 0;
    int ocorrencias = 0;
    printf("Digite uma string: ");
    fgets(texto, 100, stdin);
    while (texto[i] != '\0') {
        if (texto[i] == 'e') {
            ocorrencias++;
        }
        i++;
    }
    printf("Numero de ocorrencias da letra 'e': %d\n", ocorrencias);
    return 0;
}

int main() {
    int tamanhoDaMatriz;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);
    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];
    int soma = 0;
    int i = 0, j;
    while (i < tamanhoDaMatriz) {
        j = 0;

        while (j < tamanhoDaMatriz) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            j++;
        }

        i++;
    }
    i = 0;
    while (i < tamanhoDaMatriz) {
        soma += matriz[i][tamanhoDaMatriz - 1 - i];
        i++;
    }
    printf("\nSoma da diagonal secundaria: %d\n", soma);
    return 0;
    int main() {
    int tamanhoDoVetor;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoDoVetor);

    int vetor[tamanhoDoVetor];
    int maior, segundoMaior;

    for (int i = 0; i < tamanhoDoVetor; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    segundoMaior = vetor[0];

    for (int i = 1; i < tamanhoDoVetor; i++) {
        if (vetor[i] > maior) {
            segundoMaior = maior;
            maior = vetor[i];
        } else if (vetor[i] > segundoMaior && vetor[i] != maior) {
            segundoMaior = vetor[i];
        }
    }

    printf("Segundo maior numero: %d\n", segundoMaior);

    return 0;
}
int main() {
    char texto[100];
    int tamanho = 0;

    printf("Digite uma string: ");
    fgets(texto, 100, stdin);

    while (texto[tamanho] != '\0') {
        tamanho++;
    }

    tamanho--;

    printf("String invertida: ");

    while (tamanho >= 0) {
        if (texto[tamanho] != '\n') {
            printf("%c", texto[tamanho]);
        }

        tamanho--;
    }

    printf("\n");

    return 0;
}
    int main() {
    int tamanhoDaMatriz;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);

    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];
    int i = 0, j;
    int produto;

    while (i < tamanhoDaMatriz) {
        j = 0;

        while (j < tamanhoDaMatriz) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            j++;
        }

        i++;
    }

    i = 0;

    while (i < tamanhoDaMatriz) {
        j = 0;
        produto = 1;

        while (j < tamanhoDaMatriz) {
            produto *= matriz[i][j];
            j++;
        }

        printf("Produto da linha %d: %d\n", i, produto);
        i++;
    }

    return 0;
}
    int main() {
    char texto[200];
    int inicio = 0;
    int fim;
    int quantidade;

    printf("Digite uma string: ");
    fgets(texto, 200, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] != ' ' && texto[i] != '\n') {
            if (inicio == 0) {
                inicio = i + 1;
            }
        } else {
            if (inicio != 0) {
                fim = i;
                quantidade = fim - (inicio - 1);

                if (quantidade > 5) {
                    for (int j = inicio - 1; j < fim; j++) {
                        printf("%c", texto[j]);
                    }

                    printf("\n");
                }

                inicio = 0;
            }
        }
    }

    return 0;
}
    int main() {
    int tamanhoDaMatriz;
    int simetrica = 1;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);

    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];
    int i = 0, j;

    while (i < tamanhoDaMatriz) {
        j = 0;

        while (j < tamanhoDaMatriz) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            j++;
        }

        i++;
    }

    i = 0;

    while (i < tamanhoDaMatriz) {
        j = 0;

        while (j < tamanhoDaMatriz) {
            if (matriz[i][j] != matriz[j][i]) {
                simetrica = 0;
            }

            j++;
        }

        i++;
    }

    if (simetrica == 1) {
        printf("A matriz e simetrica.\n");
    } else {
        printf("A matriz nao e simetrica.\n");
    }

    return 0;
}
    int main() {
    int tamanhoDoVetor;
    int soma = 0;
    int quantidade = 0;
    float media;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoDoVetor);

    int vetor[tamanhoDoVetor];

    for (int i = 0; i < tamanhoDoVetor; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);

        if (vetor[i] % 2 == 0) {
            soma += vetor[i];
            quantidade++;
        }
    }

    if (quantidade > 0) {
        media = (float)soma / quantidade;
        printf("Media dos numeros pares: %.2f\n", media);
    } else {
        printf("Nao existem numeros pares no vetor.\n");
    }

    return 0;
}
    int main() {
    char texto[200];
    char letras[200];
    int quantidade = 0;
    int palindromo = 1;

    printf("Digite uma string: ");
    fgets(texto, 200, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z') ||
            (texto[i] >= 'A' && texto[i] <= 'Z')) {

            if (texto[i] >= 'A' && texto[i] <= 'Z') {
                letras[quantidade] = texto[i] + 32;
            } else {
                letras[quantidade] = texto[i];
            }

            quantidade++;
        }
    }

    for (int i = 0; i < quantidade / 2; i++) {
        if (letras[i] != letras[quantidade - 1 - i]) {
            palindromo = 0;
        }
    }

    if (palindromo == 1) {
        printf("A string e um palindromo.\n");
    } else {
        printf("A string nao e um palindromo.\n");
    }

    return 0;
}
    int main() {
    int tamanhoDaMatriz;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);

    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];
    int i = 0, j;
    int apenasPares;

    while (i < tamanhoDaMatriz) {
        j = 0;

        while (j < tamanhoDaMatriz) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            j++;
        }

        i++;
    }

    printf("\nLinhas com apenas elementos pares:\n");

    i = 0;

    while (i < tamanhoDaMatriz) {
        j = 0;
        apenasPares = 1;

        while (j < tamanhoDaMatriz) {
            if (matriz[i][j] % 2 != 0) {
                apenasPares = 0;
            }

            j++;
        }

        if (apenasPares == 1) {
            printf("Linha %d\n", i);
        }

        i++;
    }

    printf("\nColunas com apenas elementos pares:\n");

    j = 0;

    while (j < tamanhoDaMatriz) {
        i = 0;
        apenasPares = 1;

        while (i < tamanhoDaMatriz) {
            if (matriz[i][j] % 2 != 0) {
                apenasPares = 0;
            }

            i++;
        }

        if (apenasPares == 1) {
            printf("Coluna %d\n", j);
        }

        j++;
    }

    return 0;
}
    int main() {
    int tamanhoDoVetor;
    int soma = 0;
    int i = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoDoVetor);

    int vetor[tamanhoDoVetor];

    while (i < tamanhoDoVetor) {
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);

        if (vetor[i] % 2 != 0) {
            soma += vetor[i];
        }

        i++;
    }

    printf("Soma dos numeros impares: %d\n", soma);

    return 0;
}
    int main() {
    char texto[100];

    printf("Digite uma string: ");
    fgets(texto, 100, stdin);

    printf("String sem vogais: ");

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] != 'a' && texto[i] != 'e' &&
            texto[i] != 'i' && texto[i] != 'o' &&
            texto[i] != 'u' && texto[i] != 'A' &&
            texto[i] != 'E' && texto[i] != 'I' &&
            texto[i] != 'O' && texto[i] != 'U') {

            printf("%c", texto[i]);
        }
    }

    return 0;
}
    int main() {
    int tamanhoDaMatriz;
    int diagonal = 1;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &tamanhoDaMatriz);

    int matriz[tamanhoDaMatriz][tamanhoDaMatriz];
    int i = 0, j;

    while (i < tamanhoDaMatriz) {
        j = 0;

        while (j < tamanhoDaMatriz) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            j++;
        }

        i++;
    }

    i = 0;

    while (i < tamanhoDaMatriz) {
        j = 0;

        while (j < tamanhoDaMatriz) {
            if (i != j && matriz[i][j] != 0) {
                diagonal = 0;
            }

            j++;
        }

        i++;
    }

    if (diagonal == 1) {
        printf("A matriz e diagonal.\n");
    } else {
        printf("A matriz nao e diagonal.\n");
    }

    return 0;
}
 */