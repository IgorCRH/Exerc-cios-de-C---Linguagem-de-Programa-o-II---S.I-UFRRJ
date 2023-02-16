#include <stdio.h>
#include <stdlib.h>

// 1. Escreva um programa que:
// (a) Crie/abra um arquivo texto de nome “arq.txt”
// (b) Permita que o usuario grave diversos caracteres nesse arquivo, at ´ e que o usu ´ ario ´
// entre com o caractere ‘0’
// (c) Feche o arquivo
// Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados.

main() {
FILE *arq;
char c;

arq = fopen ("arq.txt","w");
if (arq == NULL){
printf("\nErro, nao foi possivel criar o arquivo!");
}

while (c != '0'){
scanf("%c",&c);
if (c != '0'){
fprintf(arq,"%c",c);
}
}

fclose(arq);

}
