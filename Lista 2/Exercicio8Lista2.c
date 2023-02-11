#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
int num, num2, cont;

printf("Digite o numero que deseja realizar a tabuada: ");
scanf("%d", &num);

cont = 0;
printf("A tabuada eh:\n");
for (cont = 0; cont <=10; cont++){
num2 = num*cont;
printf("%d x %d = %d\n", num, cont, num2);
}

return 0;
}
