#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Cambio de formato de fecha.

void Convert(char *, char *, char *);

void main(void)
{
    char date[30], *month, *year, dia[4], mes[4], ano[4];
    int i, a, b;

    printf("Digite una fecha en el formato dd/mm/aa : ");
    gets(date);
    fflush(stdin);

    month = strstr(date, "/");
    year = strstr(month + 1, "/");

    for (i = 1; i < 3; i++)
    {
        dia[i - 1] = date[i - 1];
        mes[i - 1] = month[i];
        ano[i - 1] = year[i];
    }

    a = atoi(dia);
    b = atoi(mes);

    if (a > 0 && a <= 31)
    {
        if (b > 0 && b <= 12)
        {
            printf("\n");
            Convert(dia, mes, ano);
            printf("\n");
        }
        else
            printf("Digite un mes correcto, por favor.\n");
    }
    else
        printf("Digite un día dentro del rango de lo permitido, por favor.\n");

    
}

void Convert(char *day, char *month, char *Year)
{
    int year, ndias;
    
    year = atoi(Year);
    ndias = atoi(day);

    if (strcmp(month, "01") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Enero de 19%s", day, Year);
        else
            if (year >= 0 && year <=22)
                printf("%s de Enero del 20%s", day, Year);
            else
                printf("El año es incorrecto.");

    if (strcmp(month, "02") == 0)
    {
        if (ndias < 30)
        {
            if (ndias < 29)
            {
                if (year > 22 && year <= 99)
                    printf("%s de Febrero de 19%s", day, Year);
                else
                    if (year >= 0 && year <=22)
                        printf("%s de Febrero del 20%s", day, Year);
                    else
                        printf("El año es incorrecto.");
            }
            else
            {
                if (year % 4 == 0)
                {
                    if (year > 22 && year <= 99)
                        printf("%s de Febrero de 19%s", day, Year);
                    else
                        if (year >= 0 && year <=22)
                            printf("%s de Febrero del 20%s", day, Year);
                        else
                            printf("El año es incorrecto.");
                }
                else
                    printf("El año no corresponde para que el día sea veintinueve.");
            }
        }
        else
            printf("El número de días sobrepasa los permitidos para el mes de Febrero.");
    }

    if (strcmp(month, "03") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Marzo de 19%s", day, Year);
        else
            if (year >= 0 && year <=22)
                printf("%s de Marzo del 20%s", day, Year);
            else
                printf("El año es incorrecto.");

    if (strcmp(month, "04") == 0)
    {
        if (ndias < 31)
        {
            if (year > 22 && year <= 99)
                printf("%s de Abril de 19%s", day, Year);
            else
                if (year >= 0 && year <=22)
                    printf("%s de Abril del 20%s", day, Year);
                else
                    printf("El año es incorrecto.");
        }
        else
            printf("El número de días sobrepasa los permitidos para el mes de Abril.");
    }

    if (strcmp(month, "05") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Mayo de 19%s", day, Year);
        else
            if (year >= 0 && year <=22)
                printf("%s de Mayo del 20%s", day, Year);
            else
                printf("El año es incorrecto.");

    if (strcmp(month, "06") == 0)
    {
        if (ndias < 31)
        {
            if (year > 22 && year <= 99)
                printf("%s de Junio de 19%s", day, Year);
            else
                if (year >= 0 && year <=22)
                    printf("%s de Junio del 20%s", day, Year);
                else
                    printf("El año es incorrecto.");
        }
        else
            printf("El número de días sobrepasa los permitidos para el mes de Junio.");
    }

    if (strcmp(month, "07") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Julio de 19%s", day, Year);
        else
            if (year >= 0 && year <=22)
                printf("%s de Julio del 20%s", day, Year);
            else
                printf("El año es incorrecto.");

    if (strcmp(month, "08") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Agosto de 19%s", day, Year);
        else
            if (year >= 0 && year <=22)
                printf("%s de Agosto del 20%s", day, Year);
            else
                printf("El año es incorrecto.");

    if (strcmp(month, "09") == 0)
    {
        if (ndias < 31)
        {
            if (year > 22 && year <= 99)
                printf("%s de Setiembre de 19%s", day, Year);
            else
                if (year >= 0 && year <=22)
                    printf("%s de Setiembre del 20%s", day, Year);
                else
                    printf("El año es incorrecto.");
        }
        else
            printf("El número de días sobrepasa los permitidos para el mes de Setiembre.");
    }

    if (strcmp(month, "10") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Octubre de 19%s", day, Year);
        else
            if (year >= 0 && year <=22)
                printf("%s de Octubre del 20%s", day, Year);
            else
                printf("El año es incorrecto.");

    if (strcmp(month, "11") == 0)
    {
        if (ndias < 31)
        {
            if (year > 22 && year <= 99)
                printf("%s de Noviembre de 19%s", day, Year);
            else
                if (year >= 0 && year <=22)
                    printf("%s de Noviembre del 20%s", day, Year);
                else
                    printf("El año es incorrecto.");
        }
        else
            printf("El número de días sobrepasa los permitidos para el mes de Noviembre.");
    }

    if (strcmp(month, "12") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Diciembre de 19%s", day, Year);
        else
            if (year >= 0 && year <=22)
                printf("%s de Diciembre del 20%s", day, Year);
            else
                printf("El año es incorrecto.");
}