#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "banco.h"


// Foi adicionado uma função a mais do exercício que ela pediu, de atualizar o saldo, no caso
// depositar (adicionar saldo) ou sacar (tirar do saldo).

int main (){
FILE entrada2;
char opc;

do {
		printf("Menu:\n");
		printf("1- Ler Dados de Conta\n");
		printf("2- Excluir Cliente\n");
		printf("3- Relatorio Completo\n");
        printf("4- Relatorio dos Devedores\n");
        printf("5- Otimizar Banco de Dados\n");
        printf("6- Depositar e Sacar\n");
        printf("7- Sair\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        lerdados(&entrada2);
        break;

        case 2:
        excluicliente(&entrada2);
        break;

        case 3:
        relatorio(&entrada2);
        break;

        case 4:
        devedores(&entrada2);
        break;

        case 5:
        otimiza(&entrada2);
        break;

        case 6:
        depositaresacar(&entrada2);
        break;
		}
		} while (opc != 7);
}
