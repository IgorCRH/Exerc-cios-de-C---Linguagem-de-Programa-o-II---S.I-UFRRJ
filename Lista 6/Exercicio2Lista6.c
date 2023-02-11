#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exercicio2Lista6.h"

void criadisciplina (disciplina *aux1){
int i;

fflush(stdin);
printf("Entre com o nome da disciplina");
fgets(aux1->nomedisc,50,stdin);
fflush(stdin);
printf("Entre com um codigo dela");
scanf("%d", &aux1->codigo);
for(i = 0; i < 40; i++){
aux1->turma[i].discente.matricula = 0;
}
}

void incluiraluno (disciplina *aux1){
int i, contvagas;

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
printf("Entre com o curso do aluno");
fgets(aux1->turma[i].discente.curso,50,stdin);
totalclientes++;
break;
}
if (contvagas == 40){
printf("Não há mais vagas nesta disciplina.");
}
}
}

void excluiraluno (disciplina *aux1){
int i;
char mat;

printf("Entre com a matricula do aluno");
scanf("%d", &mat);
for(i = 0; i < 40; i++){
if(aux1->turma[i].discente.matricula == mat){
aux1->turma[i].discente.matricula = 0;
}
}
}

void listaralunos (disciplina *aux1){
int i,pos = 0;

for(i = 0; i < 40; i++){
if(aux1->turma[i].discente.matricula != 0){
pos++;
printf("%d | Nome do Aluno: %s - Idade: %d - Matricula: %d - Curso: %d - CR: %f\n",pos,aux1->turma[i].discente.nome,aux1->turma[i].discente.idade,aux1->turma[i].discente.matricula,aux1->turma[i].discente.curso,aux1->turma[i].discente.cr);
}
}
}

void calcularcr (disciplina *aux1){
int i, numalun = 0, crmed2;
float crmed;

for(i = 0; i < 40; i++){
numalun++;
crmed2 += aux1->turma[i].discente.cr;
crmed = crmed2/numalun;
}
printf("O CR medio eh: %f", crmed);
}

void imprimirboletim (disciplina *aux1){
int i,pos = 0;

for(i = 0; i < 40; i++){
if(aux1->turma[i].discente.matricula != 0){
pos++;
printf("%d | Nome do Aluno: %s - Idade: %d - Matricula: %d - Curso: %d - Faltas: %d - Nota: %f\n",pos,aux1->turma[i].discente.nome,aux1->turma[i].discente.idade,aux1->turma[i].discente.matricula,aux1->turma[i].discente.curso,aux1->turma[i].faltas,aux1->turma[i].notas);
}
}
}

void fechardisciplina (disciplina *aux1){
int i;
char discaux, codigoaux;

printf("Entre com o codigo da disciplina que deseja excluir");
scanf("%d", &discaux);
for(i = 0; i < 40; i++){
if(aux1->codigo == discaux){
aux1->turma[i].discente.matricula = 0;
aux1->codigo = ' ';
strcpy(aux1->nomedisc," ");
}
puts("Disciplina foi fechada com sucesso.");
}
}

main (){
disciplina aux1;

char opc;

	do {
		printf("Menu:\n");
		printf("1- Cria Disciplina\n");
		printf("2- Incluir Aluno\n");
		printf("3- Excluir Aluno\n");
		printf("4- Listar Alunos\n");
        printf("5- Calcular CR Medio\n");
        printf("6- Imprimir Boletim\n");
        printf("7- Fechar Disciplina\n");
        printf("8- Sair\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        criadisciplina(&aux1);
        break;

        case 2:
        incluiraluno(&aux1);
        break;

        case 3:
        excluiraluno(&aux1);
        break;

        case 4:
        listaralunos(&aux1);
        break;

        case 5:
        calcularcr(&aux1);
        break;

        case 6:
        imprimirboletim(&aux1);
        break;

        case 7:
        fechardisciplina(&aux1);
        break;
		}
		} while (opc != 8);
}
