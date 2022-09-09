#include <stdio.h>
#include <string.h>

// Continuación del estudio de las principales funciones de la librería <string.h>

void main(void)
{
    char string1[50], string2[50], string3[50] = "Hola, soy Sproods ";

    puts(string3);

    printf("Digite la cadena de texto de su preferencia: ");
    gets(string1);
    puts(string1);

    printf("Digite otra cadena de texto: ");
    gets(string2);
    puts(string2);

    strcat(string3, string1);
    puts(string3);

    strncat(string3, string2, 7);
    puts(string3);
}