#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int digit = 0;
    int sum = 0;
    long position = 1;
    long length = 0;
    long n = get_long("NUMBER: ");

    // SEPERATING DOUBLED DIGITS AND NORMAL DIGITS

    for (long i = n; i > 0; i /= 10)
    {
        digit = i % 10;

        // FROM SECOND TO LAST DIGIT
        if (position % 2 == 0)
        {
            int doubled = digit * 2;
            // LETS SAY DOUBLED IS 12, SO SUM = SUM + 1 + 2
            sum = sum + (doubled / 10) + (doubled % 10);
        }

        // FROM LAST DIGIT, NON DOUBLED DIGITS
        else
        {
            sum = sum + digit;
        }
        position++;
    }

    // THE SUM SHOULD HAVE 0 AT THE END (HENCE DIVISIBLE BY 10 GIVING NO REMAINDER)
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;           // EXIT HERE IF LUHN FAILS
    }

    //IF REACHED HERE, SUM % 10 == 0 (LUHN PASSED)

    // MAKE FIRST DIGIT

    long first_digit = n;
    while (first_digit >= 10)
    {
        first_digit /= 10;
    }

    // MAKE FIRST TWO DIGITS

    long first_two_digit = n;
    while (first_two_digit >= 100)
    {
        first_two_digit /= 10;
    }

    // LENGTH

     for (long i = n; i > 0; i /= 10)
    {
        length++;
    }

    // VISA CONDITIONS
    if (first_digit == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }

    // AMEX CONDITIONS
    else if ((first_two_digit == 34 || first_two_digit == 37) && length == 15)
    {
        printf("AMEX\n");
    }

    // MASTERCARD CONDITIONS
    else if ((first_two_digit >= 51 && first_two_digit <= 55) && length == 16)
    {
        printf("MASTERCARD\n");
    }
    // IF SUM % 10 == 0, BUT NO CONDITION MATCHES:
    else
    {
        printf("INVALID\n");
    }
}

