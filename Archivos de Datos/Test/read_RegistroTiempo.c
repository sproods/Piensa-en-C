// El programa realiza la lectura de los datos del archivo habitos.txt y los imprime en pantalla, además realiza el cálculo del promedio de los tiempos.

#include <stdio.h>
#include <string.h>

#define N 30

void main(void)
{
    int i, j, n_Time, n_Act;
    char char_Tiempo[15], activity[N][N], actividad[N];
    float tiempo[N][N];
    FILE *arxiv;

    arxiv = fopen("habitos.txt", "r");

    if (arxiv != NULL)
    {
        putchar('\n');

        fgets(char_Tiempo, 15, arxiv);              // Obtenemos el tiempo que hemos puesto como control.

        puts(char_Tiempo);                          // Escribimos en pantalla la cadena de caracteres que obtenemos.

        fscanf(arxiv, "%d", &n_Time);               // Obtenemos el número del tiempo en que se van a registrar las actividades.
        fflush(stdin);

        printf("%d", n_Time);                       // Imprimimos en pantalla el valor de n_Time.

        fscanf(arxiv, "%d", &n_Act);                // Obtenemos el número de actividades.
        fflush(stdin);

        printf("\n%d", n_Act);                      // Imprimimos en pantalla el valor de n_Act.

        for (i = 0; i < n_Act; i++)
        {
            fgets(actividad, N, arxiv);          // Obtenemos y almacenamos el nombre de cada una de las actividades.
            strcpy(activity[i], actividad);
            fflush(stdin);
            // puts(activity[i]);                      // Imprimimos en pantalla el nombre de las actividades.

            for (j = 0; j < n_Time; j++)
            {
                fscanf(arxiv, "%f", &tiempo[i][j]);    // Obtenemos el valor de cada uno de los tiempos escritos en el archivo.
                fflush(stdin);
                // printf("\n%.2f", tiempo[i][j]);        // Escribimos en pantalla el valor de cada uno de los tiempos.
            }
        }

        for (i = 0; i < n_Act; i++)
        {
            printf("\n%s", activity[i]);

            for (j = 0; j < n_Time; j++)
                printf("\n%.2f", tiempo[i][j]);
        }

        fclose(arxiv);
    }
    else
        printf("\nEl archivo no se ha podido abrir.\n");
}
