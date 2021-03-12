#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    /* Keep prompting until input number is 9 or greater */
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    // Keep prompting until input number is equal or greater than 'start'
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int years = 0; //years that have passed

    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}