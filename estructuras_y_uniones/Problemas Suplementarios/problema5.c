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

void main(void)
{
    Producto TIENDA[100];
    int TAM;
    char tran;

    do
    {
        printf("\nDigite la cantidad de productos que va tener su tienda: ");
        scanf("%d", &TAM);
        fflush(stdin);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(TIENDA, TAM);

    do
    {
        printf("\nDigite, a continuación, el tipo de transacción que desea realizar:\n\t'C' Compras\n\t'V' Ventas\n");
        tran = getchar();
        fflush(stdin);
    }
    while (tran != 'C' && tran != 'V');

    while (tran)
    {
        switch (tran)
        {
            case 'C': Compras(TIENDA, TAM);
                break;
            case 'V': Ventas(TIENDA, TAM);
                break;
        }

        do
        {
            printf("\nDigite, si desea, otra transacción:\n\t'C' Compras\n\t'V' Ventas\n\t0 Salir\n");
            tran = getchar();
            fflush(stdin);
        }
        while (tran != 'C' && tran != 'V' && tran != '0');
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
                printf("\nNo hay suficientes productos para su venta, solo quedan %d en stock. ¿Desea conprarlos? -S/N-: ", A[i].exi);
                resp = getchar();
                fflush(stdin);
            }
        }
    }
}