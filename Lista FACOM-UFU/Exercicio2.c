#include <stdio.h>
#include <stdlib.h>

// 2. Fa�a um programa que receba do usu�rio um arquivo texto e mostre na tela quantas �
// linhas esse arquivo possui.

main() {
FILE *linhas;
int linhas2 = 0;

linhas = fopen ("linhas.txt","r");
if (linhas == NULL){
printf("\nErro, nao foi possivel abrir e ler o arquivo!");
}

while (!feof(linhas)){ // Usada para verificar at� onde o arquivo vai, o final dele, quando se quer ler ou percorrer o mesmo at� o final.
if (getc (linhas) == '\n'){ // Getc - Usada para retornar um caractere lido de um arquivo, quando se quer fazer especificacoes ou comparacoes de tamanho do arquivo
linhas2++;
}
}
printf("O arquivo tem %d linhas",linhas2);
fclose(linhas);
}
