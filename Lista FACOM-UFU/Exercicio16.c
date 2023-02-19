#include <stdio.h>

// Faça um programa que recebe um vetor de 10 números, converta cada um desses números para binário
// e grave a sequência de 0s e 1s em um arquivo texto. Cada número deve ser gravado em uma linha.

int main() {
    int converternum[10];
    FILE *saida;

    saida = fopen("numbinar.txt", "a");
    if (saida == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        char binario[33];
        sprintf(binario, "%32s", "");
        printf("Entre com os 10 numeros que deseja converter: ");
        scanf("%d",&converternum[i]);
        int num = converternum[i];
        int pos = 31;

        while (num > 0) {
            if (num % 2 == 1) {
                binario[pos] = '1';
            } else {
                binario[pos] = '0';
            }
            pos--;
            num /= 2;
        }
        fprintf(saida, "O numero %d em binario eh: %s\n", converternum[i], binario);
    }
    fclose(saida);
    return 0;
}
