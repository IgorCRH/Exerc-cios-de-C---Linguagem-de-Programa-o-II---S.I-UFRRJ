#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*Programa que receba do usuário um arquivo texto e um caracter.
Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.*/
int main(){

FILE *linhas;
char letra[100];//string p/ armazenar todo o txt q está no arq
int contletr = 0, j;//conta qtas vezes aparece a letra no arq
char i;

linhas = fopen("linhas.txt", "r");


if(linhas == NULL){
printf("Erro ao tentar abrir o arquivo.\n");
}

while(fgets(letra,100,linhas) != NULL){
    for(i = 'A'; i <= 'Z'; i++)
    {
      for(j = 0; letra[j] != '\0'; j++)
      {
        if(letra[j]== i || letra[j] == tolower(i))
        {
        ++contletr;
        }
    }
    if(contletr != 0)
    {
      printf("A letra %c do alfabeto, aparece %d vezes\n", i, contletr);
    }
    contletr = 0;
    }
    return 0;
    }
}
