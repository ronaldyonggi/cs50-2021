#include <stdio.h>
#include <cs50.h> // Include this library to be able to use get_string

int main(void)
{

    // Asks for an input string, store in variable 'name'
    string name = get_string("What is your name?\n"); // End with a newline '\n'

    // Use a placeholder formatting. %s is a placeholder for a string
    printf("hello, %s\n", name);
}