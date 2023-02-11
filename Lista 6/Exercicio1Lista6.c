#include <stdio.h>
#include <stdlib.h>
#include "Exercicio1Lista6.h"

void inicializa (data *num) {

printf("Entre com um dia");
scanf("%d", &num->dia);
printf("Entre com um mes");
scanf("%d", &num->mes);
printf("Entre com um ano");
scanf("%d", &num->ano);
}

int valida (data num) {
if (num.dia > 31 || num.dia == 30 && (num.mes==4)||(num.mes==6)||(num.mes==9)||(num.mes==11)){
return 0;
}
if (num.mes > 12){
return 0;
}
if (num.dia > 28 && num.mes == 2){
return 0;
}
}

void imprime (data num) {
printf("A sua data é: %d\%d\%d",num.dia,num.mes,num.ano);
}

int main (){
data num2;

inicializa(&num2);

if (valida(num2)){
imprime(num2);
}
else {
printf("A data nao eh valida");
}

}
