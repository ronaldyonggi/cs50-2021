#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for input change. Keeps prompting as long as input is less than 0
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    // Convert change to integer by multiplying 100 and round it
    int rounded = round(change * 100);
    int coins = 0; // initiate total number of coins required so far

    // while loops keeps going as long as remaining change is greater than 0
    while (rounded > 0)
    {
        // if equal or greater than 25, decrement by 25
        if (rounded >= 25)
        {
            rounded -= 25;
        }
        // otherwise if equal or greater than 10, decrement by 10
        else if (rounded >= 10)
        {
            rounded -= 10;
        }
        // otherwise if equal or greater than 5, decrement by 5
        else if (rounded >= 5)
        {
            rounded -= 5;
        }
        // otherwise decrement by 1
        else if (rounded >= 1)
        {
            rounded -= 1;
        }

        // Add coin for each cycle of while loop
        coins++;
    }
    printf("%i\n", coins);
}