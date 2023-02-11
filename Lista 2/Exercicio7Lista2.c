#include <stdio.h>
#include <stdlib.h>

main (){
int pratoprinc, bebida, sobremesa, calpratprinc, calbebida, calsob, totalcalorias;

printf ("Pratos Principais - 1: Vegetariano, 2: Peixe, 3: Frango e 4: Carne:\n");
printf ("Bebidas - 1: Cha (lata), 2: Suco de Laranja, 3: Suco de Melao e 4: Refrigerante Diet:\n");
printf ("Sobremesa - 1: Abacaxi, 2: Sorvete Diet, 3: Mousse Diet e 4: Mousse de Chocolate:\n");
printf ("Informe uma opcao de um prato principal, uma bebida, e uma sobremesa:\n");
scanf("%d %d %d", &pratoprinc, &bebida, &sobremesa);

if (pratoprinc == 1){
calpratprinc = 180;
}
else
{
if (pratoprinc == 2){
calpratprinc = 230;
}
else
{
if (pratoprinc == 3){
calpratprinc = 250;
}
else
{
if (pratoprinc == 4){
calpratprinc = 350;
}
}
}
}

if (bebida == 1){
calbebida = 80;
}
else
{
if (bebida == 2){
calbebida = 150;
}
else
{
if (bebida == 3){
calbebida = 70;
}
else
{
if (bebida == 4){
calbebida = 2;
}
}
}
}

if (sobremesa == 1){
calsob = 75;
}
else
{
if (sobremesa == 2){
calsob = 110;
}
else
{
if (sobremesa == 3){
calsob = 60;
}
else
{
if (sobremesa == 4){
calsob = 250;
}
}
}
}

totalcalorias = calpratprinc + calbebida + calsob;
printf("O total de calorias eh: %d\n", totalcalorias);

return 0;
}
