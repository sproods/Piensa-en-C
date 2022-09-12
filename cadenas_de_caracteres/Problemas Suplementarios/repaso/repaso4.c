#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Conteo de minúsculas y mayúsculas en una cadena de caracteres.

void main(void)
{
    int c = 0, minus = 0, mayus = 0;
    char string[50];

    printf("Digite el texto de su preferencia: ");
    gets(string);

    while (string[c] != '\0')
    {
        if (islower(string[c]))
            minus++;
        else if (isupper(string[c]))
            mayus++;
        c++;
    }

    printf("\nLa cadena de texto \"%s\" tiene %d minúsculas y %d mayúsculas entre sus %d letras.\n", string, minus, mayus, strlen(string));
}