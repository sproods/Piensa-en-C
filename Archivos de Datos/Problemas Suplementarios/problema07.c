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
void arrayOrdena(int [], int);
void elimina(int [], int *);
void escribe(FILE *, int []);

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

    // realizamos el ordenamiento de los valores del arreglo
    arrayOrdena(arr_mat, count_structures);

    printf("\nLas matrículas ordenadas son:\n");
    for (I = 0; I < count_structures; I++)
        printf("%d\n", arr_mat[I]);

    // realizamos la eliminación de los valores repetidos
    elimina(arr_mat, &count_structures);

    printf("\nLas matrículas actualizadas son:\n");
    for (I = 0; I < count_structures; I++)
        printf("%d\n", arr_mat[I]);

    // finalmente, realizamos la escritura de un nuevo archivo con las matrículas ordenadas
    escribe(arc, arr_mat);
}

void arrayOrdena(int A[MAX], int T)
{
    int i, j, index, may, aux;

    for (i = 0; i < T - 1; i++)
    {
        may = A[i];
        index = i;
        for (j = i + 1; j < T; j++)
        {
            if (may < A[j])
            {
                may = A[j];
                index = j;
            }
        }

        aux = A[i];
        A[i] = A[index];
        A[index] = aux;
    }
}

void elimina(int A[MAX], int *T)
{
    int i = 0, j, k;

    while (i < (*T - 1))
    {
        j = i + 1;

        while (j < *T)
        {
            if (A[i] == A[j])
            {
                for (k = j; k < (*T - 1); k++)
                    A[k] = A[k + 1];
                *T = *T - 1;
            }
            else
                j++;
        }

        i++;
    }
}
