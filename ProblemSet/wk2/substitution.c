#include <cs50.h> //get_string
#include <stdio.h> // printf
#include <ctype.h> //isalpha, isdigit, tolower, toupper
#include <string.h> //strlen
#include <stdlib.h> //atoi

int main(int argc, string argv[])
{

    // if the argument count is other than 2, print error message
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1; // include an exit code
    }
    // Assign the argument to a variable
    string argument = argv[1];
    int length = strlen(argument); // length of argument
    // If length of argument is not 26, then input is invalid. Print 'Key must contain 26 chars'
    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Iterate through each character in argument
    for (int i = 0; i < length; i++)
    {
        // If the argument contains non-alphabet character, print error message then return 1
        if (!isalpha(argument[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        // Use a different pointer, j, to check for duplicates. Not the most efficient way...O(n^2)
        for (int j = i + 1; j < length - 2; j++)
        {
            if (argument[i] == argument[j])
            {
                printf("Key contains duplicate!\n");
                return 1;
            }
        }
    }

    // TODO: Prompt for input text
    string text = get_string("plaintext: ");

    // Iterate through each character in input text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If the character is a letter, shift it!
        if (isalpha(text[i]))
        {
            // If it's uppercase, subtract by 65 ('A'), then access index in argument, then touppercase
            if (isupper(text[i]))
            {
                text[i] = toupper(argument[text[i] - 65]);
            }
            // Otherwise it's lowercase. Subtract by 97 ('a') then access index in argument, then tolowercase
            else
            {
                text[i] = tolower(argument[text[i] - 97]);
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}