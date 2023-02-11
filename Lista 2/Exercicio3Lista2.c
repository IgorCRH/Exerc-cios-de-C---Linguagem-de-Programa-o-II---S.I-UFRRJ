#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
int idade, cont21, total60, idades60, soma;
float media60;

cont21 = 0;
total60 = 0;
soma = 0;

printf("Digite a idade: ");
scanf("%d", &idade);

while (idade > 0) {
if (idade > 21)
cont21++;
if (idade > 60){
total60++;
soma += idade;
media60 = soma/total60;
}
printf("Digite a idade para continuar ou encerrar: ");
scanf("%d", &idade);
}
printf("A quantidade de pessoas com mais de 21 anos eh de: %d\n", cont21);
printf("A media de pessoas com mais de 60 anos eh de: %.2f\n", media60);

return 0;
}
