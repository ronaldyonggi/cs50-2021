#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Prompt for input credit card number.
    // Use long instead of int because input numbers are huge.
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    int sum_multiplied = 0; // sum of the digits that will be multiplied by 2
    int not_multiplied = 0; // sum of the digits that are not multiplied by two
    int start; // The starting 2 digits of the credit card number
    int length = 0; // length of the digits

    // While loop runs as long as number is greater than 0
    while (number > 0)
    {
        // Check if only 2 digits remaining. If it is, assign to start
        if (number > 9 && number < 100)
        {
            start = number;
        }
        // increment to the digits that are not multiplied by two
        not_multiplied += number % 10;
        number = number / 10;
        length++;

        // If no digits remaining, break
        if (number == 0)
        {
            break;
        }
        else
        {
            // Here check again if only 2 digits remaining
            if (number > 9 && number < 100)
            {
                start = number;
            }
            // For the digits that are multiplied by two, multiply them first
            int to_be_added = (number % 10) * 2;
            // If the result is 2 digits, separate them then sum.
            if (to_be_added > 9)
            {
                sum_multiplied += (to_be_added % 10) + (to_be_added / 10);
            }
            // Otherwise, the result is single digit. No need to separate.
            else
            {
                sum_multiplied += to_be_added;
            }
            number = number / 10;
            length++;
        }
    }

    // sum the result above with sum of the digits that are not multiplied
    int total = sum_multiplied + not_multiplied;

    // If the last digit of total is 0
    if (total % 10 == 0)
    {
        // If 15-digits and start with 34 or 37, then AMEX
        if (length == 15 && ((start == 34) || (start == 37)))
        {
            printf("AMEX\n");
        }
        // If start between 51-55 (inclusive) and 16 digits, then MASTERCARD
        else if ((start >= 51 && start <= 55) && length == 16)
        {
            printf("MASTERCARD\n");
        }
        // If starts with 4 and 13 or 16 digits, then VISA
        else if ((start / 10 == 4) && (length == 13 || length == 16))
        {
            printf("VISA\n");
        }
        // Otherwise invalid
        else
        {
            printf("INVALID\n");
        }
    }
    // If the last digit of total is not 0, then we know from the beginning that it's INVALID
    else
    {
        printf("INVALID\n");
    }
}