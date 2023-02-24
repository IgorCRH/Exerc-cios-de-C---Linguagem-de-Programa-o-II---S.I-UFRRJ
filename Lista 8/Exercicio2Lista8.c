#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"utils.h"

int main(){
FILE prova2;
figura desenho[10];

preenche(&desenho,&prova2);
imprime(&desenho,&prova2);
apaga(&desenho,&prova2);
}
