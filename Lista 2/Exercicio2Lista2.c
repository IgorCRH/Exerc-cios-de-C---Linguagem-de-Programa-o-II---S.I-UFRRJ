#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
int x, n;

printf("\n Digite o valor de x: \n");
scanf("%d", &x);

while (x < 10) {
printf("\n Sao multiplos de (%d): ", x);
for (n = x; n <= 100; n+=x)
printf("%d,", n);
return 0;
}

printf("Leitura encerrada.");

return 0;
}
