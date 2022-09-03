#include <stdio.h>
#include <math.h>

#define MAX 12
/* Resolución del problema número ocho-- El problema de las ocho reinas. */

void Nreinas(int [], int, int);         /* Prototipos de funciones. */
int Comprueba(int [], int, int);

void main(void)
{
    int N, k = 0, reinas[MAX], i;

    printf("Digite el número de reinas que desea colocar en el tablero (máximo 12), qué será de dimensiones igual al número de las reinas: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++)
        reinas[i] = -1;

    Nreinas(reinas, N, k);              /* Llamada a la función Nreinas. */
}

void Nreinas(int reinas[], int n, int k)        /* Declaramos la función Nreinas en forma recursiva. */
{
    int i, cont = 0;

    if (k == n)
    {
        cont++;
        printf("Solución %d: ", cont);

        for (i = 0; i < n; i++)
            printf("%d, ", reinas[i]);
        printf("\n");
    }

    else
    {
        for (reinas[k] = 0; reinas[k] < n; reinas[k]++)
            if(Comprueba(reinas, n, k))
                Nreinas(reinas, n, k + 1);
    }
}

int Comprueba(int reinas[], int n, int k)               /* Declaración de la función Comprueba, la cual se encargará de verificar que las condiciones se cumplan dentro del tablero. */
{
    int i;

    for (i = 0; i < k ; i++)
    {
        if(reinas[i] == reinas[k] || (fabs(k - i) == fabs(reinas[k] - reinas[i])))
        {
            return 0;
        }
    }

    return 1;
}