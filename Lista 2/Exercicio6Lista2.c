#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main (){
int paisa, paisb, tempoanos;
float crescpopa, crescpopb;

paisa = 5000000;
paisb = 7000000;
tempoanos = 0;

while (paisb > paisa) {
crescpopa = paisa*0.03;
crescpopb = paisb*0.02;
paisa = paisa + crescpopa;
paisb = paisb + crescpopb;
tempoanos++;
}
printf("O pais A passara o B em %d anos",tempoanos);
}
