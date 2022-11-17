#include <stdio.h>

// El programa escribe los datos necesarios para ser utilizados en la resolución del problema ocho en el archivo arc9.dat.

#define NUM 50
#define NOTAS 3

void escribe(FILE *);
void escribeEnArchivo(FILE *, int [], float [][NOTAS], int);
void ordena(int [], float [][NOTAS], int);

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("arc9.dat", "w");

    if (arxiv != NULL)
    {
        escribe(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nNo se puede abrir el archivo.\n");
}

void escribe(FILE *arc)
{
    int i, j, n, mat[NUM];
    float nota[NUM][NOTAS];

    printf("\nDigite el número de alumnos de los que obtendrá sus matrículs y sus notas: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nDigite la matrícula del alumno %d: ", i + 1);
        scanf("%d", &mat[i]);

        for (j = 0; j < NOTAS; j++)
        {
            printf("\nDigite la nota %d: ", j + 1);
            scanf("%f", &nota[i][j]);
        }
    }

    ordena(mat, nota, n);
    escribeEnArchivo(arc, mat, nota, n);
}

void escribeEnArchivo(FILE *arc, int A[NUM], float B[NUM][NOTAS], int N)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        fprintf(arc, "%d", A[i]);

        for (j = 0; j < NOTAS; j++)
            fprintf(arc, "\t%.2f", B[i][j]);

        if (i < N - 1)
            fputs("\n", arc);
    }
}

void ordena(int A[NUM], float B[NUM][NOTAS], int N)
{
    int i, j, min, index, aux;
    float auxf;

    for (i = 0; i < N - 1; i++)
    {
        min = A[i];
        index = i;

        for (j = i + 1; j < N; j++)
        {
            if (min > A[j])
            {
                min = A[j];
                index = j;
            }
        }

        aux = A[i];
        A[i] = A[index];
        A[index] = aux;

        for (j = 0; j < NOTAS; j++)
        {
            auxf = B[i][j];
            B[i][j] = B[index][j];
            B[index][j] = auxf;
        }
    }
}