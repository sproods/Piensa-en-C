/* El programa escribe en un archivo de texto varias cadenas de caracteres para ayudar a la resolución del problema cuatro. */

#include <stdio.h>
#include <stdbool.h>

void write(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc3.txt", "w")) != NULL)
    {
        write(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void write(FILE *arc)
{
    int i = 0, res;
    char cadena[250];

    printf("\nDigite la cadena de caracteres %d:\n", i + 1);
    gets(cadena);
    fputs(cadena, arc);

    while (true)
    {
        printf("\n¿Desea digitar otra cadena de caracteres? (1. si    0. no-salir): ");
        scanf("%d", &res);
        fflush(stdin);

        if (res == 0)
            break;

        i++;

        fputc('\n', arc);
        printf("\nDigite la cadena de caracteres %d:\n", i + 1);
        gets(cadena);
        fputs(cadena, arc);
    }
}