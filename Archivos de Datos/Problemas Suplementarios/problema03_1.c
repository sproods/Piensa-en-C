/* El programa escribe en un archivo de acceso directo varias cadenas de caracteres para se analizados en el problema número tres. */

#include <stdio.h>
#include <stdbool.h>

void write(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc2.txt", "w")) != NULL)
    {
        write(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no se ha podido abrir.\n");
}

void write(FILE *arc)
{
    int i, res;
    char cad[250];

    while (true)
    {
        i++;
        printf("\nDigite la cadena %d de caracteres:\n", i);
        gets(cad);
        fputs(cad, arc);

        printf("\n¿Desea digitar otra cadena de caracteres? (1. sí   0. no (salir)): ");
        scanf("%d", &res);
        fflush(stdin);

        if (res == 0)
            break;
        
        fputc('\n', arc);
    }
}