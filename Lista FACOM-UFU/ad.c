#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*Programa que receba do usuário um arquivo texto e um caracter.
Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.*/
int main(){

char txt[100];//string p/ armazenar todo o txt q está no arq
int conta = 0, j;//conta qtas vezes aparece a letra no arq
char i;

FILE *arq;
arq = fopen("linhas.txt", "r");


if(arq == NULL){
printf("Erro ao tentar abrir o arquivo.\n");
}

while(fgets(txt,100,arq) != EOF){
    for(i = 'A'; i <= 'Z'; i++)
    {
      for(j = 0; txt[j] != '\0'; j++)
      {
        if(txt[j]== i || txt[j] == tolower(i))
        {
        ++conta;
        }
    }


    }
    if(conta != 0)
    {
      printf("%c - %d vezes\n", i, conta);
    }
    return 0;
    }
    conta = 0;
}
