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
void Alta(EMPLEADO *, int *);
void Baja(EMPLEADO *, int *);
void Datos(EMPLEADO *, int);

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
        gets(A[i].domi->colonia);
        fflush(stdin);

        printf("\tCódigo Postal: ");
        gets(A[i].domi->cp);
        fflush(stdin);

        printf("\tCiudad: ");
        gets(A[i].domi->ciu);
        fflush(stdin);

        printf("\tTeléfono: ");
        gets(A[i].domi->tel);
        fflush(stdin);

        printf("Salario: ");
        scanf("%f", &A[i].sal);
        fflush(stdin);
    }
}

void Ordenar(EMPLEADO A[], int T)
{
    int i, j, min, x;
    EMPLEADO aux;

    for (i = 0; i < T - 1; i++)
    {
        min = A[i].num;
        x = i;

        for (j = i + 1; j < T; j++)
        {
            if (A[j].num < min)
            {
                min = A[j].num;
                x = j;
            }
        }

        aux = A[i];
        A[i] = A[x];
        A[x] = aux;
    }
}

void Alta(EMPLEADO A[], int *T)          // Función que da de alta a un empleado, incorporando todos los datos correspondientes.
{
    int i, j, numero;

    printf("\nDigite el número del empleado que desea incorporar: ");
    scanf("%d", &numero);
    fflush(stdin);

    while (*T <= 100 && numero)
    {
        i = 0;

        while ((i < *T) && (A[i].num < numero))
            i++;

        if (i == *T)
        {
            A[i].num = numero;

            printf("\nNombre: ");
            gets(A[i].name);
            fflush(stdin);

            printf("\nDepartamento: ");
            gets(A[i].depa);
            fflush(stdin);

            printf("\nDomicilio: ");
            printf("\n\tCalle y número: ");
            gets(A[i].domi->calle_Numero);
            fflush(stdin);

            printf("\tColonia: ");
            gets(A[i].domi->colonia);
            fflush(stdin);

            printf("\tCódigo Postal: ");
            gets(A[i].domi->cp);
            fflush(stdin);

            printf("\tCiudad: ");
            gets(A[i].domi->ciu);
            fflush(stdin);

            printf("\tTeléfono: ");
            gets(A[i].domi->tel);
            fflush(stdin);

            printf("Salario: ");
            scanf("%f", &A[i].sal);
            fflush(stdin);
        }
        else
            if (A[i].num == numero)
                printf("\nEl empleado ya se encuentra registrado en la planilla.");
            else
            {
                for (j = *T; j > i; j--)
                    A[j] = A[j - 1];

                A[i].num = numero;

                printf("\nNombre: ");
                gets(A[i].name);
                fflush(stdin);

                printf("\nDepartamento: ");
                gets(A[i].depa);
                fflush(stdin);

                printf("\nDomicilio: ");
                printf("\n\tCalle y número: ");
                gets(A[i].domi->calle_Numero);
                fflush(stdin);

                printf("\tColonia: ");
                gets(A[i].domi->colonia);
                fflush(stdin);

                printf("\tCódigo Postal: ");
                gets(A[i].domi->cp);
                fflush(stdin);

                printf("\tCiudad: ");
                gets(A[i].domi->ciu);
                fflush(stdin);

                printf("\tTeléfono: ");
                gets(A[i].domi->tel);
                fflush(stdin);

                printf("Salario: ");
                scanf("%f", &A[i].sal);
                fflush(stdin);

                *T = *T + 1;
            }
        
        printf("\nDigite otro número de empleado -0 para salir- : ");
        scanf("%d", &numero);
        fflush(stdin);
    }

    if (*T == 100)
        printf("\nEl registro está completo.");
}