#include <stdio.h>
#include <string.h>

/* Tienda de electrodomésticos. */

typedef struct          // Estructura de tipo estructura Producto.
{
    int cla;            // Clave del producto.
    char nom[30];       // Nombre del producto.
    int exi;            // Existencia.
} Producto;

void Lectura(Producto *, int);
void Compras(Producto *, int);
void Ventas(Producto *, int);
void Ordena(Producto *, int);
void Lista(Producto *, int);

void main(void)
{
    Producto TIENDA[100];
    int TAM, dtran = 1;
    char tran;

    do
    {
        printf("\nDigite la cantidad de productos que va tener su tienda: ");
        scanf("%d", &TAM);
        fflush(stdin);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(TIENDA, TAM);
    Ordena(TIENDA, TAM);

    do
    {
        printf("\nDigite, a continuación, el tipo de transacción que desea realizar:\n\tC - Compras\n\tV - Ventas\n\tL - Lista de los productos\n");
        tran = getchar();
        fflush(stdin);
    }
    while (tran != 'C' && tran != 'V' && tran != 'L');

    while (tran == 'C' || tran == 'V' || tran == 'L' || dtran != 0)
    {
        switch (tran)
        {
            case 'C': Compras(TIENDA, TAM);
                break;
            case 'V': Ventas(TIENDA, TAM);
                break;
            case 'L': Lista(TIENDA, TAM);
                break;
        }

        do
        {
            printf("\nDigite, si desea, otra transacción:\n\tC - Compras\n\tV - Ventas\n\tL - Lista de productos\n\t0 - Salir\n");
            tran = getchar();
            fflush(stdin);

            if (tran == '0')
                dtran = 0;
        }
        while ((tran != 'C' && tran != 'V' && tran != 'L') && dtran);
    }

    printf("\n¡Qué tenga buen día!\n");
}

void Lectura(Producto A[], int T)
{
    int i;

    for (i = 0; i < T; i++)
    {
        printf("\nDatos del producto %d", i + 1);

        printf("\n\tDigite la clave del producto: ");
        scanf("%d", &A[i].cla);
        fflush(stdin);

        printf("\tDigite el nombre del producto: ");
        gets(A[i].nom);
        fflush(stdin);

        printf("\tDigite la cantidad de productos que hay en stock: ");
        scanf("%d", &A[i].exi);
        fflush(stdin);
    }
}

void Compras(Producto A[], int T)
{
    int i, clave, cant;

    printf("\nDigite la clave del producto: ");
    scanf("%d", &clave);
    fflush(stdin);

    while (clave)
    {
        i = 0;
        while (i < T && A[i].cla < clave)
            i++;

        if (i == T || A[i].cla > clave)
            printf("\nLa clave del producto es incorrecta\n");
        else
        {
            printf("\nDigite la cantidad que va a comprar del producto %s: ", A[i].nom);
            scanf("%d", &cant);
            fflush(stdin);

            A[i].exi += cant;
        }

        printf("\nDigite la clave de otro producto -0 para salir- : ");
        scanf("%d", &clave);
        fflush(stdin);
    }
}

void Ventas(Producto A[], int T)
{
    int i, clave, cant;
    char resp;

    printf("\nDigite la clave del producto: ");
    scanf("%d", &clave);
    fflush(stdin);

    while (clave)
    {
        i = 0;
        while (i < T && A[i].cla < clave)
            i++;

        if (i == T || A[i].cla > clave)
            printf("\nLa clave del producto es incorrecta\n");
        else
        {
            printf("\nDigite la cantidad que desea vender: ");
            scanf("%d", &cant);
            fflush(stdin);

            if (A[i].exi < cant)
            {
                do
                {
                    printf("\nNo hay suficientes productos para su venta, solo quedan %d en stock. ¿Desea conprarlos? -S/N-: ", A[i].exi);
                    resp = getchar();
                    fflush(stdin);
                }
                while (resp != 'S' && resp != 'N');

                if (resp == 'S')
                    A[i].exi = 0;
            }
            else
            {
                A[i].exi -= cant;
            }
        }

        printf("\nDigite la clave de otro producto que desea vender -0 para salir- : ");
        scanf("%d", &clave);
        fflush(stdin);
    }
}

void Ordena(Producto A[], int T)
{
    int i, j, x, min;
    Producto aux;

    for (i = 0; i < T - 1; i++)
    {
        min = A[i].cla;
        x = i;

        for (j = i + 1; j < T; j++)
        {
            if (A[j].cla < min)
            {
                min = A[j].cla;
                x = j;
            }
        }

        aux = A[i];
        A[i] = A[x];
        A[x] = aux;
    }
}

void Lista(Producto A[], int T)
{
    int i;

    printf("\nLista de los productos y las cantindades existentes en stock\n");

    for (i = 0; i < T; i++)
        printf("\n\tNombre del producto: %s\tCantidad: %d", A[i].nom, A[i].exi);

    printf("\n");
}