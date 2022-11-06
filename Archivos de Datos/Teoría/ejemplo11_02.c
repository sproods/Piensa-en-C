// Programa que lee los registros escritos y/o modificacos en los ejemplos 11 y 11_01.

#include <stdio.h>

typedef struct
{
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void Leer(FILE *);

void main(void)
{
    FILE *arc;

    if ((arc = fopen("ad5.dat", "r")) != NULL)
        Leer(arc);
    else
        printf("\nNo se ha podido abrir el archivo.\n");

    fclose(arc);
}

void Leer(FILE *arxiv)
{
    empleado worker;
    int i;
    float sum;

    fread(&worker, sizeof(empleado), 1, arxiv);

    while(!feof(arxiv))
    {
        sum = 0;
        printf("\nEmpleado con clave %d: ", worker.clave);
        printf("\n\tDepartamento: %d", worker.departamento);
        printf("\n\tSalario: %.2f", worker.salario);
        for (i = 0; i < 12; i++)
            sum += worker.ventas[i];
        printf("\n\tVentas totales: %.2f", sum);

        fread(&worker, sizeof(empleado), 1, arxiv);
    }

    printf("\n\n¡Gracias por su consulta!\n");
}