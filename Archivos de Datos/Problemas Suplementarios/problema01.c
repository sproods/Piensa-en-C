/* El programa reliza la comparación entre varias cadenas de caracteres determinando la cadena con mayor número de caracteres. */

#include <stdio.h>
#include <string.h>

void cuenta(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc1.txt", "r")) != NULL)
    {
        cuenta(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void cuenta(FILE *arc)
{
    int i, caracteres, max = 0;
    char cadena[250], cad[250];

    while (!feof(arc))
    {
        fgets(cadena, 250, arc);            // obtenos la primera línea de cadena de caracteres
        
        i = 0;
        caracteres = 0;
        while (cadena[i] != '\n')
        {
            caracteres++;
            i++;
        }

        if (caracteres > max)
        {
            max = caracteres;
            strcpy(cad, cadena);
        }
    }

    printf("\nLa longitud de la cadena más grande es de %d caracteres, que corresponde a la cadena <<%s>>.\n", max, cad);
}