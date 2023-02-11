#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main (){
int idade, instrucao, opiniao, pespres, pesotimo, totalotimo, maisnovo, maisvelho, totalpese10, pespesimo, sairoucnt, escolha;
float mediaotimo, perpese10;

pesotimo = 0;
pespesimo = 0;
totalpese10 = 0;
maisvelho = idade;
maisnovo = idade;

do {
printf("Informe a sua idade: ");
scanf ("%d", &idade);
printf("Informe o grau de instrucao: ");
scanf ("%d", &instrucao);
printf("De a opiniao sobre o filme: \n");
printf("1 - Otimo | 2 - Regular | 3 - Pessimo. \n");
scanf ("%d", &opiniao);

pespres++;

if (opiniao == 1){
totalotimo++;
pesotimo += idade;
}
if (instrucao > 10){
totalpese10++;
}
if (opiniao == 3){
pespesimo += idade;
}
if (idade<maisvelho)
{
maisnovo = idade;
}
else
maisvelho = idade;
printf("Digite 1 para continuar e 2 para encerrar: ");
scanf ("%d", &escolha);
} while(1 == escolha);

mediaotimo = pesotimo/totalotimo;
perpese10 = (pespesimo/totalpese10)*100;
printf("A media de idade dos que responderam otimo eh: %f\n", mediaotimo);
printf("O telespectador mais velho tem %d e o mais novo tem %d\n", maisvelho, maisnovo);
printf("O percentual de pessoas com mais de 10 anos de instrucao\n");
printf("e que responderam pessimo eh de: %f", perpese10);

return 0;
}
