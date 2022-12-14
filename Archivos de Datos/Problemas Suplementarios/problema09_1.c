/* programa que escribe en un archivo binario bloques de datos para ser utilizados en la
 * resolución del problema ocho. */

#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int clave;          // clave del producto
    char nombre[30];    // nombre del producto
    int cantidad;       // cantidad o existencia del producto
    float precio;       // precio por unidad del producto
} producto;

void write(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("com.dat", "w")) != NULL)
    {
        write(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void write(FILE *arc)
{
    int i = 0, res;
    producto myProductos;

    printf("\n¡Bienvenido al registro de datos de su tienda!\n");

    while (true)
    {
        i++;
        printf("\nRegistro %d", i);

        printf("\nDigite la clave del producto: ");
        scanf("%d", &myProductos.clave);
        fflush(stdin);

        printf("Digite el nombre del producto: ");
        gets(myProductos.nombre);
        fflush(stdin);

        printf("Digite la cantidad del producto: ");
        scanf("%d", &myProductos.cantidad);
        fflush(stdin);

        printf("Digite el precio por unidad de %s: ", myProductos.nombre);
        scanf("%f", &myProductos.precio);
        fflush(stdin);

        fwrite(&myProductos, sizeof(producto), 1, arc);

        printf("Digite cualquier tecla para continuar o cero (0) para salir: ");
        scanf("%d", &res);
        fflush(stdin);

        if (res == 0)
            break;
    }

    printf("\nArchivo registrado satisfactoriamente.\n");
}