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
    if (month = "01")
        if (year > 22 && year <= 99)
            printf("%s de Enero de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Enero del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "02")
        if (year > 22 && year <= 99)
            printf("%s de Febrero de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Febrero del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "03")
        if (year > 22 && year <= 99)
            printf("%s de Marzo de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Marzo del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "04")
        if (year > 22 && year <= 99)
            printf("%s de Abril de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Abril del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "05")
        if (year > 22 && year <= 99)
            printf("%s de Mayo de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Mayo del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "06")
        if (year > 22 && year <= 99)
            printf("%s de Junio de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Junio del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "07")
        if (year > 22 && year <= 99)
            printf("%s de Julio de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Julio del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "08")
        if (year > 22 && year <= 99)
            printf("%s de Agosto de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Agosto del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "09")
        if (year > 22 && year <= 99)
            printf("%s de Setiembre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Setiembre del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "10")
        if (year > 22 && year <= 99)
            printf("%s de Octubre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Octubre del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "11")
        if (year > 22 && year <= 99)
            printf("%s de Noviembre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Noviembre del 20%s", day, year);
        else
            printf("El año es incorrecto.");

    if (month = "12")
        if (year > 22 && year <= 99)
            printf("%s de Diciembre de 19%s", day, year);
        else if (year >= 0 && year <=22)
            printf("%s de Diciembre del 20%s", day, year);
        else
            printf("El año es incorrecto.");
}