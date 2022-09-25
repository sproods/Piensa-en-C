#include <stdio.h>

void main(void)
{
    char cad[10][50];
    int i;

    for (i = 0; i < 2; i++)
    {
        printf("Digite una palabra: ");
        gets(cad[i]);
    }

    for (i = 0; i < 2; i++)
        printf("%s ", cad[i]);

    printf("\b...\n");
}