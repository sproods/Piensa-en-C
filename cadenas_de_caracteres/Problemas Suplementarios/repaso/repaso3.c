#include <stdio.h>
#include <string.h>
#include <ctype.h>

// El programa verifica si una posición en la cadena digitada es una letra minúscula.

void minus(char *, char);

void main(void)
{
    char string[50];
    int pos, len;

    printf("Digite una cadena de caracteres de su preferencia: ");
    gets(string);
    fflush(stdin);

    len = strlen(string);

    printf("Entre el 1 y el %d, qué posición desea saber si la letra es minúscula?: ", len);
    scanf("%d", &pos);

    if (islower(string[pos - 1]))
        printf("La letra en la posición %d sí es minúscula. De hecho, es %c\n", pos, string[pos - 1]);
    else
        printf("La letra en la posición %d no es minúscula. De hecho, es %c\n", pos, string[pos - 1]);
}