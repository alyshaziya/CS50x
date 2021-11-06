#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check if single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    // loop over command line argument to verify if its integers only
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // if command line argument is not integers, print Usage msg
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }

    }
    // convert string to integer
    int key = atoi(argv[1]);

    // prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    int ptext = strlen(plaintext);
    printf("ciphertext: ");


    for (int j = 0; j < ptext; j++)
    {
        // if letters are alphanumeric
        if (isalpha(plaintext[j]))
        {
            // if letters are uppercase
            if (isupper(plaintext[j]))
            {
                printf("%c", (((plaintext[j] - 65) + key) % 26) + 65);
            }

            // if letters are lowercase
            if (islower(plaintext[j]))
            {
                printf("%c", (((plaintext[j] - 97) + key) % 26) + 97);
            }
        }
        else
        {
            // print them regularly
            printf("%c", plaintext[j]);
        }
    }
    printf("\n");
    return 0;
}