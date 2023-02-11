#include <stdio.h>

main () {
float soma, sub, multipl, num1, num2, div;
char operador;

scanf("%f %f", &num1, &num2);
scanf("%s", &operador);
soma = num1+num2;
sub = num1-num2;
multipl = num1*num2;
div = num1/num2;

switch (operador) {
case '+' : printf ("A soma eh: %f", soma);
break;
case '-' : printf ("A subtração eh: %f", sub);
break;
case '*' : printf ("A multiplicação eh: %f", multipl);
break;
case '/' : printf ("A divisão eh: %f", div);
break;
default: printf ("A operação é invalida.\n");
}

return(0);
}
