#include <stdio.h>
#include <string.h>

// Cambio de formato de fecha.

void Convert(char *, char *, char *, char *);

void main(void)
{
    char date[10], *slash, i, *dia, *mes, *ano;

    printf("Digite una fecha en el formato dd/mm/aa : ");
    gets(date);

    while (date[i] != '\0')
    {
        if (date[i] == '/')
        {
            slash = strstr(date, "/");
        }
    }

    Convert(date, dia, mes, ano);
}

void Convert(char *string, char *day, char *month, char *year)
{
    if (strcmp(month, "01") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Enero de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Enero del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "02") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Febrero de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Febrero del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "03") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Marzo de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Marzo del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "04") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Abril de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Abril del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "05") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Mayo de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Mayo del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "06") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Junio de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Junio del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "07") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Julio de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Julio del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "08") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Agosto de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Agosto del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "09") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Setiembre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Setiembre del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "10") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Octubre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Octubre del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "11") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Noviembre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Noviembre del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (strcmp(month, "12") == 0)
        if (year > 22 && year <= 99)
            printf("%s de Diciembre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Diciembre del 20%s", day, year);
        else
            printf("El año es incorrecto.");
}