/* programa que registra los datos de los pacientes y sus respectivos datos personales. Necesario para la resolución del problema diez. */

#include <stdio.h>

typedef struct
{
    char calle[50];             // calle
    int numero;                 // número
    char colonia[50];           // colonia
    char codigo[10];            // código postal
    char ciudad[30];            // ciudad
    char tele[15];              // teléfono
} domicilio;

typedef struct
{
    int clave;                  // clave del paciente
    char nombre[30];            // nombre y apellido del paciente
    int edad;                   // edad del paciente
    char sexo[10];              // sexo del paciente
    int condicion;              // condición
    domicilio domi;             // domicilio
} datos;

void escribe(FILE *);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("paciente.dat", "w");

    if (arxiv != NULL)
    {
        escribe(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void escribe(FILE *arc)
{
    int i;
    char op;
    datos paciente;

    printf("\nBienvenido al registro de datos de los pacientes.\n");
    printf("\n¿Desea digitar los datos de pacientes? (s/n): ");
    op = getchar();
}