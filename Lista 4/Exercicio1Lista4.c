#include<stdio.h>
#include<conio.h>

main () {
int pos[20], i, fim = 19, guarda;

for(i = 0; i < 20; i++){
printf("Entre com os valores do vetor:");
scanf("%d", & pos[i]);
}
printf("Exibindo as posicoes do vetor. \n\n");
for(i = 0; i < 20; i++){
printf("As posicoes do vetor sao: %2d\n", pos[i]);
}

for(i = 0; i < 10; i++){
guarda = pos[i];
pos[i] = pos[fim];
pos[fim] = guarda;
fim--;
}

printf("Exibindo as posicoes do vetor modificado. \n\n");
for(i = 0; i < 20; i++){
printf("%d\n", pos[i]);
}
  return 0;
}
