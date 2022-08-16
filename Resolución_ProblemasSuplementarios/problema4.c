#include <stdio.h>

#define MAX 100

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

    if(RES == 1)
        printf("\n¡Es un cuadrado mágico!\n");
    else
        printf("\n¡No es un cuadrado mágico!\n");
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
    int I, J, E = 1, SUM, SUM1, SUM2, SUM3, SUM4;
    
    SUM = 0;
    for(J = 0; J < T; J++)          /* Tomando la suma inicial de la primera fila. */
    {
        SUM += A[0][J];
    }

    for(I = 1; I < T; I++)          /* Comparando las sumatorias de las filas. */
    {
        SUM1 = 0;
        for(J = 0; J < T; J++)
            SUM1 += A[I][J];
        
        if(SUM1 == SUM)
            ;
        else
            E = 0;
    }

    if(E == 1)                      /* Condición para continuar con las comparaciones. */
    {
        for(J = 0; J < T; J++)      /* Comparando las sumatorias de las columnas. */
        {
            SUM2 = 0;
            for(I = 0; I < T; I++)
                SUM2 += A[I][J];
            
            if(SUM2 == SUM)
                ;
            else
                E = 0;
        }

        if(E == 1)                  /* Condición para continuar con las comparaciones. */
        {
            SUM3 = 0;
            for(I = 0; I < T; I++)  /* Comparando las sumatorias de la diagonal principal. */
                SUM3 += A[I][I];

            if(SUM3 == SUM)
                ;
            else
                E = 0;
            
            if(E == 1)
            {
                SUM4 = 0;
                for(I = 0; I < T; I++)
                    SUM4 += A[I][T - 1 - I];
                if(SUM4 == SUM)
                    return E;
                else
                    return E;
            }
            else
                return E;
        }
        else
            return E;
        
    }
    else
        return E;
}