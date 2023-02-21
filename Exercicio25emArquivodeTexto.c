#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

// Faça um programa para gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e o aniversario (dia e mês). O programa deve permitir:
// (a) inserir contato
// (b) remover contato
// (c) pesquisar um contato pelo nome
// (d) listar todos os contatos
// (e) listar os contatos cujo nome inicia com uma dada letra
// (f) imprimir os aniversariantes do mês.
// Sempre que o programa for encerrado, os contatos devem ser armazenados em um arquivo binario. Quando o programa iniciar, os contatos devem ser inicializados com os
// dados contidos neste arquivo binario.

typedef struct {
int dia;
int mes;
int ano;
} aniversario;

typedef struct {
int ddd;
int tel;
} telefone;

typedef struct {
aniversario dataniver;
telefone numtel;
int codigo;
char nome [81];
} contato;

typedef struct {
contato contatos[MAX];
int numcontatos;
} agenda;

void inserecontatos (agenda *aux1, FILE *entrada){
int i, codigo, opc;

entrada = fopen("contatos.txt", "a");
if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < MAX; i++){
fflush(stdin);
printf("Entre com o nome do contato: ");
fgets(aux1->contatos[i].nome,81,stdin);
fprintf(entrada,"\nNome: %s",aux1->contatos[i].nome);
fflush(stdin);
printf("Entre com o dia do aniversario: ");
scanf("%d", &aux1->contatos[i].dataniver.dia);
printf("Entre com o mes do aniversario: ");
scanf("%d", &aux1->contatos[i].dataniver.mes);
printf("Entre com o mes do aniversario: ");
scanf("%d", &aux1->contatos[i].dataniver.ano);
fprintf(entrada,"\nAniversario: %d/%d/%d",aux1->contatos[i].dataniver.dia,aux1->contatos[i].dataniver.mes,aux1->contatos[i].dataniver.ano);
printf("Entre com o DDD do telefone do contato: ");
scanf("%d", &aux1->contatos[i].numtel.ddd);
printf("Entre com o numero do telefone do contato: ");
scanf("%d", &aux1->contatos[i].numtel.tel);
fprintf(entrada,"\nTelefone: %d - %d",aux1->contatos[i].numtel.ddd,aux1->contatos[i].numtel.tel);
printf("Entre com o codigo do contato: ");
scanf("%d", &aux1->contatos[i].codigo);
fprintf(entrada,"\nCodigo: %d",aux1->contatos[i].codigo);
aux1->numcontatos++;
printf("Digite 1 para encerrar ou qualquer outra tecla para continuar.");
scanf("%d",&opc);
if (opc == 1){
break;
}
}
}
fclose(entrada);
}

void removercontatos (agenda *aux1, FILE *entrada){
int i, idc, nomeremove[81];
FILE *entradatemp;
int numremove;
char auxiliar,auxiliar2,auxiliar3;
contato remover;

entrada = fopen("contatos.txt", "r");
entradatemp= fopen ("contatostemp.txt", "w+");
if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else if (entradatemp == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
fflush(stdin);
printf("Entre com o codigo do contato que deseja remover: ");
scanf("%d",&numremove);
while(!feof(entrada)){
fscanf(entrada,"\nNome: %s",aux1->contatos[i].nome);
fscanf(entrada,"\nAniversario: %d/%d/%d",&aux1->contatos[i].dataniver.dia,aux1->contatos[i].dataniver.mes,aux1->contatos[i].dataniver.ano);
fscanf(entrada,"\nTelefone: %d - %d",&aux1->contatos[i].numtel.ddd,aux1->contatos[i].numtel.tel);
fscanf(entrada,"\nCodigo: %d",&aux1->contatos[i].codigo);
for(i = 0; i < MAX; i++) {
if (aux1->contatos[i].codigo == numremove) {
        aux1->contatos[i].nome[0]= '\0';
        aux1->contatos[i].dataniver.dia= '\0';
        aux1->contatos[i].dataniver.mes= '\0';
        aux1->contatos[i].dataniver.ano= '\0';
        aux1->contatos[i].numtel.ddd= '\0';
        aux1->contatos[i].numtel.tel= '\0';
        }
}
if (aux1->contatos[i].nome[0] != '\0'){
fprintf(entradatemp,"\nNome: %s",aux1->contatos[i].nome);
fprintf(entradatemp,"\nAniversario: %d/%d/%d",aux1->contatos[i].dataniver.dia,aux1->contatos[i].dataniver.mes,aux1->contatos[i].dataniver.ano);
fprintf(entradatemp,"\nTelefone: %d - %d",aux1->contatos[i].numtel.ddd,aux1->contatos[i].numtel.tel);
}
}
printf("Contato não encontrado.\n");
fclose(entradatemp);
fclose(entrada);
}
}



void listarcontatos (agenda *aux1, FILE *entrada){
int i;
char auxiliar;

entrada = fopen("contatos.txt", "r");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem dos Contatos:");

while ((auxiliar = fgetc(entrada)) != EOF){
printf("%c",auxiliar);
}
}
fclose(entrada);
}

int main (){
agenda aux1;
FILE entrada2;
char opc;

do {
		printf("Menu:\n");
		printf("1- Insere Contato\n");
		printf("2- Remove Contato\n");
		printf("3- Pesquisar Contato pelo Nome\n");
        printf("4- Listar Contatos\n");
        printf("5- Listar Contatos\n");
        printf("6- Listar Contatos Cujo Nome Inicia com Dada Letra\n");
        printf("7- Imprimir Aniversariantes do Mes\n");
        printf("8- Sair\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        inserecontatos(&aux1,&entrada2);
        break;

        case 2:
        removercontatos(&aux1,&entrada2);
        break;

        case 3:

        break;

        case 4:
        listarcontatos(&aux1,&entrada2);
        break;

        case 5:

        break;

        case 6:

        break;

        case 7:

        break;
		}
		} while (opc != 8);
}
