#include <stdio.h>
#include <math.h>
main() {
int valor1, valor2, valor3;
float areaeq, areaesc;

scanf ("%d %d %d", &valor1, &valor2, &valor3);

areaeq = valor1*valor3/2;
areaesc = valor1*valor1*valor1*sqrt(4)/4;

if (valor1 > valor2 + valor3)
printf("Nao forma um triangulo. Os valores lidos são: %d\n %d\n %d\n", valor1, valor2, valor3);
else if (valor1 == valor2  && valor1 == valor3  && valor2 == valor3)
printf("Forma um triangulo equilatero. A area eh: %.1f", areaeq);
else if (valor1 == valor2  || valor1 == valor3  ||  valor2 == valor3)
printf("Forma um triangulo isosceles. A area eh: %.1f", areaeq);
else
printf("Forma um triangulo escaleno. A area eh: %.1f", areaesc);
}
