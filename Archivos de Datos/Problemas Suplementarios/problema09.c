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
void nuevo_registro(FILE *, int, int []);
void lee(void);

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

    // ahora transcribimos los registros ordenados a un nuevo archivo binario
    nuevo_registro(arc, conteo, array);
}

void operacion(FILE *arc)
{
    ;
}

void nuevo_registro(FILE *arc, int T, int A[])
{
    FILE *arxiv;
    int i, j, d, tam;
    producto mytienda;

    if ((arxiv = fopen("compras.dat", "w")) != NULL)
    {
        tam = sizeof(producto);

        rewind(arc);
        fread(&mytienda, tam, 1, arc);

        for (i = 0; i < T; i++)
        {
            for (j = 0; j < T; j++)
            {
                d = ftell(arc) / tam;
                if (mytienda.clave == A[i])
                {
                    fwrite(&mytienda, sizeof(producto), 1, arxiv);
                    break;
                }

                fseek(arc, d * sizeof(producto), 0);
                fread(&mytienda, sizeof(producto), 1, arc);
            }
            rewind(arc);
        }

        fclose(arxiv);

        lee();
    }
    else
        printf("\nEl nuevo archivo no ha podido ser creado.\n");
}

void lee(void)
{
    FILE *archivo;
    int i = 0;
    producto mitienda;

    if ((archivo = fopen("compras.dat", "r")) != NULL)
    {
        fread(&mitienda, sizeof(producto), 1, archivo);
        while (!feof(archivo))
        {
            i++;
            printf("\n\tResistro %d", i);
            printf("\nClave: \t%d", mitienda.clave);
            printf("\nNombre: \t%s", mitienda.nombre);
            printf("\nCantidad: \t%d", mitienda.cantidad);
            printf("\nPrecio: \t%.2f\n", mitienda.precio);

            fread(&mitienda, sizeof(producto), 1, archivo);
        }

        printf("\nEstos son todos los registros.\n");
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");

    fclose(archivo);
}