/* El programa registra en un archivo de acceso secuencial varias cadenas de caracteres. */

#include <stdio.h>

void lee(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc.txt", "w")) != NULL)
    {
        lee(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void lee(FILE *arc)
{
    int res, i = 0;
    char cad[250];

    printf("¿Desea digitar una cadena de caracteres? (1. sí   0. no-salir): ");
    scanf("%d", &res);
    fflush(stdin);

    while (res)
    {
        printf("\nDigite la cadena %d de caracteres:\n", i + 1);
        gets(cad);
        fputs(cad, arc);

        printf("\n¿Desea digitar otra cadena de caractes? (1. sí   0. no-salir): ");
        scanf("%d", &res);
        fflush(stdin);

        if (res)
        {
            fputc('\n', arc);
            i++;
        }
    }

    printf("\n\n¡Gracias por su atención!\n");
}