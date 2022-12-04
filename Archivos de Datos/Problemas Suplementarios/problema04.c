/* programa que cuenta el número de veces que una cadena de caracteres
 * digitada por el usurio se repite en un archivo de texto. */

#include <stdio.h>
#include <string.h>

void cuenta(FILE *);            // prototipo de la función.

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc3.txt", "r")) != NULL)
    {
        cuenta(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void cuenta(FILE *arc)
{
    int i = 0;
    char string_1[250], string_2[50], *string;

    printf("\nDigite la cadena de caracteres que piensa que puede repetirse en el archivo:\n");
    gets(string_2);
    fflush(stdin);

    while (!feof(arc))
    {
        fgets(string_1, 250, arc);

        // strcpy(string, string_1);

        string = strstr(string_1, string_2);          // ubicamos el apuntador donde se repite la cadena digitada en la cadena del archivo.

        while (string != NULL)
        {
            i++;
            string = strstr(string + 1, string_2);
        }
    }

    printf("\n%d son las veces que la cadena <<%s>> se repite en todo el archivo de texto.\n", i, string_2);
}