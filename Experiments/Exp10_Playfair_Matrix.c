#include <stdio.h>

char m[5][5] =
{
    {'M','F','H','I','K'},
    {'U','N','O','P','Q'},
    {'Z','V','W','X','Y'},
    {'E','L','A','R','G'},
    {'D','S','T','B','C'}
};

void position(char ch, int *r, int *c)
{
    int i, j;

    if(ch == 'J')
        ch = 'I';

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(m[i][j] == ch)
            {
                *r = i;
                *c = j;
                return;
            }
        }
    }
}

int main()
{
    char text[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE";
    char p[100];
    int n = 0;
    int i, r1, c1, r2, c2;

    for(i = 0; text[i] != '\0'; i++)
    {
        if(n > 0 && p[n - 1] == text[i])
            p[n++] = 'X';

        p[n++] = text[i];
    }

    if(n % 2 != 0)
        p[n++] = 'X';

    printf("Ciphertext: ");

    for(i = 0; i < n; i += 2)
    {
        position(p[i], &r1, &c1);
        position(p[i + 1], &r2, &c2);

        if(r1 == r2)
        {
            printf("%c%c",
                   m[r1][(c1 + 1) % 5],
                   m[r2][(c2 + 1) % 5]);
        }
        else if(c1 == c2)
        {
            printf("%c%c",
                   m[(r1 + 1) % 5][c1],
                   m[(r2 + 1) % 5][c2]);
        }
        else
        {
            printf("%c%c",
                   m[r1][c2],
                   m[r2][c1]);
        }
    }

    return 0;
}
