#include <stdio.h>
#include <stdlib.h>

main () {
int i= 0, j=0;
float M[4][5] = {{2,4,6,8,10}, {12,14,16,18,20}, {22,24,26,28,30}, {32,34,36,38,40}}, D[4][5], S[4][5];

for (i = 0; i < 4; i++){
 for (j = 0; j < 5; j++){
D[i][j] = M[i][j]*2;
}
}

printf("A matriz dobro gerada foi de:\n");
for (i = 0; i < 4; i++){
 for (j = 0; j < 5; j++){
printf("%2.f,", D[i][j]);
}
printf("\n");
}

for (i = 0; i < 4; i++){
 for (j = 0; j < 5; j++){
S[i][j] = M[i][j] + D[i][j];
}
}

printf("A matriz soma gerada foi de:\n");
for (i = 0; i < 4; i++){
 for (j = 0; j < 5; j++){
printf("%2.f,", S[i][j]);
}
printf("\n");
}

}
