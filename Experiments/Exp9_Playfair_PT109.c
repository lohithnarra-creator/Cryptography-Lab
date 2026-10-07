#include <stdio.h>

char m[5][5] =
{
    {'R','O','Y','A','L'},
    {'N','E','W','Z','D'},
    {'V','B','C','F','G'},
    {'H','I','K','M','P'},
    {'Q','S','T','U','X'}
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
    char text[] =
    "KXJEYUREBEZWEHEWRYTUHEYFS"
    "KREHEGOYFIWTTTUOLKSYCAJPO"
    "BOTEIZONTXBYBNTGONEYCUZWR"
    "GDSONSXBOUYWRHEBAAHYUSEDQ";

    int i, r1, c1, r2, c2;

    printf("Plaintext:\n");

    for(i = 0; text[i] != '\0'; i += 2)
    {
        position(text[i], &r1, &c1);
        position(text[i + 1], &r2, &c2);

        if(r1 == r2)
        {
            printf("%c%c",
                   m[r1][(c1 + 4) % 5],
                   m[r2][(c2 + 4) % 5]);
        }
        else if(c1 == c2)
        {
            printf("%c%c",
                   m[(r1 + 4) % 5][c1],
                   m[(r2 + 4) % 5][c2]);
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
