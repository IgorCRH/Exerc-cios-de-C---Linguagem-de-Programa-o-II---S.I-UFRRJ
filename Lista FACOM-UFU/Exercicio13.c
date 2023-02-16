#include<stdio.h>
#include<string.h>
#include<ctype.h>

main(){
FILE *cadastro;
char nome[20][20], tel [20][20];
int i, qtdcad;

cadastro = fopen("cadastro.txt", "a");

if (cadastro == NULL){
printf("\nO arquivo tem de ser criado!");
}

printf("Quantas pessoas deseja cadastrar?");
scanf("%d",&qtdcad);


for (i=0 ; i < qtdcad ; i++){
printf ("Entre com o nome a ser cadastrado: ");
fflush(stdin);
gets(nome[i]);
printf ("Entre com o telefone a ser cadastrado: ");
fflush(stdin);
gets(tel[i]);
}

if (tel[0] != '0'){
for (i=0 ; i < qtdcad ; i++){
fprintf(cadastro,"\nNome %s",nome[i]);
fprintf(cadastro,"\nTelefone %s",tel[i]);
fprintf(cadastro,"\n\n");
}
} else {
if (tel[0] == '0'){
printf("Entrada iniciada com zero. Fim do programa.");
}
}

fclose(cadastro);
}
