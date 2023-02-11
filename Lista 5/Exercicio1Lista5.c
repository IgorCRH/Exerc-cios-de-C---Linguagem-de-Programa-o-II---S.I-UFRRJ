#include <stdio.h>
#include <ctype.h>

void exibir (char *str){
printf("\nSua frase eh: %s\n",str);
}

void maiuscula (char *str){
int i;

for (i=0; i<30; i++){
while(str[i] != '\0'){
        str[i] = toupper(str[i]);
        i++;
    }
}
}

int tamanho (char *str){
int tam, i;

for (i = 0; i<30 ; i++){
if (str[i] == '\0'){
tam = i;
break;
}
}
return tam;
}

char *concatena (char *str, char *str2, char *str3){
int i=0, j=0, tamf1 = tamanho(str), tamf2 = tamanho(str2);

    while(i<tamf1)
    {
        str3[i]=str[0];
        i++;
    }

    while(j<tamf2)
    {
        str3[i]=str2[0];
        j++;
        i++;
    }

    str3[i]='\0';

    return str3;
}

void capitaliza (char *str){
int i, cont=tamanho(str);

for (i = 0; i<cont; i++){
if (str[i] == ' '){
str[i+1] = toupper (str[i+1]);
}
}
return str;
}

int compara (char *str1, char *str2){
int i=0, cont=tamanho(str1), cont2=tamanho(str2);

for (i = 0; i<cont; i++){
for (i = 0; i<cont2; i++){
 if(str1[i] < str2[i])
                return -1;
            else
                if(str1[i] > str2[i])
                    return 1;
    }
    return 0;
}
}

main (){
char frase1[30], frase2[30], frase3[30];
int opc;

printf("\nDigite uma frase: ");
gets(frase1);
printf("\nDigite outra frase: ");
gets(frase2);

do {
		printf("Menu:\n");
		printf("1- Converte em Maiscula\n");
		printf("2- Concatena\n");
		printf("3- Trocar para Maiscula as que seguem espacos e retornar tamanho\n");
		printf("4- Retornar Tamanho\n");
		printf("5- Compara o Tamanho das Frases, retornando resultado\n");
		printf("6- Encerra o programa\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        exibir (frase1);
        maiuscula(frase1);
        exibir (frase1);
        break;

        case 2:
        exibir (frase1);
        exibir (frase2);
        exibir (concatena(frase1,frase2,frase3));
        break;

        case 3:
        exibir (frase1);
        capitaliza (frase1);
        exibir (frase1);
        break;

        case 4:
        exibir (frase1);
        printf("\n O tamanho da frase eh: %d\n",tamanho(frase1));
        break;

        case 5:
        exibir (frase1);
        exibir (frase2);
        if (compara(frase1,frase2) == 1){
        printf("Resultado: 1. A frase 1 eh maior que a 2.\n");
        }
        if (compara(frase1,frase2) == 0){
        printf("Resultado: 0. A frase 1 eh igual a 2.\n");
        }
        if (compara(frase1,frase2) == -1){
        printf("Resultado: -1. A frase 1 eh menor que a 2.\n");
        }
		}
		} while (opc != 6);
}
