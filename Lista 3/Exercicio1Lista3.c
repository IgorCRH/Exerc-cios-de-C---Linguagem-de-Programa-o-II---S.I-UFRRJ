#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fator ()
{
int fat, x, i, n;

printf("Digite um valor de x:");
scanf("%d", &x);

if (x <= 1){
fat = 1;
printf("O fatorial de X eh: %d", fat);
}
else{
for (fat = 1; x > 1; x = x-1)
fat = fat*x;
printf("O fatorial de X eh: %d", fat);
}
}

int xy ()
{
int xy, x,y;

printf("Digite um valor de x e y:");
scanf("%d %d", &x, &y);

if (x == 0){
xy = 0;
printf("X elevado Y eh: %d", xy);
}
else if (y == 1){
xy = x;
printf("X elevado Y eh: %d", xy);
}
else {
xy = x*(pow(x,y-1));
printf("X elevado Y eh: %d", xy);
}
}

int soma ()
{
int som, x,y;

printf("Digite um valor de x e y:");
scanf("%d %d", &x, &y);

if (x == 0){
som = 0;
printf("A soma das sequencias sucessivas eh: %d", som);
}
else if (x == 0 && y == 0){
som = x;
printf("A soma das sequencias sucessivas eh: %d", som);
}
else{
som = x+(x*y-1);
printf("A soma das sequencias sucessivas eh: %d", som);
}
}

int mod ()
{
int md, x,y;

printf("Digite um valor de x e y:");
scanf("%d %d", &x, &y);

if (x > y){
md = x-y;
printf("O valor de X mod y eh: %d", md);
}
else{
md = 0;
printf("O valor de X mod y eh: %d", md);
}
}

int fib ()
{
int fib2, i, x, y, n;

x = 0;
y = 1;

printf("Digite o numero de termos:");
scanf("%d", &n);

if (n == 1 || n == 0){
fib2 = 1;
printf("O valor da sequencia Fibonacci eh: %d", fib2);
}
else {
for (i = 2; i <= n; i++) {
fib2 = x+y;
x = y;
y = fib2;
printf("O valor da sequencia Fibonacci eh: %d\n", fib2);
}
}
}

main() {
char opc;

printf("Menu de opcoes:\n");
printf("1 - Fatorial de X:\n");
printf("2 - X elevado a Y:\n");
printf("3 - Soma das Sequencias Sucessivas:\n");
printf("4 - X mod Y:\n");
printf("5 - Fibonacci:\n");
printf("6 - Fim:\n");
printf("Selecione a opcao desejada:");
scanf("%d", &opc);

switch (opc) {
case 1: fator ();
break;
case 2: xy();
break;
case 3: soma();
break;
case 4: mod();
break;
case 5: fib();
break;
case 6: printf("Fim.");
system ("pause");
}

return 0;
}
