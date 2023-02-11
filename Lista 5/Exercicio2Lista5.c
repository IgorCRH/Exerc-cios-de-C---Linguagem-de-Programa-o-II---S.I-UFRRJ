#include <stdio.h>
#include <stdlib.h>

void preenche (int *num2){
for(int i=0;i<30;i++)
	{
		num2[i]=(rand()%101);
	}
}

void exibir (int *num2){
for(int i=0;i<30;i++)
{
printf("%d, ",num2[i]);
	}
	printf("%d\n",num2[30]);
}

void zerapares (int *num2) {
int i;

for (i = 0; i < 30; i++){
if (num2[i] % 2 == 0)
num2[i] = 0;
}
return;
}

void dobra (int *num2) {
int i;

for (i = 0; i < 30; i++){
num2[i] = num2[i]*2;
}
return;
}

void soma (int *num2, int *num4){
int i;

for (i = 0; i < 30; i++){
num2[i] = num2[i]+num4[i];
}
return;
}

main () {
int num[30], num3[30];
int opc;
int segundos = time(0);
srand(segundos);

	do {
		printf("Menu:\n");
		printf("1- Zerar os Pares do Vetor\n");
		printf("2- Dobra os Elementos do Vetor\n");
		printf("3- Somar os Elementos de Mesmo Indice dos Vetores\n");
		printf("4- Fim\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        preenche (num);
        exibir (num);
        zerapares(num);
        exibir (num);
        break;

        case 2:
        preenche (num);
        exibir (num);
        dobra (num);
        exibir (num);
        break;

        case 3:
        preenche (num);
        preenche (num3);
        exibir (num);
        exibir (num3);
        soma (num3,num);
        exibir (num3);
		}
		} while (opc != 4);
}
