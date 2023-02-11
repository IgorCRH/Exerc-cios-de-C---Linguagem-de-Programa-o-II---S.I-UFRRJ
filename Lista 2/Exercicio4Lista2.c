#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int divisao  (int divisor, int dividendo)
{
return divisor - dividendo;
}

main() {

int divisor = 0;
int dividendo = 0;
int quoc = 0;
int i =0;
int resto=0;

do{

printf("Digite dois numeros inteiros, divisor e dividendo:");
scanf("%d %d", &divisor, &dividendo);

resto = divisor;
quoc = divisao(divisor,dividendo);
i++;

while(quoc >= dividendo){
i++;
quoc = divisao(quoc,dividendo);
}
while(dividendo < resto){
resto = resto-dividendo;
}
printf("%d dividido por %d , totalizando %d e resto %d\n",divisor,dividendo,i,resto);
i=0;

} while(divisor != 0);

system("pause");
}
