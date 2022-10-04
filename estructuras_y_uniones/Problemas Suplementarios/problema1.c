#include <stdio.h>
#include <string.h>

/* Registro Bancario.
 * El programa realiza operaciones bancararias de Depósitos y Retiros. */

typedef struct          // Estructura de tipo domicilio.
{
    char cnum[30];      // Calle y número.
    char cp[10];        // Código Postal.
    char col[15];       // Colonia.
    char ciu[15];       // Ciudad.
    char tel[15];       // Teléfono.
} domicilio;

typedef struct          // Estructura de tipo CLIENTE.
{
    long cue;           // Número de cuenta.
    char nom[30];       // Nombre del cliente.
    domicilio dom;      // Domicilio.
    float sal;          // Saldo.
} CLIENTE;

void Lectura(CLIENTE *, int);       // Prototipos de funciones.
void Deposito(CLIENTE *, int);
void Retiro(CLIENTE *, int);
void Ordena(CLIENTE *, int);

void main(void)
{
    CLIENTE CLI[100];
    int TAM, ope;

    do
    {
        printf("Digite el número de clientes: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);

    fflush(stdin);

    Lectura(CLI, TAM);
    Ordena(CLI, TAM);

    printf("Digite la operación que desea efectuar: \n\tDepósito - 1\tRetiro - 2\tSalir - 0: ");
    scanf("%d", &ope);
    fflush(stdin);

    while (ope)
    {
        switch (ope)
        {
            case 1: Deposito(CLI, TAM);
                break;
            case 2: Retiro(CLI, TAM);
                break;
        }

        printf("Digite la operación que desea efectura: \n\tDepósito - 1\tRetiro - 2\tSalir - 0: ");
        scanf("%d", &ope);
        fflush(stdin);
    }

    printf("\nFIN DE LAS OPERACIONES\t¡QUE TENGA UN BUEN DÍA!\n");
}

void Lectura(CLIENTE A[], int T)        // Función que lee los datos de los clientes.
{
    int i;

    for (i = 0; i < T; i++)
    {
        printf("\n\t\tDatos del usuario %d", i + 1);

        printf("\nNúmero de cuenta: ");
        scanf("%ld", &A[i].cue);
        fflush(stdin);

        printf("Nombre del cliente: ");
        gets(A[i].nom);
        fflush(stdin);

        printf("Domicilio:\n");
        printf("\tCalle: ");
        gets(A[i].dom.cnum);
        fflush(stdin);

        printf("\tCódigo Postal: ");
        gets(A[i].dom.cp);
        fflush(stdin);

        printf("\tColonia: ");
        gets(A[i].dom.col);
        fflush(stdin);

        printf("\tCiudad: ");
        gets(A[i].dom.ciu);
        fflush(stdin);

        printf("\tTeléfono: ");
        gets(A[i].dom.tel);
        fflush(stdin);

        printf("Saldo: ");
        scanf("%f", &A[i].sal);
        fflush(stdin);
    }
}

void Ordena(CLIENTE A[], int T)         // Función que ordena el arreglo de clientes en función al orden de sus números de cuentas.
{
    int i, j, x;
    long min;
    CLIENTE aux;

    for (i = 0; i < T - 1; i++)
    {
        min = A[i].cue;
        x = i;

        for (j = i + 1; j < T; j++)
        {
            if (A[j].cue < min)
            {
                min = A[j].cue;
                x = j;
            }
        }

        aux = A[i];
        A[i] = A[x];
        A[x] = aux;
    }
}

void Deposito(CLIENTE A[], int T)         // Función que efectúa la operación de depósito, sumando el monto que se indica.
{
    int i;
    long cuenta;
    float dep;

    printf("Digite su número de cuenta: ");
    scanf("%ld", &cuenta);

    while (cuenta)
    {
        i = 0;
        
        while ((i < T) && (cuenta > A[i].cue))
            i++;

        if ((i == T) || (cuenta < A[i].cue))
            printf("\nEl número de cuenta digitado no es correcto");

        if (cuenta == A[i].cue)
        {
            printf("\n\tDigite, por favor, el monto que va a depositar: ");
            scanf("%f", &dep);

            A[i].sal += dep;
        }

        printf("Digite otro número de cuenta -0 para salir- : ");
        scanf("%d", &cuenta);
    }

    printf("\nEl nuevo saldo de la cuenta %ld es %.2f", A[i].cue, A[i].sal);
}

void Retiro(CLIENTE A[], int T)         // Función qe efectúa la operación de retiro de una cantidad de una cuenta bancaria.
{
    int i;
    long cuenta;
    float ret;
    char res;

    printf("\nDigite el número de cuenta: ");
    scanf("%ld", &cuenta);

    while (cuenta)
    {
        i = 0;

        while ((i < T) && (cuenta > A[i].cue))
            i++;

        if ((i == T) || (cuenta < A[i].cue))
            printf("\nEl número de cuenta digita no es correcto.");

        if (cuenta == A[i].cue)
        {
            printf("\n\tDigite el saldo que va a retirar: ");
            scanf("%f", &ret);

            while (ret)
            {
                if (ret > A[i].sal)
                {
                    printf("\nEl saldo es insuficiente, solo hay en caja %f soles.\n¿Desea retirarlo todo? -S/N- : ");
                    res = getchar();
                    fflush(stdin);

                    if (res == 'S' || res == 's')
                        A[i].sal = 0;           // Actualización del saldo.
                }
                else
                {
                    A[i].sal -= ret;
                }

                printf("\n\tEl nuevo saldo para la cuenta %ld es de %.2f", A[i].cue, A[i].sal);

                printf("\nDigite otro monto que va a retirar -0 para salir- : ");
                scanf("%f", &ret);
            }
        }

        printf("Digite otro número de cuenta del que va a efectuar un retiro -0 para salir- : ");
        scanf("%ld", &cuenta);
    }
}