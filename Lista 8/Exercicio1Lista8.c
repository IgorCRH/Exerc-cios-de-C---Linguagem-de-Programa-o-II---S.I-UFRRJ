#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct
	{
		int x;
		int y;
		int z;
	} tpponto;

typedef struct
	{
		tpponto ponto[10];
		char rotulo[10];
	} figura;

void preenche (figura *desenho2, FILE *prova){
int i;

prova = fopen("provalp.dat", "ab");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for (i = 0; i< 10; i++){
desenho2->ponto[i].x = (rand()%10);
desenho2->ponto[i].y = (rand()%10);
desenho2->ponto[i].z = (rand()%10);
printf("Entre com um rotulo para o vetor.");
scanf("%c", &desenho2->rotulo[i]);
fflush(stdin);

fclose(prova);
}
}
}

void imprime (figura *desenho2, FILE *prova){
int i;

prova = fopen("provalp.dat", "ab");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for (i = 0; i< 10; i++){
fprintf(prova, "Ponto %d - Rotulo %c - x = %d | y = %d | z = %d\n", i, desenho2->rotulo[i], desenho2->ponto[i].x,desenho2->ponto[i].y,desenho2->ponto[i].z);
}
}
fclose(prova);
}

void apaga (figura *desenho2, FILE *prova){
int i;
char let, aux;

prova = fopen("desenho.dat", "ab");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Digite a letra que quer buscar no vetor:");
scanf("%c",&let);
for (i = 0; i < 10; i++){
if (desenho2->rotulo[i] == let){
desenho2->rotulo[i] = '#';
}
fprintf(prova, "Nº %d - Ponto %c - x = %d | y = %d | z = %d\n", i, desenho2->rotulo[i], desenho2->ponto[i].x,desenho2->ponto[i].y,desenho2->ponto[i].z);
}
}
fclose(prova);
}
int main(){
FILE prova2;
figura desenho[10];

preenche(&desenho,&prova2);
imprime(&desenho,&prova2);
apaga(&desenho,&prova2);
}
