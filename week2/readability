#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int words = 1;
    int letters = 0;
    string text = get_string("Text: ");

    // Count letters
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    // Count words
    for (int i = 0; i < length - 1; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    // Count sentences
    int sentences = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate L and S
    float L = ((float) letters * 100) / words;
    float S = ((float) sentences * 100) / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Set conditions
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

