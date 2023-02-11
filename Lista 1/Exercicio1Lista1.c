#include <stdio.h>
main() {
int nota1, nota2, nota3;
float media;

printf("Entre com as notas:");
scanf("%d %d %d", &nota1, &nota2, &nota3);
media = nota1+nota2+nota3/3;

if (media >= 6)
printf ("Aprovado\n");
else if (media < 6)
printf ("Reprovado\n");
}
