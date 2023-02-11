#include <stdio.h>
#include <string.h>

int main() {
    char frase[200], palavra[200];
    int i, j=0, x=0;

    printf("Digite uma frase: ");
    fgets(frase,200,stdin);

    for(i = 0; frase[i] != '\0'; i++) {
        if (frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u') {
                while (x < i){
                palavra[j] = frase[i];
                j++;
                i++;
            }
            palavra[j] = '\0';
            j=0;
            x++;
            printf("%s %s ", frase[i]);
        }
    }

    while (x < i-1) {
        palavra[j] = frase[i];
        j++;
        x++;
    }
    palavra[j] = '\0';
    printf("%s %s ", palavra, palavra);

    return 0;
}
