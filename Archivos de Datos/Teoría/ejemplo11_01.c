#include <stdio.h>

// Archivo que registra los salarios para que puedan ser considerados en el incremento del programa del ejemplo11.c

typedef struct
{
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void Escribe(FILE *);

void main(void)
{
    FILE *ar;

    if ((ar = fopen("ad5.dat", "w")) != NULL)
        Escribe(ar);
    else
        printf("\nEl archivo no se ha encontrado.\n");

    fclose(ar);
}

void Escribe(FILE *arxiv)
{
    empleado worker;
    int r, i;

    printf("\nDesea digitear información del empleado? (Sí-1   No-0)\n");
    scanf("%d", &r);
    fflush(stdin);

    while(r)
    {
        printf("\nDigite la clave del empleado: ");
        scanf("%d", &worker.clave);
        fflush(stdin);

        printf("\nDigite el departamento de empleado: ");
        scanf("%d", &worker.departamento);
        fflush(stdin);

        printf("\nDigite el salario del empleado: ");
        scanf("%f", &worker.salario);
        fflush(stdin);

        printf("\nDigite las ventas del empleado:\n");
        for (i = 0; i < 12; i++)
        {
            printf("\nVentas del mes %d: ", i + 1);
            scanf("%f", &worker.ventas[i]);
            fflush(stdin);
        }

        fwrite(&worker, sizeof(empleado), 1, arxiv);

        printf("\nDesea digitar la información de otro empleado: (Sí- 1   No- 0)\n");
        scanf("%d", &r);
        fflush(stdin);
    }
}