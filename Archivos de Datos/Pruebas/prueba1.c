#include <stdio.h>

// Prueba de código del aprendizaje de escritura de caracteres y cadenas de caracteres.

void main(void)
{
    int op;
    char string[100];
    FILE *arx;

    arx = fopen("frases.txt", "a+");

    if (arx != NULL)
        fputs("\n", arx);

    if (arx != NULL)
    {
        printf("¿Desea digitar una frase? (Sí-1   No-0): ");
        scanf("%d", &op);

        while (op)
        {
            fflush(stdin);
            printf("\nDigite la frase: ");
            gets(string);
            fputs(string, arx);

            printf("\n¿Desea digitar otra frase? (Sí-1   No-0): ");
            scanf("%d", &op);

            if (op)
                fputs("\n", arx);
        }

        fclose(arx);
    }
    else
        printf("\nNo se pudo abrir el archivo.\n");
}