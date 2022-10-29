// El programa modifica los datos del registro de pacientes almacenado en un archivo dat.

#include <stdio.h>

typedef struct          // Declaración de la estructura tipo paciente.
{
    int cod;
    char nom[20];
    char sex[20];
    char est[20];
    float pes;
    float tall;
} paciente;

void Modifica(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("pacientes.dat", "r+")) != NULL)
    {
        Modifica(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");
}

void Modifica(FILE *archivo)
{
    paciente paci;
    int ubi;

    printf("\nDetermine la ubicación del archivo: ");
    scanf("%d", &ubi);

    fseek(archivo, (ubi - 1) * sizeof(paciente), 0);

    fread(&paci, sizeof(paciente), 1, archivo);

    printf("\nDetermine el peso actual del paciente %s: ", paci.nom);
    scanf("%f", &paci.pes);

    fseek(archivo, (ubi - 1) * sizeof(paciente), 0);

    fwrite(&paci, sizeof(paciente), 1, archivo);
}