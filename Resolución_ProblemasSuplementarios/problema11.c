#include <stdio.h>

/* Datos del número de turistas dados por la secretaría de Turismo. */

#define CEN 10
#define MES 12
#define YEAR 5

void Total_Visitantes(int [][MES][YEAR]);          /* Prototipos de funciones. */
void Min_Max(int [][MES][YEAR]);
void Lectura(int [][MES][YEAR]);

void main(void)
{
    int SEC[CEN][MES][YEAR];

    printf("Digite el número de visitantes para el año, mes y centro correspondiente:\n");
    Lectura(SEC);

    printf("\nTotal de visitantes en los cinco años para cada uno de los centros turísticos:\n\n");
    Total_Visitantes(SEC);

    printf("\nEn el quinto año, los meses con menor y mayor número de visitantes fueron:\n\n");
    Min_Max(SEC);
}

void Lectura(int A[CEN][MES][YEAR])
{
    int i, j, k;

    for (k = 0; k < YEAR; k++)
        for (i = 0; i < CEN; i++)
            for (j = 0; j < MES; j++)
            {
                printf("Año %d\tCentro %d\tMes %d: \n", k + 1, i + 1, j + 1);
                scanf("%d", &A[i][j][k]);
            }
}

void Total_Visitantes(int A[CEN][MES][YEAR])          /* Función que realiza el cálculo del total de visitantes para cada centro de turismo. */
{
    int i, j, k, total, min, may, cenMin, cenMay;

    min = 10000 * YEAR * MES;
    may = 0;

    for (i = 0; i < YEAR; i++)
    {
        total = 0;
        printf("CENTRO %d: ", i + 1);
        for (k = 0; k < YEAR; k++)
            for (j = 0; j < MES; j++)
                total += A[i][j][k];
        
        printf("%d en los cinco años.\n", total);

        if(may < total)
        {
            may = total;
            cenMay = i;
        }

        if(min > total)
        {
            min = total;
            cenMin = i;
        }
    }

    printf("El centro con mayor número de visitantes es el %d con %d visitantes en los últimos cinco años\n", cenMay, may);
    printf("El centro con menor número de visitantes es el %d con %d visitantes en los últimos cinco años\n", cenMin, min);
}

void Min_Max(int A[CEN][MES][YEAR])
{
    int i, j, men, may, mesMen, mesMay, sum;

    sum = 0;
    may = 0;
    men = 100000 * MES;

    for (j = 0; j < MES; j++)
    {
        for (i = 0; i < CEN; i++)
            sum += A[i][j][YEAR];
        
        if (sum > may)
        {
            may = sum;
            mesMay = j;
        }

        if (sum < men)
        {
            men = sum;
            mesMen = j;
        }
    }

    printf("El mes con menor número de visitantes en el quinto año fue el %d con %d visitante\n", mesMen, men);
    printf("El mes con mayor número de visitantes en el quinto año fue el %d con %d visitante\n", mesMay, may);
}