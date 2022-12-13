/* Programa que realiza el ordenamiento y eliminación de matrículas repetidas y las almacena en un archivo de tipo dat. */

#include <stdio.h>
#include <string.h>

#define MAX 100

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
    int i, tam, may_mat = 0, index = 0, count_structures = 0, arr_mat[MAX], I;
    Datos datos_alumno;

    tam = sizeof(Datos);        // definimos el tamaño de cada bloque de estructura

    fseek(arc, 0, 0);           // nos posicionamos al inicio del archivo
    fread(&datos_alumno, sizeof(Datos), 1, arc);

    // realizamos un conteo de la cantidad de estructuras que hay en el archivo
    while (!feof(arc))
    {
        i = ftell(arc) / tam;

        if (datos_alumno.mat > 0)
            count_structures++;

        fseek(arc, i * sizeof(Datos), 0);
        fread(&datos_alumno, sizeof(Datos), 1, arc);
    }

    // almacenamos las matrículas en un arreglo unidimensional
    rewind(arc);
    fread(&datos_alumno, sizeof(Datos), 1, arc);
    
    for (I = 0; I < count_structures; I++)
    {
        i = ftell(arc) / tam;
        arr_mat[I] = datos_alumno.mat;
        
        fseek(arc, i * sizeof(Datos), 0);
        fread(&datos_alumno, sizeof(Datos), 1, arc);
    }
    
    printf("Las matrículas son:\n");
    for (I = 0; I < count_structures; I++)
        printf("%d\n", arr_mat[I]);
}
