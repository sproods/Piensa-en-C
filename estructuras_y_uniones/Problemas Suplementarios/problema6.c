#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Escuela.
 * El programa realiza un detallado informe sobre los datos de los alumnos de una escuela en la Ciudad de México. */

#define MAX 1000



typedef struct          // Estructura de tipo Calificaciones.
{
    char mate[20];              // Materia.
    float prom;                 // Promedio.
} Calificaciones;

typedef struct          // Estructura de tipo Domicilio.
{
    char call_num[40];          // Calle y número.
    int cp;                     // Código Postal.
    char col[20];               // Colonia.
    char ciu[30];               // Ciudad.
    char tel[20];               // Teléfono.
} Domicilio;

typedef struct          // Estructura de tipo Nivel.
{
    char niv[20];               // Nivel.
    int gra;                    // Grado.
    char sal[20];               // Salón.
    Calificaciones cal[7];      // Calificaciones.
} Nivel;

typedef struct          // Estructura de tipo Alumno.
{
    int matri;                  // Matrícula.
    char name[50];              // Nombre y apellido.
    Domicilio dom;              // Domicilio.
    Nivel level;                // Nivel de estudios.
} Alumno;



/* Prototipos de funciones. */
void Lectura(Alumno *, int);
void Ordena(Alumno *, int);
void Lista(Alumno *, int);
void Promedio_alumno(Alumno *, int);
void Lista_promedios(Alumno *, int);



/* Programa principal. */
void main(void)
{
    Alumno ESCUELA[MAX];
    int TAM;

    do
    {
        printf("\nDigite el número de alumnos en la escuela: ");
        scanf("%d", &TAM);
        fflush(stdin);
    }
    while (TAM > MAX || TAM < 1);

    Lectura(ESCUELA, TAM);
    Ordena(ESCUELA, TAM);
    Lista(ESCUELA, TAM);
    Promedio_alumno(ESCUELA, TAM);
    Lista_promedios(ESCUELA, TAM);
}

/* Declaración de la función Lectura. */
void Lectura(Alumno A[], int T)
{
    int i, j, elec;

    for (i = 0; i < T; i++)
    {
        printf("\nDatos del alumno %d\n", i + 1);

        printf("\nMatrícula del alumno: ");
        scanf("%d", &A[i].matri);
        fflush(stdin);

        printf("Nombre y apellido: ");
        gets(A[i].name);
        fflush(stdin);

        // Domicilio.
        printf("Domicilio del alumno:");
        printf("\n\tCalle y número: ");
        gets(A[i].dom.call_num);
        fflush(stdin);

        printf("\tCódigo Postal: ");
        scanf("%d", &A[i].dom.cp);
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

        // Nivel de Estudios.
        printf("Nivel de estudios:");
        do
        {
            printf("\n\tNivel de estudios del alumno: 1- Primaria   2- Secundaria   3- Preparatoria: ");
            scanf("%d", &elec);
            fflush(stdin);
        }
        while (elec > 3 || elec < 1);

        switch (elec)
        {
            case 1: strcpy(A[i].level.niv, "Primaria");
                break;
            case 2: strcpy(A[i].level.niv, "Secundaria");
                break;
            case 3: strcpy(A[i].level.niv, "Preparatoria");
                break;
        }

        printf("\tGrado: ");
        scanf("%d", &A[i].level.gra);
        fflush(stdin);

        printf("\tSalón: ");
        gets(A[i].level.sal);
        fflush(stdin);

        // Calificaciones.
        printf("\tCalificaciones:");
        for (j = 0; j < 7; j++)
        {
            printf("\n\t\tMateria %d: ", j + 1);
            gets(A[i].level.cal[j].mate);
            fflush(stdin);

            printf("\t\tPromedio de la materia %s: ", A[i].level.cal[j].mate);
            scanf("%f", &A[i].level.cal[j].prom);
            fflush(stdin);
        }
    }
}

/* Declaración de la función Ordena. Función que ordena de manera craciete en función de la matrícula de los alumnos. */
void Ordena(Alumno A[], int T)
{
    int i, j, min, x;
    Alumno aux;

    for (i = 0; i < T - 1; i++)
    {
        min = A[i].matri;
        x = i;

        for (j = i + 1; j < T; j++)
        {
            if (A[j].matri < min)
            {
                min = A[j].matri;
                x = j;
            }
        }

        aux = A[i];
        A[i] = A[x];
        A[x] = aux;
    }
}

/* Declaración de la función Lista. Función que muestra en pantalla los la matrícula y el nombre de cada alumno. */
void Lista(Alumno A[], int T)
{
    int i;

    printf("\nDatos de los alumnos:\n");
    for (i = 0; i < T; i++)
    {
        printf("\n\tMatrícula: %d\n\tNombre: %3s\n", A[i].matri, A[i].name);
    }
}

/* Declaración de la función Promedio_alumno. Función que calcula el promedio general del alumno de matrícula digitada. */
void Promedio_alumno(Alumno A[], int T)
{
    int i, j, mat;
    float sum, prom;

    printf("\nDigite el número de la matrícula del alumno: ");
    scanf("%d", &mat);
    fflush(stdin);

    while (mat)
    {
        i = 0;

        while (i < T && mat > A[i].matri)
            i++;

        if (i == T || A[i].matri > mat)
            printf("\nLa matrícula digitada es incorrecta.\n");
        
        if (A[i].matri == mat)
        {
            sum = 0.0;

            for (j = 0; j < 7; j++)
                sum += A[i].level.cal[j].prom;

            prom = sum / 7;

            printf("\nEl promedio general del alumno %s es %.2f\n", A[i].name, prom);
        }

        printf("\nDigite otro número de matrícula -0 para salir- : ");
        scanf("%d", &mat);
        fflush(stdin);
    }
}

/* Declaración de la función Lista_promedios. Función que muestra en pantalla la matrícula, el nombre y el promedio general de todos
 * los alumnos coincidan con el nivel de estudios, el grado y el salón digitados por el usuario. */
void Lista_promedios(Alumno A[], int T)
{
    int i, j, grado, salon, elec, dsalon;
    float promg, sumP;
    char nivel[15];

    do
    {
        printf("\nEscoja el nivel de estudios:\n\t1- Primaria   2- Secundaria   3- Preparatoria\n");
        scanf("%d", &elec);
        fflush(stdin);
    }
    while (elec < 1 || elec > 3);
    switch (elec)
    {
        case 1: strcpy(nivel, "Primaria");
            break;
        case 2: strcpy(nivel, "Secundaria");
            break;
        case 3: strcpy(nivel, "Preparatoria");
            break;
    }
    printf("Digite el grado: ");
    scanf("%d", &grado);
    fflush(stdin);
    printf("Digite el salón: ");
    scanf("%d", &salon);
    fflush(stdin);

    while (elec)
    {        
        for (i = 0; i < T; i++)
        {
            // Conversión del valor del salón en enteros.
            dsalon = atoi(A[i].level.sal);
            
            if (strcmp(A[i].level.niv, nivel) == 0)
                if (A[i].level.gra == grado)
                    if (dsalon == salon)
                    {
                        sumP = 0.0;
                        promg = 0.0;

                        // Cálculo del promedio general (promg)
                        for (j = 0; j < 7; j++)
                            sumP += A[i].level.cal[j].prom;
                        promg = sumP / 7;

                        printf("\n\tMatrícula: %d\n\tNombre: %s\n\tPromedio General: %.2f\n", A[i].matri, A[i].name, promg);
                    }
        }

        do
        {
            printf("\nEscoja un nivel de estudios: \n\t1- Primaria   2- Secundaria   3- Preparatoria  0- Salir\n");
            scanf("%d", &elec);
            fflush(stdin);
        }
        while (elec < 0 || elec > 3);

        if (elec != 0)
        {
            switch (elec)
            {
                case 1: strcpy(nivel, "Primaria");
                    break;
                case 2: strcpy(nivel, "Secundaria");
                    break;
                case 3: strcpy(nivel, "Preparatoria");
                    break;
            }
            printf("Digite el grado: ");
            scanf("%d", &grado);
            fflush(stdin);
            printf("Digite el salón: ");
            scanf("%d", &salon);
            fflush(stdin);
        }
    }
}