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
case '-' : printf ("A subtra��o eh: %f", sub);
break;
case '*' : printf ("A multiplica��o eh: %f", multipl);
break;
case '/' : printf ("A divis�o eh: %f", div);
break;
default: printf ("A opera��o � invalida.\n");
}

return(0);
}
