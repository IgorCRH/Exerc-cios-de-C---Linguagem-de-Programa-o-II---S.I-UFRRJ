#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
int x, par, totalnum, totalnum2, somaimpar, totalimpar, totalpar, maior, menor, escolha;
float mediaimpar, perpar;

maior = x;
menor = x;
totalnum = 0;
totalpar = 0;
totalimpar = 0;
somaimpar = 0;

do{

printf("Digite um numero inteiro:");
scanf("%d", &x);

totalnum++;

if (x % 2 != 0){
totalimpar++;
somaimpar += x;
}
if (x % 2 == 0){
totalpar++;
perpar = totalpar;
}
if (x<menor)
{
maior = x;
}
else
menor = x;
} while (x > 0);

mediaimpar = somaimpar/totalimpar;
printf("Os numeros lidos foram: %d\n", totalnum);
printf("Os numeros pares lidos foram: %d\n", totalpar);
printf("O percentual dos numeros pares eh: %.1f%%\n", (perpar/totalnum)*100);
printf("A media dos numeros impares eh: %f\n", mediaimpar);
printf("O menor numero eh %d e o maior %d", maior, menor);
}
