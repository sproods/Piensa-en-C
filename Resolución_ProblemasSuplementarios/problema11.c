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

void Total_Visitantes(int A[][][])          /* Función que realiza el cálculo del total de visitantes para cada centro de turismo. */
{
    int i, j, k;
}