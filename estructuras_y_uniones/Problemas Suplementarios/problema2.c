#include <stdio.h>
#include <string.h>

/* Tabla de posiciones. */

typedef struct          // Estructura tipo EQUIPO.
{
    char team_Name[20];     // Nombre del equipo.
    int played_Games;       // Partidos jugados.
    int won_Games;          // Partidos ganados.
    int tie_Games;          // Partidos empatados.
    int lost_Games;         // Partidos perdidos.
    int for_Goals;          // Goles a favor.
    int against_Goals;      // Goles en cotra.
    int difference_Goals;   // Diferencia de goles.
    int points;             // Puntos.
} EQUIPO;

void Lectura(EQUIPO *, int);
void Ordena(EQUIPO *, int);
void Tabla(EQUIPO *, int);

void main(void)
{
    EQUIPO FUTBOL[20];
    int TAM;

    do
    {
        printf("Digite el número de equipos: ");
        scanf("%d", &TAM);
        fflush(stdin);
    }
    while (TAM > 20 || TAM < 2);

    Lectura(FUTBOL, TAM);
    Tabla(FUTBOL, TAM);
}

void Lectura(EQUIPO A[], int T)         // Función que registra los datos de cada equipo.
{
    int i;

    for (i = 0; i < T; i++)
    {
        printf("\n\tDatos del equipo %d\n", i + 1);

        printf("Nombre del equipo: ");
        gets(A[i].team_Name);
        fflush(stdin);

        A[i].played_Games = 0;
        A[i].won_Games = 0;
        A[i].tie_Games = 0;
        A[i].lost_Games = 0;
        A[i].for_Goals = 0;
        A[i].against_Goals = 0;
        A[i].difference_Goals = 0;
        A[i].points = 0;
    }
}

void Tabla(EQUIPO A[], int T)           // Función que muestra en pantalla las posiciones de los equipos después de cada temporada.
{
    int i;

    printf("\n\tTabla de Posiciones\n");
    printf("\nEquipo\t\tPuntaje\n\n");

    for (i = 0; i < T; i++)
    {
        printf("%s\t\t%3d\n", A[i].team_Name, A[i].points);
    }
}

void Ordena(EQUIPO A[], int T)            // Función que ordena la Tabla de posiciones en función de los puntos de cada equipo.
{
    int i, j, x, max;
    EQUIPO aux;

    for (i = 0; i < T - 1; i++)
    {
        max = A[i].points;
        x = i;

        for (j = i + 1; j < T; j++)
        {
            if (A[j].points > max)
            {
                max = A[j].points;
                x = j;
            }
        }

        aux = A[i];
        A[i] = A[x];
        A[x] = aux;
    }
}