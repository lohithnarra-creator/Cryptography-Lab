#include <stdio.h>

int main()
{
    char text[1000];
    int count[256] = {0};
    int i;

    printf("Enter ciphertext:\n");
    scanf(" %[^\n]", text);

    for(i = 0; text[i] != '\0'; i++)
        count[(unsigned char)text[i]]++;

    printf("\nCharacter Frequency:\n");

    for(i = 0; i < 256; i++)
    {
        if(count[i] > 0)
            printf("%c = %d\n", i, count[i]);
    }

    return 0;
}
