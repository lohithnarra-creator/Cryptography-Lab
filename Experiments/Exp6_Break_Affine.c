#include <stdio.h>

int inverse(int a)
{
    int i;

    for(i = 0; i < 26; i++)
    {
        if((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

int main()
{
    char text[200];
    int a = 3, b = 15;
    int inv, i, p;

    printf("Most frequent B -> E\n");
    printf("Second frequent U -> T\n");

    printf("a = 3\n");
    printf("b = 15\n");

    printf("\nEnter ciphertext to decrypt: ");
    scanf("%s", text);

    inv = inverse(a);

    printf("Plaintext: ");

    for(i = 0; text[i] != '\0'; i++)
    {
        p = inv * ((text[i] - 'A' - b + 26) % 26);
        p = p % 26;

        printf("%c", p + 'A');
    }

    return 0;
}
