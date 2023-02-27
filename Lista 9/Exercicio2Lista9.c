#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "lojas.h"

int main (){
FILE entrada3, entrada4;
char opc;

do {
		printf("Menu:\n");
		printf("1- Cadastra Produto\n");
		printf("2- Inserir no Estoque\n");
		printf("3- Realiza Venda\n");
        printf("4- Atualizar Preco do Produto\n");
        printf("5- Compra Produto\n");
        printf("6- Invalida Item\n");
        printf("7- Invalida Loja\n");
        printf("8- Otimiza Banco de Dados\n");
        printf("9- Fazer Relatorio de Estoque\n");
        printf("10- Fazer Relatorio de Item\n");
        printf("11- Fazer Relatorio Consolidado\n");
        printf("12- Sair\n");
		printf("insira sua opcao: ");
		scanf("%d",&opc);


		switch (opc)
		{
        case 1:
        cadprodutos(&entrada3);
        break;

        case 2:
        inserirestoque(&entrada3);
        break;

        case 3:
        realizarvenda(&entrada3);
        break;

        case 4:
        atualizaprod(&entrada3);
        break;

        case 5:
        compraprod(&entrada3);
        break;

        case 6:
        anulaitem(&entrada3);
        break;

        case 7:
        anulaloja(&entrada3);
        break;

        case 8:
        otimiza(&entrada3,&entrada4);
        break;

        case 9:
        relatorioestoque(&entrada3);
        break;

        case 10:
        relatorioitem(&entrada3);
        break;

        case 11:
        relatorioconsolidado(&entrada3);
        break;
		}
		} while (opc != 12);
}
