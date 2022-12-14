/* programa que lee los registros de una archivo binario. */

#include <stdio.h>

typedef struct
{
    int clave;
    char nombre[30];
    int cantidad;
    float precio;
} producto;

void read(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("com.dat", "r")) != NULL)
    {
        read(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void read(FILE *arc)
{
    int i = 0;
    producto myProducto;

    printf("\nProductos de la tienda:\n");

    fread(&myProducto, sizeof(producto), 1, arc);

    while (!feof(arc))
    {
        i++;
        printf("\n\tRegistro %d", i);

        printf("\nClave: \t%d", myProducto.clave);
        printf("\nNombre: \t%s", myProducto.nombre);
        printf("\nCantidad: \t%d", myProducto.cantidad);
        printf("\nPrecio: \t%.2f\n", myProducto.precio);

        fread(&myProducto, sizeof(producto), 1, arc);
    }
}