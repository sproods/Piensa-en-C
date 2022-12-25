/* pragrama que realiza la muestra en pantalla de los análisis necesarios para poder considerar en las estadísticas de los datos de los pacientes de un hospital. */

#include <stdio.h>
#include <string.h>

typedef struct
{
    char calle[20];
    int numero;
    char colonia[50];
    char codigo[10];
    char ciudad[30];
    char tele[15];
} domicilio;

typedef struct
{
    int clave;
    char nombre[30];
    int edad;
    char sexo[30];
    int condicion;
    domicilio domi;
} datos;

void porcentaje(FILE *);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("pacientes.dat", "r");

    if (arxiv != NULL)
    {
        porcentaje(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void porcentaje(FILE *arc)
{
    datos paciente;
    int n_hombres = 0, n_mujeres = 0, total_pacientes = 0, d, tam;
    float prom_mujeres, prom_hombres;

    tam = sizeof(datos);
    fseek(arc, 0, 0);
    // fread(&paciente.domi, sizeof(domicilio), 1, arc);
    fread(&paciente, tam, 1, arc);

    while (!feof(arc))
    {
        d = ftell(arc) / tam;
        total_pacientes++;

        if (strcmp(paciente.sexo, "Femenino") == 0)
            n_mujeres++;
        if (strcmp(paciente.sexo, "Masculino") == 0)
            n_hombres++;

        fseek(arc, d * sizeof(datos), 0);
        fread(&paciente.domi, sizeof(domicilio), 1, arc);
        fread(&paciente, tam, 1, arc);
    }

    prom_mujeres = (float)n_mujeres / total_pacientes;
    prom_hombres = (float)n_hombres / total_pacientes;

    printf("\nhombres: %d\tmujeres: %d\ttotal: %d\n", n_hombres, n_mujeres, total_pacientes);
    printf("\nEl promedio de mujeres que hay en el hospital es del %.2f \%\n", prom_mujeres * 100);
    printf("\nEl promedio de hombres que hay en el hospital es del %.2f \%\n", prom_hombres * 100);
}