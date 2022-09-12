#include <stdio.h>
#include <string.h>

// Continuación del estudio de las principales funciones de la librería <string.h>

void main(void)
{
    char string1[50], string2[50], string3[50] = "Hola, soy Sproods ";
    int N;

    puts(string3);

    printf("Digite la cadena de texto de su preferencia: ");
    gets(string1);
    puts(string1);
    fflush(stdin);

    printf("Digite otra cadena de texto: ");
    gets(string2);
    puts(string2);
    fflush(stdin);

    strcat(string3, string1);
    puts(string3);

    strcat(string3, " ");

    printf("Digite la cantidad de caracteres que desea incorporar al texto inicial: ");
    scanf("%d", &N);

    strncat(string3, string2, N);
    strcat(string3, ". Y todo el mundo lo sabe. ;)");
    puts(string3);
}