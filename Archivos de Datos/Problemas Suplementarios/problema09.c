/* programa que realiza operaciones venta, reabasteciemiento y lectura de los productos de una tienda
 * cuyos registros se escriben en una archivo binario. */

#include <stdio.h>

#define MAX 200

typedef struct
{
    int clave;
    char nombre[30];
    int cantidad;
    float precio;
} producto;

void ordena(FILE *);
void operacion(FILE *);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("com.dat", "r+");

    if (arxiv != NULL)
    {
        ordena(arxiv);
        //operacion(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void ordena(FILE *arc)
{
    int conteo = 0, d, tam, i, array[MAX];
    int j, min, index, aux;
    producto mytienda;

    tam = sizeof(producto);

    // primero, realizamos un conteo del número de registros que hay en el archivo binario
    fseek(arc, 0, 0);
    fread(&mytienda, sizeof(producto), 1, arc);

    while (!feof(arc))
    {
        d = ftell(arc) / tam;

        conteo++;

        fseek(arc, d * sizeof(producto), 0);
        fread(&mytienda, sizeof(producto), 1, arc);
    }

    // almacenamos los números de las claves en un arreglo unidimensional
    fseek(arc, 0, 0);
    fread(&mytienda, tam, 1, arc);
    for (i = 0; i < conteo; i++)
    {
        d = ftell(arc) / tam;

        array[i] = mytienda.clave;

        fseek(arc, d * sizeof(producto), 0);
        fread(&mytienda, tam, 1, arc);
    }

    // realizamos el ordenamiento de los valores almacenados en el arreglo
    for (i = 0; i < conteo - 1; i++)
    {
        min = array[i];
        index = i;
        for (j = i + 1; j < conteo; j++)
            if (min > array[j])
            {
                min = array[j];
                index = j;
            }
        aux = array[i];
        array[i] = array[index];
        array[index] = aux;
    }
}

void operacion(FILE *arc)
{
    ;
}