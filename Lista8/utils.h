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
tpponto ponto2;

prova = fopen("provalp.dat", "ab");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for (i = 0; i<10; i++){
printf("Entre com um rotulo para o vetor: ");
fgets(desenho2->rotulo, 10, stdin);
ponto2.x = (rand()%10);
ponto2.y = (rand()%10);
ponto2.z = (rand()%10);
fwrite(&ponto2, sizeof(tpponto), 1, prova);
fwrite(&desenho2, sizeof(figura), 1, prova);
}
}
fclose(prova);
}

void imprime (figura *desenho2, FILE *prova){
int i = 0;
tpponto ponto2;

prova = fopen("provalp.dat", "rb");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem dos Pontos:");
for (i = 0; i< 10; i++){
while (fread(&ponto2, sizeof(tpponto), 1, prova) == 1 && fread(&desenho2, sizeof(figura), 1, prova) == 1){
fflush(stdin);
printf("\nX: %d | Y: %d | Z: %d | Rotulo: %s", ponto2.x,ponto2.y,ponto2.z, desenho2->rotulo);
}
}
}
fclose(prova);
}

void apaga (figura *desenho2, FILE *prova){
int i = 0;
char let;
FILE *prova2;
tpponto ponto2;

prova2 = fopen("provalp.dat", "rb");
prova = fopen("desenho.dat", "ab");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
fflush(stdin);
printf("Digite a letra que quer buscar no vetor:");
scanf("%c",&let);

for (i = 0; i < 10; i++){
while (fread(&ponto2, sizeof(tpponto), 1, prova2) == 1 && fread(&desenho2, sizeof(figura), 1, prova2) == 1){

if (desenho2->rotulo[i] == let){
desenho2->rotulo[i] = '#';
fwrite(&ponto2, sizeof(tpponto), 1, prova);
fwrite(&desenho2, sizeof(figura), 1, prova);
}
printf("\nX: %d | Y: %d | Z: %d | Rotulo: %s", ponto2.x,ponto2.y,ponto2.z, desenho2->rotulo);
}
}
}
fclose(prova2);
fclose(prova);
}
