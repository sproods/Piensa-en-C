#include <stdio.h>
#include <math.h>

/* Recorrido en espiral de un arreglo de números enteros. */

#define MAX 50

// void Lectura(int [][MAX], int , int);           /* Prototipos de funciones. */
void Imprime(int [][MAX], int , int);
void Path(int [][MAX], int , int);

void main(void)
{
    int MAT[MAX][MAX], M, N;

    do
    {
        printf("Digite el número de filas del arreglo: \n");
        scanf("%d", &M);
    }
    while(M < 1 || M > 50);

    do
    {
        printf("Digite el número de columnas del arreglo: \n");
        scanf("%d", &N);
    }
    while(N < 1 || N > 50);

    // Lectura(MAT, M, N);
    // printf("\nEL ARREGLO:");
    // Imprime(MAT, M, N);
    printf("\nEL RECORRIDO EN ESPIRAL DEL AREGLO:\n");
    Path(MAT, M, N);
}

// void Lectura(int A[][MAX], int F, int C)
// {
//     int I, J;

//     for(I = 0; I < F; I++)
//         for(J = 0; J < C; J++)
//         {
//             printf("Digite el componente %d %d: ", I + 1, J + 1);
//             scanf("%d", &A[I][J]);
//         }
// }

void Imprime(int A[][MAX], int F, int C)
{
    int I, J;

    printf("\n");
    for(I = 0; I < F; I++)
    {
        printf("|");
        for(J = 0; J < C; J++)
            printf(" %d |", A[I][J]);
        printf("\n");
    }
}

void Path(int A[][MAX], int F, int C)
{
    int i, j, cam, sen, inicio, limitefil, limitecol, maximo, N;

    maximo = F * C;
    N = 1;
    i = 0;
    limitefil = F;
    limitecol = C;
    inicio = 0;
    cam = 0;
    sen = 1;
    
    while(N <= maximo)
    {
        if (sen == 1)
        {
            for (j = inicio; j < limitecol; j++)
            {
                j += pow(-1, cam);
                A[i][j] = N++;
            }
            C--;
            sen--;
        }

        else
        {
            for (i = 1; i < limitefil; i++)
            {
                i += pow(-1, cam);
                printf("MAT[%d][%d] = %3d\n", i, j, A[i][j]);
            }
            F--;
            sen++;
            cam++;
        }
    }
}