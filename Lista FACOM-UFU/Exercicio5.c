#include <stdio.h>
#include <stdlib.h>

// 5. Faça um programa que receba do usuario um arquivo texto e um caracter. Mostre na tela ´
// quantas vezes aquele caractere ocorre dentro do arquivo.

main() {
FILE *linhas;
char caract;
int aux, contcaract = 0;

linhas = fopen ("linhas.txt","r");
if (linhas == NULL){
printf("\nErro, nao foi possivel abrir e ler o arquivo!");
}

printf("Entre com um caracter");
scanf("%c",&caract);

while (!feof(linhas)){
aux = getc(linhas);
if (aux == caract || aux == toupper(caract)){
contcaract++;
}
}
printf("O caracter %c aparece %d vezes no arquivo.",caract,contcaract);
fclose(linhas);
}
