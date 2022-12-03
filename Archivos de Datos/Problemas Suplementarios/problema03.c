/* Programa que cuenta el número de palabras que hay en un archivo de texto de acceso secuencial. */

#include <stdio.h>

void words(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc2.txt", "r")) != NULL)
    {
        words(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void words(FILE *arc)
{
    int nWords, i, x;
	char word[250];

    x = 0;
    while (!feof(arc))
	{
		fgets(word, 250, arc);
		
        i = 0;
		while (word[i] != '\0')     // esta estructura realiza el conteo de las palabras excepto a la primera palabra.
        {
            if (word[i] == ' ' && word[i + 1] != ' ')
                x++;

            i++;
        }
        x++;            // se agrega una unidad por la palabra inicial que no se toma en cuenta en el conteo del while.
	}

    printf("\nHay %d palabras en el archivo.\n", x);
}