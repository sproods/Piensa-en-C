#include <stdio.h>
#include <string.h>

// Completando una cadena de caracteres con el caractere "-".

#define MAX 100

void main(void)
{
    char string[MAX], aux[MAX];
    int length, i;

    printf("Digite una cadena de caracteres - de no más de %d caracteres - : ", MAX);
    gets(string);

    for (i = 0; i < MAX; i++)
        aux[i] = '-';

    length = strlen(string);

    printf("\n");

    if (length < MAX)
    {
        strncat(string, aux, MAX - length);
        puts(string);
    }
    else
        puts(string);

    printf("\n");
}