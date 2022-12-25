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
void condicion_pacientes(FILE *);
void edades(FILE *);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("pacientes.dat", "r");

    if (arxiv != NULL)
    {
        porcentaje(arxiv);
        condicion_pacientes(arxiv);
        edades(arxiv);
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
    printf("\nEl promedio de mujeres que hay en el hospital es del %.2f \%\a", prom_mujeres * 100);
    printf("\nEl promedio de hombres que hay en el hospital es del %.2f \%\n", prom_hombres * 100);
}

void condicion_pacientes(FILE *arc)
{
    datos pacientes;
    int i, condicio_N[5] = {0}, tam, d;

    tam = sizeof(datos);
    fseek(arc, 0, 0);
    fread(&pacientes, tam, 1, arc);

    while (!feof(arc))
    {
        d = ftell(arc) / tam;
        condicio_N[pacientes.condicion - 1]++;

        fseek(arc, d * sizeof(datos), 0);
        fread(&pacientes.domi, sizeof(domicilio), 1, arc);
        fread(&pacientes, sizeof(datos), 1, arc);
    }

    printf("\nNúmero de pacientes por la condición de su salud:\n");
    for (i = 0; i < 5; i++)
        printf("Condición %d: %d pacientes\n", i + 1, condicio_N[i]);
}

void edades(FILE *arc)
{
    datos paciente;
    int edad[11] = {0}, tam , d, i;

    tam = sizeof(datos);

    fseek(arc, 0, 0);
    fread(&paciente, sizeof(datos), 1, arc);

    while (!feof(arc))
    {
        d = ftell(arc) / tam;

        edad[paciente.edad / 10]++;

        fseek(arc, d * sizeof(datos), 0);
        fread(&paciente.domi, sizeof(domicilio), 1, arc);
        fread(&paciente, sizeof(datos), 1, arc);
    }

    printf("\nNúmero de pacientes por rango de edades:\n");
    for (i = 0; i < 11; i++)
        printf("\t<%d - %d>: \t%d pacientes\n", i * 10, ((i + 1) * 10) - 1, edad[i]);

    printf("\nEstudio de datos finalizada...\n");
}