#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    printf("Key: %i\n", key);

    string text = get_string("plaintext:  ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];
        if (islower(c))
        {
            c = ((c - 'a') + key) % 26 + 'a';
        }
        else if (isupper(c))
        {
            c = ((c - 'A') + key) % 26 + 'A';
        }

        printf("%c", c);
    }
    printf("\n");
    return 0;
}

