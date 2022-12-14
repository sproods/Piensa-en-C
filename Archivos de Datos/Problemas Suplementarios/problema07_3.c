/* programa que lee un archivo de acceso directo. */

#include <stdio.h>

typedef struct
{
    int mat;
    char name[30];
    int car;
    float pro;
} Datos;

void read(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("ark7.dat", "r")) != NULL)
    {
        read(arxiv);
        fclose(arxiv);
    }
    else
        printf("\El archivo no ha podido ser abierto.\n");
}

void read(FILE *arc)
{
    int i = 0;
    Datos datitox;

    fread(&datitox, sizeof(Datos), 1, arc);

    while (!feof(arc))
    {
        i++;

        printf("\nRegistro %d\n", i);
        printf("\nMatrícula: \t%d", datitox.mat);
        printf("\nNombre: \t%s", datitox.name);
        printf("\nCarrera: \t%d", datitox.car);
        printf("\nPromedio: \t%.2f\n", datitox.pro);

        fread(&datitox, sizeof(Datos), 1, arc);
    }
}
