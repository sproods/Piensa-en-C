#include <stdio.h>

// Programa que lee una línea de cadena de caracteres de un archivo de texto.

void main(void)
{
    char string[50];
    FILE *arxiv;

    if ((arxiv = fopen("frases.txt", "r")) != NULL)
    {
        while (!feof(arxiv))
        {
            fgets(string, 50, arxiv);       // Se lee una línea de cadena de caracteres del archivo de texto.
            // puts(string);           // Se imprime en pantalla la cadena leída.
            printf("%s", string);       // Impresión en pantalla salvando el salto de línea.
        }

        printf("\n");

        fclose(arxiv);
    }
    else
        printf("\nNo se puede abrir el archivo.\n");
}