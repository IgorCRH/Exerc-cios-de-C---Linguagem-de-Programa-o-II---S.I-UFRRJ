#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct {
int idade, matricula;
float cr;
char nome [81], curso [51];
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
int i, contvagas;
FILE *disc3;

disc2 = fopen("alunos.txt", "a");
disc3 = fopen("boletins.txt", "a");
if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 40; i++){
if (aux1->turma[i].discente.matricula == 0){
fflush(stdin);
printf("Entre com o nome do aluno: ");
fgets(aux1->turma[i].discente.nome,81,stdin);
fprintf(disc2,"\nNome: %s",aux1->turma[i].discente.nome);
fprintf(disc3,"\nNome: %s",aux1->turma[i].discente.nome);
printf("Entre com a idade do aluno: ");
scanf("%d", &aux1->turma[i].discente.idade);
fprintf(disc2,"\nIdade: %d\n",aux1->turma[i].discente.idade);
fprintf(disc3,"\nIdade: %d\n",aux1->turma[i].discente.idade);
fflush(stdin);
printf("Entre com a matricula do aluno: \n");
scanf("%d", &aux1->turma[i].discente.matricula);
fprintf(disc2,"\nMatricula: %d\n",aux1->turma[i].discente.matricula);
fprintf(disc3,"\nMatricula: %d\n",aux1->turma[i].discente.matricula);
printf("Entre com o CR do aluno: \n");
scanf("%f", &aux1->turma[i].discente.cr);
fprintf(disc2,"CR: %.4f\n",aux1->turma[i].discente.cr);
fprintf(disc3,"CR: %.4f\n",aux1->turma[i].discente.cr);
printf("Entre com o curso do aluno: \n");
fflush(stdin);
fgets(aux1->turma[i].discente.curso,51,stdin);
fprintf(disc2,"Curso: %s\n",aux1->turma[i].discente.curso);
fprintf(disc3,"Curso: %s\n",aux1->turma[i].discente.curso);
printf("Entre com as faltas do aluno: \n");
scanf("%d", &aux1->turma[i].faltas);
fprintf(disc3,"Faltas: %d\n",aux1->turma[i].faltas);
fflush(stdin);
printf("Entre com a nota da P1 do aluno: \n");
scanf("%f", &aux1->turma[i].notas);
fprintf(disc3,"Nota P1: %f\n",aux1->turma[i].notas);
printf("Entre com a nota da P2 do aluno: \n");
scanf("%f", &aux1->turma[i].notas);
fprintf(disc3,"Nota P2: %f\n",aux1->turma[i].notas);
printf("Entre com a nota da P3 do aluno: \n");
scanf("%f", &aux1->turma[i].notas);
fprintf(disc3,"Nota P1: %f\n",aux1->turma[i].notas);
contvagas++;
break;
}
if (contvagas == 40){
printf("Não há mais vagas nesta disciplina.");
}
}
}
fclose(disc2);
fclose(disc3);
}

void listaralunos (disciplina *aux1, FILE *disc2){
int i;
char auxiliar;

disc2 = fopen("alunos.txt", "r");

if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem de Alunos:");

for(i = 0; i <= 40; i++){
if(aux1->turma[i].discente.matricula != 0){
while ((auxiliar = fgetc(disc2)) != EOF){
printf("%c",auxiliar);
}
}
}
}
fclose(disc2);
}

void imprimirboletim (disciplina *aux1, FILE *disc3){
int i;
char auxiliar;

disc3 = fopen("boletins.txt", "r");

if (disc3 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {

for(i = 0; i < 40; i++){
if(aux1->turma[i].discente.matricula != 0){
while ((auxiliar = fgetc(disc3)) != EOF){
printf("%c",auxiliar);
}
}
}
}
fclose(disc3);
}

int main (){
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
