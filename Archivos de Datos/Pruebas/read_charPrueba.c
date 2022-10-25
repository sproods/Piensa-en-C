#include <stdio.h>

// El programa lee un archivo de formato de texto caracter por caracter.

void main(void)
{
    char letter;
    FILE *arx;

    if((arx = fopen("frases.txt", "r")) != NULL)        // Abro el archivo y verifico si el archivo existe.
    {
        while (!feof(arx))
        {
            letter = fgetc(arx);
            putchar(letter);
        }

        printf("\n");

        fclose(arx);
    }
    else
        printf("\nNo se pudo abrir el archivo.\n");
}