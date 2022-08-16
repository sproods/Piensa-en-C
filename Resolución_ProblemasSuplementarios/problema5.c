#include <stdio.h>

/* Resolución del problema número cinco del libro.
Problemas sobre multiplicación de matrices bidimensionales. */

#define MAX 50

void Lectura(float [][MAX], int, int);         /* Prototipos de funciones. */
void Imprime(float [][MAX], int, int);
void Multiplica(float [][MAX], float [][MAX], float [][MAX], int, int, int);

void main(void)
{
    int M, N, P;
    float VEC1[MAX][MAX], VEC2[MAX][MAX], MUL[MAX][MAX];

    do
    {
        printf("\nDigite el número de filas del primer arreglo bidimensional: ");
        scanf("%d", &M);
    }
    while(M < 1 || M > MAX);

    do
    {
        printf("\nDigite el número de columnas del primer arreglo bidimensional: ");
        scanf("%d", &N);
    }
    while(N < 1 || N > MAX);

    do
    {
        printf("\nDigite el número de columnas del segundo arreglo bidimensional: ");
        scanf("%d", &P);
    }
    while(P < 1 || P > MAX);

    printf("\nPara el primer arreglo bidimensional de %dx%d:", M, N);
    Lectura(VEC1, M, N);
    printf("\nPara el segundo arreglo bidimensional de %dx%d:", N, P);
    Lectura(VEC2, N, P);
    Imprime(VEC1, M, N);
    Imprime(VEC2, N, P);

    Multiplica(VEC1, VEC2, MUL, M, N, P);
    Imprime(MUL, M, P);
}

void Lectura(float A[][MAX], int F, int C)
{
    int I, J;
    for(I = 0; I < F; I++)
        for(J = 0; J < C; J++)
        {
            printf("\nDigite el componente %d %d: ", I + 1, J + 1);
            scanf("%f", &A[I][J]);
        }
}

void Imprime(float A[][MAX], int F, int C)
{
    int I, J;
    for(I = 0; I < F; I++)
        for(J = 0; J < C; J++)
            printf("\n");
}