#include <stdio.h>
#include <math.h>

int x1 ()
{
int x, n, y;

if (x > 0){
n = 1;

for (n = 1; n <= 100; n++){
y = x+n/n;
return (y);
}
}
}

int x2 ()
{
int x, y, c, n;

if (x <= 0){

for (n = 100; n <= 100; n--){
for (c = 1; c <= 100; n++){
y = x*x+c/n-x*x+c/n+x*x+c/n;
return (y);
}
}
}
}

main() {
int x;

printf("Digite o valor de x: ");
scanf("%d", &x);

if (x > 0){
return (x1);
}
if (x <= 0){
return (x2);
}

return 0;
}
