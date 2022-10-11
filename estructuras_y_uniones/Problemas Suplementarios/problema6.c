#include <stdio.h>
#include <string.h>

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
}

/* Declaración de la función Lectura. */
void Lectura(Alumno A[], int T)
{
    int i, elec;

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
            case 3: strcpy(A[i].level.niv, "¨Preparatoria");
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
        for (i = 0; i < 7; i++)
        {
            printf("\n\t\tMateria %d: ", i + 1);
            gets(A[i].level.cal->mate);
            fflush(stdin);

            printf("\t\tPromedio de la materia %s: ", A[i].level.cal->mate);
            scanf("%f", &A[i].level.cal->prom);
            fflush(stdin);
        }
    }
}