#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int divisores (int m)
{
int n, p, teste;

printf("Digite numero de valor para m:\n");
scanf("%d", &m);

if (m % 2 == 0) {
printf("\n Sao divisores de (%d): ", m);
p = 0;
for (n=1; n <= m; ++n){
if (m % n == 0){
printf("%d,", n);
p++;
}
}
printf("\n Quantidade de divisores: %d\n", p);
}
else printf("Esse numero nao eh par.");
}

int fatorial (int m)
{
int fat;

printf("Digite numero de valor para m:\n");
scanf("%d", &m);

if (m % 2 != 0 && m < 10){
if (m <= 1){
fat = 1;
printf("O fatorial de M eh: %d", fat);
}
else{
for (fat = 1; m > 1; m = m-1)
fat = fat*m;
printf("O fatorial de M eh: %d", fat);
}
}
else printf ("Esse numero nao e impar ou menor que 10.");
}

int soma (int m)
{
int i, somar;

printf("Digite numero de valor para m:\n");
scanf("%d", &m);

somar=0;
i=0;

if (m % 2 != 0 && m > 10){
for (i = 1; i <= m; i++){
somar = somar + i;
}
printf("A soma dos inteiros de 1 ate %d eh: %d\n", m, somar);
}
else printf ("Esse numero nao e impar ou maior que 10.");
}

main() {
int m, x;
char opc;

printf("Escolha a opcao desejada:\n");
printf("1 - Ver os Divisores:\n");
printf("2 - Calcular o fatorial:\n");
printf("3 - Calcular a soma dos inteiros de 1 até m:\n");
printf("4 - Encerrar.\n");
scanf("%d", &opc) ;

switch (opc) {
case 1: divisores(m);
break;
case 2: fatorial(m);
break;
case 3: soma(m);
break;
case 4: printf("Fim.");
system ("pause");
}

return 0;
}
