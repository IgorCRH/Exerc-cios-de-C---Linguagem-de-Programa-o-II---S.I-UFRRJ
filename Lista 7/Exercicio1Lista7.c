#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct {
int idade, matricula;
float cr;
char nome [80], curso [50];
} aluno;

typedef struct {
aluno discente;
float notas;
int faltas;
} alunosmat;

typedef struct {
int codigo;
alunosmat turma[40];
char nomedisc [50];
} disciplina;


void criadisciplina (disciplina *aux1, FILE *disc){
int i;

disc = fopen("disciplina.txt", "a");

if (disc == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
fflush(stdin);
printf("Entre com o nome da disciplina");
fgets(aux1->nomedisc,50,stdin);
fflush(stdin);
printf("Entre com um codigo dela");
scanf("%d", &aux1->codigo);

for(i = 0; i < 40; i++){
aux1->turma[i].discente.matricula = 0;
}
fprintf(disc,"Disciplina: %s Código: %d\n",aux1->nomedisc,aux1->codigo);
fclose(disc);
}
}

void incluiraluno (disciplina *aux1, FILE *disc2){
int i, pos = 0, contvagas;

disc2 = fopen("alunos.txt", "a");
if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 40; i++){
if (aux1->turma[i].discente.matricula == 0){
fflush(stdin);
printf("Entre com o nome do aluno");
fgets(aux1->turma[i].discente.nome,80,stdin);
printf("Entre com a idade do aluno");
scanf("%d", &aux1->turma[i].discente.idade);
printf("Entre com a matricula do aluno");
scanf("%d", &aux1->turma[i].discente.matricula);
printf("Entre com o CR do aluno");
scanf("%f", &aux1->turma[i].discente.cr);
fflush(stdin);
printf("Entre com o curso do aluno");
fgets(aux1->turma[i].discente.curso,50,stdin);
printf("Entre com as faltas do aluno");
scanf("%d", &aux1->turma[i].faltas);
contvagas++;
fprintf(disc2,"Nome do Aluno: %s - Idade: %d - Matricula: %d - Curso: %d - Faltas: %d - CR: %f\n",aux1->turma[i].discente.nome,aux1->turma[i].discente.idade,aux1->turma[i].discente.matricula,aux1->turma[i].discente.curso,aux1->turma[i].faltas,aux1->turma[i].discente.cr);
break;
}
if (contvagas == 40){
printf("Não há mais vagas nesta disciplina.");
}
}
}
fclose(disc2);
}

void listaralunos (disciplina *aux1, FILE *disc2){
int i, pos = 0;
char auxiliar;

disc2 = fopen("alunos.txt", "r");

if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 40; i++){
if(aux1->turma[i].discente.matricula != 0){
pos++;
}
while ((auxiliar = fgetc(disc2)) != EOF)
        putchar(auxiliar);
}
}
fclose(disc2);
}

void imprimirboletim (disciplina *aux1, FILE *disc3){
int i;
FILE *disc2, *disc;
char auxiliar2, auxiliar3;

disc3 = fopen("boletins.txt", "w");
disc2 = fopen("alunos.txt", "r");
disc = fopen("disciplina.txt", "r");

if (disc3 == NULL){
printf("\nO arquivo tem de ser criado!");
} else if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
}
else if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 40; i++){
while ((auxiliar2 = fgetc(disc2)) != EOF){
        putchar(auxiliar2);
        fputc(auxiliar2,disc3);
}
while ((auxiliar3 = fgetc(disc)) != EOF){
        putchar(auxiliar3);
}
}
}
fclose(disc3);
fclose(disc2);
fclose(disc);
}

main (){
disciplina aux1;
FILE disc4, disc5, disc6;
char opc;

do {
		printf("Menu:\n");
		printf("1- Cria Disciplina\n");
		printf("2- Incluir Aluno\n");
		printf("3- Listar Alunos\n");
        printf("4- Imprimir Boletim\n");
        printf("5- Sair\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        criadisciplina(&aux1,&disc4);
        break;

        case 2:
        incluiraluno(&aux1,&disc5);
        break;

        case 3:
        listaralunos(&aux1,&disc5);
        break;

        case 4:
        imprimirboletim(&aux1,&disc6);
        break;
		}
		} while (opc != 5);
}
