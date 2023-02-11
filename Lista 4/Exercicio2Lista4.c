#include<stdio.h>
#include<conio.h>

int main () {
int i=0, j=0, l=19;
int vetor1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int vetor2[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
int vetor3[20];

for (i < 0; i < 20 && j < 10 & j < 10; i += 2){
vetor3[i] = vetor1 [j];
vetor3[i+1] = vetor2 [j];
j++;
}

printf("Os valores do vetor invertido:");
for (l = 19; l> -1; l--){
printf("%d,", vetor3[l]);
}

return 0;
}
