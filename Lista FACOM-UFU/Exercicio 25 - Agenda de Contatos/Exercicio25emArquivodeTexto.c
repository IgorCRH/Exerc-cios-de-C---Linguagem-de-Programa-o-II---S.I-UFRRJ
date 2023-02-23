#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

// Exercicio 25 da Lista, só que feito em formato para arquivo de texto.
// Faça um programa para gerenciar uma agenda de contatos. Para cada contato armazene o nome, o telefone e o aniversario (dia e mês). O programa deve permitir:
// (a) inserir contato
// (b) remover contato
// (c) pesquisar um contato pelo nome
// (d) listar todos os contatos
// (e) listar os contatos cujo nome inicia com uma dada letra
// (f) imprimir os aniversariantes do mês.
// Sempre que o programa for encerrado, os contatos devem ser armazenados em um arquivo de texto. Quando o programa iniciar, os contatos devem ser inicializados com os
// dados contidos neste arquivo texto.

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

void inserecontatos (FILE *entrada){
int i, opc;
contato contatos;

entrada = fopen("contatos.txt", "a");
if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < MAX; i++){
fflush(stdin);
    printf("Digite o nome do contato: ");
    scanf("%s", contatos.nome);

    printf("Digite o dia do aniversario do contato: ");
    scanf("%d", &contatos.dataniver.dia);

    printf("Digite o mes do aniversario do contato: ");
    scanf("%d", &contatos.dataniver.mes);

    printf("Digite o ano do aniversario do contato: ");
    scanf("%d", &contatos.dataniver.ano);

    printf("Digite o DDD do telefone do contato: ");
    scanf("%d", &contatos.numtel.ddd);

    printf("Digite o telefone do contato: ");
    scanf("%d", &contatos.numtel.tel);

    fprintf(entrada, "\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, contatos.dataniver.dia, contatos.dataniver.mes, contatos.dataniver.ano, contatos.numtel.ddd, contatos.numtel.tel);
printf("Digite 1 para encerrar ou qualquer outra tecla para continuar.");
scanf("%d",&opc);
if (opc == 1){
break;
}
}
}
fclose(entrada);
}

void removercontatos (FILE *entrada){
char nome[81];
int i, encontrado = 0;
FILE *entradatemp;
contato contatos;

entrada = fopen("contatos.txt", "r");
entradatemp = fopen("contatostemp.txt", "w");

printf("Digite o nome do contato que deseja remover: ");
scanf("%s", nome);
for(i = 0; i < MAX; i++){
while (fscanf(entrada, "\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, &contatos.dataniver.dia, &contatos.dataniver.mes, &contatos.dataniver.ano, &contatos.numtel.ddd, &contatos.numtel.tel) != EOF) {
        if (strcmp(contatos.nome, nome) != 0) {
            fprintf(entradatemp,"\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d",contatos.nome,contatos.dataniver.dia, contatos.dataniver.mes, contatos.dataniver.ano,contatos.numtel.ddd, contatos.numtel.tel);
        } else {
            encontrado = 1;
        }
    }
}
fclose(entradatemp);
fclose(entrada);

remove("contatos.txt");
rename("contatostemp.txt","contatos.txt");

    if (encontrado) {
        printf("Contato removido com sucesso!\n");
    } else {
        printf("Contato nao encontrado.\n");
    }
}

void pesquisarcontatos (FILE *entrada){
char nome [81];
int encontrado = 0;
contato contatos;

entrada = fopen ("contatos.txt","r");

printf("Digite o nome do contato que deseja pesquisar: ");
scanf("%s", nome);

while (fscanf(entrada, "\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, &contatos.dataniver.dia, &contatos.dataniver.mes, &contatos.dataniver.ano, &contatos.numtel.ddd, &contatos.numtel.tel) != EOF) {
        if (strcmp(contatos.nome, nome) == 0) {
            printf("\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, contatos.dataniver.dia, contatos.dataniver.mes, contatos.dataniver.ano, contatos.numtel.ddd, contatos.numtel.tel);
            break;
            encontrado = 1;
        }
        if (!encontrado) {
        printf("Contato nao foi encontrado!\n");
        break;
    }
    }
fclose(entrada);
}


void listarcontatos (FILE *entrada){
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

void listarcontinicnome (FILE *entrada){
char inic;
int encontrado = 0;
contato contatos;

entrada = fopen ("contatos.txt","r");

fflush(stdin);
printf("Digite a inicial, em maisculo, que deseja procurar pelos nomes: ");
scanf("%c", &inic);

while (fscanf(entrada, "\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, &contatos.dataniver.dia, &contatos.dataniver.mes, &contatos.dataniver.ano, &contatos.numtel.ddd, &contatos.numtel.tel) != EOF) {
        if (contatos.nome[0] == inic) {
            printf("\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, contatos.dataniver.dia, contatos.dataniver.mes, contatos.dataniver.ano, contatos.numtel.ddd, contatos.numtel.tel);
            break;
            encontrado = 1;
        }
        if (!encontrado) {
        fflush(stdin);
        printf("Contato nao foi encontrado!\n");
        break;
    }
    }
fclose(entrada);
}

void impaniversariante (FILE *entrada){
int mes, encontrado = 0;
contato contatos;

entrada = fopen ("contatos.txt","r");

printf("Digite o mes que gostaria de saber quem faz aniversario: ");
scanf("%d",&mes);

while (fscanf(entrada, "\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, &contatos.dataniver.dia, &contatos.dataniver.mes, &contatos.dataniver.ano, &contatos.numtel.ddd, &contatos.numtel.tel) != EOF) {
        if (contatos.dataniver.mes == mes) {
            printf("\nNome: %s \nAniversário: %d %d %d \nTelefone: %d - %d", contatos.nome, contatos.dataniver.dia, contatos.dataniver.mes, contatos.dataniver.ano, contatos.numtel.ddd, contatos.numtel.tel);
            break;
            encontrado = 1;
        }
        if (!encontrado) {
        printf("Contato nao foi encontrado!\n");
        break;
    }
    }
fclose(entrada);
}

int main (){
FILE entrada2;
char opc;

do {
		printf("Menu:\n");
		printf("1- Insere Contato\n");
		printf("2- Remove Contato\n");
		printf("3- Pesquisar Contato pelo Nome\n");
        printf("4- Listar Contatos\n");
        printf("5- Listar Contatos Cujo Nome Inicia com Dada Letra\n");
        printf("6- Imprimir Aniversariantes do Mes\n");
        printf("7- Sair\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        inserecontatos(&entrada2);
        break;

        case 2:
        removercontatos(&entrada2);
        break;

        case 3:
        pesquisarcontatos(&entrada2);
        break;

        case 4:
        listarcontatos(&entrada2);
        break;

        case 5:
        listarcontinicnome(&entrada2);
        break;

        case 6:
        impaniversariante(&entrada2);
        break;
		}
		} while (opc != 7);
}
