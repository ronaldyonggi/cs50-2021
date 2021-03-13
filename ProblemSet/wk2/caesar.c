#include <cs50.h> //get_string
#include <stdio.h> // printf
#include <ctype.h> //isalpha, isdigit
#include <string.h> //strlen
#include <stdlib.h> //atoi

int main(int argc, string argv[])
{

    // Assign error message to a variable
    string err = "Usage: ./caesar key\n";
    // if the argument count is other than 2, print error message then return 1
    if (argc != 2)
    {
        printf("%s", err);
        return 1; // include an exit code
    }
    // Assign the argument to a variable 'argument'
    string argument = argv[1];

    // Iterate through each character in argument
    for (int i = 0, length = strlen(argument); i < length; i++)
    {
        // If the argument contains non-numeric character, print error message, then return 1
        if (!isdigit(argument[i]))
        {
            printf("%s", err);
            return 1; // include an exit code
        }
    }
    // Converts argument to int
    int key = atoi(argument);

    // TODO: Prompt for input text
    string text = get_string("plaintext: ");

    // Iterate through each character in input text
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // If the character is a letter, shift it!
        if (isalpha(text[i]))
        {
            // If it's uppercase, subtract by 65 ('A') + key, then mod 26, then add 65 back
            if (isupper(text[i]))
            {
                text[i] = ((text[i] - 65 + key) % 26) + 65;
            }
            // Otherwise it's lowercase. Subtract by 97 ('a') + key, then mod 26, then add 97 back
            else
            {
                text[i] = ((text[i] - 97 + key) % 26) + 97;
            }
        }
    }
    printf("ciphertext: %s\n", text);
    return 0;
}