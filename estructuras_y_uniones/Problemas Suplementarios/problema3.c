#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Univerdidad.
 * El programa realiza el cálculo del salario de los profesores de una universidad. */

typedef struct          // Estructura tipo profesor.
{
    int number_emp;         // Número de empleado.
    char name_Address[30];  // Nombre y apellido.
    char dep[20];           // Departamento al que pertenece.
    char puesto[20];        // Puesto que ocupa.
    char grado[20];         // Grado académico.
    char nacio[20];         // Nacionalidad.
    float sal[12];          // Salario.
} PROFESOR;

void Lectura(PROFESOR *, int);
void Exitoso(PROFESOR *, int);
void Extranjeros(PROFESOR *, int);
void Departamento_pagos(PROFESOR *, int);

void main(void)
{
    int TAM;
    PROFESOR EMPLE[200];

    do
    {
        printf("Digite el número de profesores: ");
        scanf("%d", &TAM);
        fflush(stdin);
    }
    while (TAM > 200 || TAM < 1);

    Lectura(EMPLE, TAM);
    Exitoso(EMPLE, TAM);
    Extranjeros(EMPLE, TAM);
    Departamento_pagos(EMPLE, TAM);
}

void Lectura(PROFESOR A[], int T)
{
    int i, elec, j;

    for (i = 0; i < T; i++)
    {
        printf("\n\tDatos del profesor %d", i + 1);

        printf("\nNúmero de registro: ");
        scanf("%d", &A[i].number_emp);
        fflush(stdin);

        printf("Nombre y apellido: ");
        gets(A[i].name_Address);
        fflush(stdin);

        do
        {
            printf("Departamento al que pertenece: 1. Economía   2. Derecho   3. Computación   4. Administración\n");
            scanf("%d", &elec);
            fflush(stdin);
        }
        while (elec > 4 || elec < 1);
        switch (elec)
        {
            case 1: strcpy(A[i].dep, "Economía");
                break;
            case 2: strcpy(A[i].dep, "Derecho");
                break;
            case 3: strcpy(A[i].dep, "Computación");
                break;
            case 4: strcpy(A[i].dep, "Administración");
                break;
        }

        printf("Puesto que ocupa: ");
        gets(A[i].puesto);
        fflush(stdin);

        printf("Grado académico: ");
        gets(A[i].grado);
        fflush(stdin);

        printf("Nacionalidad: ");
        gets(A[i].nacio);
        fflush(stdin);

        for (j = 0; j < 12; j++)
        {
            printf("Salario del mes %d: ", j + 1);
            scanf("%f", &A[i].sal[j]);
            fflush(stdin);
        }
    }
}

void Exitoso(PROFESOR A[], int T)           // Función que calcula y muestra los datos del profesor que ganó más el año pasado.
{
    int i, j, x;
    float sum, max = 0.0;
    char pro[30], depa[20], nac[20];

    for (i = 0; i < T; i++)
    {
        sum = 0.0;
        x = 0;
        for (j = 0; j < 12; j++)
            sum += A[i].sal[j];

        if (sum > max)
        {
            max = sum;
            x = i;
        }
    }

    i = 0;
    while (A[x].name_Address[i] != '\0')
    {
        pro[i] = toupper(A[x].name_Address[i]);
        i++;
    }
    pro[i] = '\0';

    i = 0;
    while (A[x].dep[i] != '\0')
    {
        depa[i] = toupper(A[x].dep[i]);
        i++;
    }
    depa[i] = '\0';

    i = 0;
    while (A[x].nacio[i] != '\0')
    {
        nac[i] = toupper(A[x].nacio[i]);
        i++;
    }
    nac[i] = '\0';

    printf("\nEl profesor que ganó más el año pasado:\n");
    printf("El profesor %s del departamento de %s de nacionalidad %s quien ganó $%.2f.\n", pro, depa, nac, max);
}

void Extranjeros(PROFESOR A[], int T)       // Función que calcula los gastos de paga a los profesores extranjeros y el porcentaje del total.
{
    int i, j;
    float sum = 0.0, total = 0.0;

    for (i = 0; i < T; i++)
    {
        if (strcmp(A[i].nacio, "Colombia") != 0)
            for (j = 0; j < 12; j++)
                sum += A[i].sal[j];
    }

    for (i = 0; i < T; i++)
        for (j = 0; j < 12; j++)
            total += A[i].sal[j];

    if (sum)
        printf("\nEl monto total pagado a los profesores extranjeros es de $%.2f que representa el %.2f por ciento del total de erogado que es %.2f.", sum, (sum / total) * 100, total);
    else
        printf("\nNo hay profesores extranjeros\nEl pago total a los profesores es de $%.2f", total);
}

void Departamento_pagos(PROFESOR A[], int T)    // Función que calcula el total del pago de cada departamento.
{
    int i, j;
    float saldo_Economia = 0.0, saldo_Derecho = 0.0, saldo_Computacion = 0.0, saldo_Administracion = 0.0;

    for (i = 0; i < T; i++)
    {
        if (strcmp(A[i].dep, "Economía") == 0)
            for (j = 0; j < 12; j++)
                saldo_Economia += A[i].sal[j];
        else
            if (strcmp(A[i].dep, "Derecho") == 0)
                for (j = 0; j < 12; j++)
                    saldo_Derecho += A[i].sal[j];
            else
                if (strcmp(A[i].dep, "Computación") == 0)
                    for (j = 0; j < 12; j++)
                        saldo_Computacion += A[i].sal[j];
                else
                    if (strcmp(A[i].dep, "Administración") == 0)
                        for (j = 0; j < 12; j++)
                            saldo_Administracion += A[i].sal[j];
    }

    printf("\n\nSalarios en cada departamento:\n");
    printf("\n\tEconomía: $%.2f\n\tDerecho: $%.2f\n\tComputación: $%.2f\n\tAdministración: $%.2f\n", saldo_Economia, saldo_Derecho, saldo_Computacion, saldo_Administracion);

    if (saldo_Economia > saldo_Derecho)
        if (saldo_Economia > saldo_Computacion)
            if (saldo_Economia > saldo_Administracion)
                printf("\nSe gastó más en Economía, un monto de $%.2f\n", saldo_Economia);
            else
                printf("\nSe gastó más en Administraciónn, un monto de $%.2f\n", saldo_Administracion);
        else
            if (saldo_Computacion > saldo_Administracion)
                printf("\nSe gastó más en Computación, un monto de %.2f\n", saldo_Computacion);
            else
                printf("\nSe gastó más en Administración, un monto de %.2f\n", saldo_Administracion);
    else
        if (saldo_Derecho > saldo_Computacion)
            if (saldo_Derecho > saldo_Administracion)
                printf("\nSe gastó más en Derecho, un monto de %.2f\n", saldo_Derecho);
            else
                printf("\nSe gastó más en Administración, un monto de %.2f\n", saldo_Administracion);
        else
            if (saldo_Computacion > saldo_Administracion)
                printf("\nSe gastó más en Computaición, un montó de %.2f\n", saldo_Computacion);
            else
                printf("\nSe gastó más en Administración, un montó de %.2f\n", saldo_Administracion);
}