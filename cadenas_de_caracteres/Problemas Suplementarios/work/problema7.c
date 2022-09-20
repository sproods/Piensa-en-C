#include <stdio.h>
#include <string.h>

// Cambio de formato de un número telefónico.

void main(void)
{
    char phone[30], newPhone_1[15], newPhone_2[15], newPhone_3[15], *phoneX;
    int i = 0, len;

    printf("Digite el número de teléfono de su preferencia: ");
    gets(phone);
    fflush(stdin);

    strcpy(phoneX, phone);
    len = strlen(phoneX);

    while (i < 3)
    {
        newPhone_1[i] = phoneX[i];
        i++;
    }

    while (i < 6)
    {
        newPhone_2[i - 3] = phoneX[i];
        i++;
    }

    while (i < len)
    {
        newPhone_3[i - 6] = phoneX[i];
        i++;
    }

    printf("\nNew Number Phone: (%s)-%s-%s\n", newPhone_1, newPhone_2, newPhone_3);
}