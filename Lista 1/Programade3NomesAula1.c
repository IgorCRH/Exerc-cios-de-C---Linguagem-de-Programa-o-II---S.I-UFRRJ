#include <stdio.h>

int main(){

    char nome[3][30];
    int i, idade[3];

    for(i = 0; i < 3; i++){
        printf("Digite nome e nota do estudante: ");
        scanf("%s%d", &nome[i], &idade[i]);
    }

    printf("\n\tNome\tIdade\n");
    for(i = 0; i < 3; i++)
        printf("\t%s\t%.2d\n", nome[i], idade[i]);

    return 0;
}
