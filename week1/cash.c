#include <cs50.h>
#include <stdio.h>
int main(void)

{
   int change_owed;
   do
   {
      change_owed = get_int("change owed : ");
   }
   while (change_owed < 0);

   if (change_owed == 0)
   {
      printf("0\n");
      return 0;
   }

    int quarter = change_owed / 25;
    printf("%i\n", quarter);
    change_owed %= 25;

    int dimes = change_owed / 10;
    printf("%i\n", dimes);
    change_owed %= 10;

    int nickels = change_owed / 5;
    printf("%i\n", nickels);
    change_owed %= 5;

    int pennies = change_owed;
    printf("%i\n", pennies);

    printf("total : %i\n", quarter + dimes + nickels + pennies);

}

