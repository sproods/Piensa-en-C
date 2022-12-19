/* programa que realiza operaciones venta, reabasteciemiento y lectura de los productos de una tienda
 * cuyos registros se escriben en una archivo binario. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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
void ventasProductos(void);
void nuevosProductos(void);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("com.dat", "r+");

    if (arxiv != NULL)
    {
        ordena(arxiv);
        operacion(arxiv);
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
    int op;
    char op2;

    printf("\n¡Bienvenido a la aplicación del registro de su tienda!\n\nDigite, a continuación, la opción que desea llevar a cabo:\n");

    do
    {
        printf("\t1. Venta\t2. Reabastecimientos\t3. Ver la lista de productos\n");
        scanf("%d", &op);
        fflush(stdin);
    }
    while (op < 1 || op > 3);

    while (op)
    {
        switch (op)
        {
            case 1: ventasProductos();
                break;
            case 2: nuevosProductos();
                break;
            case 3: lee();
                break;
        }

        do
        {
            printf("\n¿Desea realizar otra operación? (s/n): ");
            op2 = getchar();
            fflush(stdin);
        }
        while (op2 != 's' && op2 != 'n');

        if (op2 == 's')
        {
            printf("\nDigite, a continuación, la opción que desea llevar a cabo:\n");
            do
            {
                printf("\t1. Venta\t2. Reabastecimientos\t3. Ver la lista de productos\n");
                scanf("%d", &op);
                fflush(stdin);
            }
            while (op < 1 || op > 3);
        }
        else
        {
            printf("\n¡Gracias!\n");
            break;
        }
    }
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

void ventasProductos()
{
    int tam, d, nItems;
    float totalPagar = 0;
    char item[30], op;
    FILE *archivo;
    producto mitienda;

    while (true)
    {
        printf("\nDigite, por favor, el nombre del producto que desea vender: ");
        gets(item);
        fflush(stdin);

        item[0] = toupper(item[0]);

        // recorremos por todo el contenido del archivo en busca del registro que contenga el nombre buscado
        archivo = fopen("compras.dat", "r+");
        if (archivo != NULL)
        {
            tam = sizeof(producto);
            fseek(archivo, 0, 0);
            fread(&mitienda, sizeof(producto), 1, archivo);

            while (!feof(archivo))
            {
                d = ftell(archivo) / tam;
                if (strcmp(mitienda.nombre, item) == 0)
                {
                    printf("\nNúmero de elementos %s que va a vender: ", item);
                    scanf("%d", &nItems);
                    fflush(stdin);

                    if (nItems < mitienda.cantidad)
                    {
                        mitienda.cantidad -= nItems;
                        totalPagar += nItems * mitienda.precio;
                        printf("\nEl total a pagar será de %.2f\n", totalPagar);

                        fseek(archivo, (d - 1) * tam, 0);
                        fwrite(&mitienda, tam, 1, archivo);
                        fclose(archivo);
                        break;
                    }
                }

                fseek(archivo, d * tam, 0);
                fread(&mitienda, tam, 1, archivo);
            }
            fclose(archivo);
        }
        else
            printf("\nEl archivo de la tienda no se ha podido abrir.\n");

        do
        {
            printf("\n¿Va a realizar otra venta? (s/n): ");
            op = getchar();
            fflush(stdin);
        }
        while (op != 's' && op != 'n');

        if (op == 's')
            continue;
        else if(op == 'n')
            break;
    }
}

void nuevosProductos()
{
    ;
}