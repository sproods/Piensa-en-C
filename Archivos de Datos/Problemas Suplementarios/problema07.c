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
    int i;

}
