#include <cs50.h>
#include <stdio.h>
void print_row(int brick, int n);
void print_row2(int brick);
int main(void)
{
    int n;
    do
    {
        n = get_int("Height : ");
    }
    while(n < 1 || n > 8);
    for(int i = 0; i < n; i++)
    {
        print_row(i + 1, n);
        printf("  ");
        print_row2(i + 1);
    }
}



void print_row(int brick, int n)
{
    for(int i = 0; i < n - brick; i++)
    {
        printf(" ");
    }
    for(int i = 0; i < brick; i++)
    {
        printf("#");
    }
}

void print_row2(int brick)
{
    for(int i = 0; i < brick; i++)
    {
        printf("#");
    }
    printf("\n");
}




