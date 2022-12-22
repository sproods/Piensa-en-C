/* programa que registra los datos de los pacientes y sus respectivos datos personales. Necesario para la resolución del problema diez. */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
    char sexo[30];              // sexo del paciente
    int condicion;              // condición
    domicilio domi;             // domicilio
} datos;

void escribe(FILE *);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("pacientes.dat", "w");

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
    int sex;
    char op;
    datos paciente;

    printf("\nBienvenido al registro de datos de los pacientes.\n");
    do
    {
        printf("\n¿Desea digitar los datos de pacientes? (s/n): ");
        op = getchar();
        fflush(stdin);
    }
    while (op != 's' && op != 'n');

    while (op == 's')
    {
        printf("\nDigite la clave del paciente: ");
        scanf("%d", &paciente.clave);
        fflush(stdin);

        printf("\nDigite el nombre del paciente: ");
        gets(paciente.nombre);
        fflush(stdin);

        printf("\nDigite la edad del paciente: ");
        scanf("%d", &paciente.edad);
        fflush(stdin);

        do
        {
            printf("\nDigite el sexo del paciente: (1. femenino   2. marculino   3. prefiere no contestar): ");
            scanf("%d", &sex);
            fflush(stdin);
        }
        while (sex < 1 || sex > 3);
        switch (sex)
        {
            case 1: strcpy(paciente.sexo, "femenino");
                break;
            case 2: strcpy(paciente.sexo, "Masculino");
                break;
            case 3: strcpy(paciente.sexo, "Prefiere no especificar");
                break;
        }

        do
        {
            printf("\nDigite la condición del paciente (1 - 5) donde 1. es menos grave y 5. es muy grave: ");
            scanf("%d", &paciente.condicion);
            fflush(stdin);
        }
        while (paciente.condicion < 1 || paciente.condicion > 5);

        printf("\nDatos del domicilio del paciente");
        printf("\n\tCalle: ");
        gets(paciente.domi.calle);
        fflush(stdin);

        printf("\n\tNúmero: ");
        scanf("%d", &paciente.domi.numero);
        fflush(stdin);

        printf("\n\tColonia: ");
        gets(paciente.domi.colonia);
        fflush(stdin);

        printf("\n\tCódigo: ");
        gets(paciente.domi.codigo);
        fflush(stdin);
        
        printf("\n\tCiudad: ");
        gets(paciente.domi.ciudad);
        fflush(stdin);

        printf("\n\tTeléfono: ");
        gets(paciente.domi.tele);
        fflush(stdin);

        fwrite(&paciente, sizeof(datos), 1, arc);

        do
        {
            printf("\n¿Desea digitar los datos de otro  paciente? (s/n): ");
            op = getchar();
            fflush(stdin);
        }
        while (op != 's' && op != 'n');

        if (op == 's')
            continue;
        else if (op == 'n')
        {
            printf("\nDatos registrados exitosamente.\n");
            break;
        }
    }
}