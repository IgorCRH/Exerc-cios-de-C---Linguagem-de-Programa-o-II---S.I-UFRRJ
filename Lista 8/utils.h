typedef struct
	{
		int x;
		int y;
		int z;
	} tpponto;

typedef struct
	{
		tpponto ponto;
		char rotulo;
	} figura;

void preenche (figura *desenho2, FILE *prova){
int i;

prova = fopen("provalp.dat", "ab");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
for (i = 0; i<10; i++){
printf("Entre com um rotulo para o vetor: ");
scanf("%c", &desenho2[i].rotulo);
fflush(stdin);
desenho2[i].ponto.x = (rand()%10);
desenho2[i].ponto.y = (rand()%10);
desenho2[i].ponto.z = (rand()%10);
fwrite(&desenho2[i], sizeof(figura), 1, prova);
}
}
fclose(prova);
}

void imprime (figura *desenho2, FILE *prova){
int i = 0;
figura figura2;

prova = fopen("provalp.dat", "rb");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
printf("Listagem dos Pontos:");
for (i = 0; i< 10; i++){
while (fread(&figura2, sizeof(figura), 1, prova) == 1){
printf("\nX: %d | Y: %d | Z: %d | Rotulo: %c", figura2.ponto.x,figura2.ponto.y,figura2.ponto.z, figura2.rotulo);
}
}
}
fclose(prova);
}

void apaga (figura *desenho2, FILE *prova){
int i = 0;
char let;
FILE *prova2;
figura figura2;

prova2 = fopen("provalp.dat", "rb");
prova = fopen("desenho.dat", "ab");

if (prova == NULL){
printf("\nO arquivo tem de ser criado!");
} else {
fflush(stdin);
printf("Digite a letra que quer buscar no vetor:");
scanf("%c",&let);

for (i = 0; i < 10; i++){
while (fread(&figura2, sizeof(figura), 1, prova2) == 1){

if (figura2.rotulo == let){
desenho2[i].rotulo = '#';
figura2.rotulo = '#';

fwrite(&figura2, sizeof(figura), 1, prova);
}
printf("\nX: %d | Y: %d | Z: %d | Rotulo: %c", figura2.ponto.x,figura2.ponto.y,figura2.ponto.z, figura2.rotulo);
}
}
}
fclose(prova2);
fclose(prova);
}
