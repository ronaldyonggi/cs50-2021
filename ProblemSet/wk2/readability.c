#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for text
    string text = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // If the char is not alphanumeric, it's either a space or special characters
        if (!(isalpha(text[i])))
        {
            // If it's a space, increment words
            if (text[i] == ' ')
            {
                words++;
            }
            // Otherwise it's a special character. Increment sentences
            else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
            {
                sentences++;
            }
        }
        // Otherwise it's a letter or numeric. Increment letters.
        else
        {
            letters++;
        }
    }
    // In the end, increment words by 1 since words are always 1 extra than spaces
    words++;

    // Compute L and S. Make sure to multiply by 100.0 rather than 100 because with 100
    // some decimals might be shave off, resulting in wrong rounding!
    float L = letters * 100.0 / words;
    float S = sentences * 100.0 / words;
    // Now calculate index
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    /*
    printf("Letters: %i\n", letters);
    printf("Words: %i\n", words);
    printf("Sentences: %i\n", sentences);
    */

}