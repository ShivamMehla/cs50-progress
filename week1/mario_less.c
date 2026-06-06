#include <stdio.h>
#include <cs50.h>
void print_row(int space, int brick);
int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n < 0 || n > 8);

    for(int i = 0; i < n; i++)
    {
        print_row(n - (i + 1), i + 1);
    }

}

void print_row(int space, int brick)
{
    for(int i = 0; i < space; i++)
    {
        printf(" ");
    }
    for(int i = 0; i < brick; i++)
    {
        printf("#");
    }
    printf("  ");
    for(int i = 0; i < brick; i++)
    {
        printf("#");
    }
    printf("\n");
}
