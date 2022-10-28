// Programa que recoge datos de pacientes y los escribe en un archivo de formato binario y acceso directo.

#include <stdio.h>
#include <string.h>

typedef struct          // Declaración de la estructura paciente.
{
    int cod;            // Código del paciente.
    char nom[20];       // Nombre del paciente.
    char sex[15];       // Sexo del paciente.
    char est[15];       // Estado civil del paciente.
    float pes;          // Peso del paciente.
    float tall;         // Talla del paciente.
} paciente;

void Lectura(FILE *);           // Prototipo de función.

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("pacientes.dat", "w")) != NULL)
    {
        Lectura(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");
}

void Lectura(FILE *arc)
{
    int op, op_sex, op_est;
    paciente pac;

    printf("\n¿Desea digitar los datos del paciente? (SÍ- 1   NO- 0): ");
    scanf("%d", &op);

    while (op)
    {
        printf("\nDigite el código del paciente: ");
        scanf("%d", &pac.cod);
        fflush(stdin);

        printf("Digite el nombre del paciente: ");
        gets(pac.nom);
        fflush(stdin);

        printf("Elija la opción que corresponda al sexo del paciente %s:\n", pac.nom);
        printf("\t1. Hombre   2. Mujer   3. Otro   4. Prefiere no especificar\n");
        scanf("%d", &op_sex);
        switch(op_sex)
        {
            case 1: strcpy(pac.sex, "Hombre");
                break;
            case 2: strcpy(pac.sex, "Mujer");
                break;
            case 3: strcpy(pac.sex, "Otro");
                break;
            default: strcpy(pac.sex, "No especificado");
                break;
        }

        printf("\nElija la opción que corresponda con el estado civil del paciente %s:\n", pac.nom);
        printf("\t1. Soltero   2. Casado   3. Viudo   4. Divorciado   5. Prefiere no contestar\n");
        scanf("%d", &op_est);
        switch(op_est)
        {
            case 1: strcpy(pac.est, "Soltero");
                break;
            case 2: strcpy(pac.est, "Casado");
                break;
            case 3: strcpy(pac.est, "Viudo");
                break;
            case 4: strcpy(pac.est, "Divorciado");
                break;
            default: strcpy(pac.est, "No especificado");
                break;
        }

        printf("\nDigite la talla del paciente %s: \n", pac.nom);
        scanf("%f", &pac.tall);
        fflush(stdin);

        printf("\nDigite el peso del paciente %s: \n", pac.nom);
        scanf("%f", &pac.pes);
        fflush(stdin);

        fwrite( &pac, sizeof(paciente), 1, arc);

        printf("\n¿Desea digitar los datos de otro paciente? (SÍ- 1   NO- 0): ");
        scanf("%d", &op);
    }
}