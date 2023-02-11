#include <stdio.h>
#include <math.h>

main() {
int n, totalnumeros, cont, cont2, soma, maior, menor;
float medianumeros;

totalnumeros = 0;
cont = 0;
maior = n;
menor = n;

while (n >= 0) {
printf("Digite um numero: ");
scanf("%d", &n);
totalnumeros = totalnumeros+1;
printf("A quantidade de numeros lidos eh de: %d\n", totalnumeros);
cont++;
soma += n;
medianumeros = soma/cont;
printf("A media dos numeros lidos eh de: %lf\n", medianumeros);
if (n<menor)
{
menor = n;
}
else
maior = n;
}

printf("| O menor numero eh: %d\n", menor);
printf("| O maior numero eh: %d\n", maior);

return 0;
}

