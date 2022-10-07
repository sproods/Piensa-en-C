#include <stdio.h>
#include <string.h>

/* Registro de empleados. */

typedef struct          // Estructura de tipo DOMICILIO.
{
    char calle_Numero[30];      // Calle y número.
    char colonia[20];           // Colonia.
    char cp[20];                // Código Postal.
    char ciu[20];               // Ciudad.
    char tel[15];               // Teléfono.
} DOMICILIO;

typedef struct          // Estructura de tipo EMPLEADO.
{
    int num;            // Número de empleado.
    char name[30];      // Nombre y apellido.
    char depa[30];      // Departamento.
    DOMICILIO domi[30];      // Domicilio.
    float sal;          // Salario.
} EMPLEADO;

void Lectura(EMPLEADO *, int);
void Ordena(EMPLEADO *, int);

void main(void)
{
    int TAM;
    EMPLEADO EMPLE[100];

    do
    {
        printf("Digite el número de empleados: ");
        scanf("%d", &TAM);
        fflush(stdin);
    }
    while (TAM > 100 || TAM < 1);

    Lectura(EMPLE, TAM);
    Ordena(EMPLE, TAM);
}

void Lectura(EMPLEADO A[], int T)
{
    int i;

    for (i = 0; i < T; i++)
    {
        printf("\nDigite, a continuación, los datos del empleado %d: ", i + 1);

        printf("\nNúmero de empleado: ");
        scanf("%d", &A[i].num);
        fflush(stdin);

        printf("Nombre y apellido: ");
        gets(A[i].name);
        fflush(stdin);

        printf("Departamento: ");
        gets(A[i].depa);
        fflush(stdin);

        printf("Domicilio: ");
        printf("\n\tCalle y número: ");
        gets(A[i].domi->calle_Numero);
        fflush(stdin);

        printf("\tColonia: ");
        
    }
}