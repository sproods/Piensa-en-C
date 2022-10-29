// El programa lee los datos de los pacientes del archivo pacientes.dat

#include <stdio.h>

typedef struct          // Declaración de la estructura paciente.
{
    int cod;
    char nom[20];
    char sex[20];
    char est[20];
    float pes;
    float tall;
} paciente;

void Read(FILE *);      // Prototipo de función.

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("pacientes.dat", "r")) != NULL)
    {
        Read(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");
}

void Read(FILE *archivo)        // Función que lee y muestra en pantalla los datos del o los pacientes.
{
    paciente datos_paciente;

    fread(&datos_paciente, sizeof(paciente), 1, archivo);

    while (!feof(archivo))
    {
        printf("\nCódigo: %d", datos_paciente.cod);
        printf("\n\tNombre: \t%s", datos_paciente.nom);
        printf("\n\tSexo: \t\t%s", datos_paciente.sex);
        printf("\n\tEstado civil: \t%s", datos_paciente.est);
        printf("\n\tEstatura: \t%.2f", datos_paciente.tall);
        printf("\n\tPeso: \t\t%.2f\n", datos_paciente.pes);

        fread(&datos_paciente, sizeof(paciente), 1, archivo);
    }
}