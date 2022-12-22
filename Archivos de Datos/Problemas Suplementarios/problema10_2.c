/* Programa que lee el archivo que contiene los datos de los pacientes para la resolución del problema diez. */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char calle[50];
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

void lee(FILE *);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("pacientes.dat", "r");

    if (arxiv != NULL)
    {
        lee(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void lee(FILE *arc)
{
    int i = 0;
    datos paciente;

    fread(&paciente, sizeof(datos), 1, arc);

    while (!feof(arc))
    {
        i++;
        printf("\nDatos del paciente %d:\n", i);
        printf("\nClave: \t%d", paciente.clave);
        printf("\nNombre: \t%s", paciente.nombre);
        printf("\nEdad: \t%d", paciente.edad);
        printf("\nSexo: \t%s", paciente.sexo);
        printf("\ncondición: \t%d", paciente.condicion);
        printf("\nDomicilio:");
        printf("\n\tCalle: %s", paciente.domi.calle);
        printf("\n\tNúmero: %d", paciente.domi.numero);
        printf("\n\tColonia: %s", paciente.domi.colonia);
        printf("\n\tCódigo: %s", paciente.domi.codigo);
        printf("\n\tCiudad: %s", paciente.domi.ciudad);
        printf("\n\tTeléfono: %s", paciente.domi.tele);

        fread(&paciente, sizeof(datos), 1, arc);
    }
}