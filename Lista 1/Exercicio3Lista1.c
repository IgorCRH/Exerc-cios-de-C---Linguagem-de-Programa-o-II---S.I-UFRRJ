#include <stdio.h>
main() {
int idadenad;

scanf ("%d", &idadenad);
if (idadenad >= 5  && idadenad < 7)
printf("O nadador eh da classe Infantil A");
else if (idadenad >= 8  && idadenad < 10)
printf("O nadador eh da classe Infantil B");
else if (idadenad >= 11  && idadenad < 13)
printf("O nadador eh da classe Juvenil A");
else if (idadenad >= 14  && idadenad < 17)
printf("O nadador eh da classe Juvenil B");
else if (idadenad >= 18)
printf("O nadador eh da classe Adulta");
}
