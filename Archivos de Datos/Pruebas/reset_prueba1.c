#include <stdio.h>

// Este programa reinicia o deja vacío el archivo de texto creado en el archivo "prueba1.c".

void main(void)
{
    FILE *arx;

    if ((arx = fopen("frases.txt", "w")) != NULL)
    {
        printf("\n¡El archivo se reseteó con éxito!\n");
        fclose(arx);
    }
    else
        printf("\nNo se pudo encontrar el archivo.\n");
}