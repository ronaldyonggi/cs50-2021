#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for input height
    // Keep prompting until input height is between (including) 1 to 8.
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Prints the pyramid
    for (int i = 1; i <= height; i++)
    {
        // Prints the spaces before the hash. The end point is height - i.
        for (int dot = 1; dot <= height - i; dot++)
        {
            printf(" ");
        }

        // Prints the hash
        for (int hash = 1; hash <= i; hash++)
        {
            printf("#");
        }

        // Ends with a newline
        printf("\n");
    }
}