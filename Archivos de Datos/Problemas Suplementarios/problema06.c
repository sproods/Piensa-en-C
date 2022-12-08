/* programa que realiza la corrección ortográfica de las letras b y v en la escritura española. */

#include <stdio.h>
#include <string.h>

#define MAX 50

void correction(FILE *);            // prototipo de función

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("doc.dat", "r");

    if (arxiv != NULL)
    {
        correction(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto. :(\n");
}

void correction(FILE *arc)
{
    int lines = 0, i;
    char dance[250], strings[MAX][250];

    while (!feof(arc))
    {
        fgets(dance, 250, arc);
        lines++;
    }
    
    rewind(arc);

    while(!feof(arc))
    {
        for (i = lines - 1; i >= 0; i--)
        {
            fgets(dance, 250, arc);
            strcpy(strings[i], dance);
        }
    }

    for (i = 0; i < lines; i++)
        printf("%s\n", strings[i]);
}
