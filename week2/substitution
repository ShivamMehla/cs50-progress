#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int n = strlen(key);

    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not have duplicate characters.\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");
    printf("cipher: ");

    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if(islower(text[i]))
        {
            int index = text[i] - 'a';
            printf("%c", tolower(key[index]));
        }
        else if (isupper(text[i]))
        {
            int index = text[i] - 'A';
            printf("%c", toupper(key[index]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
