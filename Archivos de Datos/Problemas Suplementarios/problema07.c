/* Programa que realiza el ordenamiento y eliminación de matrículas repetidas y las almacena en un archivo de tipo dat. */

#include <stdio.h>
#include <string.h>

typedef struct
{
    int mat;
    char name[30];
    int car;
    float pro;
} Datos;

void ordena(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("ad5.dat", "r")) != NULL)
    {
        ordena(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void ordena(FILE *arc)
{
    int i, tam, may_mat = 0, index = 0;
    Datos datos_alumno;

    tam = sizeof(Datos);        // definimos el tamaño de cada bloque de estructura

    fseek(arc, 0, 0);           // nos posicionamos al inicio del archivo
    fread(&datos_alumno, sizeof(Datos), 1, arc);

    while (!feof(arc))
    {
        i = ftell(arc) / tam;

        if (datos_alumno.mat > may_mat)
        {
            may_mat = datos_alumno.mat;
            index = i;
        }

        fseek(arc, i * sizeof(Datos), 0);
        fread(&datos_alumno, sizeof(Datos), 1, arc);
    }

    printf("\nLa matrícula mayor es %d ubicada en el índice %d\n", may_mat, index);
}
