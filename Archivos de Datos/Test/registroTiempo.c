// El programa realiza la escritura de los tiempos de alguna actividad espicificada por el usuario durante un tiempo también especificado por el usuario.

#include <stdio.h>
#include <string.h>

#define MAXTIME 50

void main(void)
{
    int i, j, N, res1, nTime;
    float time;
    char tiempo[7], act[20];
    FILE *arxiv;

    arxiv = fopen("habitos.txt", "w");

    if (arxiv != NULL)
    {
        printf("\n¿Los datos se registrarán en días, meses o años? \n\t1. días   2. meses   3. años: ");
        scanf("%d", &res1);
        fflush(stdin);

        switch(res1)
        {
            case 1: strcpy(tiempo, "días");
                    fputs(tiempo, arxiv);
                    break;
            case 2: strcpy(tiempo, "meses");
                    fputs(tiempo, arxiv);
                    break;
            case 3: strcpy(tiempo, "años");
                    fputs(tiempo, arxiv);
                    break;
        }

        fputc('\n', arxiv);
        printf("\n¿Por cuántos %s será el registro?: ", tiempo);
        scanf("%d", &nTime);
        fflush(stdin);
        fprintf(arxiv, "%d", nTime);

        fputc('\n', arxiv);

        printf("\nDigite el número de actividades que va a registrar: ");
        scanf("%d", &N);
        fprintf(arxiv, "%d", N);
        fflush(stdin);

        fputc('\n', arxiv);
        for (i = 0; i < N; i++)
        {
            printf("\nDigite la actividad número %d: ", i + 1);
            gets(act);
            fflush(stdin);
            fputs(act, arxiv);
            fputc('\n', arxiv);

            for (j = 0; j < nTime; j++)
            {
                printf("\n¿Durante cuánto tiempo hizo %s el %s %d: ", act, tiempo, j + 1);
                scanf("%f", &time);
                fflush(stdin);
                fprintf(arxiv, "%.2f", time);
                fputc('\n', arxiv);
            }
        }

        fclose(arxiv);
    }
    else
        printf("\nEl archivo no se ha podido abrir satisfactoriamente.\n");
}
