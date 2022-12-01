/* Escritura del archivo de taxto como parte de la resolución al problema uno. */

#include <stdio.h>
#include <stdbool.h>

void lee(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc1.txt", "w")) != NULL)
    {
        lee(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void lee(FILE *arc)
{
    char string[250];
    int res;

    printf("\n¿Desea digitar una cadena de caracteres? (1. sí   0. no (salir)): ");
    scanf("%d", &res);
    fflush(stdin);

    while (true)
    {
        printf("\nDigite la cadena de su preferencia:\n");
        gets(string);
        fputs(string, arc);

        printf("\n¿Desea digitar otra cadena de caracteres? (1. sí   0. no (salir)): ");
        scanf("%d", &res);
        fflush(stdin);

        if (res == 0)
            break;
        
        fputs("\n", arc);
    }
}