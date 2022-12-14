#include <stdio.h>

/* El programa escribe en un archivo los datos de las matrículas de N alumnos. */

#define MES 5

void Escribe(FILE *, int);

void main(void)
{
    int N;
    FILE *arxiv;

    printf("\nDigite la cantidad de alumnos de los cuales escribirá sus calificiones: ");
    scanf("%d", &N);
    fflush(stdin);

    if ((arxiv = fopen("arc2.txt", "w")) != NULL)
    {
        Escribe(arxiv, N);
        fclose(arxiv);
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");
}

void Escribe(FILE *arc, int cant)
{
    int i, j;
    float nota;
    char name[50];

    fprintf(arc, "%d", cant);

    for (i = 0; i < cant; i++)
    {
        printf("\nDigite el nombre del alumno %d: ", i + 1);
        gets(name);
        fflush(stdin);
        fputc('\n', arc);
        fputs(name, arc);

        for (j = 0; j < MES; j++)
        {
            printf("\tDigite la nota %d del alumno %s: ", j + 1, name);
            scanf("%f", &nota);
            fflush(stdin);
            fprintf(arc, "\n%.2f", nota);
        }
    }
}