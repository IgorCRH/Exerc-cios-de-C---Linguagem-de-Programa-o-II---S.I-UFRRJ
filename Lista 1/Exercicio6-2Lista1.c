#include <stdio.h>

main() {
int i,j,n;

printf("Digite o valor de N:");
scanf("%d", &n);

for (i=1; i<=n; i++){
 for (j=1; j == 1 ; ++j)
printf("*", j);
 for (j=2; j<=i; j++)
printf("**", j);
printf("\n");
}
return 0;
}
