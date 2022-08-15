#include <stdio.h>

const int MAX = 50;

void Lectura(int[][MAX], int);        /* Prototipos de funciones. */
void Imprime(int[][MAX], int);
int Prueba(int[][MAX], int);

void main(void)
{
    int CUA[MAX][MAX], TAM, RES;

    do
    {
        printf("\nDigite el tamaño del cuadrado mágico: ");
        scanf("%d", &TAM);
    }
    while((TAM < 1 || TAM > 50) && (TAM % 2 == 0));

    Lectura(CUA, TAM);
    Imprime(CUA, TAM);
    RES = Prueba(CUA, TAM);
}

void Lectura(int A[][MAX], int T)       /* La funión Lectura lee los componentes del arreglo. */
{
    int I, J;

    for(I = 0; I < T; I++)
        for(J = 0; J < T; J++)
        {
            printf("\nDigite el componente %d %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
}

void Imprime(int A[][MAX], int T)
{
    int I, J;

    printf("\n");
    for(I = 0; I < T; I++)
    {
        printf("|");
        for(J = 0; J < T; J++)
        {
            printf(" %d |", A[I][J]);
        }
        printf("\n");
    }
}

int Prueba(int A[][MAX], int T)
{
    int I, J;
}