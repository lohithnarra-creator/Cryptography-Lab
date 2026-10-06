#include <stdio.h>

int main()
{
    char text[100];
    int k, i;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter key: ");
    scanf("%d", &k);

    for(i = 0; text[i] != '\0'; i++)
    {
        text[i] = (text[i] - 'A' + k) % 26 + 'A';
    }

    printf("Encrypted text: %s", text);

    return 0;
}
