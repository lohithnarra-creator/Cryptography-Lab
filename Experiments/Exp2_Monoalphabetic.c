#include <stdio.h>

int main()
{
    char text[100], key[27];
    int i;

    printf("Enter plaintext: ");
    scanf("%s", text);

    printf("Enter 26-letter key: ");
    scanf("%s", key);

    for(i = 0; text[i] != '\0'; i++)
        text[i] = key[text[i] - 'A'];

    printf("Ciphertext: %s", text);

    return 0;
}
