#include <stdio.h>
#include <string.h>

/* Bienes raices.
 * El programa maneja infomación sobre las propiedades que tiene una empresa de bienes
 * raices de la ciudad de Lima, Perú, tanto para ventas como para renta. */

typedef struct          // Declaración de la estructura ubicación.
{
    char zona[20];
    char calle[20];
    char col[20];       // Colonia.
} ubicacion;

typedef struct          // Declaración de la estructura propiedades.
{
    char clave[5];
    float scu;          // Superficie cubierta.
    float ste;          // Superficie terreno.
    char car[50];       // Características.
    ubicacion ubi;      // Observe que este campo es de tipo estructura ubicacion.
    float precio;
    char dispo;         // Disponibilidad.
} propiedades;

void Lectura(propiedades *, int);       // Prototipos de funciones.
void F1(propiedades *, int);
void F2(propiedades *, int);

void main(void)
{
    propiedades PROPIE[100];        // Se declara un arreglo unidimensional de tipo estructura propiedad.
    int TAM;

    do
    {
        printf("Digite el número de propiedades: ");
        scanf("%d", &TAM);
        fflush(stdin);
    }
    while (TAM > 100 || TAM < 1);   // Se verifica que el tamaño del arreglo sea correcto.

    Lectura(PROPIE, TAM);
    F1(PROPIE, TAM);
    F2(PROPIE, TAM);
}

void Lectura(propiedades A[], int T)
/* Esta función se utiliza para leer un arreglo unidimensional de tipo estructura propiedades de T elementos. */
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("\n\tDigite los datos de la propiedad %d", I + 1);
        printf("\nClave: ");
        gets(A[I].clave);
        fflush(stdin);

        printf("Superficie cubierta: ");
        scanf("%f", &A[I].scu);
        fflush(stdin);

        printf("Superficie terreno: ");
        scanf("%f", &A[I].ste);
        fflush(stdin);

        printf("Características: ");
        gets(A[I].car);
        fflush(stdin);

        printf("\tZona: ");
        gets(A[I].ubi.zona);
        fflush(stdin);

        printf("\tCalle: ");
        gets(A[I].ubi.calle);
        fflush(stdin);

        printf("\tColonia: ");
        gets(A[I].ubi.col);
        fflush(stdin);

        printf("Precio: ");
        scanf("%f", &A[I].precio);
        fflush(stdin);

        printf("Disponibilidad (Venta-V  Renta-R: ");
        scanf("%c", &A[I].dispo);
        fflush(stdin);
    }
}

void F1(propiedades A[], int T)
/* Esta función se utiliza para generar un listado de las propiedades disponibles
 * para venta en la zona de Miraflores, cuyo valor oscila entre 450,000 y 650,000 nuevos soles. */
{
    int I;

    printf("\n\t\tListado de Propiedades para Venta en Miraflores");

    for (I = 0; I < T; I++)
        if ((A[I].dispo == 'V') && (strcmp(A[I].ubi.zona, "Miraflores") == 0))
            if ((A[I].precio >= 450000) && (A[I].precio <= 650000))
            {
                printf("\nClave de la propiedad: ");
                puts(A[I].clave);
                printf("\nSuperficie cubierta: %f", A[I].scu);
                printf("\nSuperficie terreno: %f", A[I].ste);
                printf("\nCaracterísticas: ");
                puts(A[I].car);
                printf("Calle: ");
                puts(A[I].ubi.calle);
                printf("Colonia: ");
                puts(A[I].ubi.col);
                printf("Precio: %.2f\n", A[I].precio);
            }
}

void F2(propiedades A[], int T)
/* Al recibir como datos una zona geográfica de Lima, Perú, y un cierto rango respecto al
 * monto, esta función genera un listado de todas las propiedades disponibles para renta. */
{
    int I;
    float li, ls;
    char zon[20];

    printf("\n\t\tListado de Propiedades para Renta");
    printf("\nDigite zona geográfica: ");
    fflush(stdin);
    gets(zon);

    printf("Digite el límite inferior del precio: ");
    scanf("%f", &li);
    fflush(stdin);

    printf("Digite el límite superior del precio: ");
    scanf("%f", &ls);
    fflush(stdin);

    for (I = 0; I < T; I++)
        if ((A[I].dispo == 'R') && (strcmp(A[I].ubi.zona, zon) == 0))
            if ((A[I].precio >= li) && (A[I].precio <= ls))
            {
                printf("\nClave de la propiedad: ");
                puts(A[I].clave);
                printf("\nSuperficie cubierta: %d", A[I].scu);
                printf("\nSuperficie terreno: %d", A[I].ste);
                printf("\nCaracterísticas: ");
                puts(A[I].car);
                printf("Calle: ");
                puts(A[I].ubi.calle);
                printf("Colonia: ");
                puts(A[I].ubi.col);
                printf("Precio: %.2f", A[I].precio);
            }
            else
                printf("\nEl precio no esta contemplado en el rango digitado.\n");
        else
            printf("\nNo hay disponibilidad o la zona no está no concuerda con la digitada.\n");
}