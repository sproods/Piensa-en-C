#include <stdio.h>
#include <string.h>

// Prueba de algoritmo de ordenamiento de una estructura dentro de un arreglo.

typedef struct
{
    int codigo;
    char nombre[30];
    char descripcion[100];
    float valoracion;
} project;

void Lectura(project [], int);
void Imprime(project [], int);
void Orden(project [], int);

void main(void)
{
    project ARR[30];
    int TAM;

    printf("Digite la cantidad de proyectos que va a tener: ");
    scanf("%d", &TAM);

    Lectura(ARR, TAM);
    Orden(ARR, TAM);
    Imprime(ARR, TAM);
}

void Lectura(project A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("Datos del proyecto %d", I + 1);
        printf("\n\tCódigo: ");
        scanf("%d", &A[I].codigo);
        fflush(stdin);

        printf("\tNombre: ");
        gets(A[I].nombre);

        printf("\tDescripción: ");
        gets(A[I].descripcion);

        printf("\tValoración: ");
        scanf("%f", &A[I].valoracion);
        fflush(stdin);
    }
}

void Orden(project A[], int T)
{
    int I, J, min, aux, X;

    for (I = 0; I < T - 1; I++)
    {
        min = A[I].codigo;
        X = I;

        for (J = I + 1; J < T; J++)
        {
            if (min > A[J].codigo)
            {
                min = A[J].codigo;
                X = J;
            }
        }

        aux = A[I].codigo;
        A[I].codigo = A[X].codigo;
        A[X].codigo = aux;
    }
}

void Imprime(project A[], int T)
{
    int I;

    for (I = 0; I < T; I++)
    {
        printf("\nCódigo: %d", A[I].codigo);
        printf("\tNombre: %s", A[I].nombre);
        printf("\tDescripción: %s", A[I].descripcion);
        printf("\tValoración: %.2f", A[I].valoracion);
    }
}