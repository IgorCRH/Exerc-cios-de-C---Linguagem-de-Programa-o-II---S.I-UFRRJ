#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func1 ()
{
double x, xless10, x4, x5x10;

printf("Digite o valor de x:");
scanf("%lf", &x);

if (x >= 10 && x > 0){
xless10 = sqrt(x-10)/2;
return (xless10);
}

if (x <= 4 && x > 0){
x4 = sqrt(pow(x,2)+1)/2;
return (x4);
}

if ( x = 5 && x < 10 && x > 0){
x5x10 = (pow(x,2))-0/(pow(x,3))-16;
return (x5x10);
}
}


main() {
double x;

if (x >= 10) {
printf("O valor de X eh: %2.lf\n", func1());
}

if ( x <= 4 ) {
printf("O valor de X eh: %2.lf\n", func1());
}

if ( x = 5 && x < 10) {
printf("O valor de X eh: %2.lf\n", func1());
}

if (x <= 0) {
printf("Valor nulo ou negativo.");
}

}
