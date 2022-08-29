#include <stdio.h>

/* El programa realiza el estudio de los datos estadísticos sobre el número de asistentes a diez estadios de fútbol durante los doce meses en los últimos cinco años. */

#define EST 10
#define MES 12
#define ANO 5

void Lectura(int [EST][MES][ANO]);          /* Prototipos de funciones. */
void Analisis1(int [EST][MES][ANO]);
void Ordena(int *);
void Analisis2(int [EST][MES][ANO]);
void Analisis3(int [EST][MES][ANO]);

void main(void)
{
    int FUT[EST][MES][ANO];

    printf("Digite el número de asistentes para el año, estadio y mes correspondientes:\n\n");
    Lectura(FUT);
    printf("\n");
    Analisis1(FUT);
    printf("\n");

    printf("Los estadios con mayor y menor afluencia en los últimos cinco años fueron:\n\n");
    Analisis2(FUT);
    printf("\n");

    printf("En el último año, el mes con más afluencia de espectadores para cada estadio fue el siguiente:\n\n");
    Analisis3(FUT);
}

void Lectura(int A[EST][MES][ANO])
{
    int i, j, k;

    for(k = 0; k < ANO; k++)
        for(i = 0; i < EST; i++)
            for(j = 0; j < MES; j++)
            {
            printf("AÑO %d\tESTADIO %d\tMES %d: \n",k + 1, i + 1, j + 1);
                scanf("%d", &A[i][j][k]);
            }
}

void Analisis1(int A[EST][MES][ANO])
{
    int i, j, ASIS[EST] = {0}, sum;

    for(i = 0; i < EST; i++)
        for(j = 0; j < MES; j++)
        {
            ASIS[i] += A[i][j][ANO - 1];
        }

    Ordena(ASIS);
    printf("El número de asistentes en cada mes del año %d fue de: (ordenados de mayor a menor)\n", ANO);
    printf("{");
    for(i = 0; i < EST; i++)
        printf("%d, ", ASIS[i]);
    printf("\b\b}\n");
}

void Ordena(int *A)
{
    int i, j, AUX;

    for(i = 0; i < EST - 1; i++)
        for(j = i + 1; j < EST; j++)
            if(A[i] < A[j])
            {
                AUX = A[i];
                A[i] = A[j];
                A[j] = AUX;
            }
}

void Analisis2(int A[EST][MES][ANO])
{
    int i, j, k, sum, men, may, estadioMen, estadioMay;

    sum = 0;

    for(k = 0; k < ANO; k++)
        for(j = 0; j < MES; j++)
            sum += A[0][j][k];

    may = sum;
    men = sum;
    estadioMay = 0;
    estadioMen = 0;

    for(i = 1; i < EST; i++)
    {
        sum = 0;
        for(k = 0; k < ANO; k++)
            for(j = 0; j < MES; j++)
                sum += A[i][j][k];

        if(sum > may)
        {
            may = sum;
            estadioMay = i;
        }

        if(sum < men)
        {
            men = sum;
            estadioMen = i;
        }
    }

    printf("El estadio con mayor afluencia fue el %d con %d espectadores.\n", estadioMay + 1, may);
    printf("El estadio con menor afluencia fue el %d con %d espectadores.\n", estadioMen + 1, men);    
}

void Analisis3(int A[EST][MES][ANO])
{
    int i, j, espect_May, mes_May;

    mes_May = 0;
    espect_May = A[0][0][ANO - 1];

    for(i = 0; i < EST; i++)
    {
        for(j = 0; j < MES; j++)
        {
            if(espect_May < A[i][j][ANO - 1])
            {
                espect_May = A[i][j][ANO - 1];
                mes_May = j;
            }
        }

        printf("Estadio %d: El mes %d con %d asistentes.\n", i + 1, mes_May + 1, espect_May);
    }
}