#include <stdio.h>

// El programa obtiene en un archivo de texto los tiempos que he venido meditanto cada día.

void main(void)
{
    int i, j, days;
    float time;
    FILE *arxiv;

    printf("\nDigite la cantidad de días seguidos que ha meditado: ");
    scanf("%d", &days);

    if ((arxiv = fopen("meditacion.txt", "w+")) != NULL)
    {
        fprintf(arxiv, "%d", days);

        for (i = 0; i < days; i++)
        {
            printf("\nDigite cuánto tiempo ha meditado el día %d: ", i + 1);
            scanf("%f", &time);
            fprintf(arxiv, "\n%f", time);
        }

        fclose(arxiv);
    }
    else
        printf("\nNo se pudo abrir el archivo.\n");
}