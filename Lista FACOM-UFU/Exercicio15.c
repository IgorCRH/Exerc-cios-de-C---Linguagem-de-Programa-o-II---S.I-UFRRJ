#include<stdio.h>
#include<string.h>
#include<ctype.h>

// Faça um programa que receba como entrada o ano corrente e o nome de dois arquivos:
// um de entrada e outro de sa´ıda. Cada linha do arquivo de entrada contem o nome de
// uma pessoa (ocupando 40 caracteres) e o seu ano de nascimento. O programa deverá
// ler o arquivo de entrada e gerar um arquivo de saída onde aparece o nome da pessoa
// seguida por uma string que representa a sua idade.

int main (){
FILE *entrada, *saida;
char nome[40], opc, aux;
int anonasc, idade, i, a;

entrada = fopen("nomeenasc.txt", "a");
saida = fopen("saidaidade.txt", "a");
if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else if (saida == NULL){
printf("\nO arquivo tem de ser criado!");
} else {

do {
fflush(stdin);
printf("Entre com o nome do individuo: ");
fgets(nome,40,stdin);
fflush(stdin);
printf("Entre com o ano de nascimento do individuo: ");
scanf("%d",&anonasc);
fprintf(entrada,"Nome: %s |",nome);
fprintf(entrada,"Ano Nascimento:%d\n",anonasc);
fflush(stdin);
idade = 2023 - anonasc;
if (idade > 18){
fprintf(saida,"Nome: %s\n - Idade: Maior de 18\n",nome);
} else if (idade < 18) {
fprintf(saida,"Nome: %s\n - Idade: Menor de 18\n",nome);
} else {
fprintf(saida,"Nome: %s\n - Idade: Entrando na maioridade\n",nome);
}
printf("Digite 1 para encerrar apos coleta do nome e nascimento ou continuar.");
scanf("%d",&opc);
} while (opc != 1);
fclose(entrada);
fclose(saida);

}
}
