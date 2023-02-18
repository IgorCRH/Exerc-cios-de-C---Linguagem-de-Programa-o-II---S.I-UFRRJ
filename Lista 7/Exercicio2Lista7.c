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
float notap1, notap2, notap3;
int faltas;
} alunosmat;

typedef struct {
int codigo;
alunosmat turma[40];
char nomedisc [50];
} disciplina;


void criadisciplina (disciplina *aux1, FILE *disc){
int i;

disc = fopen("disciplina.dat", "ab");

if (disc == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
fflush(stdin);
printf("Entre com o nome da disciplina");
fgets(aux1->nomedisc,50,stdin);
fwrite(&aux1->nomedisc,sizeof(disciplina),1,disc);
fflush(stdin);
printf("Entre com um codigo dela");
scanf("%d", &aux1->codigo);
fwrite(&aux1->codigo,sizeof(disciplina),1,disc);

for(i = 0; i < 40; i++){
aux1->turma[i].discente.matricula = 0;
}
fclose(disc);
}
}

void incluiraluno (disciplina *aux1, FILE *disc2){
int i, pos = 0, contvagas;
FILE *disc3;

disc2 = fopen("alunos.dat", "ab");
disc3 = fopen("boletins.dat", "ab");
if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 40; i++){
if (aux1->turma[i].discente.matricula == 0){
fflush(stdin);
printf("Entre com o nome do aluno: ");
fgets(aux1->turma[i].discente.nome,81,stdin);
printf("Entre com a idade do aluno: ");
scanf("%d", &aux1->turma[i].discente.idade);
printf("Entre com a matricula do aluno: ");
scanf("%d", &aux1->turma[i].discente.matricula);
printf("Entre com o CR do aluno: ");
scanf("%f", &aux1->turma[i].discente.cr);
fflush(stdin);
printf("Entre com o curso do aluno: ");
fgets(aux1->turma[i].discente.curso,51,stdin);
fwrite(&aux1->turma[i].discente, sizeof(aluno), 1,disc2);
fwrite(&aux1->turma[i].discente, sizeof(aluno), 1,disc3);
printf("Entre com as faltas do aluno: ");
scanf("%d", &aux1->turma[i].faltas);
fflush(stdin);
printf("Entre com a notas da P1 do aluno: ");
scanf("%f", &aux1->turma[i].notap1);
printf("Entre com a notas da P2 do aluno: ");
scanf("%f", &aux1->turma[i].notap2);
printf("Entre com a notas da P3 do aluno: ");
scanf("%f", &aux1->turma[i].notap3);
fwrite(&aux1->turma[i], sizeof(alunosmat), 1,disc3);
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
int i = 0, aux = 0, pos = 0;
char auxiliar;
aluno imprimir;

disc2 = fopen("alunos.dat", "rb");

if (disc2 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 40; i++){
if(aux1->turma[i].discente.matricula != 0){
pos++;
}
while(!feof(disc2)){
aux = fread(&imprimir, sizeof(aluno),1,disc2);
if (aux){
printf("Nome do Aluno: %s | ", imprimir.nome);
printf("Idade: %d | ", imprimir.idade);
printf("Curso: %s | ", imprimir.curso);
printf("Matricula: %d | ", imprimir.matricula);
printf("CR: %.2f ", imprimir.cr);
printf("\n");
}
}
}
}
fclose(disc2);
}

void imprimirboletim (disciplina *aux1, FILE *disc3){
int i = 0, aux= 0, aux2=0;
aluno imprimir;
alunosmat imprimir2;
char auxiliar2, auxiliar3;

disc3 = fopen("boletins.dat", "rb");

if (disc3 == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for(i = 0; i < 40; i++){
while(!feof(disc3)){
aux = fread(&imprimir, sizeof(aluno),1,disc3);
aux2 = fread(&imprimir2, sizeof(alunosmat),1,disc3);
if (aux){
printf("Nome do Aluno: %s | ", imprimir.nome);
printf("Idade: %d | ", imprimir.idade);
printf("Curso: %s | ", imprimir.curso);
printf("Matricula: %d | ", imprimir.matricula);
printf("Faltas: %d | ", imprimir2.faltas);
printf("Nota P1: %.2f | \n", imprimir2.notap1);
printf("Nota P2: %.2f | \n", imprimir2.notap2);
printf("Nota P3: %.2f | \n", imprimir2.notap3);
printf("\n");
}
}
}
fclose(disc3);
}
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
