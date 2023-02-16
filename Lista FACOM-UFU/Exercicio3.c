#include <stdio.h>
#include <stdlib.h>

// 3 e 4. Faça um programa que receba do usuario um arquivo texto e mostre na tela quantas ´
// letras sao vogais e quanto sao consoantes.

main() {
FILE *linhas;
int aux, vog = 0, cst = 0;

linhas = fopen ("linhas.txt","r");
if (linhas == NULL){
printf("\nErro, nao foi possivel abrir e ler o arquivo!");
}

while (!feof(linhas)){
aux = getc(linhas);
if (aux == 'A' || aux == 'a' || aux == 'E' || aux == 'e' ||aux == 'I' || aux == 'i' ||aux == 'O' || aux == 'o' ||aux == 'U' || aux == 'u'){
vog++;
} else if (aux != '\n' && aux != ' ' && aux != '0' && aux != '1'&& aux != '2' && aux != '3' && aux != '4' && aux != '5' && aux != '6' && aux != '7' && aux != '8' && aux != '9')
cst++;
printf("%c",aux);
}
printf("\n");
printf("\nO arquivo tem %d vogais e %d consoantes.",vog,cst);
fclose(linhas);
}
