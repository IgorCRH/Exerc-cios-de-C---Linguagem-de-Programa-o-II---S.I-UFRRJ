#include <stdio.h>
#include <stdlib.h>

main () {
int vet[100], i = 0, n, j = 0, qtd = 0, maior, contmaior = 0;
memset(&vet, 0, sizeof(vet));
char opcao;


do {
printf("Entre com numero: ");
scanf("%d", &n);
vet[qtd] = n;
qtd++;
printf("Aperte f para encerrar.\n");
scanf("%c", &opcao);

} while (opcao != 'f' && opcao != 'F');

maior = vet[0];
for (i = 0 ; i < 100; i++){
if (vet[i] > maior){
maior = vet[i];
}
}

for (j = 0 ; j < 100; j++){
if (maior == vet[j]){
contmaior++;
}
}

printf("O maior elemento eh: %d\n", maior);
printf("E esse valor apareceu na quantidade de %d vezes\n", contmaior);

}

