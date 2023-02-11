#include <stdio.h>
#include <math.h>

main() {
int x, n;

while (x > 0) {
printf("\n Digite o valor de x: \n");
scanf("%d", &x);

printf("\n Sao divisores de (%d): ", x);
for (n=1; n <= x; ++n){
if (x % n == 0){
printf("%d,", n);
}
}
}
printf("Leitura encerrada.");

return 0;
}
