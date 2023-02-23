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

void inserecontatos (FILE *entrada){
int i, opc;
contato novocontato;

entrada = fopen("contatos.dat", "ab");
if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < MAX; i++){
fflush(stdin);
    printf("Digite o nome do contato: ");
    fgets(novocontato.nome, 81, stdin);

    printf("Digite o dia do aniversario do contato: ");
    scanf("%d", &novocontato.dataniver.dia);

    printf("Digite o mes do aniversario do contato: ");
    scanf("%d", &novocontato.dataniver.mes);

    printf("Digite o ano do aniversario do contato: ");
    scanf("%d", &novocontato.dataniver.ano);

    printf("Digite o DDD do telefone do contato: ");
    scanf("%d", &novocontato.numtel.ddd);

    printf("Digite o telefone do contato: ");
    scanf("%d", &novocontato.numtel.tel);

   fwrite(&novocontato, sizeof(contato), 1, entrada);
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
contato contatoatual;

entrada = fopen("contatos.dat", "rb");
entradatemp = fopen("contatostemp.dat", "wb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o nome do contato que deseja remover: ");
fgets(nome, 81, stdin);

for(i = 0; i < MAX; i++){
while (fread(&contatoatual, sizeof(contato), 1, entrada) == 1) {
        if (strcmp(contatoatual.nome, nome) != 0) {
            fwrite(&contatoatual, sizeof(contato), 1, entradatemp);
        } else {
            encontrado = 1;
        }
    }
}
fclose(entradatemp);
fclose(entrada);

remove("contatos.dat");
rename("contatostemp.dat","contatos.dat");

    if (encontrado) {
        fflush(stdin);
        printf("Contato removido com sucesso!\n");
    } else {
        fflush(stdin);
        printf("Contato nao encontrado.\n");
    }
}

void pesquisarcontatos (FILE *entrada){
char nome [81];
int encontrado = 0;
contato contatoatual;

entrada = fopen ("contatos.dat","rb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite o nome do contato que deseja pesquisar: ");
fgets(nome, 81, stdin);

while (fread(&contatoatual, sizeof(contato), 1, entrada) == 1) {
        if (strcmp(contatoatual.nome, nome) == 0) {
            printf("Nome: %s", contatoatual.nome);
            printf("Aniversario: %d/%d/%d\n", contatoatual.dataniver.dia, contatoatual.dataniver.mes,contatoatual.dataniver.ano);
            printf("Telefone: %d - %d", contatoatual.numtel.ddd, contatoatual.numtel.tel);
            break;
            encontrado = 1;
        }
        if (encontrado == 0) {
        printf("Contato nao foi encontrado!\n");
        break;
    }
    }
fclose(entrada);
}


void listarcontatos (FILE *entrada){
int i, aux = 0;
contato contatoatual;

entrada = fopen("contatos.dat", "rb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem dos Contatos:");

while (!feof(entrada)){
aux = fread(&contatoatual, sizeof(contato), 1, entrada);
if (aux){
printf("Nome: %s", contatoatual.nome);
printf("Aniversario: %d/%d/%d\n", contatoatual.dataniver.dia, contatoatual.dataniver.mes,contatoatual.dataniver.ano);
printf("Telefone: %d - %d", contatoatual.numtel.ddd, contatoatual.numtel.tel);
}
}
fclose(entrada);
}
}

void listarcontinicnome (FILE *entrada){
char inic;
int encontrado = 0;
contato contatoatual;

entrada = fopen ("contatos.dat","rb");

if (entrada == NULL){
printf("\nO arquivo tem de ser criado!");
}

fflush(stdin);
printf("Digite a inicial, em maisculo, que deseja procurar pelos nomes: ");
scanf("%c", &inic);

while (fread(&contatoatual, sizeof(contato), 1, entrada) == 1) {
        if (contatoatual.nome[0] == inic) {
            printf("Nome: %s", contatoatual.nome);
            printf("Aniversario: %d/%d/%d\n", contatoatual.dataniver.dia, contatoatual.dataniver.mes,contatoatual.dataniver.ano);
            printf("Telefone: %d - %d", contatoatual.numtel.ddd, contatoatual.numtel.tel);
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

void impaniversariante (FILE *entrada){
int mes, encontrado = 0;
contato contatoatual;

entrada = fopen ("contatos.dat","rb");

printf("Digite o mes que gostaria de saber quem faz aniversario: ");
scanf("%d",&mes);

while (fread(&contatoatual, sizeof(contato), 1, entrada) == 1) {
        if (contatoatual.dataniver.mes == mes) {
            printf("Nome: %s", contatoatual.nome);
            printf("Aniversario: %d/%d/%d\n", contatoatual.dataniver.dia, contatoatual.dataniver.mes,contatoatual.dataniver.ano);
            printf("Telefone: %d - %d", contatoatual.numtel.ddd, contatoatual.numtel.tel);
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
