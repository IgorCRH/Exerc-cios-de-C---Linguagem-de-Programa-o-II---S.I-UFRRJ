#include <stdio.h>
#include <stdlib.h>

main () {
float M[3][5] = {{2,4,6,8,10}, {12,14,16,18,20}, {22,24,26,28,30}};
int somalinha[3];
int somal, i=0, j=0;

printf("A matriz M eh: \n");
for (i = 0; i < 3; i++){
 for (j = 0; j < 5; j++){
printf("%1.f,", M[i][j]);
}
printf("\n");
}

for (i = 0; i < 3; i++){
somal = 0;
 for (j = 0; j < 5; j++){
somal += M[i][j];
}
somalinha[i] = somal;
}

printf("A soma das linhas eh: \n");
for (i = 0; i < 3; i++){
printf("Linha %d: Soma %d\n", i, somalinha[i]);
}

}

